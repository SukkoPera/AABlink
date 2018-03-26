template<typename INTERVAL_T>
class AAFade_T {
private:
	byte pin;
	unsigned long pmillis = 0;
	INTERVAL_T time;
	int led_level = 0;
	int increment = 10;
	unsigned long nextEventTime = 0;
	bool running = false;

public:
	void begin (byte _pin, INTERVAL_T _fadeTime, int _increment = 10) {
	  pin = _pin;
	  time = _fadeTime;
	  increment = _increment;
	  analogWrite (pin, 0);
	}

	void fade () {
		led_level = 0;
		nextEventTime = 0;		// Might not be necessary
		running = true;
	}

	void noFade () {
		analogWrite (pin, 0);	// Make sure led is off
		running = false;
	}

	void loop () {
	  if (running && millis () - pmillis >= time) {
		led_level += increment;
		if (led_level >= 255) {
			increment *= -1;
			led_level = 255;
		} else if (led_level <= 0) {
			increment *= -1;
			led_level = 0;
		}
		analogWrite (pin, led_level);
		pmillis = millis ();
	  }
	}
};

// This works for all intervals
typedef AAFade_T<unsigned long> AAFade;


/* If you don't need intervals longer than 65.535 seconds, this saves some
 * flash/RAM
 */
typedef AAFade_T<unsigned int> AAFadeShort;
