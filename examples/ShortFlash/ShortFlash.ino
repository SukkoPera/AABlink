#include <AABlink.h>

AABlinkShort aaLed;

void setup () {
	aaLed.begin (LED_BUILTIN, 10, 60000);		// Blink for 10 ms every minute
}

void loop () {
	aaLed.loop ();
}
