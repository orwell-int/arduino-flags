[![Build Status](https://travis-ci.org/orwell-int/arduino-flags.svg?branch=master)](https://travis-ci.org/orwell-int/arduino-flags) [![Stories in Ready](https://badge.waffle.io/orwell-int/arduino-flags.png?label=ready&title=Ready)](https://waffle.io/orwell-int/arduino-flags) [![Coverage Status](https://coveralls.io/repos/orwell-int/arduino-flags/badge.svg?branch=master)](https://coveralls.io/r/orwell-int/arduino-flags?branch=master)

arduino-flags
=============

This is the code running on the Arduino Uno in the ORWELL project to handle the RGB flags.

Hardware prerequisites
----------------------

Connect 24 WS2812b RGB leds in chain on digital pin 2.
Protect the digital pin with a 220 - 470 Ohms resistor (between the pin and the first led).
Connect an Arduino Uno to a computer/server-flag through a serial port.

Checkout the code
-----------------
Get the sources
```
git clone git@github.com:orwell-int/arduino-flags.git
```

Make it run
-----------
Compile and upload the code on your Arduino (using Sketch for instance).

Discover the serial address of your Arduino: plug it on your machine by serial, run 
```
ls /dev/tty*
```
to find it address.

Send serial data on the arduino from your server, by using RGB int values (0 to 255) separated by
a comma and ending with a new line.

Example in Python:
```
>>> import serial
>>> ser = serial.Serial('/dev/ttyACM0')
>>> ser.write("255,0,0\n")
```
