/* 
* Filename:    getSignal.ino
* Revision:    1.0
* Date:        2019/05/31
* Author:      hceng
* Email:       huangcheng.job@foxmail.com
* Website:     http://www.100ask.net/
* Function:    Check If Someone. 
* Notes:       none.
* Description: 
* 1. 实例化R501；
* 2. 调用getSignal()判断是否有人，打印对应结果；
*/
#include <sr501.h>

void setup()
{
	
}

void loop()
{
	static SR501 sr501;

	if(sr501.getSignal() == 1)
	{
		cout << "Detected someone!" <<endl;
		while(sr501.getSignal() == 0);
	}
	else
		cout << "No one detected!" <<endl;
	
	msleep(200);  
}

