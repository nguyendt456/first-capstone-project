#include <main.h>

void ReconnectOnDisconnect(WiFiEvent_t event, WiFiEventInfo_t info);
void APServerHandle(WiFiEvent_t event, WiFiEventInfo_t info);
void ClientMode(WiFiEvent_t event, WiFiEventInfo_t info);
void HandleOnConnected(WiFiEvent_t event, WiFiEventInfo_t info);
void SwitchWiFiMode(wifi_mode_t mode);