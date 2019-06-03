/* 
* Filename:    Blink.ino
* Revision:    1.0
* Date:        2019/05/31
* Author:      hceng
* Email:       huangcheng.job@foxmail.com
* Website:     http://www.100ask.net/
* Function:    Turn an LED on and off.
* Notes:       Only support LED4.
* Description: 
* 1. 实例化LED，需指定LED(传入参数LED4)；
* 2. 每间隔1s，调用on()/off()，控制LED亮灭；  
*/
#include <led.h>

void setup()
{
	
}

void loop()
{
	LED led(LED4);
	
	led.on();  
	sleep(1);
		
	led.off(); 
	sleep(1);
}
