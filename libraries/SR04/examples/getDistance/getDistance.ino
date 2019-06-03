/* 
* Filename:    getDistance.ino
* Revision:    1.0
* Date:        2019/05/31
* Author:      hceng
* Email:       huangcheng.job@foxmail.com
* Website:     http://www.100ask.net/
* Function:    Measuring distance. 
* Notes:       none.
* Description: 
* 1. 实例化SR04；
* 2. 调用getDistance()获取距离数据，打印对应结果；
*/
#include <sr04.h>

void setup()
{
	
}

void loop()
{
	static SR04 sr04;

	cout << "distance: " << sr04.getDistance() << "cm" <<endl;
	msleep(200);
}

