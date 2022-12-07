#include <main.h>

void PowerButtonInit() {
    pinMode(POWER_BUTTON, INPUT_PULLUP);
}

void PowerButtonTimer() {
    power_button_state1 = power_button_state2;
    power_button_state2 = power_button_state3;
    power_button_state3 = digitalRead(15);
    if(power_button_state1 == power_button_state2 && power_button_state2 == power_button_state3) {
        if(power_button_state1 != power_button_state) {
            power_button_state = power_button_state1;
            // Handle when button pressed
            setTimer1(30);
        }
        else {
            if(timer1_flag == 1 && power_button_state == LOW) {
                Serial.println("Button pressed for 3 seconds");
                Serial.println("Switching to AP mode");
                SwitchWiFiAPMode();
                setTimer1(0);
            }
            if(timer1_flag == 1 && power_button_state == HIGH) setTimer1(0); 
        }
    }

}