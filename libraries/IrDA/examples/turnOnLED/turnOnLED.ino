/* 
* Filename:    turnOnLED.ino
* Revision:    1.0
* Date:        2019/05/31
* Author:      hceng
* Email:       huangcheng.job@foxmail.com
* Website:     http://www.100ask.net/
* Function:    turn On LED4. 
* Notes:       none.
* Description: 
* 1. 实例化LED，定义为静态类型(防止循环里反复实例化导致LED亮)；
* 2. 实例IRDA；
* 3. 调用readKey()读取按键状态；
* 4. 如果KEY_1按下，或者长按，打开LED4;
*/
#include <led.h>
#include <irda.h>

void setup()
{
	
}

void loop()
{
	static LED led(LED4); //定义为静态类型(防止循环里反复实例化导致LED亮)

	static IRDA irda;
	irda.readKey();
	
	//如果KEY_1按下，或者长按，打开LED4
	if((irda.code == KEY_1) && (irda.value == 1 || irda.value == 2)) 
		led.on();
	else
		led.off();
}
