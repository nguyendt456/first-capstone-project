#include <main.h>

extern volatile bool timer1_flag;
extern volatile int timer1_counter;
extern volatile bool timer2_flag;
extern volatile int timer2_counter;


void setTimer1(int counter);
void setTimer2(int counter);

void IRAM_ATTR timerRun();