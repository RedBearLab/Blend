/*

Copyright (c) 2012-2014 RedBearLab

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

*/

#include <Arduino.h>

void blend_init()
{
#if defined(BLEND_MICRO_8MHZ)
    // As the F_CPU = 8000000UL, the USB core make the PLLCSR = 0x02
    // But the external xtal is 16000000Hz, so correct it here.
    PLLCSR |= 0x10;                     // Need 16 MHz xtal
    while (!(PLLCSR & (1<<PLOCK)));		// wait for lock pll
#elif defined(BLEND_MICRO_16MHZ)
    // The CPU clock in bootloader is 8MHz, change to 16MHz for sketches to run (overclock if running at 3.3v).
    CLKPR = 0x80;
    CLKPR = 0;
#endif
}
