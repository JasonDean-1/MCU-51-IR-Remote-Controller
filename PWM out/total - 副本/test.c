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
#define uchar	unsigned	char
#define uint	unsigned	int 
void out0(void)
{

		
 	
	PWM_Init(9000,8);	 //����Ƶ��PWMƵ��=72000/900/(8+1)=888hz
   
 		LED0_PWM_VAL=4500;	
			//0 out
	 
		 
}

void out1(void)
{

	PWM_Init(18000,8);	 //����Ƶ��PWMƵ��=72000/900=444hz
   	
 	LED0_PWM_VAL=4500;//1 out	   
		  
		 
}

int main(void)
{	uchar addr[2]={0,0};
uint flag,j;	
 
		
 	Stm32_Clock_Init(9); //ϵͳʱ������
	delay_init(72);	     //��ʱ��ʼ��
	uart_init(72,9600);  //���ڳ�ʼ�� 
	LED_Init();		  	 //��ʼ����LED���ӵ�Ӳ���ӿ�


	 while(flag<2)
   {
          for(j = 0; j< 2 ; j++ )
    {	             
         if(addr[j] == 0)	    //��ַ��
      {	
      PWM_Init(9000,8);	 //����Ƶ��PWMƵ��=72000/900/(8+1)=888hz
   
 		LED0_PWM_VAL=4500;	

      }
      else if (addr[j] == 1)
      {	   
       PWM_Init(18000,8);	 //����Ƶ��PWMƵ��=72000/900=444hz
   	
 	LED0_PWM_VAL=4500;//1 out	 	    	
      }
      flag++;	
    }	    	  
   }
  
	
  
	 //sync();
	



	/* out0();
	 out1();
	 out0();
	 out1();
	 out0();
	 out1();//control bit
	 out1();
	 out0();
	 out1();
	 out0();
	 out1();
	 out0();
	 out1();
	 out0();//
	 		  */  
		 
	  
     	
	
}














