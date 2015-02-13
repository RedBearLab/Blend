#include <Arduino.h>

int main(void)
{
	init();

#if defined(USBCON)
	USBDevice.attach();
#endif

	// As the F_CPU = 8000000UL, the USB core make the PLLCSR = 0x02
	// But the external xtal is 16000000Hz, so correct it here.
	PLLCSR |= 0x10;				// Need 16 MHz xtal
	while (!(PLLCSR & (1<<PLOCK)));		// wait for lock pll

	setup();

	for (;;) {
		loop();
		if (serialEventRun) serialEventRun();
	}

	return 0;
}

