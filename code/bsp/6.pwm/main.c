#include "system.h"
#include "task.h"

int main(void)
{
    sys_init();
    while (1)
    {
       task_run(); 
         
    }
}

