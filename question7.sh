#!/bin/bash

#Menu
echo "Select an option from the menu below"
printf '\n'

echo "1. Currently logged user and his logname."
echo "2. Your current shell."
echo "3. Your home directory."
echo "4. You current path setting."
echo "5. Your current working directory."
echo "6. Show currently logged number of users."
echo "7. Show disk usage."
echo "8. Show information about last log."
echo "9. Show information about last reboot."
echo "10. Just Quit"
echo "Enter your choice from the above menu[1:10]: "

userName="$USER"

while :
do

read choice

case $choice in 
	
	#choice1
		1) echo "You chose 1st choice"
		echo "Currently logged user is ${userName}"
		printf '\n';;
	#choice2
		2) echo "You chose 2nd choice"
			echo $0
			printf '\n';;
	#choice3
		3) echo "You chose 3rd choice"
			echo $HOME
			printf '\n';;
	#choice4
		4) echo "You chose 4th choice"
			echo $PATH
			printf '\n';;
	#choice5
		5) echo "You chose 5th choice"
			echo "Your current working directory is ${PWD}"
			printf '\n';;
	#choice6
		6) echo "You chose 6th choice"
			userCount=$( who --count )
			echo "Number of logged in user is ${userCount}"
			printf '\n';;
	#choice7
		7) echo "You chose 7th choice"
			for entry in `df -H`;do
				echo $entry
			done
			
			printf '\n';;
	#choice8
		8) echo "You chose 8th choice"
			echo $( last )
			printf '\n';;
	#choice9
		9) echo "You chose 9th choice"
			#for entry in `last reboot`;do
			#	echo $entry
			#done
			#lastReboot=
			echo $(last reboot)
			printf '\n';;
	#choice10
		10) echo "You chose 10th choice. Quiting menu."
			break
			printf '\n';;
	#defaultCase
		*) echo "Invalid Option";;

esac
	echo -n "Enter your menu choice  [1-10]: "
done
