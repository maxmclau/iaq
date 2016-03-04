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



struct SensorSettings
{
	/**
	 *  Main Interface and mode settings
	 */
	uint8_t i2CAddress;
	uint8_t sensorType;
	uint8_t chipSelectPin; //Undefined in .cpp
	
	uint8_t sampleType;
};


class IAQ : public Sensor
{
	public:
	
		IAQ( uint8_t passI2CAddress, uint8_t passSensorType);
		~IAQ();

		SensorSettings settings;
		
		void debug();
		
		/**
		 *  Getters
		 *
		 *  @return to pass variables information
		 */
		uint16_t getCO2();
		uint8_t getStatus();
		int32_t getResistance();
		uint16_t getTvoc();
		uint8_t getSampleType();
	
	private:
	
		/**
		 *  Model Default Methods
		 */
		void readAllBytes( void );
		void checkStatus( void );
};


enum class SampleType { CONTINUOUS, PULSED };


#endif // _IAQ_H_
