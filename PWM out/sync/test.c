#include "sys.h"
#include "usart.h"		
#include "delay.h"	
#include "led.h" 
#include "key.h"
#include "exti.h"
#include "wdg.h"
#include "timer.h"	 	 
//Mini STM32�����巶������8
//PWM��� ʵ��
//����ԭ��@ALIENTEK
//������̳:www.openedv.com	  

int main(void)
{		
 
		
 	Stm32_Clock_Init(9); //ϵͳʱ������
	delay_init(72);	     //��ʱ��ʼ��
	uart_init(72,9600);  //���ڳ�ʼ�� 
	LED_Init();		  	 //��ʼ����LED���ӵ�Ӳ���ӿ�
	PWM_Init(32400,2);	 //����Ƶ��PWMƵ��=72000/900=80Khz
   	while(1)
	{
 		LED0_PWM_VAL=21600;	
			//sync
	}	 
	
     	
	
}

























