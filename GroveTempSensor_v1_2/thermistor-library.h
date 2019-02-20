#include <math.h>
#include "Arduino.h"

class Thermistor {
	private:
		int _pin;
	    float _resistance;
		int _temp_raw;
		float _temp_c;
		float _temp_f;

	public:
		Thermistor(int pin);
		void begin(void);
		float getTemp(bool smooth=false);
		float getTempF(bool smooth=false);
		float getTempC(bool smooth=false);
		int getTempRaw(bool smooth=false);
};
