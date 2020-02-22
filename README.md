# AntTracker

Minimalist telemetric tracker derived from an old version of zs6buj AntTracker
- Tracker for tracking a moving model aircraft or drone
- Based on v0.32 of this project https://github.com/zs6buj/AntTracker
- Supports only Mavlink 

The goal of this version is to make it work properly in the following particular case :
- STM32F1 Blue pill flashed using a ST-Link V2 programmer
- Own antenna tracker compass : cheap magnetometer QMC5883L. This library is used : https://github.com/mprograms/QMC5883LCompass
- Mavlink downlink Telemetry (from QLRS in relay mode for my application, but works with all Mavlink system by changing baud)
- 180 degres servos used for lacet (yaw/azimuth) and tangage (pitch/elevation) : a major bug is corrected in this version to manage different home heading cases

To avoid common compilation problems, the used Mavlink library is in the zip file provided in this repository : unzip in your arduino/sketch directory.
QMC5883LCompass library (https://github.com/mprograms/QMC5883LCompass) has to be installed in your arduino lib. directory.

Wire library for STM32F1 with SotWire.h must be installed on your arduino IDE too (I2C/needed for compass)
