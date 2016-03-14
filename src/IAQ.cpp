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


#include <Arduino.h>
#include "IAQ.h"


IAQ::IAQ(uint8_t i2CAddress, uint8_t sampleType)
{
  _i2CAddress = i2CAddress;
  _sampleType = sampleType;
  
  Wire.begin();
}

IAQ::~IAQ() { }


void IAQ::readAllBytes()
{
  Wire.requestFrom(_i2CAddress, 9);
  
  _cO2 = (Wire.read()<< 8 | Wire.read());
  _status = Wire.read();
  _resistance = (Wire.read()& 0x00)| (Wire.read()<<16)| (Wire.read()<<8| Wire.read());
	_tvoc = (Wire.read()<<8 | Wire.read());
}


uint8_t IAQ::getStatus()
{
  readAllBytes();
  
  switch ((uint8_t)_status)
  {
    case 16:  //0x10
      return IAQ_STATUS_TYPE_WARMING_UP;
    case 0:   //0x00
      return IAQ_STATUS_TYPE_READY;
    case 1:   //0x01
      return IAQ_STATUS_TYPE_BUSY;
    case 128: //0x80
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


