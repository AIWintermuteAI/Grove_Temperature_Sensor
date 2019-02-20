#include "thermistor-library.h"

// Analog pin the thermistor is connected to
int thermPin = A0;

// Configure the Thermistor class
Thermistor Thermistor(thermPin);


void setup() {
	// Start Serial output
	Serial.begin(9600);

	// Initialize the Thermistor class
	Thermistor.begin();
}


void loop() {

	// Print temperature in degrees Celsius
	Serial.print("Celsius: ");
	Serial.println(Thermistor.getTempC());
	

	// Wait 1 second
	delay(1000);
}
