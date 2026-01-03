#!/bin/bash

while true
do
    echo "1. Display lines having exactly 2 characters"
    echo "2. Display lines having more than one blank space"
    echo "3. Exit"
    echo "Enter your choice:"
    read ch

    case $ch in
    1)
        echo "Enter the file name:"
        read file
        grep -n '^..$' "$file"
        ;;
    2)
        echo "Enter the file name:"
        read file
        grep '[[:space:]]\{2,\}' "$file"
        ;;
    3)
        exit
        ;;
    *)
        echo "Invalid choice"
        ;;
    esac
done
