#include "system.h"
#include "uart.h"
#include "task.h"
#include "string.h"
u8 UART0_RxBUF[UART0_RXBUF_SIZE];//串口接收缓冲区（数组）
u16 UART0_RecPos=0;//用于指向接收缓冲区的最后一个数据的位置
void uart0_init(void)
{
   //清除串口中断标志
    NVIC_ClearPendingIRQ(UART_0_INST_INT_IRQN);
    //使能串口中断
    NVIC_EnableIRQ(UART_0_INST_INT_IRQN); 
}
//串口发送单个字符
void uart0_send_char(char ch)
{
    //当串口0忙的时候等待，不忙的时候再发送传进来的字符
    while( DL_UART_isBusy(UART_0_INST) == true );
    //发送单个字符
    DL_UART_Main_transmitData(UART_0_INST, ch);
}
//串口发送字符串
void uart0_send_string(char* str)
{
    //当前字符串地址不在结尾 并且 字符串首地址不为空
    while(*str!=0&&str!=0)
    {
        //发送字符串首地址中的字符，并且在发送完成之后首地址自增
        uart0_send_char(*str++);
    }
}

//串口的中断服务函数
void UART_0_INST_IRQHandler(void)
{
    //如果产生了串口中断
    switch( DL_UART_getPendingInterrupt(UART_0_INST) )
    {
        case DL_UART_IIDX_RX://如果是接收中断
            //接发送过来的数据保存在变量中
            UART0_REC_TIMER = UART_REC_FRA;
            UART0_RxBUF[UART0_RecPos++] = DL_UART_Main_receiveData(UART_0_INST);
            break;

        default://其他的串口中断
            break;
    }
}


void uart0_rec_prosess(void)
{
    if(UART0_REC_TIMER)return;
    if(!UART0_RecPos)return;
    UART0_RxBUF[UART0_RecPos] = '\0';
    uart0_send_string((char*)UART0_RxBUF);
    
    
    
    
    memset(UART0_RxBUF,0,UART0_RXBUF_SIZE);
    UART0_RecPos=0;//接收缓冲区指针清零
}