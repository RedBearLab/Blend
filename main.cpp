#include <Arduino.h>

int main(void)
{
	init();

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

