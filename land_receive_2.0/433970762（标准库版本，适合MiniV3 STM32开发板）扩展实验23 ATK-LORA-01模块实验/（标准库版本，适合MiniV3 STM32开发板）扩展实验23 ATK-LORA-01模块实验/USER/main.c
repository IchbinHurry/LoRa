#include "led.h"
#include "delay.h"
#include "sys.h"
#include "usart.h"
#include "lcd.h"
#include "key.h"
#include "usmart.h" 
#include "malloc.h"  
#include "MMC_SD.h" 
#include "ff.h"  
#include "exfuns.h"
#include "fontupd.h"
#include "text.h"		
#include "touch.h"	
#include "usart2.h"	
#include "lora_app.h"
/************************************************
 ALIENTEK Mini STM32������ ��չʵ��23
 ATK-LORA-01ģ�����ʵ��    
 ����֧�֣�www.openedv.com
 �Ա����̣�http://eboard.taobao.com 
 ��ע΢�Ź���ƽ̨΢�źţ�"����ԭ��"����ѻ�ȡSTM32���ϡ�
 ������������ӿƼ����޹�˾  
 ���ߣ�����ԭ�� @ALIENTEK
************************************************/

 //������
 int main(void)
 { 
	u8 key,fontok=0; 
    NVIC_Configuration();	 
	delay_init();	    	         //��ʱ������ʼ��	  
	uart_init(115200);	 	         //���ڳ�ʼ��Ϊ9600	
    usmart_dev.init(72);		     //��ʼ��USMART		 
				         //��ʼ��Һ�� 
	LED_Init();         	         //LED��ʼ��	 
	KEY_Init();				         //������ʼ��	  													    
	//tp_dev.init();			         //��������ʼ��
 	mem_init();				         //��ʼ���ڴ��	    
 	exfuns_init();			         //Ϊfatfs��ر��������ڴ�  
    f_mount(fs[0],"0:",1); 	         //����SD�� 
 	f_mount(fs[1],"1:",1); 	         //����FLASH.
	key=KEY_Scan(0);  

	//fontok=font_init();		         //����ֿ��Ƿ�OK
 
	Lora_Test();//������
}

