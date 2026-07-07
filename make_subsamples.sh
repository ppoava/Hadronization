#!/bin/bash
set -euo pipefail

# Build Paul-style subsample complete_root directories from per-job THnSparse
# status-analysis outputs.
#
# Usage:
#   ./make_subsamples.sh
#   ./make_subsamples.sh TUNE NSUBSAMPLES NJOBS_PER_SUBSAMPLE [SEED] [JOB_TAG] [SUBSAMPLE_TAG]
#   ./make_subsamples.sh ALL 10 10 123 Job700 700
#
# TUNE can be MONASH, JUNCTIONS, CLOSEPACKING, or ALL.
#
# Numeric shorthand is also accepted:
#   ./make_subsamples.sh NSUBSAMPLES NJOBS_PER_SUBSAMPLE [SEED]
# which defaults to TUNE=ALL.

usage() {
    cat <<'USAGE'
Usage:
  ./make_subsamples.sh
  ./make_subsamples.sh TUNE NSUBSAMPLES NJOBS_PER_SUBSAMPLE [SEED] [JOB_TAG] [SUBSAMPLE_TAG]
  ./make_subsamples.sh ALL 10 10 123 Job700 700

Numeric shorthand:
  ./make_subsamples.sh NSUBSAMPLES NJOBS_PER_SUBSAMPLE [SEED]

TUNE:
  MONASH
  JUNCTIONS
  CLOSEPACKING
  ALL

Defaults:
  TUNE          = ALL
  NSUBSAMPLES   = 10
  NJOBS/SAMPLE  = 10
  SEED          = 123
  JOB_TAG       = Job700
  SUBSAMPLE_TAG = 700

Environment overrides:
  ANALYSIS_OUTPUT_BASE Per-job THnSparse analysis output base directory.
  ANALYZED_DATA_BASE   Destination base for AnalyzedData.
  HADRONIZATION_BASE   Hadronization checkout, used for setupEnv.sh and AnalyzedData default.
  SUBSAMPLE_MODE       partition (default) or bootstrap.

The default partition mode shuffles the available jobs once per tune and then
splits them into non-overlapping subsamples. Use SUBSAMPLE_MODE=bootstrap only
when overlapping random resamples are intentional.
USAGE
}

script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
project_base="${HADRONIZATION_BASE:-${script_dir}}"
project_base="${project_base%/}"
export HADRONIZATION_BASE="${project_base}"

default_tune="ALL"
default_nsubsamples="10"
default_njobs_per_subsample="10"
default_seed="123"
default_job_tag="Job700"
default_subsample_tag="700"

if [[ "${1:-}" == "-h" || "${1:-}" == "--help" ]]; then
    usage
    exit 0
fi

if [[ "$#" -eq 0 ]]; then
    requested_tune="${default_tune}"
    nsubsamples="${default_nsubsamples}"
    njobs_per_subsample="${default_njobs_per_subsample}"
    seed="${default_seed}"
    job_tag="${default_job_tag}"
    subsample_tag="${default_subsample_tag}"
elif [[ "${1}" =~ ^[0-9]+$ ]]; then
    requested_tune="${default_tune}"
    nsubsamples="${1}"
    njobs_per_subsample="${2:-}"
    seed="${3:-${default_seed}}"
    job_tag="${default_job_tag}"
    subsample_tag="${default_subsample_tag}"
else
    requested_tune="$(printf '%s' "${1}" | tr '[:lower:]' '[:upper:]')"
    nsubsamples="${2:-${default_nsubsamples}}"
    njobs_per_subsample="${3:-${default_njobs_per_subsample}}"
    seed="${4:-${default_seed}}"
    job_tag="${5:-${default_job_tag}}"
    subsample_tag="${6:-${default_subsample_tag}}"
fi

for value_name in nsubsamples njobs_per_subsample seed; do
    value="${!value_name}"
    if ! [[ "${value}" =~ ^[0-9]+$ ]]; then
        echo "ERROR: ${value_name} must be an integer, got '${value}'" >&2
        exit 1
    fi
done

analysis_output_base="${ANALYSIS_OUTPUT_BASE:-/data/alice/pveen_new/PanosPaper/RootFiles/AnalysisResults/HF}"
analyzed_data_base="${ANALYZED_DATA_BASE:-${project_base}/AnalyzedData}"
output_base_dir="${analyzed_data_base}/SUBSAMPLES_${subsample_tag}"
subsample_mode="${SUBSAMPLE_MODE:-partition}"

case "${subsample_mode}" in
    partition|bootstrap)
        ;;
    *)
        echo "ERROR: SUBSAMPLE_MODE must be 'partition' or 'bootstrap', got '${subsample_mode}'" >&2
        exit 1
        ;;
esac

if [[ -f "${project_base}/setupEnv.sh" ]]; then
    # shellcheck disable=SC1091
    source "${project_base}/setupEnv.sh"
fi

resolve_tunes() {
    case "$1" in
        MONASH|JUNCTIONS|CLOSEPACKING)
            printf '%s\n' "$1"
            ;;
        ALL)
            printf '%s\n' MONASH JUNCTIONS CLOSEPACKING
            ;;
        *)
            echo "ERROR: unknown tune '$1'. Expected MONASH, JUNCTIONS, CLOSEPACKING, or ALL." >&2
            exit 1
            ;;
    esac
}

