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
gcc main.c -o main && ./main
