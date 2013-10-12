/* Digital Light sensor demo V1.0
* Connect the sensor to I2C port of Arduino to use.
*
* By:http://www.seeedstudio.com
*/
#include <Wire.h>
#include <Digital_Light_TSL2561.h>
void setup()
{
    Wire.begin(); 
    Serial.begin(9600);
    TSL2561.init(); 
}

void loop()
{   
    unsigned long  Lux;
    
    TSL2561.getLux();
 
    Serial.print("The Light value is: ");
    Serial.println(TSL2561.calculateLux(0,0,1));
    delay(1000);
}
