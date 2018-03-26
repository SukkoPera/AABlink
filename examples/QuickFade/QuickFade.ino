#include <AAFade.h>

AAFadeShort aaLed;

void setup () {
	aaLed.begin (3, 50, 5);		// Change brightness by 5 every 50 ms
	aaLed.fade ();
}

void loop () {
	aaLed.loop ();
}
