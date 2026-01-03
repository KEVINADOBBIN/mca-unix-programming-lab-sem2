#!/bin/bash

# Check minimum arguments
if [ $# -lt 2 ]
then
    echo "Usage: $0 file1 file2 [file3 ...]"
    exit 1
fi

# Check if all files exist
for file in "$@"
do
    if [ ! -f "$file" ]
    then
        echo "File not found: $file"
        exit 1
    fi
done

# Read words from first file
for word in $(cat "$1")
do
    echo "The word \"$word\" is found:"
    
    # Search in remaining files
    for file in "${@:2}"
    do
        count=$(grep -wo "$word" "$file" | wc -l)
        echo "$file : $count"
    done

    echo "--------------------------------"
done
