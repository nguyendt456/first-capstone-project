#include <main.h>

void setup() {
    Serial.begin(9600);
    EEPROM.begin(128);

    cleanupEEPROM();
    credentialReadFromEEPROM();
	WiFiCrentialCheck();

    WiFi.mode(WIFI_AP);
    WiFi.softAP(SSID.c_str(), PASSWORD.c_str());
    WiFi.softAPConfig(IP, GATEWAY, NETMASK, DHCP_RANGE);
    webServer.begin();

    WiFi.onEvent(ReconnectOnDisconnect, WiFiEvent_t::ARDUINO_EVENT_WIFI_STA_DISCONNECTED);
	WiFi.onEvent(HandleOnConnected, WiFiEvent_t::ARDUINO_EVENT_WIFI_STA_CONNECTED);
    WiFi.onEvent(APServerHandle, WiFiEvent_t::ARDUINO_EVENT_WIFI_AP_STACONNECTED);
    WiFi.onEvent(ClientMode, WiFiEvent_t::ARDUINO_EVENT_WIFI_STA_START);
}

void loop() {}