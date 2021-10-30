#!/bin/bash
echo "Enter the file path "
read path
if [ -e "$path" ];then
   echo " $path exists "
   if [ -d "$path" ];then
      echo " $path is a directory "
      echo " List of files in the directory"
      ls "$path"
      echo "No of files in the directory "
      ls "$path" | wc -l
   fi
   if [ -f "$path" ];then
      echo "$path it is a file path "
      if [[ -r "$path" && -w "$path" ]];then
      echo "File is both readable and writable "
      echo "number of lines, word count, byte and characters count in the file."
      wc "$path"
      fi
      
   fi   
          
      
 else
   echo " $path doesn't exist "
 fi      
 