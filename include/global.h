#include <main.h>
#define DEFAULT_SSID "do_an_muoi_diem"
#define DEFAULT_PASSWORD "12345678"
#define AP_MODE 0
#define STA_MODE 1
#define ON_SWITCH

extern int power_button_state1;
extern int power_button_state2;
extern int power_button_state3;
extern int power_button_state;

extern bool STA_init_check;

extern hw_timer_t* timer;
extern portMUX_TYPE timerMux;

extern String SSID;
extern String PASSWORD;

extern String AP_SSID;
extern String AP_PASSWORD;

extern AsyncWebServer webServer;

extern const char APSetup_html[] PROGMEM;

extern IPAddress IP;
extern IPAddress GATEWAY;
extern IPAddress NETMASK;
extern IPAddress DHCP_RANGE;

extern bool SYSTEM_STATE;