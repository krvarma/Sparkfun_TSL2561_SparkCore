Spark Core, [Sparkfun TSL2561][1] and PushingBox
----------------------------------------

----------
This is beginner level sample application to retrive sensor value from Sparkfun TSL2561. The TSL2561 is light sensor which outputs illumination in lux. This sample application retrieve the illumination value and if it is less than a particular value then send push notification using PushingBox. The lower limit is configurable using a Spark Function. 

This sample uses TSL256 code from [TSL2561 hookup guide from Sparkfun][2], PushingBox code from [this link][3] and [@bko's Web Page][4].

###Wiring###
 1. TSL2561 Vcc to 3.3V
 2. TSL2561 GND to GND 
 3. TSL2561 SCL to D1
 4. TSL2561 SDA to D0

###How to run the application###
Load the sample application into the Spark Core. Open the Web Page in an editor and replace the tokens *deviceid* and *access token* with actual values. Open the web page in a browser and press ***Connect*** Button.
  
![Wiring][5]


  [1]: https://www.sparkfun.com/products/12055
  [2]: https://learn.sparkfun.com/tutorials/tsl2561-luminosity-sensor-hookup-guide
  [3]: https://github.com/Clement87/PushingBox-for-Spark-Core
  [4]: https://community.spark.io/t/tutorial-getting-started-with-spark-publish/3422
  [5]: https://raw.githubusercontent.com/krvarma/Sparkfun_TSL2561_SparkCore/master/IMG_0052.JPG