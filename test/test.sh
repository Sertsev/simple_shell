#!/bin/bash

ans="y"

echo " are you okay?"

echo -n "y/n "
read answer

sleep 1.5

if [[ "$answer" == "y" ]]; then
        echo " yesss"
fi