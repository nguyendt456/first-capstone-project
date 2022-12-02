#include <main.h>
#define DEFAULT_SSID "do_an_muoi_diem"
#define DEFAULT_PASSWORD "12345678"

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

extern bool first_time_check;