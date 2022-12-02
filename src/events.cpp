#include <main.h>

void ReconnectOnDisconnect(WiFiEvent_t event, WiFiEventInfo_t info) {
    if (first_time_check == 1) {
        Serial.println("WiFi disconnected. Trying to reconnect !");
        WiFi.reconnect();
    }
}

void APServerHandle(WiFiEvent_t event, WiFiEventInfo_t info) {
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
            delay(200);
            credentialReadFromEEPROM();
        }
    });
    webServer.begin();
}