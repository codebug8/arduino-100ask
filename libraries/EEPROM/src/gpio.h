#ifndef GPIO_H
#define GPIO_H

#include <Arduino.h>

class GPIO {
	private:
		int m_iPin;
		string m_sPath;
		
	public:
		GPIO(void);
		GPIO(int pin);
		
		void setPin(int pin);
		int getPin(void);	
		
		void setPath(int pin);
		string getPath(void);
		
		int setDirection(int dir);
		int getDirection(void);
		
		int setValue(int val);
		int getValue(void);
		
		int exportGPIO(void);
		int unexportGPIO(void);
};

#endif