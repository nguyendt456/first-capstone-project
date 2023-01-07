# First capstone project HCMUT :whale:

## Introduction

Implement interactive configuration for WiFi ssid and password.

And could be more than that...

## Feature

* ![alt text][supported] &nbsp; Asynchronous server for user to enter WiFi credentials.
* ![alt text][supported] &nbsp; EEPROM to persistent store credential information.
* ![alt text][supported] &nbsp; Event-driven design for good code structure managements and scalable.
* ![alt text][supported] &nbsp; Press power button for 3 seconds to enter AP mode and re-enter credential WiFi information. (debounce using timer).
* ![alt text][on_develop] &nbsp; Displaying state of device.

[supported]: https://img.shields.io/badge/-Supported-brightgreen
[on_develop]: https://img.shields.io/badge/-On%20developing-yellow

## Prerequisite

**Microprocess board**

* ESP32 TTGO Display

**Library:**

* `WiFi.h`&nbsp;&nbsp;**default**
* `EEProm.h`&nbsp;&nbsp;**default** (Deprecating in future)
* `AsyncTCP`&nbsp;&nbsp;**ESPAsyncWebServer-esphome**
* `ESPAsyncWebServer`&nbsp; **ESPAsyncWebServer-esphome**
* `TFP_eSPI`&nbsp; **by Bobmer**

**Develop environment:**

* PlatformIO