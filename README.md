# Indoor Air Quality (IAQ)

...

#### Install
```Shell
$ cd ~/Documents/Arduino/libraries
$ git clone https://github.com/moa/IAQ.git
```

#### Usage

```Arduino

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
```

#### License

**`Apache 2.0`**

