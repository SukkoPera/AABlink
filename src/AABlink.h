template<typename INTERVAL_T>
class AABlink_T {
private:
	byte pin;
	unsigned long pmillis = 0;
	INTERVAL_T times[2];	// 0 -> On, 1 -> Off
	byte led_level = 0;
	unsigned long nextEventTime = 0;

public:
	void begin (byte _pin, INTERVAL_T _timeOn, INTERVAL_T _timeOff) {
	  pin = _pin;
	  times[0] = _timeOn;
	  times[1] = _timeOff;

	  pinMode (pin, OUTPUT);
	}

	void loop () {
	  if (millis () - pmillis >= nextEventTime) {
		nextEventTime = times[led_level];
		led_level = !led_level;
		digitalWrite (pin, led_level);
		pmillis = millis ();
	  }
	}
};

// This works for all intervals
typedef AABlink_T<unsigned long> AABlink;


/* If you don't need intervals longer than 65.535 seconds, this saves some
 * flash/RAM
 */
typedef AABlink_T<unsigned int> AABlinkShort;
