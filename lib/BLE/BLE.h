//
// Created by Latiao-lf on 2023/6/16.
//
#include <Arduino.h>
#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLE2902.h>
// 定义收发服务的UUID（唯一标识）
#define SERVICE_UUID           "6E400001-B5A3-F393-E0A9-E50E24DCCA9E"
// RX串口标识
#define CHARACTERISTIC_UUID_RX "6E400002-B5A3-F393-E0A9-E50E24DCCA9E"
// TX串口标识
#define CHARACTERISTIC_UUID_TX "6E400003-B5A3-F393-E0A9-E50E24DCCA9E"

String data = "";
BLECharacteristic *pTxCharacteristic;
BLEServer *pServer = nullptr;
bool deviceConnected = false;
bool oldDeviceConnected = false;

class MyServerCallbacks : public BLEServerCallbacks {
    void onConnect(BLEServer *pServer) override{
        deviceConnected = true;
    }
    void onDisconnect(BLEServer *pServer) override {
        deviceConnected = false;
    }
};

//监听手机发送的特征值回调函数
class MyCallbacks : public BLECharacteristicCallbacks {
    void onWrite(BLECharacteristic *pCharacteristic) override{
    std::string rxValue = pCharacteristic->getValue();

    if (rxValue.length() > 0) {
        Serial.println("*********");
        Serial.print("Received Value: ");
        for (char i : rxValue) {
            Serial.print(i);
        }
        Serial.println();
        data = rxValue.c_str();
        //Serial.println(data);
        Serial.println("*********");
        Serial.println();
    }
}
};

class BLEMethods{
private:
    char a[10];
    char b[10];
    char c[10];
    char d[10];
public:
    void BLEInit(){
        BLEDevice::init("ESP32 test");
        // 为蓝牙设备创建服务器
        pServer = BLEDevice::createServer();
        pServer->setCallbacks(new MyServerCallbacks());
        // 基于SERVICE_UUID来创建一个BLE服务
        BLEService *pService = pServer->createService(SERVICE_UUID);
        pTxCharacteristic = pService->createCharacteristic(
                CHARACTERISTIC_UUID_TX,
                BLECharacteristic::PROPERTY_NOTIFY
        );
        pTxCharacteristic->addDescriptor(new BLE2902());
        BLECharacteristic *pRxCharacteristic = pService->createCharacteristic(
                CHARACTERISTIC_UUID_RX,
                BLECharacteristic::PROPERTY_WRITE
        );
        pRxCharacteristic->setCallbacks(new MyCallbacks());
        // 开启服务
        pService->start();
        // 开启广播
        pServer->getAdvertising()->start();
//        Serial.println("Waiting a client connection to notify...");
//        Serial.println();
    }
    void connecting(){
        // 没有新连接时
        if (!deviceConnected && oldDeviceConnected) {
            // 给蓝牙堆栈准备数据的时间
            delay(500);
            pServer->startAdvertising();
            // 重新开始广播
            Serial.println("start advertising");
            oldDeviceConnected = deviceConnected;
        }
        // 正在连接时
        if (deviceConnected && !oldDeviceConnected) {
            // 正在连接时进行的操作
            oldDeviceConnected = deviceConnected;
        }
    }
    void connected(){
        if (deviceConnected == 1) {
            //使数据加上不同的特征符
            sprintf(a, "%.1f%s", Temperature, "a");
            sprintf(b, "%.1f%s", Humidity, "b");
            sprintf(c, "%.2f%s", BATTERY_VOLTAGE, "c");
            sprintf(d, "%d%s", PPB, "d");
            //更改特征值向外广播
            pTxCharacteristic->setValue(a);
            pTxCharacteristic->notify();
            delay(10);
            pTxCharacteristic->setValue(b);
            pTxCharacteristic->notify();
            delay(10);
            pTxCharacteristic->setValue(c);
            pTxCharacteristic->notify();
            delay(10);
            pTxCharacteristic->setValue(d);
            pTxCharacteristic->notify();
        }
    }
};
