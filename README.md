# ESP32-On-PlatformIO BY Latiao-lf

这是一个基于ESP32-S3 N8R16的物联网环境检测个人项目的嵌入式部分，可作为一个完整的课程设计或毕业设计。
基于PlatformIO生态、Arduino框架开发。

# 传感器
温度传感器采用AM2320（库采用[@RobTillaart/AM232X](https://github.com/RobTillaart/AM232X)），气体质量传感器采用AGS02MA（库采用[@RobTillaart/AGS02MA](https://github.com/RobTillaart/AGS02MA)），NB-IOT模块采用塔石E33V-DTU。

# 多种数据取得方式
用户可通过微信小程序（[@]()）连接*BLE*进行数据交互，也可通过写串口的形式通过NB-IOT模块访问后端*HTTP*接口（@）实现远程云端落盘记录数据。


