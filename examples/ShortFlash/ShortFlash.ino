#include <AABlink.h>

AABlink aaLed;

void setup () {
	aaLed.begin (LED_BUILTIN, 15, 1000);
}

void loop () {
	aaLed.loop ();
}
