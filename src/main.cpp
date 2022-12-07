#include <main.h>

void setup() {
    Serial.begin(9600);
    EEPROM.begin(128);

    timer = timerBegin(0, 80, true);
    timerAttachInterrupt(timer, &timerRun, true);
    timerAlarmWrite(timer, 100000, true);
    pinMode(POWER_BUTTON, INPUT_PULLUP);
    
    credentialReadFromEEPROM();
	if(WiFiCrentialCheck()) {
        WiFi.mode(WIFI_AP);
        WiFi.softAP(SSID.c_str(), PASSWORD.c_str());
        WiFi.softAPConfig(IP, GATEWAY, NETMASK, DHCP_RANGE);
        webServer.begin();
    }

    WiFi.onEvent(ReconnectOnDisconnect, WiFiEvent_t::ARDUINO_EVENT_WIFI_STA_DISCONNECTED);
	WiFi.onEvent(HandleOnConnected, WiFiEvent_t::ARDUINO_EVENT_WIFI_STA_CONNECTED);
    WiFi.onEvent(APServerHandle, WiFiEvent_t::ARDUINO_EVENT_WIFI_AP_STACONNECTED);
    WiFi.onEvent(ClientMode, WiFiEvent_t::ARDUINO_EVENT_WIFI_STA_START);
}

void loop() {
    if(SYSTEM_STATE == STA_MODE) {
        if(STA_init_check == 1) {
            STA_init_check = 0;
            webServer.end();            // end Async webserver
            timerAlarmEnable(timer);    // enable timer for Button
            setTimer2(1);
            SwitchWiFiSTAMode();        // switch to STA mode
        }
        if(timer2_flag == 1) {
            setTimer2(1);
            PowerButtonTimer();
        }
    }
    delay(1);
}