#include <global.h>

AsyncWebServer webServer(80);

TFT_eSPI tft = TFT_eSPI();

String SSID = "";
String PASSWORD = "";

bool STA_init_check = 0;

hw_timer_t* timer = NULL;
portMUX_TYPE timerMux = portMUX_INITIALIZER_UNLOCKED;
volatile bool timer1_flag = 0;
volatile int timer1_counter = 0;

volatile bool timer2_flag = 0;
volatile int timer2_counter = 0;

int power_button_state1 = 1;
int power_button_state2 = 1;
int power_button_state3 = 1;
int power_button_state = 1;

IPAddress IP = {192, 168, 0, 0};
IPAddress GATEWAY = {192, 168, 1, 0};
IPAddress NETMASK = {255, 255, 255, 0};
IPAddress DHCP_RANGE = {192, 168, 0, 2};

String AP_SSID = "";
String AP_PASSWORD = "";

const char APSetup_html[] PROGMEM = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
<style>
input[name=wifi_form_ssid], select {
    width: 80%;
    padding: 12px 20px;
    margin: 8px 0;
    display: inline-block;
    border: 1px solid #ccc;
    border-radius: 5px;
    box-sizing: border-box;
}
input[name=wifi_form_pass], select {
    width: 80%;
    padding: 12px 20px;
    margin: 8px 0;
    display: inline-block;
    border: 1px solid #ccc;
    border-radius: 5px;
    box-sizing: border-box;
}
input[type=submit] {
    width: 30%;
    background-color: #3B71CA;
    color: white;
    padding: 14px 20px;
    margin: 8px 0;
    border: none;
    border-radius: 5px;
    cursor: pointer;
}
input[type=submit]:hover {
    background-color: #1952ad;
}
</style>
</head>
<body>
    <div>
        <form method="POST" action="/get">
          <label for="ssid">SSID</label><br>
          <input type="text" id="ssid" name="wifi_form_ssid" placeholder="SSID">
            <br>
          <label for="Password">Password</label> <br>
          <input type="password" id="password" name="wifi_form_pass" placeholder="Password">
          <input type="submit" value="Submit">
        </form>
    </div>
</body>
</html>)rawliteral";

/// @brief System state (0: AP mode for interactive WiFi configuation -- 1: Client mode for connect to server device)
bool SYSTEM_STATE = 0; 