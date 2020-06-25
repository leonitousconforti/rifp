# Arduino-Code

This folder contains all the the sketches that are made to run on the arduino. The arduino is located next to the led light rings and above the jetson nano.

# Rationale

The main reason for including an arduino was because the led light rings (Adafruit Neopixel Rings) require precise timings to control the lights - they are driven from a single control wire on a pwm interface. The jetson-nano simply does not have the hardware to create such precise pwm signals that are required. Also the leds require a 5V input signal whereas the jetson-nano is only able to output a 3.3V signal, so even if you were able to create the pwm signal an additional logic converter would still be necessary.

# Compiling and Uploading

These sketches can all be compiled and uploaded remotely through the use of the [arduino-cli](https://github.com/arduino/arduino-cli) program. Each sketch needs to be in a separate folder with the file name matching the folder name, and you should copy the [compile-upload.sh](example/compile-upload.sh) script from the example folder - this script will be responsible for pushing the code to the arduino. To upload a sketch:

1. ssh into the jetson-nano with `ssh rifp@jetson-nano.local` and enter the password.
2. run the compile-upload script form the terminal for which ever sketch you want uploaded, ex. `./arduino/example/compile-upload.sh`
