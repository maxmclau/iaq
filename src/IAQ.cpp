//
//  IAQ.cpp
//
//
//  Created by Christian Tamburilla for (MOA)
//
//

#include <Arduino.h>
#include "IAQ.h"


IAQ::IAQ(uint8_t i2CAddress, uint8_t sampleType)
{
  _i2CAddress = i2CAddress;
  _sampleType = sampleType;
  
  Wire.begin();
}

IAQ::~IAQ(void) { }


void IAQ::readAllBytes()
{
  Wire.requestFrom(_i2CAddress, 9);
  
  _status = Wire.read();
	_cO2 = (Wire.read()<< 8 | Wire.read());
	_resistance = (Wire.read()& 0x00)| (Wire.read()<<16)| (Wire.read()<<8| Wire.read());
	_tvoc = (Wire.read()<<8 | Wire.read());
}


uint8_t IAQ::getStatus()
{
  readAllBytes();
  
  switch (_status)
  {
    
    case 0x10:
      return IAQ_STATUS_TYPE_WARMING_UP;
    case 0x00:
      return IAQ_STATUS_TYPE_READY;
    case 0x01:
      return IAQ_STATUS_TYPE_BUSY;
    case 0x80:
      return IAQ_STATUS_TYPE_ERROR;
    default:
      return IAQ_STATUS_TYPE_NONE;
  }
}

uint16_t IAQ::getCO2()
{
  readAllBytes();
  return _cO2;
}

int32_t IAQ::getResistance()
{
  readAllBytes();
  return _resistance;
}

uint16_t IAQ::getTvoc()
{
  readAllBytes();
  return _tvoc;
}





//
/*
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
 //Serial.print("STATUS: ");
 //Serial.println(getStatus());
 Serial.print("RESISTANCE: ");
 Serial.println(getResistance());
 Serial.print("TVOC: ");
 Serial.println(getTvoc());
 Serial.print("SAMPLE-TYPE: ");
 Serial.println(getSampleType());
 Serial.println("");
 
 
 }
 */


