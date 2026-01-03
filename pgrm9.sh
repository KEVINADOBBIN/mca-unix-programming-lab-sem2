#!/bin/bash

while true
do
    echo "1. Copy files within the same directory"
    echo "2. Copy files between two directories"
    echo "3. Exit"
    echo "Enter your choice:"
    read ch

    case $ch in
    1)
        echo "Enter the source file:"
        read sfile

        if [ ! -f "$sfile" ]
        then
            echo "Source file does not exist"
            exit 1
        fi

        echo "Enter the destination file:"
        read dfile

        cp "$sfile" "$dfile"
        echo "File successfully copied within the directory"
        ;;
    2)
        echo "Enter the source file with path:"
        read sfilepath

        if [ ! -f "$sfilepath" ]
        then
            echo "Source file does not exist"
            exit 1
        fi

        echo "Enter the destination file with path:"
        read dfilepath

        cp "$sfilepath" "$dfilepath"
        echo "File successfully copied between directories"
        ;;
    3)
        exit
        ;;
    *)
        echo "Invalid choice"
        ;;
    esac
done
