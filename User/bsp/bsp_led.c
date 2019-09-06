
/*
 *
 * Change Logs:
 * Date           Author       Notes
 * 2019-6-11     suozhang      the first version
 *
 */

#include "bsp_led.h"

void bsp_led_init( void )
{
	GPIO_InitTypeDef GPIO_InitStructure;

	/* 打开GPIO时钟 */
	RCC_APB2PeriphClockCmd(RCC_ALL_LED, ENABLE);

	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;	/* 推挽输出模式 */
	
	GPIO_InitStructure.GPIO_Pin = GPIO_PIN_LED1;
	GPIO_Init(GPIO_PORT_LED1, &GPIO_InitStructure);

	bsp_led_off( e_led_all );
	
}

void bsp_led_on( E_LED_OBJECT led_object )
{

	if( e_led_red_system_status == led_object )
	{
		GPIO_ResetBits( GPIO_PORT_LED1, GPIO_PIN_LED1 );
	}

}

void bsp_led_off( E_LED_OBJECT led_object )
{
	if( e_led_red_system_status == led_object )
	{
		GPIO_SetBits( GPIO_PORT_LED1, GPIO_PIN_LED1 );
	}

	if( e_led_all == led_object )
	{
		GPIO_SetBits( GPIO_PORT_LED1, GPIO_PIN_LED1 );
	}

}

void bsp_led_toggle( E_LED_OBJECT led_object )
{

	if( e_led_red_system_status == led_object )
	{
		GPIO_PORT_LED1->ODR ^= GPIO_PIN_LED1;
	}

}
