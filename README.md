Grove - Digital Light Sensor
---------------------------------------------------------

Version 1

[![Grove - Digital Light Sensor](https://raw.githubusercontent.com/SeeedDocument/Grove-Digital_Light_Sensor/master/img/Digital_Light_Sensor.jpg)](http://www.seeedstudio.com/depot/grove-digital-light-sensor-p-1281.html?cPath=25_27)


This module is based on the I2C light-to-digital converter TSL2561 to transform light intensity to a digital signal. Different from traditional analog light sensor, as [Grove - Light Sensor](http://www.seeedstudio.com/depot/grove-light-sensorp-p-1253.html?cPath=144_148), this digital module features a selectable light spectrum range due to its dual light sensitive diodes: infrared and full spectrum. 
 
You can switch between three detection modes to take your readings. They are infrared mode, full spectrum and human visible mode. When running under the human visible mode, this sensor will give you readings just close to your eye feelings.

Version 2 (Fixme when we have a bazaar image)

[![Grove - Digital Light Sensor v2](https://raw.githubusercontent.com/SeeedDocument/Grove-Digital_Light_Sensor/master/img/Digital_Light_Sensor.jpg)](http://www.seeedstudio.com/depot/grove-digital-light-sensor-p-1281.html?cPath=25_27)


# Usage:

This is an Arduino Library of Grove - Digital Light Sensor (two versions).

### Include the corresponding header file

Version 1:

    #include <Digital_Light_TSL2561.h>

Version 2:

    #include <Digital_Light_ISL29035.h>

### Initialization:

    //for v1
    TSL2561.init();
    //for v2
    ISL29035.init();

### Get the Lux reading of visible light

    unsigned long readVisibleLux();


<br>
For more information, please refer to [wiki page](http://www.seeedstudio.com/wiki/Grove_-_Digital_Light_Sensor).

    
----


This software is written by zhangkun for seeed studio and is licensed under [The MIT License](http://opensource.org/licenses/mit-license.php). Check License.txt for more information.<br>

Contributing to this software is warmly welcomed. You can do this basically by<br>
[forking](https://help.github.com/articles/fork-a-repo), committing modifications and then [pulling requests](https://help.github.com/articles/using-pull-requests) (follow the links above<br>
for operating guide). Adding change log and your contact into file header is encouraged.<br>
Thanks for your contribution.

Seeed is a hardware innovation platform for makers to grow inspirations into differentiating products. By working closely with technology providers of all scale, Seeed provides accessible technologies with quality, speed and supply chain knowledge. When prototypes are ready to iterate, Seeed helps productize 1 to 1,000 pcs using in-house engineering, supply chain management and agile manufacture forces. Seeed also team up with incubators, Chinese tech ecosystem, investors and distribution channels to portal Maker startups beyond.


[![Analytics](https://ga-beacon.appspot.com/UA-46589105-3/Grove_Digital_Light_Sensor)](https://github.com/igrigorik/ga-beacon)


