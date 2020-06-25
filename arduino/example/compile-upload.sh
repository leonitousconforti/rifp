#!/bin/bash

# the name of the project (must match the folder and file.ino name)
# this is the only thing you are required to change
PROJECT_NAME="example"

# get the working directory
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

echo "pwd is '$DIR'"
echo "project is '$PROJECT_NAME'"

# use the arduino-cli program to compile the sketch
$DIR/../arduino-cli compile --fqbn arduino:avr:uno $DIR/../$PROJECT_NAME
# use the arduino-cli program to upload the sketch
sudo $DIR/../arduino-cli upload -p /dev/ttyACM0 --fqbn arduino:avr:uno $DIR/../$PROJECT_NAME

# clean up some of the files that are no longer needed
rm $DIR/$PROJECT_NAME.arduino.avr.uno.elf
rm $DIR/$PROJECT_NAME.arduino.avr.uno.hex
rm $DIR/$PROJECT_NAME.arduino.avr.uno.with_bootloader.hex
