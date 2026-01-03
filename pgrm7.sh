#!/bin/bash

while true
do
    echo "1. Count number of lines without vowels"
    echo "2. Count number of characters, words, and lines"
    echo "3. Exit"
    printf "Enter your choice: "
    read ch

    case $ch in
    1)
        echo "Enter the file name:"
        read file
        grep -ci -v '[aeiou]' "$file"
        ;;
    2)
        echo "Enter the file name:"
        read file
        echo "Number of characters:"
        wc -c "$file"
        echo "Number of words:"
        wc -w "$file"
        echo "Number of lines:"
        wc -l "$file"
        ;;
    3)
        exit
        ;;
    *)
        echo "Invalid choice"
        ;;
    esac
done
