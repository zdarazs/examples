#!/bin/bash

if [[ $(xdotool get_desktop) == 0 ]];then
    wmctrl -s 1
elif [[ $(xdotool get_desktop) == 1 ]];then
    wmctrl -s 0
fi

