/*

Copyright (c) 2012, 2013 RedBearLab

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

*/

#ifndef  _BLEND_H
#define _BLEND_H

#include <boards.h>
#include <lib_aci.h>
#include <aci_setup.h>
#include <SPI.h>

#include <avr/sleep.h>
#include <avr/interrupt.h>

/* Put the nRF8001 setup in the RAM of the nRF8001.*/
#include "services.h"
/* Include the services_lock.h to put the setup in the OTP memory of the nRF8001.
This would mean that the setup cannot be changed once put in.
However this removes the need to do the setup of the nRF8001 on every reset.*/

#if defined(BLEND_MICRO)
#define DEFAULT_REQN    6
#define DEFAULT_RDYN    7
#else
#define DEFAULT_REQN    9
#define DEFAULT_RDYN    8
#endif

void blend_begin();
void blend_set_name(char *name);
void blend_write(unsigned char data);
void blend_write_bytes(unsigned char *data, unsigned char len);
void blend_do_events();
int blend_read();
unsigned char blend_available();
unsigned char blend_connected(void);
void blend_set_pins(uint8_t reqn, uint8_t rdyn);
unsigned char blend_busy();

#endif

