#!/bin/bash

echo "Enter the directory name:"
read dir

if [ ! -d "$dir" ]
then
    echo "Not a directory name"
    exit 1
fi

cd "$dir"
echo "Files in the directory $dir are:"
ls
