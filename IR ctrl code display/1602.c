
	#include <reg51.h>	//51�Ĵ����ļ�
	#include <intrins.h>
	#include"1602.h"
/****************��ʱ����************************/	
	void delay1(int ms)
	{                    //��ʱ�ӳ���
	int i;
	while(ms--)
	{
	  for(i = 0; i< 250; i++)
	  {
	   _nop_();	  //��ִ��
	   _nop_();
	   _nop_();
	   _nop_();
	  }
	}
	}

/****************��æ����************************/		
	BOOL lcd_bz()
	{                         
	BOOL result;
	LCD_RS = 0;
	LCD_RW = 1;
	LCD_EP = 1;
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	result = (BOOL)(P0 & 0x80);	 //���P0���λ�Ƿ�Ϊ1
	LCD_EP = 0;
	return result;//���ز�æ���
	}

/****************д�����************************/
		
	void lcd_wcmd_8bit(int cmd)
	{                          // д��ָ�����ݵ�LCD
	while(lcd_bz());
	LCD_RS = 0;
	LCD_RW = 0;
	LCD_EP = 0;
	_nop_();
	_nop_(); 
	P0 = cmd; //����4λλָ��ͨ��P0�ڴ���1602
	_nop_();
	_nop_(); //���ڲ���һ��������
	_nop_();
	_nop_();
	LCD_EP = 1;
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	LCD_EP = 0;  
	}	
		
	void lcd_wcmd(int cmd)
	{                          // д��ָ�����ݵ�LCD
	while(lcd_bz());
	LCD_RS = 0;
	LCD_RW = 0;
	LCD_EP = 0;
	_nop_();
	_nop_(); 
	P0 = cmd; //����4λλָ��ͨ��P0�ڴ���1602
	_nop_();
	_nop_(); //���ڲ���һ��������
	_nop_();
	_nop_();
	LCD_EP = 1;
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	LCD_EP = 0;  
	P0 = (cmd&0x0f)<<4; //����4λָ��ͨ��P0�ڴ���1602
	_nop_();
	_nop_(); //���ڲ���һ��������
	_nop_();
	_nop_();
	LCD_EP = 1;
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	LCD_EP = 0;  
	}
	
	void lcd_pos(BYTE pos)
	{                          //�趨��ʾλ��
	lcd_wcmd(pos | 0x80);
	}

/****************д���ݺ���************************/	
	void lcd_wdat(BYTE dat) 
	{                   //д���ַ���ʾ���ݵ�LCD
	while(lcd_bz());
	LCD_RS = 1;
	LCD_RW = 0;
	LCD_EP = 0;
	P0 = dat ;  //����4λ����ͨ��P0�ڴ���1602
	_nop_();
	_nop_();   //���ڲ���һ��������
	_nop_();
	_nop_();
	LCD_EP = 1;
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	LCD_EP = 0; 

	LCD_RS = 1;
	LCD_RW = 0;
	LCD_EP = 0;
		_nop_();
	_nop_();
	_nop_();
	_nop_();
	P0 = (dat&0x0f)<<4;  //����4λλ����ͨ��P0�ڴ���1602
	_nop_();
	_nop_();   //���ڲ���һ��������
	_nop_();
	_nop_();
	LCD_EP = 1;
	_nop_();
	_nop_();
	_nop_();
	_nop_();
	LCD_EP = 0; 
	}
	
	void lcd_init()					//LCD��ʼ���趨
	{ 
    lcd_wcmd_8bit(0x38);                       //16*2��ʾ��5*7����8λ����
	delay1(1);  
	lcd_wcmd_8bit(0x38);                       //16*2��ʾ��5*7����8λ����
	delay1(1);  
	lcd_wcmd_8bit(0x28);     //16*2��ʾ��5*7����8λ����
	delay1(1);  
	lcd_wcmd(0x28);
	delay1(1);
  	lcd_wcmd(0x0c);     //��ʾ�����ع��
	delay1(1);
   	lcd_wcmd(0x02);     //��ʾ�����ع��
	delay1(1);
   	lcd_wcmd(0x01);     //���LCD����ʾ����
	delay1(1);



/*	lcd_wcmd(0x38);     //16*2��ʾ��5*7����8λ����
	delay(1);
	lcd_wcmd(0x08);     //��ʾ�����ع��
	delay(1);
//	lcd_wcmd(0x04);     //�ƶ����
	delay(1);
	lcd_wcmd(0x02);     // 4λѡ��
	delay(1);
	lcd_wcmd(0x01);     //���LCD����ʾ����
	delay(1); */
	}