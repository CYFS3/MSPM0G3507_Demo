#include "system.h"
#include "exit.h"

void exit_init(void)
{
    NVIC_EnableIRQ(key_INT_IRQN);//开启按键引脚的GPIOA端口中断
}

void GROUP1_IRQHandler(void)//Group1的中断服务函数
{
    //读取Group1的中断寄存器并清除中断标志位
    switch( DL_Interrupt_getPendingGroup(DL_INTERRUPT_GROUP_1) )
    {
        //检查是否是KEY的GPIOA端口中断，注意是INT_IIDX，不是PIN_18_IIDX
        case key_INT_IIDX:
            //如果按键按下变为高电平
            if( DL_GPIO_readPins(key_PORT, key_PIN_18_PIN) > 0 )
            {
                //设置LED引脚状态翻转
                DL_GPIO_togglePins(LED0_PORT, LED0_PIN_14_PIN);
            }
        break;
    }
}