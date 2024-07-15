#ifndef __SYSTEM_H__
#define __SYSTEM_H__
#include "ti_msp_dl_config.h"
#include "task.h"

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
void delay_ms(unsigned int ms);
void sys_init(void);

#endif
