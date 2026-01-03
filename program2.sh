#!/bin/bash

echo "Enter the directory name:"
read dir

if [ -d "$dir" ]
then
    cd "$dir"

    for file in *
    do
        if [ -f "$file" ]
        then
            if [ -r "$file" -a -w "$file" -a -x "$file" ]
            then
                echo "All permissions exist for $file"
                ls -l "$file"
            else
                echo "Permissions not available for $file"
                chmod 777 "$file"
                echo "Permission given"
                ls -l "$file"
            fi
        fi
    done
else
    echo "Directory does not exist"
fi