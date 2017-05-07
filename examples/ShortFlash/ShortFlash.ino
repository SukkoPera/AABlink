#include <AABlink.h>

AABlinkShort aaLed;

void setup () {
	aaLed.begin (LED_BUILTIN, 10, 10000);		// Blink for 10 ms every 10 s
}

void loop () {
	aaLed.loop ();
}
