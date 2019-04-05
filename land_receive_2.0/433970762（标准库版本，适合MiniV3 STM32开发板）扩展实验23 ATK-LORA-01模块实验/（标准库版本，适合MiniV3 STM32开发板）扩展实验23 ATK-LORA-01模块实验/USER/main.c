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
 ALIENTEK Mini STM32开发板 扩展实验23
 ATK-LORA-01模块测试实验    
 技术支持：www.openedv.com
 淘宝店铺：http://eboard.taobao.com 
 关注微信公众平台微信号："正点原子"，免费获取STM32资料。
 广州市星翼电子科技有限公司  
 作者：正点原子 @ALIENTEK
************************************************/

 //主函数
 int main(void)
 { 
	u8 key,fontok=0; 
    NVIC_Configuration();	 
	delay_init();	    	         //延时函数初始化	  
	uart_init(115200);	 	         //串口初始化为9600	
    usmart_dev.init(72);		     //初始化USMART		 
				         //初始化液晶 
	LED_Init();         	         //LED初始化	 
	KEY_Init();				         //按键初始化	  													    
	//tp_dev.init();			         //触摸屏初始化
 	mem_init();				         //初始化内存池	    
 	exfuns_init();			         //为fatfs相关变量申请内存  
    f_mount(fs[0],"0:",1); 	         //挂载SD卡 
 	f_mount(fs[1],"1:",1); 	         //挂载FLASH.
	key=KEY_Scan(0);  

	//fontok=font_init();		         //检查字库是否OK
 
	Lora_Test();//主测试
}

