#!/bin/bash

# Check for exactly 4 arguments:
# 3 input files + 1 output file
if [ $# -ne 4 ]
then
    echo "Usage: $0 file1 file2 file3 outputfile"
    exit 1
fi

# Check whether input files exist
for file in "$1" "$2" "$3"
do
    if [ ! -f "$file" ]
    then
        echo "File not found: $file"
        exit 1
    fi
done

# Merge files into output file
cat "$1" "$2" "$3" > "$4"

echo "All 3 files copied into $4"
echo "--------------------------------"
echo "Contents of merged file:"
cat "$4"

echo "--------------------------------"
echo "File description:"
ls -l "$4"
