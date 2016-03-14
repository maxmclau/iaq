/***************************************************************************
 The MIT License (MIT)
 
 Copyright (c) 2016 Maxmillion McLaughlin <maxmclau.com>
 
 Permission is hereby granted, free of charge, to any person obtaining a copy
 of this software and associated documentation files (the "Software"), to deal
 in the Software without restriction, including without limitation the rights
 to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 copies of the Software, and to permit persons to whom the Software is
 furnished to do so, subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in all
 copies or substantial portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 SOFTWARE.
 ***************************************************************************/

/*
 * Redesigned by Christian Tamburilla for use in (MOA) @ BrunoAir
 * Code reduced to barebones
 */

#ifndef _IAQ_H_
#define _IAQ_H_

#include <Arduino.h>
#include <Wire.h>
//#include <Sensor.h>


class IAQ : //Sensor
{
	public:
	
		/*
		 * @brief Constructor
		 */
		IAQ(uint8_t i2CAddress, uint8_t sampleType);
		~IAQ();
	
		/*
		 * @brief Getters
		 */
		uint8_t getStatus();
		uint16_t getCO2();
		int32_t getResistance();
		uint16_t getTvoc();
	
	private:
		/*
		 * @brief Main Interface
		 */
		uint8_t _i2CAddress;
  
		/*
     * @brief Wire return values
     */
		uint16_t _cO2;
		uint32_t _resistance;
		uint16_t _tvoc;
		uint8_t _sampleType;
	
	
		/*
		 * @brief Default Reader
		 */
		void readAllBytes( void );
};




#endif // _IAQ_H_
