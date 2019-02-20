#include "thermistor-library.h"
int B=3975;                  //B value of the thermistor

Thermistor::Thermistor(int pin) {
	_pin = pin;
}


void Thermistor::begin(void) {
	pinMode(_pin, INPUT);
}


int Thermistor::getTempRaw(bool smooth) {
	delay(1);
	
	if(smooth==true) {
		int total = 0;
		
		for(int i=0; i<100; i++) {
			total += analogRead(_pin);
			delay(1);
		}
		
		_temp_raw = total/100;
	} else
		_temp_raw = analogRead(_pin);

	return _temp_raw;
}


float Thermistor::getTempC(bool smooth) {
	_temp_raw = getTempRaw(smooth);
	_resistance=(float)(1023-_temp_raw)*10000/_temp_raw; //get the resistance of the sensor;
    _temp_c=1/(log(_resistance/10000)/B+1/298.15)-273.15;//convert to temperature via datasheet&nbsp;;
	return _temp_c;
}


float Thermistor::getTempF(bool smooth) {
	_temp_c = getTempC(smooth);
	_temp_f = (_temp_c * 9.0)/ 5.0 + 32.0;
	return _temp_f;
}


float Thermistor::getTemp(bool smooth) {
	return getTempC(smooth);
}
