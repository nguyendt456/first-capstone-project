#include <main.h>

void setup() {
  Serial.begin(9600);
  EEPROM.begin(128);
  credentialReadFromEEPROM();
  if(SSID == "" && PASSWORD == "") {
    SSID = DEFAULT_SSID;
    PASSWORD = DEFAULT_PASSWORD;
  }
  // Set WiFi to station mode and disconnect from an AP if it was previously connected
  WiFi.mode(WIFI_AP);
  WiFi.softAP(SSID.c_str(), PASSWORD.c_str());
  WiFi.softAPConfig(IP, GATEWAY, NETMASK, DHCP_RANGE);
  webServer.begin();

  WiFi.onEvent(ReconnectOnDisconnect, WiFiEvent_t::ARDUINO_EVENT_WIFI_STA_DISCONNECTED);
  WiFi.onEvent(APServerHandle, WiFiEvent_t::ARDUINO_EVENT_WIFI_AP_STACONNECTED);

  delay(5000);
  Serial.println(SSID);
  Serial.println(PASSWORD);
  
}

void loop() {
}