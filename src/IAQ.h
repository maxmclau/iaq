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


/**
 * Status Modes
 */
enum {
	IAQ_STATUS_TYPE_WARMING_UP,
	IAQ_STATUS_TYPE_READY,
	IAQ_STATUS_TYPE_BUSY,
	IAQ_STATUS_TYPE_ERROR,
	IAQ_STATUS_TYPE_NONE,
	IAQ_SAMPLE_TYPE_CONTINUOUS,
	IAQ_SAMPLE_TYPE_PULSED
};


class IAQ
{
	public:

		IAQ(uint8_t i2CAddress, uint8_t sampleType);
		~IAQ();
	
		/**
		 *  Getters
		 *
		 *  @return to pass variables information
		 */
		uint8_t getStatus();
		uint16_t getCO2();
		int32_t getResistance();
		uint16_t getTvoc();
	
	private:
		/**
		 *  Main Interface and mode settings
		 */
		uint8_t _i2CAddress;
	
	
		uint8_t _status;
		uint16_t _cO2;
		uint32_t _resistance;
		uint16_t _tvoc;
		uint8_t _sampleType;
	
	
		/**
		 *  Model Default Methods
		 */
		void readAllBytes( void );
};




#endif // _IAQ_H_
