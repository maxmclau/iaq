# Sensor

Common sensor library used by all Moa projects

#### Install
```Shell
$ cd ~/Documents/Arduino/libraries
$ git clone https://github.com/moa/sensor-lib.git
```

#### Usage

```Arduino
Adafruit_TSL2561 tsl = Adafruit_TSL2561(TSL2561_ADDR_FLOAT, 12345);
...
/* Get a new sensor event */ 
sensors_event_t event;
tsl.getEvent(&event);

/* Display the results (light is measured in lux) */
if (event.light)
{
	Serial.print(event.light); Serial.println(" lux");
}
else
{
	/* If event.light = 0 lux the sensor is probably saturated
	and no reliable data could be generated! */
	Serial.println("Sensor overload");
}
```

#### License

**`Apache 2.0`**
