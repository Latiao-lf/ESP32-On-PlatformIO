ESP32-On-PlatformIO

这是一个基于ESP32-S3 N8R16的物联网环境检测嵌入式个人项目。
基于PlatformIO生态，Arduino框架开发。

温度传感器采用AM2320（库采用@RobTillaart/AM232X），气体质量传感器采用AGS02MA（库采用@RobTillaart/AGS02MA），NB-IOT模块采用塔石E33V-DTU。

用户可通过微信小程序（@）连接BLE进行数据交互，也可通过写串口的形式通过NB-IOT模块访问后端HTTP接口（@）实现远程云端落盘记录数据。


