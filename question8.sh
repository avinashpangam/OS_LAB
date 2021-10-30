#!/bin/bash

LOG_DIR=/var/log
ROOT_UID=0 # Only users with $UID 0 have root privileges.
LINES=50 # Default number of lines saved.
E_XCD=86 # Can’t change directory?
E_NOTROOT=87 # Non-root exit error.

# Run as root, of course.
if [ “$UID” -ne “$ROOT_UID” ]
then
echo “Must be root to run this script.”
exit $E_NOTROOT
fi

if [ -n “$1” ]
# Test whether command-line argument is present (non-empty).
then
lines=$1
else
lines=$LINES # Default, if not specified on command-line.
fi

cd $LOG_DIR

if [ `pwd` != “$LOG_DIR” ] # or if [ “$PWD” != “$LOG_DIR” ]
# Not in /var/log?
then
echo “Can’t change to $LOG_DIR.”
exit $E_XCD
fi # Doublecheck if in right directory before messing with log file.