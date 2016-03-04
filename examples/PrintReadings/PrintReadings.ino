
#include <IAQ.h>

#define IAQ_ADDRESS 0x5A

//Create an instance of the IAQ sensor (I2CAddress, SampleType)
IAQ sensor(IAQ_ADDRESS, IAQ_SAMPLE_TYPE_CONTINUOUS);

void setup()
{
  Serial.begin(9600);
}

void loop()
{

  Serial.print("STATUS: ");
  Serial.println(sensor.getStatus());
  Serial.print("CO2: ");
  Serial.println(sensor.getCO2());
  Serial.print("RESISTANCE: ");
  Serial.println(sensor.getResistance());
  Serial.print("TVOC: ");
  Serial.println(sensor.getTvoc());
  Serial.println("");

  delay(2000);
}
