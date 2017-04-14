class AABlink {
private:
	byte pin;
	unsigned long pmillis;
	unsigned long timeOn;  // time LED ON
	unsigned long timeOff;  // time LED OFF

	int led_level = LOW;
	unsigned long nextEventTime = 0;

public:
	void begin (byte _pin, unsigned long _timeOn, unsigned long _timeOff) {
	  pin = _pin;
	  timeOn = _timeOn;
	  timeOff = _timeOff;
	  pmillis = 0;

	  pinMode (pin, OUTPUT);
	}

	void loop () {
	  if (millis() - pmillis >= nextEventTime) {
		pmillis = millis ();

		if (led_level) {
		  nextEventTime = timeOff;
		} else {
		  nextEventTime = timeOn;
		}
		led_level = !led_level;

		digitalWrite (pin, led_level);
	  }
	}
};
