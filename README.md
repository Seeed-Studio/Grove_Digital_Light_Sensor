Grove - Digital Light Sensor
---------------------------------------------------------
[![Grove - Digital Light Sensor](http://www.seeedstudio.com/depot/images/product/Digital%20Light%20Sensor.jpg)](http://www.seeedstudio.com/depot/grove-digital-light-sensor-p-1281.html?cPath=25_27)

This module is based on the I2C light-to-digital converter TSL2561 to transform light intensity to a digital signal. Different from traditional analog light sensor, as [Grove - Light Sensor](http://www.seeedstudio.com/depot/grove-light-sensorp-p-1253.html?cPath=144_148), this digital module features a selectable light spectrum range due to its dual light sensitive diodes: infrared and full spectrum. 
 
You can switch between three detection modes to take your readings. They are infrared mode, full spectrum and human visible mode. When running under the human visible mode, this sensor will give you readings just close to your eye feelings.


# Usage:

This is an Arduino Library of Grove - Digital Light Sensor.

### Initialization:

    TSL2561.init(); 

### Get Data

    unsigned long calculateLux(unsigned int iGain, unsigned int tInt,int iType);


<br>
For more information, please refer to [wiki page](http://www.seeedstudio.com/wiki/Grove_-_Digital_Light_Sensor).

    
----


This software is written by loovee [luweicong@seeedstudio.com](luweicong@seeedstudio.com "luweicong@seeedstudio.com") for seeed studio<br>
and is licensed under [The MIT License](http://opensource.org/licenses/mit-license.php). Check License.txt for more information.<br>

Contributing to this software is warmly welcomed. You can do this basically by<br>
[forking](https://help.github.com/articles/fork-a-repo), committing modifications and then [pulling requests](https://help.github.com/articles/using-pull-requests) (follow the links above<br>
for operating guide). Adding change log and your contact into file header is encouraged.<br>
Thanks for your contribution.

Seeed Studio is an open hardware facilitation company based in Shenzhen, China. <br>
Benefiting from local manufacture power and convenient global logistic system, <br>
we integrate resources to serve new era of innovation. Seeed also works with <br>
global distributors and partners to push open hardware movement.<br>




[![Analytics](https://ga-beacon.appspot.com/UA-46589105-3/Grove_Digital_Light_Sensor)](https://github.com/igrigorik/ga-beacon)


