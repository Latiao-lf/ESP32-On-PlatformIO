//
// Created by Latiao-lf on 2023/6/20.
//
#include <Arduino.h>
#include <AM232X.h>
#include <AGS02MA.h>
#define AM2320_scl 6//4
#define AM2320_sda 7//5
#define AGS02MA_scl 4//6
#define AGS02MA_sda 5//7

TwoWire I2C_AGS02MA = TwoWire(0);
TwoWire I2C_AM2320 = TwoWire(1);
AM232X AM2320(&I2C_AM2320);
AGS02MA AGS(26, &I2C_AGS02MA);

float Humidity,Temperature;
uint16_t PPB;

class sensorMethod{
public:
    void sensorInit(){
        I2C_AM2320.begin(AM2320_sda, AM2320_scl, 100000);
        I2C_AGS02MA.begin(AGS02MA_sda, AGS02MA_scl);

        if (!AM2320.begin(AM2320_sda, AM2320_scl)) {
            Serial.println("AM2320 not found");
        }

        if (!AM2320.begin(AGS02MA_sda, AGS02MA_scl)) {
            Serial.println("AGS02MA not found");
        }

        AGS.setPPBMode();
    }
    void getSensorData(){
        AM2320.wakeUp();
        AM2320.read();

        Humidity=AM2320.getHumidity();
        Temperature=AM2320.getTemperature();
        PPB=AGS.readPPB();
    }
};