shuffle_jobs() {
    local tune_index="$1"
    local subsample_index="$2"
    local shuffle_seed=$((seed + tune_index * 100000 + subsample_index))

    awk -v seed="${shuffle_seed}" '
        BEGIN { srand(seed) }
        { print rand() "\t" $0 }
    ' | sort -k1,1n | cut -f2-
}

make_tune_subsamples() {
    local tune="$1"
    local tune_index="$2"
    local input_dir="${analysis_output_base}/${tune}/${job_tag}"
    local output_dir="${output_base_dir}/combined_root_subSamples_${tune}"

    echo "========================================"
    echo "Creating subsamples for ${tune}"
    echo "Input:  ${input_dir}"
    echo "Output: ${output_dir}"
    echo "Mode:   ${subsample_mode}"
    echo "========================================"

    if [[ ! -d "${input_dir}" ]]; then
        echo "ERROR: input directory not found for ${tune}: ${input_dir}" >&2
        return 1
    fi

    mkdir -p "${output_dir}"

    all_jobs=()
    while IFS= read -r job; do
        all_jobs+=("${job}")
    done < <(
        find "${input_dir}" \
            -mindepth 1 -maxdepth 1 \
            -type d \
            -name "hf_*_job*" | sort
    )

    local njobs_total=${#all_jobs[@]}

    if [[ "${njobs_total}" -eq 0 ]]; then
        echo "ERROR: no jobs found in ${input_dir}" >&2
        return 1
    fi

    echo "Found ${njobs_total} total jobs"

    local first_job=""
    local job
    for job in "${all_jobs[@]}"; do
        if compgen -G "${job}/*.root" > /dev/null; then
            first_job="${job}"
            break
        fi
    done

    if [[ -z "${first_job}" ]]; then
        echo "ERROR: no ROOT files found in any job under ${input_dir}" >&2
        return 1
    fi

    rootfiles=()
    while IFS= read -r rootfile; do
        rootfiles+=("${rootfile}")
    done < <(
        find "${first_job}" \
            -type f -name "*.root" \
            -exec basename {} \; | sort
    )

    echo "Found ${#rootfiles[@]} ROOT file types"

    local total_requested=$((nsubsamples * njobs_per_subsample))
    local shuffled_all_jobs=()

    if [[ "${subsample_mode}" == "partition" ]]; then
        if [[ "${total_requested}" -gt "${njobs_total}" ]]; then
            echo "ERROR: partition mode requested ${total_requested} job slots (${nsubsamples} subsamples x ${njobs_per_subsample} jobs), but only ${njobs_total} jobs are available for ${tune}." >&2
            echo "       Reduce NSUBSAMPLES or NJOBS_PER_SUBSAMPLE, or set SUBSAMPLE_MODE=bootstrap if overlapping resamples are intentional." >&2
            return 1
        fi

        while IFS= read -r shuffled_job; do
            shuffled_all_jobs+=("${shuffled_job}")
        done < <(
            printf "%s\n" "${all_jobs[@]}" | shuffle_jobs "${tune_index}" 0
        )
    fi

    local s
    for (( s=1; s<=nsubsamples; s++ )); do
        echo "Creating ${tune} subsample ${s}"

        local sub_dir="${output_dir}/combined_root_${s}"
        mkdir -p "${sub_dir}"

        local joblist_file="${sub_dir}/jobs_used.txt"
        : > "${joblist_file}"

        selected_jobs=()
        if [[ "${subsample_mode}" == "partition" ]]; then
            local offset=$(((s - 1) * njobs_per_subsample))
            selected_jobs=("${shuffled_all_jobs[@]:offset:njobs_per_subsample}")
        else
            shuffled_jobs=()
            while IFS= read -r shuffled_job; do
                shuffled_jobs+=("${shuffled_job}")
            done < <(
                printf "%s\n" "${all_jobs[@]}" | shuffle_jobs "${tune_index}" "${s}"
            )
            selected_jobs=("${shuffled_jobs[@]:0:njobs_per_subsample}")
        fi

        if [[ ${#selected_jobs[@]} -lt "${njobs_per_subsample}" ]]; then
            echo "WARNING: requested ${njobs_per_subsample} jobs but only selected ${#selected_jobs[@]}" >&2
        fi

        for job in "${selected_jobs[@]}"; do
            basename "${job}" >> "${joblist_file}"
        done

        local rootfile
        for rootfile in "${rootfiles[@]}"; do
            files=()

            for job in "${selected_jobs[@]}"; do
                candidate="${job}/${rootfile}"
                if [[ -f "${candidate}" ]]; then
                    files+=("${candidate}")
                fi
            done

            if [[ ${#files[@]} -eq 0 ]]; then
                echo "Skipping ${rootfile} for ${tune} subsample ${s}: no files found" >&2
                continue
            fi

            echo "Merging ${rootfile} with ${#files[@]} files"
            hadd -f "${sub_dir}/${rootfile}" "${files[@]}"
        done

        echo "Finished ${tune} subsample ${s}"
    done
}

tunes=($(resolve_tunes "${requested_tune}"))

tune_index=0
for tune in "${tunes[@]}"; do
    make_tune_subsamples "${tune}" "${tune_index}"
    tune_index=$((tune_index + 1))
done

echo "========================================"
echo "ALL REQUESTED SUBSAMPLES COMPLETE"
echo "Output base: ${output_base_dir}"
echo "Tunes: ${tunes[*]}"
echo "========================================"
