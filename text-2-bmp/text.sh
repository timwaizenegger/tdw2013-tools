#!/bin/bash


convert -background white -fill black -threshold 1% -gravity center -size 50x20 label:"$1" test.bmp
