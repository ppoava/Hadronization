#!/bin/bash
set -euo pipefail

source /user/pveen/Hadronization/setupEnv.sh

# =========================================================
# USAGE
# =========================================================
# ./make_subsamples.sh <NSUBSAMPLES> <NJOBS_PER_SUBSAMPLE> [SEED]
#
# Example:
# ./make_subsamples.sh 8 10 123
# =========================================================

NSUBSAMPLES=${1:-}
NJOBS_PER_SUBSAMPLE=${2:-}
SEED=${3:-0}

if [[ -z "$NSUBSAMPLES" || -z "$NJOBS_PER_SUBSAMPLE" ]]; then
    echo "Usage: $0 <NSUBSAMPLES> <NJOBS_PER_SUBSAMPLE> [SEED]"
    exit 1
fi

# =========================================================
# USER CONFIG
# =========================================================

INPUT_DIR="/data/alice/pveen_new/PanosPaper/RootFiles/AnalysisResults/HF/MONASH/Job700"

OUTPUT_BASE_DIR="/user/pveen/Hadronization/AnalyzedData/SUBSAMPLES_700"
OUTPUT_DIR="${OUTPUT_BASE_DIR}/combined_root_subSamples_MONASH"

mkdir -p "${OUTPUT_DIR}"

# =========================================================
# FIND ALL JOB DIRECTORIES
# =========================================================

mapfile -t ALL_JOBS < <(
    find "${INPUT_DIR}" \
        -mindepth 1 -maxdepth 1 \
        -type d \
        -name "hf_*_job*"
)

NJOBS_TOTAL=${#ALL_JOBS[@]}

if [[ "$NJOBS_TOTAL" -eq 0 ]]; then
    echo "ERROR: No jobs found in ${INPUT_DIR}"
    exit 1
fi

echo "Found ${NJOBS_TOTAL} total jobs"

# =========================================================
# RANDOM SEED CONTROL
# =========================================================

RANDOM=$SEED

# =========================================================
# GET ROOT FILE LIST FROM FIRST VALID JOB
# =========================================================

FIRST_JOB=""
for j in "${ALL_JOBS[@]}"; do
    if compgen -G "${j}/*.root" > /dev/null; then
        FIRST_JOB="$j"
        break
    fi
done

if [[ -z "$FIRST_JOB" ]]; then
    echo "ERROR: No ROOT files found in any job"
    exit 1
fi

mapfile -t ROOTFILES < <(
    find "${FIRST_JOB}" \
        -type f -name "*.root" \
        -exec basename {} \; | sort
)

echo "Found ${#ROOTFILES[@]} ROOT file types"

# =========================================================
# SUBSAMPLING LOOP
# =========================================================

for (( s=1; s<=NSUBSAMPLES; s++ ))
do
    echo "========================================"
    echo "Creating subsample ${s}"
    echo "========================================"

    SUB_DIR="${OUTPUT_DIR}/combined_root_${s}"
    mkdir -p "${SUB_DIR}"

    JOBLIST_FILE="${SUB_DIR}/jobs_used.txt"
    : > "${JOBLIST_FILE}"

    # -----------------------------------------------------
    # SAMPLE JOBS (WITHIN SUBSAMPLE NO REPLACEMENT)
    # -----------------------------------------------------

    mapfile -t SHUFFLED_JOBS < <(
        printf "%s\n" "${ALL_JOBS[@]}" | shuf
    )

    SELECTED_JOBS=("${SHUFFLED_JOBS[@]:0:NJOBS_PER_SUBSAMPLE}")

    if [[ ${#SELECTED_JOBS[@]} -lt "$NJOBS_PER_SUBSAMPLE" ]]; then
        echo "WARNING: not enough jobs, using ${#SELECTED_JOBS[@]}"
    fi

    # save job list
    for j in "${SELECTED_JOBS[@]}"; do
        basename "$j" >> "${JOBLIST_FILE}"
    done

    # -----------------------------------------------------
    # MERGE EACH ROOT FILE TYPE
    # -----------------------------------------------------

    for ROOTFILE in "${ROOTFILES[@]}"
    do
        FILES=()

        for JOB in "${SELECTED_JOBS[@]}"
        do
            F="${JOB}/${ROOTFILE}"
            if [[ -f "$F" ]]; then
                FILES+=("$F")
            fi
        done

        if [[ ${#FILES[@]} -eq 0 ]]; then
            echo "Skipping ${ROOTFILE} (no files found)"
            continue
        fi

        OUTPUT_FILE="${SUB_DIR}/${ROOTFILE}"

        echo "Merging ${ROOTFILE} with ${#FILES[@]} files"

        hadd -f "${OUTPUT_FILE}" "${FILES[@]}"
    done

    echo "Finished subsample ${s}"
done

echo "========================================"
echo "ALL SUBSAMPLES COMPLETE"
echo "Output: ${OUTPUT_DIR}"
echo "========================================"
