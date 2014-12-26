Blend
=====

An Arduino compatible development board with BLE support (Atmega32u4 + nRF8001).

This add-on package is to add support to the Arduino IDE (tested on v1.0.5) for this board.

Note that we do not support v1.5.x as it is still in beta.


Installation
============

Step 1:

Copy the “Arduino\hardware" folder to your sketchbook folder. The sketchbook folder is your "Documents\Arduino” folder.

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

An option to play without using the add-on:

Use it as Arduino Micro at 16 MHz (it is so called "overclock", since it is running at 3.3V), the bootloader still requires our driver to work, see Driver session (Windows platform only).

Modify your sketch with the following code in setup():

```
void setup()
{
    // Set to 16 MHz as external crystal.
    CLKPR = 0x80;
    CLKPR = 0;

    // Since default pins set to 9 and 8 for REQN and RDYN to nRF8001 for Arduino Micro
    // But the Blend Micro is using 6 and 7, so change the pins here. 
    ble_set_pins(6, 7);

    // other setup code here.
}
```

Step 3:

The Blend Micro board can be used as a standalone Arduino board without BLE. If you use BLE function, you need to use two libraries.

1: Get Nordic nRF8001 SDK for Arduino<br/>
https://github.com/NordicSemiconductor/ble-sdk-arduino

It provides a lot of BLE examples/tutorials includes how to create your own services and characteristics.

2: Get RBL nRF8001 Library (added some simple APIs)<br/>
https://github.com/RedBearLab/nRF8001

It requires Nordic’s to work and provides a simple service and some APIs for easy to use with RBL examples and App. It is easy to use if you just want to exchange data between the board and iPhone or other BLE Central devices.


*** It is similar to install on Linux.
*** For Linux (e.g. Ubuntu 14.04) users: if you found you cannot upload sketches, you have to remove ModemManager

sudo apt-get remove ModemManager


Driver
======

The board contains an USB port, which allows you to load compiled sketches on to the board, the USB will act as a USB CDC (virtual COM) port and it requires driver to work.

Download the signed driver (RBL_Windows_Driver_Installer.zip) for Windows (includes up to Windows 8 PC)<br/>

Installation

Do not connect the Blend board to any USB port before the device driver is installed. To install, unzip the file, run the .exe and follow the instructions. After that, connect your Blend board to one of USB ports.

For Mac OSX and Linux, no driver is required.

For Linux (e.g. Ubuntu), ModemManager will try to use the Blend Micro as a modem and this causes the upload process fail using Arduino IDE. To allow Arduino IDE to upload correctly, you need to fix it by modify the UDEV rule, write a simple UDEV rule to ignore it from being handled by modem manager.

In "/etc/udev/rules.d/77-mm-usb-device-blacklist.rules", simply add this single line:

ATTR{idVendor}=="03eb",  ENV{ID_MM_DEVICE_IGNORE}="1"


Troubleshooting
===============


There are two possible causes of not able to upload sketches to your Blend Micro

1. You may have forgotten to change/modify the main.cpp file.

2. Fail to upload a complete sketch last time. (e.g. uploading and suddenly removing power source, then the board's USB will not work since the firmware inside the board is invalid)

Recovery Procedure

1. Modify the main.cpp as mentioned in the "Arduino IDE Setup" session shown above.

2. Open the Blink sketch

3. Reset the board, it will enter to bootloader mode for 8 seconds (the LED - L will be flashing).

4. During this 8-second period, select the COM port of the board in the Arduino IDE (Menu -> Tools -> Serial Port)

5. Press "Compile and Upload" and then press the reset button on the board again, it should be able to load the sketch and fix the issue.


Resources
=========

1. [Blend Micro Forum](https://redbearlab.zendesk.com/forums/23046987-Blend-Micro)

2. [Nordic nRF8001 SDK for Arduino - Library](https://github.com/NordicSemiconductor/ble-sdk-arduino)

3. [Nordic nRF8001 SDK for Arduino - Forum](https://redbearlab.zendesk.com/forums/21921933-Nordic-nRF8001-SDK-for-Arduino)

4. [RBL nRF8001 Library](https://github.com/RedBearLab/nRF8001)

5. [Nordic Developer Zone](https://devzone.nordicsemi.com/)

6. [Bluetooth SIG](https://www.bluetooth.org/en-us)


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
