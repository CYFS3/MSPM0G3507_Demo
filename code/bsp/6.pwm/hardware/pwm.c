#include "system.h"
#include "pwm.h"


void tima0_ch2_set(int i)
{
    DL_TimerG_setCaptureCompareValue(PWM_0_INST,i,GPIO_PWM_0_C2_IDX);
}
