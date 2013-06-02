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
    // int CH0_LOW,CH0_HIGH,CH1_LOW,CH1_HIGH;
    // int Channal0,Channal1;
    unsigned long  Lux;
    //read two bytes from registers 0x0C and 0x0D
    //  CH0_LOW=TSL2561.readRegister(TSL2561_ADDRESS,TSL2561_CHANNAL0L);
    //  CH0_HIGH=TSL2561.readRegister(TSL2561_ADDRESS,TSL2561_CHANNAL0H);
    //  CH1_LOW=TSL2561.readRegister(TSL2561_ADDRESS,TSL2561_CHANNAL1L);
    //  CH1_HIGH=TSL2561.readRegister(TSL2561_ADDRESS,TSL2561_CHANNAL1H);
    //  
    //  Channal0=CH0_HIGH*256+CH0_LOW;
    //  Channal1=CH1_HIGH*256+CH1_LOW;
    //    
    //  Serial.print("Channal0:");
    //  Serial.println( Channal0);
    //  Serial.print( "Channal1:");
    //  Serial.println( Channal1);
    TSL2561.getLux();
  //  Lux=TSL2561.calculateLux(0,0,1);
    
    Serial.print("The Light value is: ");
    Serial.println(TSL2561.calculateLux(0,0,1));
    delay(1000);
}
