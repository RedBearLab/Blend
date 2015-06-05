Blend
=====

An Arduino compatible development board with BLE support (Atmega32u4 + nRF8001).

This add-on package is to add support to the Arduino IDE (tested on v1.6.0) for this board.

* Tested and support Arduino IDE version 1.6.4.


Installation
============

Step 1 - Install the Blend boards to Arduino IDE:

Install using Arduino IDE (version 1.6.4) Boards Manager, follow this document:

https://github.com/RedBearLab/Blend/blob/master/Docs/BoardsManager.pdf

Step 2 - Install BLE libraries:

Install using Arduino IDE (version 1.6.4) Library Manager, follow this document:

https://github.com/RedBearLab/Blend/blob/master/Docs/LibraryManager.pdf

The Blend Micro board can be used as a standalone Arduino board without BLE. If you use BLE function, you need to use two libraries.

1: Get and install [Nordic nRF8001 SDK for Arduino](https://github.com/cheong2k/ble-sdk-arduino)

It provides a lot of BLE examples/tutorials includes how to create your own services and characteristics.

2: Get and install [RBL nRF8001 Library](https://github.com/RedBearLab/nRF8001)

* This library requires Nordic’s to work and provides a simple service and some APIs for easy to use with RBL examples and App. It is easy to use if you just want to exchange data between the board and iPhone or other BLE Central devices.

*** For Linux (e.g. Ubuntu 14.04) users: ModemManager will try to use the Blend Micro as a modem and this causes the upload process fail using Arduino IDE. To allow Arduino IDE to upload correctly, you need to fix it by modify the UDEV rule, write a simple UDEV rule to ignore it from being handled by modem manager.

In "/etc/udev/rules.d/77-mm-usb-device-blacklist.rules", simply add this single line:

ATTR{idVendor}=="03eb",  ENV{ID_MM_DEVICE_IGNORE}="1"

3: Another very useful library you can use which allows to define services and characteristics in code without using Nordic's nRFgo Studio. 

https://github.com/sandeepmistry/arduino-BLEPeripheral


Driver
======

The board contains an USB port, which allows you to load compiled sketches on to the board, the USB will act as a USB CDC (virtual COM) port and it requires driver to work.

Download the signed driver (RBL_Windows_Driver_Installer.zip) for Windows (includes up to Windows 8 PC)<br/>

Installation

Do not connect the Blend board to any USB port before the device driver is installed. To install, unzip the file, run the .exe and follow the instructions. After that, connect your Blend board to one of USB ports.

For Mac OSX and Linux, no driver is required.

Fritzing
========

Blend Micro

[Fritzing file for the Blend Micro](https://github.com/makenai/FritzingParts)


Credits
=======

1. [@sandeepmistry](https://github.com/sandeepmistry) provides another useful library for the Blend boards.
2. [@makenai](https://github.com/makenai) made a [Fritzing file for the Blend Micro](https://github.com/makenai/FritzingParts).


Troubleshooting
===============

Recovery Procedure for Blend Micro sketch upload failing

1. Open the Blink sketch

2. Reset the board, it will enter to bootloader mode for 8 seconds (the LED - L will be flashing).

3. During this 8-second period, select the COM port of the board in the Arduino IDE (Menu -> Tools -> Serial Port)

4. Press "Compile and Upload" and then press the reset button on the board again, it should be able to load the sketch and fix the issue.


Potential reasons for sketch upload failure

1. Fail to upload a complete sketch last time. (e.g. uploading and suddenly removing power source, then the board's USB will not work since the firmware inside the board is invalid)


Resources
=========

1. [Blend Micro Forum](https://redbearlab.zendesk.com/forums/23046987-Blend-Micro)

2. [Nordic nRF8001 SDK for Arduino - Library](https://github.com/cheong2k/ble-sdk-arduino)

3. [Nordic nRF8001 SDK for Arduino - Forum](https://redbearlab.zendesk.com/forums/21921933-Nordic-nRF8001-SDK-for-Arduino)

4. [RBL nRF8001 Library](https://github.com/RedBearLab/nRF8001)

5. [Nordic Developer Zone](https://devzone.nordicsemi.com/)

6. [Bluetooth SIG](https://www.bluetooth.org/en-us)

7. Thanks [@makenai](https://github.com/makenai), made a [Fritzing file for the Blend Micro](https://github.com/makenai/FritzingParts).


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
