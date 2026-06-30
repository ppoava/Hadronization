#!/bin/bash
set -euo pipefail

# Submit Paul's THnSparse status analysis for one HF tune or for all paper tunes.
#
# Usage:
#   ./submit_status_analysis.sh TUNE [NUMBER_OF_SUBJOBS] [JOB_TAG]
#   ./submit_status_analysis.sh ALL 100 Job700
#
# TUNE can be MONASH, JUNCTIONS, CLOSEPACKING, or ALL.
#
# Environment overrides:
#   RAW_INPUT_BASE      default: /data/alice/ipardoza/Hadronization/RootFiles/HF
#   ANALYSIS_OUTPUT_BASE default: /data/alice/pveen_new/PanosPaper/RootFiles/AnalysisResults/HF
#   HADRONIZATION_BASE  default: directory containing this script
#   DRY_RUN             set to 1/true to write the submit file without condor_submit

usage() {
    cat <<'USAGE'
Usage:
  ./submit_status_analysis.sh TUNE [NUMBER_OF_SUBJOBS] [JOB_TAG]
  ./submit_status_analysis.sh ALL 100 Job700

TUNE:
  MONASH
  JUNCTIONS
  CLOSEPACKING
  ALL

Defaults:
  NUMBER_OF_SUBJOBS = 1
  JOB_TAG           = Job700

Environment overrides:
  RAW_INPUT_BASE       Raw HF ROOT input base directory.
  ANALYSIS_OUTPUT_BASE Per-job THnSparse analysis output base directory.
  HADRONIZATION_BASE   Hadronization checkout containing AnalysisScripts.
  DRY_RUN              Set to 1/true to write the submit file without condor_submit.
USAGE
}

script_dir="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
project_base="${HADRONIZATION_BASE:-${script_dir}}"
project_base="${project_base%/}"
export HADRONIZATION_BASE="${project_base}"

raw_input_base="${RAW_INPUT_BASE:-/data/alice/ipardoza/Hadronization/RootFiles/HF}"
analysis_output_base="${ANALYSIS_OUTPUT_BASE:-/data/alice/pveen_new/PanosPaper/RootFiles/AnalysisResults/HF}"
analysis_scripts_dir="${project_base}/AnalysisScripts"
dry_run="${DRY_RUN:-0}"

requested_tune="${1:-}"
number_of_subjobs="${2:-1}"
job_tag="${3:-Job700}"

if [[ -z "${requested_tune}" || "${requested_tune}" == "-h" || "${requested_tune}" == "--help" ]]; then
    usage
    exit 0
fi

requested_tune="$(printf '%s' "${requested_tune}" | tr '[:lower:]' '[:upper:]')"

if ! [[ "${number_of_subjobs}" =~ ^[0-9]+$ ]]; then
    echo "ERROR: NUMBER_OF_SUBJOBS must be an integer, got '${number_of_subjobs}'" >&2
    exit 1
fi

if [[ ! -d "${analysis_scripts_dir}" ]]; then
    echo "ERROR: AnalysisScripts directory not found: ${analysis_scripts_dir}" >&2
    exit 1
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

tunes=($(resolve_tunes "${requested_tune}"))

subfile="submit_status_analysis_${requested_tune}_${job_tag}.sub"

cat > "${subfile}" <<EOF
universe = vanilla
executable = ${project_base}/run_status_analysis.sh

request_cpus = 1
request_memory = 2GB
request_disk = 2GB

+UseOS = "el9"
+JobCategory = "short"

environment = "HADRONIZATION_BASE=${project_base}"

should_transfer_files = YES
when_to_transfer_output = ON_EXIT

EOF

queued_jobs=0

for tune in "${tunes[@]}"; do
    input_directory="${raw_input_base}/${tune}"
    output_directory="${analysis_output_base}/${tune}/${job_tag}"
    output_logs_directory="${output_directory}/Logs"

    mkdir -p "${output_directory}"
    mkdir -p "${output_logs_directory}"

    if [[ ! -d "${input_directory}" ]]; then
        echo "WARNING: input directory not found for ${tune}: ${input_directory}" >&2
        continue
    fi

    for (( i=0; i<number_of_subjobs; i++ )); do
        file=$(find "${input_directory}" -name "*job${i}.root" | head -n 1)

        if [[ -z "${file}" ]]; then
            echo "WARNING: missing file for ${tune} job ${i}" >&2
            continue
        fi

        cat >> "${subfile}" <<EOF

arguments = ${i} ${file} ${output_directory} ${analysis_scripts_dir}

output = ${output_logs_directory}/job_${i}.out
error  = ${output_logs_directory}/job_${i}.err
log    = ${output_logs_directory}/job_${i}.log

queue 1
EOF

        queued_jobs=$((queued_jobs + 1))
    done
done

if [[ "${queued_jobs}" -eq 0 ]]; then
    echo "ERROR: no status-analysis jobs were queued. Check input directories and job count." >&2
    exit 1
fi

echo "Prepared ${queued_jobs} status-analysis jobs in ${subfile}"
echo "Tunes: ${tunes[*]}"
echo "Raw input base: ${raw_input_base}"
echo "Analysis output base: ${analysis_output_base}"

case "${dry_run}" in
    1|true|TRUE|yes|YES)
        echo "DRY_RUN=${dry_run}; not submitting to Condor."
        exit 0
        ;;
esac

condor_submit "${subfile}"
