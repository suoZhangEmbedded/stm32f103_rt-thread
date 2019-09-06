
/*
 *
 * Change Logs:
 * Date           Author       Notes
 * 2019-6-11     suozhang      the first version
 *
 */

#include "stm32f10x.h"

#include "SEGGER_RTT.h"
#include "stdio.h"

#include "bsp_led.h"

/**
 * �ض���fputc����
 *
 * @param ������ַ�
 * @param Ŀ���ļ�
 *
 * @return ch
 */
int fputc(int ch, FILE *f)
{

	SEGGER_RTT_Write( 0, &ch, 1 );
	
	return ch;

}

int main(void)
{
	
	/* ���ȼ���������Ϊ4 */
	NVIC_PriorityGroupConfig( NVIC_PriorityGroup_4 );

	while(1);
	
}


















