#!/bin/bash

#Menu
echo -n "Select an option";
echo -n "1.List of files in current directory"
echo -n "2.Processes of Users."
echo -n "3.Today's Date."
echo -n "4.Quit."
echo -n "Enter your choice from the above menu [1:4]: "

userName="$USER"

while :
do

read choice

case $choice in
	#choice1
	1) echo "You chose option 1."
	   for entry in `ls $search_dir`; do
		echo $entry
	   done
		printf '\n';;
	#choice2
	2) echo "You chose option 2."
		for process in `ps -U $userName`;do
			echo $process
		done
		printf '\n';;
	#choice3
	3) echo "You chose option 3."
		currDate=$(date +'%r')
		echo "${currDate}"

		printf '\n';;

	#choice4
	4) echo "You chose option 4. Exiting Menu now."
		break
		printf '\n';;
	#default
	*) echo "Invalid option";;

esac 
	echo -n "Enter your menu choice [1-4]: "
done

