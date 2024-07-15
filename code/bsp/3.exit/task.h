#ifndef __TASK_H__
#define __TASK_H__

#define TASK_MAX 2
extern volatile unsigned int sys_timer[TASK_MAX];
#define DELAY_TIMER    sys_timer[0]
#define LED_TASK_TIMER sys_timer[1]

#define LED_TASK_TIMER_PERIOD 1000
void task_run(void);
#endif