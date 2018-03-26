#include <AABlink.h>
#include <AAFade.h>

AABlinkShort bLed;
AAFadeShort fLed;

// Must support PWM
const byte PIN = 3;

boolean blinking;

unsigned long lastModeChange = 0;

void setup () {
	bLed.begin (PIN, 500);			// Blink every half second
	fLed.begin (PIN, 35, 3);		// Change brightness by 5 every 35 ms

	// Start blinking
	blinking = false;
}

void loop () {
	if (lastModeChange == 0 || millis () - lastModeChange >= 5000) {
		if (blinking) {
			bLed.noBlink ();
			fLed.fade ();
			blinking = false;
		} else {
			fLed.noFade ();
			bLed.blink ();
			blinking = true;
		}

		lastModeChange = millis ();
	}

	bLed.loop ();
	fLed.loop ();
}
