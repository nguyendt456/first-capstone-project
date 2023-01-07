#include <main.h>

void SwitchWiFiSTAMode() {
    WiFi.mode(WIFI_STA);
    WiFi.begin(SSID.c_str(), PASSWORD.c_str());
    SYSTEM_STATE = STA_MODE;
}

void SwitchWiFiAPMode() {
    ap_mode_print();
    WiFi.mode(WIFI_AP);
    WiFi.softAP(DEFAULT_SSID, DEFAULT_PASSWORD);
    WiFi.softAPConfig(IP, GATEWAY, NETMASK, DHCP_RANGE);
    SYSTEM_STATE = AP_MODE;
}

void ReconnectOnDisconnect(WiFiEvent_t event, WiFiEventInfo_t info) {
    if (SYSTEM_STATE == STA_MODE) {
        Serial.println("WiFi disconnected. Trying to reconnect !");
        sta_disconnected_print();
        WiFi.reconnect();
    }
}

void APServerHandle(WiFiEvent_t event, WiFiEventInfo_t info) {
    ap_mode_print();
    webServer.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send_P(200, "text/html", APSetup_html);
    });
    webServer.on("/get", HTTP_POST, [] (AsyncWebServerRequest *request) {
        String inputMessage;
        if (request->hasParam("wifi_form_ssid", true)) {
            inputMessage = request->getParam("wifi_form_ssid", true)->value();
            AP_SSID = inputMessage;
            Serial.println(AP_SSID);
        }
        if (request->hasParam("wifi_form_pass", true)) {
            inputMessage = request->getParam("wifi_form_pass", true)->value();
            AP_PASSWORD = inputMessage;
            Serial.println(AP_PASSWORD);
        }
        if (AP_PASSWORD.length() < 8) 
            request->send(200, "text/html", "Please choose password larger than or equal 8 characters ! <br><a href=\"/\">Return to Home Page</a>");
        else if (AP_SSID.length() < 4)
            request->send(200, "text/html", "Please choose another SSID ! <br><a href=\"/\">Return to Home Page</a>");
        else {
            request->send(200, "text/html", "Get SSID and Password successfully ! <br><a href=\"/\">Return to Home Page</a>");
            cleanupEEPROM();
            credentialWriteToEEPROM();
            SSID = AP_SSID;
            PASSWORD = AP_PASSWORD;
            Serial.println("Switching to STA mode");
            STA_init_check = 1;
            SYSTEM_STATE = STA_MODE;
        }
    });
    if(SYSTEM_STATE == AP_MODE) webServer.begin();
}

void ClientMode(WiFiEvent_t event, WiFiEventInfo_t info) {
    Serial.print("Mac Address: ");
    Serial.println(WiFi.macAddress());
    Serial.print("IP address: ");
    Serial.println(WiFi.localIP());
}

void HandleOnConnected(WiFiEvent_t event, WiFiEventInfo_t info) {
    Serial.println("I am connected. Do something in here");
    sta_connected_print();
}