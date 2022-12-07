# First capstone project HCMUT :whale:

## Introduction

Implement interactive configuration for WiFi ssid and password.

And could be more than that...

## Feature

* Asynchronous server for user to enter WiFi credentials.
* EEPROM to persistent store credential information.
* Event-driven design for good code structure managements and scalable.
* Press power button for 3 seconds to enter AP mode and re-enter credential WiFi information. (debounce using timer).

## Prerequisite

**Microprocess board**

* ESP32 dev module (Recommended 1 core module)

**Library:**

* `WiFi.h`&nbsp;&nbsp;**default**
* `EEProm.h`&nbsp;&nbsp;**default**
* `AsyncTCP`&nbsp;&nbsp;**ESPAsyncWebServer-esphome**
* `ESPAsyncWebServer`&nbsp; **ESPAsyncWebServer-esphome**

**Develop environment:**

* PlatformIO