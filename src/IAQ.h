//
//  IAQ.h
//  
//
//  Created by Christian Tamburilla for (MOA)
//
//

#ifndef _IAQ_H_
#define _IAQ_H_

#include <Arduino.h>
#include <Wire.h>
#include "Sensor.h"


//Constructor
struct SensorSettings
{
	//Main Interface and mode settings
	uint8_t I2CAddress;
	uint8_t chipSelectPin; //Undefined in .cpp
	uint8_t sampleType;
};


class IAQ : public Sensor
{
	public:
		IAQ();
		~IAQ();

		SensorSettings settings;
	
		void loop();
	
	private:
		
		void readAllBytes( void );
		void checkStatus( void );
	
};

enum class SampleType { CONTINUOUS, PULSED };


#endif // _IAQ_H_
