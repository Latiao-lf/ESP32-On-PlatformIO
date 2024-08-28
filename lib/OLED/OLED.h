//
// Created by Latiao-lf on 2023/6/20.
//
#include <Arduino.h>
#include <U8g2lib.h>
U8G2_SSD1306_128X64_NONAME_F_SW_I2C u8g2(U8G2_R0, 16, 15, U8X8_PIN_NONE);

class OLEDMethods{
public:
    void OLEDInit(){
        u8g2.begin();
        u8g2.enableUTF8Print();
        u8g2.setFont(u8g2_font_wqy12_t_gb2312a);
        u8g2.setFontDirection(0);
    }
    void OLEDDisplay(){
        u8g2.clearBuffer();
        u8g2.setCursor(0, 12);+
        u8g2.print("湿度: " + String(Humidity)+"%");
        u8g2.setCursor(0, 24);
        u8g2.print("温度: " + String(Temperature)+"℃");
        u8g2.setCursor(0, 36);
        u8g2.print("PPB: " + String(PPB));
        u8g2.setCursor(54, 36);
        if (PPB<200) {
            u8g2.print("空气质量优");
        } else if(PPB<1000){
            u8g2.print("空气质量良");
        } else if(PPB<3000){
            u8g2.print("空气质量一般");
        } else{
            u8g2.print("空气质量差");
        }
        u8g2.setCursor(0, 48);
        u8g2.print("电池电压: " + String(BATTERY_VOLTAGE)+"V");
        u8g2.setCursor(0, 60);
        if (deviceConnected){
            u8g2.print("蓝牙已连接");
        } else{
            u8g2.print("蓝牙未连接");
        }
        u8g2.setCursor(64, 60);
        if (HTTPConnected){
            u8g2.print("HTTP已连接");
        } else{
            u8g2.print("HTTP未连接");
        }
        u8g2.sendBuffer();
    }
};