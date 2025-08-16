#!/bin/bash

RED_COLOR="\033[0;31m"
GREEN_COLOR="\033[0;32m"
RESET_COLOR="\033[0m"

function check_status()
{
    retVal=$?
    if [ $retVal -ne 0 ]; then
        printf "${RED_COLOR}Error: $1 ${RESET_COLOR}\n"
        exit $retVal
    else
        printf "${GREEN_COLOR}Done: $1 ${RESET_COLOR}\n"
    fi
}

# Check if a folder already exists in /tmp with the prefix 'build-'
existing_dir=$(find /tmp -maxdepth 1 -type d -name 'build-*' | head -n 1)

if [ -n "$existing_dir" ]; then
    # Use the existing folder
    echo "using existing folder: $existing_dir"
    dir="$existing_dir"
else
    # Create a new folder with mktemp
    dir=$(mktemp -d -t build-XXXXX)
    echo "Created new folder: $dir"
fi
echo "build dir: $dir"

check_status "create cmake build dir"

cmake -B${dir} -DCMAKE_BUILD_TYPE=Release .

check_status "cmake"

make -C ${dir}

check_status "make"

for exe_file in "$dir"/*.exe; do
    if [ -f "$exe_file" ]; then
    echo "------- Running: ${exe_file} -------"
    "$exe_file" # Run the .exe file
    check_status "${exe_file}"
    echo "----------------------------------"
    fi
done