//
//  IAQ.cpp
//
//
//  Created by Christian Tamburilla for (MOA)
//
//

#include <Arduino.h>
#include "IAQ.h"

uint16_t predict;
uint8_t statu;
int32_t resistance;
uint16_t tvoc;


IAQ::IAQ(uint8_t passI2CAddress,uint8_t passSensorType)
{
  settings.i2CAddress = passI2CAddress;
  settings.sampleType = (uint8_t)SampleType::CONTINUOUS; //Consider alternative to forced cast?
  
  Wire.begin();
  
}

IAQ::~IAQ(void) { }


void IAQ::readAllBytes()
{
  Wire.requestFrom(settings.i2CAddress, 9);
  
  statu = Wire.read();
	predict = (Wire.read()<< 8 | Wire.read());
	resistance = (Wire.read()& 0x00)| (Wire.read()<<16)| (Wire.read()<<8| Wire.read());
	tvoc = (Wire.read()<<8 | Wire.read());
}


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


void IAQ::debug()
{
  checkStatus();
  
  Serial.print("CO2: ");
  Serial.println(getCO2());
  Serial.print("STATUS: ");
  Serial.println(getStatus());
  Serial.print("RESISTANCE: ");
  Serial.println(getResistance());
  Serial.print("TVOC: ");
  Serial.println(getTvoc());
  Serial.print("SAMPLE-TYPE: ");
  Serial.println(getSampleType());
  Serial.println("");
  
  delay(2000);
    
}


uint16_t IAQ::getCO2()
{
  readAllBytes();
  return predict;
}

uint8_t IAQ::getStatus()
{
  readAllBytes();
  return statu, HEX;
}

int32_t IAQ::getResistance()
{
  readAllBytes();
  return resistance;
}

uint16_t IAQ::getTvoc()
{
  readAllBytes();
  return tvoc;
}

uint8_t IAQ::getSampleType()
{
  return settings.sampleType;
}






