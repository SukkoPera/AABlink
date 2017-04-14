#include <AABlink.h>

AABlinkShort aaLed;

void setup () {
	aaLed.begin (LED_BUILTIN, 15, 60000);
}

void loop () {
	aaLed.loop ();
}
