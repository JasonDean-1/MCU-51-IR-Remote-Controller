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
#define uchar unsigned char
#define uint  unsigned int

void out0(void)
{

	PWM_Init(27000,2);	 //����Ƶ��PWMƵ��=72000/900/(8+1)=888hz
 	LED0_PWM_VAL=13500;	
			//0 out
}

void out1(void)
{
	PWM_Init(54000,2);	 //����Ƶ��PWMƵ��=72000/900=444hz	
 	LED0_PWM_VAL=13500;//1 out	   	 
}
void sync(void)
{
 PWM_Init(32400,2);	 //����Ƶ��PWMƵ��=72000/900=80Khz{
	LED0_PWM_VAL=21600;
}


void button1(void)
{
  sync();
	delay_us(13500);
  out0();
	delay_us(1125);
  out0();
	delay_us(1125);
  out0();
	delay_us(1125);
  out0();
	delay_us(1125);
  out0();
	delay_us(1125);
  out0();
	delay_us(1125);
  out0();
	delay_us(1125);
  out0();
	delay_us(1125);//address
  out1();
	delay_us(2250);
	 out1();
	delay_us(2250);
	 out1();
	delay_us(2250);
	 out1();
	delay_us(2250);
	 out1();
	delay_us(2250);
	 out1();
	delay_us(2250);
	 out1();
	delay_us(2250);
	 out1();
	delay_us(2250);//address-complement
	out0();
	delay_us(1125);
  out0();
	delay_us(1125);
  out0();
	delay_us(1125);
  out0();
	delay_us(1125);
  out0();
	delay_us(1125);
  out0();
	delay_us(1125);
  out0();
	delay_us(1125);
  out0();
	delay_us(1125);//control
  out1();
	delay_us(2250);
	 out1();
	delay_us(2250);
	 out1();
	delay_us(2250);
	 out1();
	delay_us(2250);
	 out1();
	delay_us(2250);
	 out1();
	delay_us(2250);
	 out1();
	delay_us(2250);
	out1();
	delay_us(2250);//control-complement
	out1();
	delay_us(2250);//stop
}


void button2(void)
{
  sync();
	delay_us(13500);
  out0();
	delay_us(1125);
  out0();
	delay_us(1125);
  out0();
	delay_us(1125);
  out0();
	delay_us(1125);
  out0();
	delay_us(1125);
  out0();
	delay_us(1125);
  out0();
	delay_us(1125);
  out1();
	delay_us(1125);//address
  out1();
	delay_us(2250);
	 out1();
	delay_us(2250);
	 out1();
	delay_us(2250);
	 out1();
	delay_us(2250);
	 out1();
	delay_us(2250);
	 out1();
	delay_us(2250);
	 out1();
	delay_us(2250);
	 out0();
	delay_us(2250);//address-complement
	out0();
	delay_us(1125);
  out0();
	delay_us(1125);
  out0();
	delay_us(1125);
  out0();
	delay_us(1125);
  out0();
	delay_us(1125);
  out0();
	delay_us(1125);
  out0();
	delay_us(1125);
  out1();
	delay_us(1125);//control
  out1();
	delay_us(2250);
	 out1();
	delay_us(2250);
	 out1();
	delay_us(2250);
	 out1();
	delay_us(2250);
	 out1();
	delay_us(2250);
	 out1();
	delay_us(2250);
	 out1();
	delay_us(2250);
	out0();
	delay_us(2250);//control-complement
	out1();
	delay_us(2250);//stop
}


void button3(void)
{
  sync();
	delay_us(13500);
  out0();
	delay_us(1125);
  out0();
	delay_us(1125);
  out0();
	delay_us(1125);
  out0();
	delay_us(1125);
  out0();
	delay_us(1125);
  out0();
	delay_us(1125);
  out1();
	delay_us(1125);
  out1();
	delay_us(1125);//address
  out1();
	delay_us(2250);
	 out1();
	delay_us(2250);
	 out1();
	delay_us(2250);
	 out1();
	delay_us(2250);
	 out1();
	delay_us(2250);
	 out1();
	delay_us(2250);
	 out0();
	delay_us(2250);
	 out0();
	delay_us(2250);//address-complement
	out0();
	delay_us(1125);
  out0();
	delay_us(1125);
  out0();
	delay_us(1125);
  out0();
	delay_us(1125);
  out0();
	delay_us(1125);
  out0();
	delay_us(1125);
  out1();
	delay_us(1125);
  out1();
	delay_us(1125);//control
  out1();
	delay_us(2250);
	 out1();
	delay_us(2250);
	 out1();
	delay_us(2250);
	 out1();
	delay_us(2250);
	 out1();
	delay_us(2250);
	 out1();
	delay_us(2250);
	 out0();
	delay_us(2250);
	out0();
	delay_us(2250);//control-complement
	out1();
	delay_us(2250);//stop
}


unsigned char i;



int main(void)
{ unsigned int key; 
  unsigned char code1[32]={1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
 	Stm32_Clock_Init(9); //ϵͳʱ������
	delay_init(72);	     //��ʱ��ʼ��
	uart_init(72,9600);  //���ڳ�ʼ�� 
	LED_Init();
	while(1)
   {
	switch(key)
		 {
		 case 1,
		 }
   }		  	 
 
}

























