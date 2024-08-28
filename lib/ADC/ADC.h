//
// Created by MIAO-LAPTOP on 2023/6/20.
//
#include <Arduino.h>
double ADC1_VOLTAGE,ADC1_PREVIOUS_VOLTAGE,BATTERY_VOLTAGE;

class ADCMethods{
public:
    void ADC1_GET(){
        for (int i = 0; i < 40; ++i) {
            ADC1_VOLTAGE+= analogRead(8) * 3.3 / 4095;//ADC非线性特性修正
            delay(5);
        }
        if (ADC1_PREVIOUS_VOLTAGE!=0){
            BATTERY_VOLTAGE=(ADC1_VOLTAGE+ADC1_PREVIOUS_VOLTAGE)/40*2.72;//阻抗匹配后电阻分压修正
        }
    }
    void ADC1_INIT(){
        ADC1_VOLTAGE=ADC1_PREVIOUS_VOLTAGE=BATTERY_VOLTAGE=0;
    }
    void ADC1_READY(){
        ADC1_PREVIOUS_VOLTAGE=ADC1_VOLTAGE;
        ADC1_VOLTAGE=BATTERY_VOLTAGE=0;
    }
};
