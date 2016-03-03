//
//  IAQ.cpp
//
//
//  Created by Christian Tamburilla for (MOA)
//
//

#include <Arduino.h>
#include "IAQ.h"

#define IAQADDRESS 0x5A

//readAllBytes global variables for use in loop()
uint16_t predict;
uint8_t statu;
int32_t resistance;
uint16_t tvoc;

//Constructor
IAQ::IAQ( void )
{
  settings.I2CAddress = IAQADDRESS;
  settings.sampleType = (uint8_t)SampleType::CONTINUOUS; //Consider alternative to forced cast?
  
  Wire.begin();
  
}

//Deconstructor
IAQ::~IAQ( void ) { }


//Temporary method for sensor model-specific functionality
void IAQ::loop()
{
	readAllBytes();
	checkStatus();
	
	Serial.print("CO2:");
	Serial.print(predict);
	Serial.print(", Status:");
	Serial.print(statu, HEX);
	Serial.print(", Resistance:");
	Serial.print(resistance);
	Serial.print(", TVoC:");
	Serial.print(tvoc);
  Serial.print(", Sample Type: ");
  Serial.println(settings.sampleType);
	
	delay(2000);
	
}

////////////////////////////////////////////////////////////////////////
void IAQ::readAllBytes()
{
	Wire.requestFrom(IAQADDRESS, 9);
	
	predict = (Wire.read()<< 8 | Wire.read());
	statu = Wire.read();
	resistance = (Wire.read()& 0x00)| (Wire.read()<<16)| (Wire.read()<<8| Wire.read());
	tvoc = (Wire.read()<<8 | Wire.read());
}

////////////////////////////////////////////////////////////////////////
void IAQ::checkStatus()
{
	if(statu == 0x10)
	{
		Serial.println("Warming up...");
	}
	else if(statu == 0x00)
	{
		Serial.println("Ready");
	}
	else if(statu == 0x01)
	{
		Serial.println("Busy");
	}
	else if(statu == 0x80)
	{
		Serial.println("Error");
	}
	else
  Serial.println("No Status, check module");
}

