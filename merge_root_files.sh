#!/bin/bash
set -euo pipefail

source /user/pveen/Hadronization/setupEnv.sh

# =========================================================
# DIRECTORIES
# =========================================================

INPUT_DIR="/data/alice/pveen_new/PanosPaper/RootFiles/AnalysisResults/HF/JUNCTIONS/Job700"

OUTPUT_BASE_DIR="/user/pveen/Hadronization/AnalyzedData"

OUTPUT_DIR="${OUTPUT_BASE_DIR}/complete_root_21_06_2026_JUNCTIONS"

# =========================================================
# CREATE OUTPUT DIRECTORY
# =========================================================

mkdir -p "${OUTPUT_DIR}"

# =========================================================
# FIND UNIQUE ROOT FILENAMES
# =========================================================

ROOT_FILENAMES=$(find "${INPUT_DIR}" \
    -mindepth 2 -maxdepth 2 \
    -type f -name "*.root" \
    -exec basename {} \; | sort | uniq)

if [[ -z "${ROOT_FILENAMES}" ]]; then
    echo "ERROR: No ROOT files found in ${INPUT_DIR}"
    exit 1
fi

# =========================================================
# MERGE EACH ROOT FILE TYPE
# =========================================================

for ROOTFILE in ${ROOT_FILENAMES}
do

    echo "========================================"
    echo "Processing ${ROOTFILE}"
    echo "========================================"

    mapfile -t FILES < <(
        find "${INPUT_DIR}" \
            -mindepth 2 -maxdepth 2 \
            -type f -name "${ROOTFILE}"
    )

    if [[ ${#FILES[@]} -eq 0 ]]; then
        echo "WARNING: no files found for ${ROOTFILE}"
        continue
    fi

    OUTPUT_FILE="${OUTPUT_DIR}/${ROOTFILE}"

    echo "Found ${#FILES[@]} files"
    echo "Output: ${OUTPUT_FILE}"

    hadd -f "${OUTPUT_FILE}" "${FILES[@]}"

    echo "Finished merging ${ROOTFILE}"
    echo

done

echo "========================================"
echo "All merges completed successfully"
echo "Output directory: ${OUTPUT_DIR}"
echo "========================================"
