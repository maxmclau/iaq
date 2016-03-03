
#include <IAQ.h>

//Create an instance of the IAQ sensor
IAQ sensor;

void setup()
{
  Serial.begin(9600);
  
  //Call the class
  sensor;
}

void loop()
{
  sensor.loop();
}
