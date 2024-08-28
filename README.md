# ESP32-On-PlatformIO BY Tomorii

这是一个基于ESP32-S3 N8R16的物联网环境检测项目的嵌入式部分，较为简陋。几乎完全隐藏了硬件上的实现细节，直接面向功能，简单易懂。适合初学者，可作为一个完整的课程设计或个人项目设计。

基于PlatformIO生态、Arduino框架开发。

实现细节已经被大部分隐藏，简单封装了一些接口，入口与Loop只需调用不同生命周期函数即可。

# 传感器
温度传感器采用AM2320（库采用[@RobTillaart/AM232X](https://github.com/RobTillaart/AM232X)），气体质量传感器采用AGS02MA（库采用[@RobTillaart/AGS02MA](https://github.com/RobTillaart/AGS02MA)），NB-IOT模块采用塔石E33V-DTU。

# 多种数据取得/展现方式
用户可通过微信小程序（[@Monitor-On-WX](https://github.com/Latiao-lf/Monitor-On-WX)）连接*BLE*进行数据交互，也可通过写串口的形式通过NB-IOT模块访问后端*HTTP*接口（@）实现远程云端落盘记录数据。

# 欢迎联系我提供配套硬件设计资料

*##### 该项目实际最后维护时间为2023.06，可能与IDEA最新版本的PlatformIO Plugin不兼容*
