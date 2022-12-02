#include <main.h>

void cleanupEEPROM() {
    for (int i = 0; i < 512; i++) {
        EEPROM.write(i, 0);
    }
    EEPROM.commit();
    delay(200);
}

void credentialWriteToEEPROM() {
    byte ssid_len = AP_SSID.length();
    byte pass_len = AP_PASSWORD.length();
    EEPROM.write(0, ssid_len);
    for (int i = 0; i < ssid_len; i++) {
        EEPROM.write(i + 1, AP_SSID[i]);
    }
    EEPROM.write(ssid_len + 2, pass_len);
    for (int i = ssid_len + 3; i < pass_len + ssid_len + 3; i++) {
        EEPROM.write(i + 1, AP_PASSWORD[i - (ssid_len + 3)]);
    }
    EEPROM.commit();
}

void credentialReadFromEEPROM() {
    byte ssid_len = EEPROM.read(0);
    SSID = "";
    PASSWORD = "";
    for(int i = 0; i < ssid_len; i++) {
        SSID += (char)EEPROM.read(i + 1);
    }
    byte pass_len = EEPROM.read(ssid_len + 2);
    for(int i = ssid_len + 3; i < pass_len + ssid_len + 3; i++) {
        PASSWORD += (char)EEPROM.read(i + 1);
    }
}

void WiFiCrentialCheck() {
    if(SSID == "" && PASSWORD == "") {
        SSID = DEFAULT_SSID;
        PASSWORD = DEFAULT_PASSWORD;
    }
    else {
        SYSTEM_STATE = 1;
        SwitchWiFiMode(WIFI_STA);
    }
}