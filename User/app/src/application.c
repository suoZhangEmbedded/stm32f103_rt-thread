/*
 * File      : application.c
 * This file is part of RT-Thread RTOS
 * COPYRIGHT (C) 2006 - 2013, RT-Thread Development Team
 *
 * The license and distribution terms for this file may be
 * found in the file LICENSE in this distribution or at
 * http://www.rt-thread.org/license/LICENSE
 *
 * Change Logs:
 * Date           Author       Notes
 * 2009-01-05     Bernard      the first version
 */

/**
 * @addtogroup STM32
 */
/*@{*/

#include <board.h>
#include <rtthread.h>

#ifdef RT_USING_DFS
#include <dfs_fs.h>
#include <dfs_init.h>
#include <dfs_elm.h>
#endif

#ifdef RT_USING_LWIP
#include <stm32_eth.h>
#include <netif/ethernetif.h>
extern int lwip_system_init(void);
#endif

#ifdef RT_USING_FINSH
#include <shell.h>
#include <finsh.h>
#endif

#include "bsp_led.h"

void rt_init_thread_entry(void* parameter)
{
    while (1)
    {
			bsp_led_toggle( e_led_red_system_status );
			
			rt_kprintf( "hello,rtthread.tick:%u.\r\n", rt_tick_get() );
			
			/* —” ± 1000ms */
			rt_thread_mdelay( 1000 );

    }
}

int rt_application_init(void)
{
    rt_thread_t tid;

    tid = rt_thread_create("init",rt_init_thread_entry, RT_NULL, 512, RT_THREAD_PRIORITY_MAX/3, 20);
    
		if (tid != RT_NULL) rt_thread_startup(tid);
	
    return 0;
}

/*@}*/
