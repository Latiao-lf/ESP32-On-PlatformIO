#include <Arduino.h>
#include <WS2812FX.h>
#include <SENSOR.h>
#include <ADC.h>
#include <SERIAL.h>
#include <BLE.h>
#include <OLED.h>

//WS2812FX ws2812fx = WS2812FX(30, 48, NEbO_GRB + NEO_KHZ800);
//    ws2812fx.init();
//    ws2812fx.setBrightness(1);
//    ws2812fx.setSpeed(1000);
//    ws2812fx.setMode(FX_MODE_RAINBOW_CYCLE);
//    ws2812fx.start();
//    ws2812fx.service();

SERIALMethods SERIALUTILS;
BLEMethods BLE;
sensorMethod SENSOR;
OLEDMethods OLED;
ADCMethods ADC;

void setup() {
    SERIALUTILS.SERIALInit();
    OLED.OLEDInit();
    BLE.BLEInit();
    SENSOR.sensorInit();
    ADC.ADC1_INIT();
    delay(1000);
}

void loop() {
    ADC.ADC1_READY();
    ADC.ADC1_GET();
    SENSOR.getSensorData();
    BLE.connected();
    BLE.connecting();
    SERIALUTILS.SERIAL1_WRITE();
    SERIALUTILS.SERIAL1_READ();
    SERIALUTILS.SERIAL0_OUTPUT();
    OLED.OLEDDisplay();
    delay(2000);
}


