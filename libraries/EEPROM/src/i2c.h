#ifndef _I2C_H
#define _I2C_H

#include <Arduino.h>

#define I2C0  "/dev/i2c-0"
#define I2C1  "/dev/i2c-1"

#define AT24C256  0x50
#define RX8025SA  0x68


class I2C {
private:
	static int m_iUseCount;
	
	string m_sPath;
	static int m_iFile;
	unsigned int m_iDevAddr;
	
public:

	I2C();
	I2C(string bus, unsigned int dev);
	virtual unsigned char readRegister(unsigned int registerAddress);
	virtual int writeRegister(unsigned int registerAddress, unsigned char value);
	virtual ~I2C();
};


#endif 


