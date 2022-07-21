#!/usr/bin/env bash

if [ $# -eq 0 ]
then
    rm $HOME/.mltsk/time_in_default
fi

for var in "$@"
do
    rm $HOME/.mltsk/time_in_$var
done
