#!/bin/bash

#
# Shell script to backup MySQL database.
#
# Notes:
# - gcc is assumed
# - UNIX target environment is assumed
#

echo
echo "Build and run project"
gcc -c main.c
gcc -c header.c
gcc -o main main.o header.o
./main
