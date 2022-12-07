#include <main.h>

void setTimer1(int counter) {
    portENTER_CRITICAL_ISR(&timerMux);
    timer1_counter = counter;
    timer1_flag = 0;
    portEXIT_CRITICAL_ISR(&timerMux);
}

void setTimer2(int counter) {
    portENTER_CRITICAL_ISR(&timerMux);
    timer2_counter = counter;
    timer2_flag = 0;
    portEXIT_CRITICAL_ISR(&timerMux);
}

void IRAM_ATTR timerRun() {
    if(timer1_counter > 0) {    
        portENTER_CRITICAL_ISR(&timerMux);
        timer1_counter--;
        if(timer1_counter <= 0) timer1_flag = 1;
        portEXIT_CRITICAL_ISR(&timerMux);
    }
    if(timer2_counter > 0) {
        portENTER_CRITICAL_ISR(&timerMux);
        timer2_counter--;
        if(timer2_counter <= 0) timer2_flag = 1;
        portEXIT_CRITICAL_ISR(&timerMux);
    }
}