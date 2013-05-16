#!/bin/bash

#:<< '--COMMENT--'

TEXT = "sample"
@ECHO off
clear

# ******  reading text and generating bitmap image  ******************

echo TEXT execution...
echo "Write the text:"
#read TEXT
#convert -background white -type truecolor -fill black -threshold 1% -gravity center -font helvetica-Bold -size 90x50 label:$TEXT teste.bmp 
convert -background white -type truecolor -fill black -threshold 1% -gravity center -font helvetica-Bold -size 90x50 label:"$1" teste.bmp 
echo Press enter to continue...
read


# ******  MAKEFILE  ******************
echo MAKE:
cd /home/miller/Gtestes/ewoms
make lens_immiscible
echo "done!"
echo Press enter to continue...
read

# ******  Lens_immiscible execution  ******************

echo Lens_Immmiscible:
cd /home/miller/Gtestes/ewoms/test/implicit
./lens_immiscible
echo "done!"
echo Press enter to continue...
read
#--COMMENT--


cd /home/miller
pvbatch script6.py


# ******  Image conversion  ******************
#echo PNG to GIF conversion
#echo "Converting..."
#convert "/home/miller/TDWimages/*.png" "/home/miller/TDWimages/images.gif"
#echo "done!"

# ******  AVI conversion  ******************
#cd /mnt/compartilha/images
#ffmpeg -qscale 5 -r 10 -b 9600 -i im.00%02d.png "/home/miller/movie.avi"





# ******  GARBAGE  ******************


#convert images.gif /home/miller/imagesaux/old%02d.jpg
#ffmpeg -r 25 -i old%02d.jpg -y -an new.avi
#ffmpeg -r 25 -i /home/miller/imagesaux/old%02d.jpg -y -an new.avi
#convert  "/mnt/compartilha/images/*.png" video.mpg
#mencoder -ovc lavc -lavcopts vcodec=mpeg1video:vbitrate=1500  w=800:h=600:fps=15:type=png -nosound -of mpeg -o output.mpg mf://*.png
#convert *.png %02d.jpg
#mencoder mf://*.jpg -mf w=800:h=600:fps=15:type=png -ovc raw -oac copy -o output.mpeg
