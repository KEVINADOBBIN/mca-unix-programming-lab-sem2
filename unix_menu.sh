#!/bin/bash

while true
do
echo "---------------- UNIX COMMAND MENU ----------------"
echo "1. Display date"
echo "2. Previously executed commands"
echo "3. User manual for cat"
echo "4. List of users"
echo "5. Current user"
echo "6. System uptime"
echo "7. Information of current user"
echo "8. Calendar"
echo "9. Display file content using cat"
echo "10. Create and edit file using vi"
echo "11. Display file using more"
echo "12. Display first few lines using head"
echo "13. Display last few lines using tail"
echo "14. Search word in a file"
echo "15. Compare two files"
echo "16. Word count of a file"
echo "17. Copy file"
echo "18. List files and directories"
echo "19. Rename or move file"
echo "20. Remove file"
echo "21. Change file permission"
echo "22. Find file"
echo "23. Active processes with PID and PPID"
echo "24. Display terminal name"
echo "25. Time taken by a process"
echo "26. Send signal to process"
echo "27. Exit"
echo "28. Create new directory"
echo "29. Change directory"
echo "30. Remove directory"
echo "31. Print present working directory"
echo "---------------------------------------------------"
echo "Enter your choice:"
read ch

case $ch in
1) date ;;
2) history ;;
3) man cat ;;
4) who ;;
5) whoami ;;
6) uptime ;;
7) finger ;;
8) cal ;;
9) echo "Enter file name:"
   read f
   cat $f ;;
10) echo "Enter file name:"
    read f
    vi $f ;;
11) echo "Enter file name:"
    read f
    more $f ;;
12) echo "Enter file name:"
    read f
    head $f ;;
13) echo "Enter file name:"
    read f
    tail $f ;;
14) echo "Enter file name:"
    read f
    echo "Enter word to search:"
    read w
    grep $w $f ;;
15) echo "Enter first file:"
    read f1
    echo "Enter second file:"
    read f2
    cmp $f1 $f2 ;;
16) echo "Enter file name:"
    read f
    wc $f ;;
17) echo "Enter source file:"
    read s
    echo "Enter destination file:"
    read d
    cp $s $d ;;
18) ls ;;
19) echo "Enter source file:"
    read s
    echo "Enter destination file:"
    read d
    mv $s $d ;;
20) echo "Enter file to delete:"
    read f
    rm $f ;;
21) echo "Enter file name:"
    read f
    chmod 777 $f ;;
22) echo "Enter file name:"
    read f
    find . -name $f ;;
23) ps -ef ;;
24) tty ;;
25) time sleep 3 ;;
26) echo "Enter PID:"
    read pid
    kill $pid ;;
27) exit ;;
28) echo "Enter directory name:"
    read d
    mkdir $d ;;
29) echo "Enter directory name:"
    read d
    cd $d ;;
30) echo "Enter directory name:"
    read d
    rmdir $d ;;
31) pwd ;;
*) echo "Invalid choice" ;;
esac
done