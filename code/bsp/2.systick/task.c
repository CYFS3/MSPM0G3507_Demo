#include "system.h"
#include "task.h"
void led_task_run(void)
{
    if(LED_TASK_TIMER)return;
    LED_TASK_TIMER = LED_TASK_TIMER_PERIOD;
    static char state = 0;
    if(state)
    {
       DL_GPIO_setPins(LED0_PORT, LED0_PIN_14_PIN); 
    }
    else
    {
       DL_GPIO_clearPins(LED0_PORT, LED0_PIN_14_PIN); 
    }
   state = !state;    
}


void task_run(void)
{
    led_task_run();
}
