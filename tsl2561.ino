 x// This #include statement was automatically added by the Spark IDE.
#include "SFE_TSL2561.h"

const char serverName[] = "api.pushingbox.com";

SFE_TSL2561 tsl = SFE_TSL2561();
unsigned char id;
boolean gain;     // Gain setting, 0 = X1, 1 = X16;
unsigned int ms;  // Integration ("shutter") time in milliseconds
unsigned int data1;
unsigned int data2;
char szInfo[128];

int lowerLimit = 20;
boolean isSendPush = false;

int setLowerLimit(String args){
    lowerLimit = args.toInt();
    
    return lowerLimit;
}

void setup() {
    Serial.begin(9600);
    tsl.begin();
    
    tsl.getID(id);
    tsl.setTiming(0, 2, ms);
    tsl.setPowerUp();
    
    Spark.function("setLightLowerLimit", setLowerLimit);
}

void loop() {
    tsl.getData(data1, data2);
    
    double lux;
    boolean good = tsl.getLux(gain,ms,data1,data2,lux);
    
    sprintf(szInfo, "Sensor ID: %X, Lux: %2.2f (%s)", id, lux, (good ? "good" : "bad"));
    
    Spark.publish("lightinfo", szInfo);
    
    if(lux < lowerLimit){
        if(!isSendPush){
			// Replace with your device id.
            sendToPushingBox("<<deviceid>>", (int)lux);
            
            isSendPush = true;
        }
    }
    else{
        isSendPush = false;
    }
    
    delay(1000);
}

void sendToPushingBox(const char * devid, int lightvalue){
    TCPClient client;
    
    if (client.connect(serverName, 80)){
        char szLightValue[32];
        
        sprintf(szLightValue, "%d", lightvalue);
        
        client.print("GET /pushingbox?devid=");
        client.print(devid);
        client.print("&light=");
        client.print(szLightValue);
        client.println(" HTTP/1.1");
        client.print("Host: ");
        client.println(serverName);
        client.println("User-Agent: Spark");
        
        client.println();
        client.flush();
        
        delay(2000);
        
        client.stop();
    }
    else{
        Serial.println("TCP Client not connected.");
    }
}