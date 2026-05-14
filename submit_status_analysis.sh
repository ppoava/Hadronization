#!/bin/bash
set -euo pipefail

# =========================================================
# USER INPUTS
# =========================================================

INPUT_DIRECTORY="/data/alice/ipardoza/Hadronization/RootFiles/HF/MONASH"
INPUT_ANALYSIS_SCRIPTS_DIRECTORY="/user/pveen/Hadronization/AnalysisScripts"

OUTPUT_DIRECTORY="/data/alice/pveen_new/PanosPaper/RootFiles/AnalysisResults/HF/MONASH/Job500"
OUTPUT_LOGS_DIRECTORY="${OUTPUT_DIRECTORY}/Logs"

NUMBER_OF_SUBJOBS=${1:-1}

# =========================================================
# CREATE OUTPUT DIRS
# =========================================================

mkdir -p "${OUTPUT_DIRECTORY}"
mkdir -p "${OUTPUT_LOGS_DIRECTORY}"

# =========================================================
# BUILD SUBMIT FILE
# =========================================================

SUBFILE="submit_status_analysis.sub"

cat > "${SUBFILE}" <<EOF
universe = vanilla
executable = run_status_analysis.sh

request_cpus = 1
request_memory = 2GB
request_disk = 2GB

+UseOS = "el9"
+JobCategory = "short"

should_transfer_files = YES
when_to_transfer_output = ON_EXIT

EOF

# =========================================================
# FIND INPUT FILES
# =========================================================

for (( i=0; i<NUMBER_OF_SUBJOBS; i++ ))
do
    FILE=$(find "${INPUT_DIRECTORY}" -name "*job${i}.root" | head -n 1)

    if [[ -z "${FILE}" ]]; then
        echo "WARNING: missing file for job ${i}"
        continue
    fi

    cat >> "${SUBFILE}" <<EOF

arguments = ${i} ${FILE} ${OUTPUT_DIRECTORY} ${INPUT_ANALYSIS_SCRIPTS_DIRECTORY}

output = ${OUTPUT_LOGS_DIRECTORY}/job_${i}.out
error  = ${OUTPUT_LOGS_DIRECTORY}/job_${i}.err
log    = ${OUTPUT_LOGS_DIRECTORY}/job_${i}.log

queue 1
EOF

done

# =========================================================
# SUBMIT
# =========================================================

condor_submit "${SUBFILE}"
