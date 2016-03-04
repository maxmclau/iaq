
#include <IAQ.h>

#define IAQADDRESS 0x5A

//Create an instance of the IAQ sensor (I2CAddress, SensorType)
IAQ sensor(IAQADDRESS, 0);

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  sensor.debug();
}
