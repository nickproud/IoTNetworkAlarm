# IoTNetworkAlarm
A device which checks that a defined remote host is online and sounds an alarm when it is unreachable. 
Code is compiled for ESP8266 WiFi module which performs network monitoring and sounds alarm. 

## Prerequisites:
1. Arduino IDE installed. https://www.arduino.cc/en/main/software
2. ESP8266-ping library installed in Arduino-IDE https://www.arduinolibraries.info/libraries/esp8266-ping

## Setup:
1. In Arduino IDE, go open the sketch: IoTNetworkAlarmSketch.ino
2. Replace `ssid` with SSID for your WiFi network. 
3. Replace `password` with WiFi password for your WiFi network
4. Replace `hostIP` with the IP address of the host you wish to monitor. 
