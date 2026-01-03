#!/bin/bash

# Check whether at least one argument is provided
if [ $# -lt 1 ]
then
    echo "Usage: $0 file1 [file2 ...]"
    exit 1
fi

# Process each file
for file in "$@"
do
    if [ -f "$file" ]
    then
        echo "Contents of $file in UPPERCASE:"
        cat "$file" | tr 'a-z' 'A-Z'
        echo "--------------------------------"
    else
        echo "File not found: $file"
    fi
done