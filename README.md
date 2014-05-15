Spark Core, Sparkfun TSL2561 and PushingBox
----------------------------------------

----------
This is beginer level sample application to retrive sensor value from Sparkfun TSL2561. The TSL2561 is light sensor which outputs illimination in lux. This sample application retrieve the illumination value and if it is less than a particular value then send push notification using PushingBox. The lower limit is configuration using a Spark Function. 

This sample uses TSL256 code from [TSL2561 hookup guide from Sparkfun][1], PushingBox code from [this link][2] and [@bko's Web Page][3].

###Connection###
 1. TSL2561 Vcc to 3.3V
 2. TSL2561 GND to GND 
 3. TSL2561 SCL to D1
 4. TSL2561 SDA to D0

  [1]: https://learn.sparkfun.com/tutorials/tsl2561-luminosity-sensor-hookup-guide
  [2]: https://github.com/Clement87/PushingBox-for-Spark-Core
  [3]: https://community.spark.io/t/tutorial-getting-started-with-spark-publish/3422