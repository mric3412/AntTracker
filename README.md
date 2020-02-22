# AntTracker
Minimalist telemetric tracker derived from an old version of zs6buj AntTracker
- Tracker for tracking a moving model aircraft or drone based on v0.32 of this project https://github.com/zs6buj/AntTracker
- Supports only Mavlink 
This version is based on v0.32 of zs6buj Antenna tracker. The goal is to make it work properly in the following particular case :
- STM32F1 Blue pill flashed using a ST-Link V2 programmer
- own antenna tracker compass : cheap magnetometer QMC5883L. This library is used : https://github.com/mprograms/QMC5883LCompass
- Mavlink downlink Telemetry (from QLRS in relay mode for my application, but works with all Mavlink system by changing baud)
- 180 degres servos used for lacet (yaw/azimuth) and tangage (pitch/elevation) : a major bug is corrected in this version to manage different home heading cases
