#include "system.h"
volatile unsigned int sys_timer[TASK_MAX];
void sys_init(void)
{
    SYSCFG_DL_init();
}
//搭配滴答定时器实现的精确ms延时
void delay_ms(unsigned int ms)
{
    DELAY_TIMER = ms;
    while( DELAY_TIMER != 0 );
}

void SysTick_Handler(void)
{
    for(int i = 0;i < TASK_MAX;i++)
    {
        if(sys_timer[i])
        {
            sys_timer[i]--;
        }
    }
}
