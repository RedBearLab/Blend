/*
  main.cpp - Main loop for Arduino sketches
  Copyright (c) 2005-2013 Arduino Team.  All right reserved.

  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/

#include <Arduino.h>

//Declared weak in Arduino.h to allow user redefinitions.
int atexit(void (*func)()) { return 0; }

// Weak empty variant initialization function.
// May be redefined by variant files.
void initVariant() __attribute__((weak));
void initVariant() { }

int main(void)
{
	init();

	initVariant();

#if defined(USBCON)
	USBDevice.attach();
#endif
	
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
	
	setup();
    
	for (;;) {
		loop();
		if (serialEventRun) serialEventRun();
	}
        
	return 0;
}


