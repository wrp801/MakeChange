#!/bin/bash
input="args.txt"
######################################
# $IFS removed to allow the trimming # 
#####################################
while read -r line
do
  echo "$line"
done < "$input"
