#include <Arduino.h>

int main(void)
{
	init();

#if defined(USBCON)
	USBDevice.attach();
#endif

	// The CPU clock in bootloader is 8MHz, change to 16MHz for sketches to run (i.e. overclock running at 3.3v).
	CLKPR = 0x80;
	CLKPR = 0;

	setup();

	for (;;) {
		loop();
		if (serialEventRun) serialEventRun();
	}

	return 0;
}

