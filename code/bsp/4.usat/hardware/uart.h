#ifndef __UART_H__
#define __UART_H__

#define UART0_RXBUF_SIZE 64
void uart0_init(void);
void uart0_send_char(char ch);
void uart0_send_string(char* str);
void uart0_rec_prosess(void);
#endif
