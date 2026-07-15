#!/bin/bash
set -euo pipefail

# Merge per-job THnSparse status-analysis outputs into Paul's complete_root input
# directories for one tune or for all paper tunes.
#
# Usage:
#   ./merge_root_files.sh TUNE [JOB_TAG] [OUTPUT_TAG]
#   ./merge_root_files.sh ALL Job700 21_06_2026
#
# TUNE can be MONASH, JUNCTIONS, CLOSEPACKING, or ALL.

usage() {
    cat <<'USAGE'
Usage:
  ./merge_root_files.sh TUNE [JOB_TAG] [OUTPUT_TAG]
  ./merge_root_files.sh ALL Job700 21_06_2026

TUNE:
  MONASH
  JUNCTIONS
  CLOSEPACKING
  ALL

Defaults:
  JOB_TAG    = Job700
  OUTPUT_TAG = 21_06_2026

Environment overrides:
  ANALYSIS_OUTPUT_BASE Per-job THnSparse analysis output base directory.
  ANALYZED_DATA_BASE   Destination base for complete_root directories.
  HADRONIZATION_BASE   Hadronization checkout, used for setupEnv.sh and AnalyzedData default.
  MERGE_BACKEND         object (default) or hadd.
USAGE
}

script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
project_base="${HADRONIZATION_BASE:-${script_dir}}"
project_base="${project_base%/}"
export HADRONIZATION_BASE="${project_base}"

requested_tune="${1:-}"
job_tag="${2:-Job700}"
output_tag="${3:-21_06_2026}"

if [[ -z "${requested_tune}" || "${requested_tune}" == "-h" || "${requested_tune}" == "--help" ]]; then
    usage
    exit 0
fi

requested_tune="$(printf '%s' "${requested_tune}" | tr '[:lower:]' '[:upper:]')"

analysis_output_base="${ANALYSIS_OUTPUT_BASE:-/data/alice/pveen_new/PanosPaper/RootFiles/AnalysisResults/HF}"
analyzed_data_base="${ANALYZED_DATA_BASE:-${project_base}/AnalyzedData}"
merge_backend="${MERGE_BACKEND:-object}"

case "${merge_backend}" in
    object|hadd)
        ;;
    *)
        echo "ERROR: MERGE_BACKEND must be 'object' or 'hadd', got '${merge_backend}'" >&2
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

merge_files() {
    local output_file="$1"
    shift

    case "${merge_backend}" in
        object)
            local merge_macro="${project_base}/AnalysisScripts/MergeAnalysisObjects.C"
            if [[ ! -f "${merge_macro}" ]]; then
                echo "ERROR: object merge backend requested, but macro not found: ${merge_macro}" >&2
                return 1
            fi

            local input_list
            input_list="$(mktemp "/tmp/merge_root_files_XXXXXX.txt")"
            printf '%s\n' "$@" > "${input_list}"

            root -l -b <<ROOTCMDS
.L ${merge_macro}+
int __merge_result = MergeAnalysisObjects("${input_list}", "${output_file}", true);
if (__merge_result != 0) { gSystem->Exit(__merge_result); }
.q
ROOTCMDS
            ;;
        hadd)
            local tmp_output
            tmp_output="$(mktemp "/tmp/hadronization_hadd_XXXXXX.root")"
            rm -f "${tmp_output}"
            mkdir -p "$(dirname "${output_file}")"

            if hadd -f -v 0 "${tmp_output}" "$@"; then
                mv -f "${tmp_output}" "${output_file}"
            else
                rm -f "${tmp_output}"
                return 1
            fi
            ;;
    esac
}

merge_tune() {
    local tune="$1"
    local input_dir="${analysis_output_base}/${tune}/${job_tag}"
    local output_dir="${analyzed_data_base}/complete_root_${output_tag}_${tune}"

    echo "========================================"
    echo "Merging tune: ${tune}"
    echo "Input:  ${input_dir}"
    echo "Output: ${output_dir}"
    echo "========================================"

    if [[ ! -d "${input_dir}" ]]; then
        echo "ERROR: input directory not found for ${tune}: ${input_dir}" >&2
        return 1
    fi

    mkdir -p "${output_dir}"

    local root_filenames
    root_filenames=$(find "${input_dir}" \
        -mindepth 2 -maxdepth 2 \
        -type f -name "*.root" \
        -exec basename {} \; | sort | uniq)

    if [[ -z "${root_filenames}" ]]; then
        echo "ERROR: no ROOT files found in ${input_dir}" >&2
        return 1
    fi

    local rootfile
    for rootfile in ${root_filenames}; do
        echo "Processing ${rootfile}"

        files=()
        while IFS= read -r file; do
            files+=("${file}")
        done < <(
            find "${input_dir}" \
                -mindepth 2 -maxdepth 2 \
                -type f -name "${rootfile}"
        )

        if [[ ${#files[@]} -eq 0 ]]; then
            echo "WARNING: no files found for ${rootfile}" >&2
            continue
        fi

        echo "Found ${#files[@]} files"
        echo "Output: ${output_dir}/${rootfile}"
        merge_files "${output_dir}/${rootfile}" "${files[@]}"
        echo
    done

    echo "Finished ${tune}: ${output_dir}"
}

tunes=($(resolve_tunes "${requested_tune}"))

for tune in "${tunes[@]}"; do
    merge_tune "${tune}"
done

echo "========================================"
echo "All requested merges completed successfully"
echo "Tunes: ${tunes[*]}"
echo "========================================"
