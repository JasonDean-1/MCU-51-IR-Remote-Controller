
   	typedef unsigned char BYTE;	//��BYTE����unsigned char 
	typedef bit BOOL;  // ��BOOL����bit 
		
	sbit LCD_RS = P2^6;  //��λ��            
	sbit LCD_RW = P2^5;	 //д���ݶ�
	sbit LCD_EP = P2^7;	 //ʹ�ܶ�

	void delay1(int ms);
	BOOL lcd_bz();
	void lcd_wcmd(int cmd);
	void lcd_pos(BYTE pos);
	void lcd_wdat(BYTE dat);
	void lcd_init();