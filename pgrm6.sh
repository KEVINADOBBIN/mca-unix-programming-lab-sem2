#!/bin/bash

# Check for two arguments
if [ $# -lt 2 ]
then
    echo "Enter two file names as arguments"
    exit 1
fi

# Check if both files exist
if [ -f "$1" -a -f "$2" ]
then
    if cmp "$1" "$2" > /dev/null
    then
        echo "Files are same"
        rm "$2"
        echo "Second file deleted"
    else
        echo "Files are different"
    fi
else
    echo "One or both files do not exist"
fi
