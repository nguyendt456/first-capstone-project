#include <main.h>

void tft_init() {
    tft.init();
    tft.setFreeFont(FM12);
    tft.setRotation(1);
    tft.fillScreen(TFT_BLACK);
}

void tft_draw(int x, int y, String content) {
    tft.setCursor(x, y);
    tft.print(content);
}

void ap_mode_print() {
    tft.fillScreen(TFT_BLACK);
    char buf[50];
    tft_draw(10, 18, "AP mode:");
    tft.setFreeFont(FM9);
    strcpy(buf, "SSID: ");
    strcat(buf, DEFAULT_SSID);
    tft_draw(25, 60, buf);

    char pass_buf[50];
    strcpy(pass_buf, "PASS: ");
    strcat(pass_buf, DEFAULT_PASSWORD);
    tft_draw(25, 82, pass_buf);
    
    tft.setFreeFont(FM12);
}

void sta_connected_print() {
    tft.fillScreen(TFT_BLACK);
    char buf[50];
    char ssid_buff[50];
    tft_draw(10, 18, "CONNECTED !");
    tft.setFreeFont(FM9);
    SSID.toCharArray(ssid_buff, SSID.length() + 1);
    strcpy(buf, "SSID: ");
    strcat(buf, ssid_buff);
    tft_draw(25, 70, buf);

    tft.setFreeFont(FM12);
}

void sta_disconnected_print() {
    tft.fillScreen(TFT_BLACK);
    char buf[50];
    tft_draw(20, 70, "Disconnected !");
}