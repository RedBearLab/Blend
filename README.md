Blend
=====

An Arduino compatible development board with BLE support (Atmega32u4 + nRF8001).

This add-on package is to add support to the Arduino IDE (v1.0.5) for this board.

Installation
============

Step 1:

Copy the “Arduino\hardware" folder to your sketchbook folder.

The sketchbook folder is your "Documents\Arduino” folder.

Mac OSX:<br/>
Documents > Arduino

Windows:<br/>
C: > Users > YourName > Documents > Arduino

Step 2:

Locate “main.cpp” in your Arduino IDE, and replace it with the one provided in this repository.

Mac OSX:<br/>
Right click your Arduino IDE, click “Show Package Contents”, the “main.cpp” in<br/>
Contents > Resources > Java > hardware > arduino > cores > arduino > main.cpp

Windows:<br/>
Arduino IDE > hardware > arduino > cores > arduino > main.cpp

Or modify it yourself with the following code before setup():

```
#if defined(BLEND_MICRO_8MHZ)
	// As the F_CPU = 8000000UL, the USB core make the PLLCSR = 0x02
	// But the external xtal is 16000000Hz, so correct it here.
	PLLCSR |= 0x10;				// Need 16 MHz xtal
	while (!(PLLCSR & (1<<PLOCK)));		// wait for lock pll
#elif defined(BLEND_MICRO_16MHZ)
	// The CPU clock in bootloader is 8MHz, change to 16MHz for sketches to run (i.e. overclock running at 3.3v).
	CLKPR = 0x80;
	CLKPR = 0;
#endif
```

This code is to set the USB and CPU clock as it is running at 8 MHz with 3.3v but the external crystal is 16 MHz, so need to adjust the USB to run correctly.


How to Use
==========

The Blend Micro board can be used as a standalone Arduino board without BLE. If you use BLE function, you need to use two libraries.

1. Nordic nRF8001 SDK for Arduino
https://github.com/NordicSemiconductor/ble-sdk-arduino

It provides a lot of BLE examples/tutorials includes how to create your own services and characteristics.

2. RBL nRF8001 Library (added some simple APIs)
https://github.com/RedBearLab/nRF8001

It requires Nordic’s to work and provides a simple service and some APIs for easy to use with RBL examples and App. It is easy to use if you just want to exchange data between the board and iPhone or other BLE Central devices.


License
=======

Copyright (c) 2014 RedBearLab

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal 
in the Software without restriction, including without limitation the rights 
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER 
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
