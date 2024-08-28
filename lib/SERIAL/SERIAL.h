//
// Created by MIAO-LAPTOP on 2023/6/20.
//
#include <Arduino.h>
#include <ArduinoJson.h>

int timer = 0;
bool HTTPConnected = true;

class SERIALMethods {
private:
    char a[10];
    char b[10];
    char c[10];
    char d[10];
public:
    void SERIALInit() {
        Serial.begin(9600);
        Serial1.begin(9600, SERIAL_8N1, 17, 18);
    }

    void SERIAL0_OUTPUT() {
        Serial.print("Humidity:");
        Serial.println(Humidity);
        Serial.print("Temperature:");
        Serial.println(Temperature);
        Serial.print("PPB:");
        Serial.println(PPB);
        Serial.println("\n\n");
    }

    void SERIAL1_WRITE() {
        if (timer == 5 && HTTPConnected) {
            char jsonStr[] = "{\n"
                             "    \"temperature\":,\n"
                             "    \"humidity\":,\n"
                             "    \"voltage\":,\n"
                             "    \"ppm\":\n"
                             "}";
            DynamicJsonDocument jsonDoc(128);
            deserializeJson(jsonDoc, jsonStr);

            sprintf(a, "%.1f", Temperature);
            sprintf(b, "%.1f", Humidity);
            sprintf(c, "%.2f", BATTERY_VOLTAGE);
            sprintf(d, "%d", PPB);

            jsonDoc["temperature"] = a;
            jsonDoc["humidity"] = b;
            jsonDoc["voltage"] = c;
            jsonDoc["ppm"] = d;

            String post;
            serializeJson(jsonDoc, post);
            Serial1.write(post.c_str());
            timer = 0;
        } else {
            timer++;
        }
    }

    void SERIAL1_READ() {
        if (Serial1.available()) {
            String buf = Serial1.readString();
            String CONNECTED="+STATUS: 2, CONNECTED";
            String CLOSED="+STATUS: 2, CLOSED";
            Serial.print(buf);
            if (buf==CONNECTED) {
                HTTPConnected = true;
            } else if (buf==CLOSED) {
                HTTPConnected = false;
            }
        }
    }
};
