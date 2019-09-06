
/*
 *
 * Change Logs:
 * Date           Author       Notes
 * 2019-6-11     suozhang      the first version
 *
 */


#ifndef _BSP_LED_H
#define _BSP_LED_H

#include "stm32f10x.h"

#define RCC_ALL_LED 	( RCC_APB2Periph_GPIOC )

#define GPIO_PORT_LED1  GPIOC
#define GPIO_PIN_LED1		GPIO_Pin_13

/* led 对象. */
typedef enum
{
	e_led_red_system_status = 0,  /* led red 表示系统运行状态. */
	e_led_all,									  /* led all. */
} E_LED_OBJECT;

void bsp_led_init( void );
void bsp_led_on( E_LED_OBJECT led_object );
void bsp_led_off( E_LED_OBJECT led_object );
void bsp_led_toggle( E_LED_OBJECT led_object );
	
#endif /* _BSP_LED_H */

