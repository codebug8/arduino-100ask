
#include <linux/input.h>
#include <signal.h>
#include "adxl345.h"

static int spi_cs = -1;
static int spidev0_fd = -1;
static int spidev1_fd = -1;

static void func1(int signal)
{
	struct adxl34x_info_msg ad_info_msg;
	
	ad_info_msg.chip_select = spi_cs;
	if (spi_cs == 0)
		ad_info_msg.irq_pin = 12;
	else 
		ad_info_msg.irq_pin = 12; //待改为两一个SPI接口对应的GPIO	
	
	if (spidev0_fd > 0)
	{
		if(ioctl(spidev0_fd, ADXL34X_IOCEXIT, &ad_info_msg) < 0) 
			perror("ADXL34X: Failed to exit to the device\n");
		spidev0_fd = -1;
	}
	
	if (spidev1_fd > 0)
	{
		if(ioctl(spidev1_fd, ADXL34X_IOCEXIT, &ad_info_msg) < 0) 
			perror("ADXL34X: Failed to exit to the device\n");
		spidev1_fd = -1;
	}
	
	exit(0);
}

ADXL345::ADXL345(int num) : m_iCS(num - 1)
{
	struct adxl34x_info_msg ad_info_msg;
	ad_info_msg.chip_select = this->m_iCS;
	if (this->m_iCS == 0)
		ad_info_msg.irq_pin = 12;
	else 
		ad_info_msg.irq_pin = 12; //待改为两一个SPI接口对应的GPIO
	
	this->m_iAdxl345File = open("/dev/adxl345", O_RDWR);
	if (this->m_iAdxl345File < 0)
		perror("ADXL345: can't open device");
    
	if(ioctl(this->m_iAdxl345File, ADXL34X_IOCINIT, &ad_info_msg) < 0) 
		perror("ADXL345: Failed to init to the device\n");

	
	//解决CTRL+C 退出时，没有清除adxl345的片选
	spi_cs = this->m_iCS;
	if (spi_cs == 0)
		spidev0_fd= this->m_iAdxl345File;
	else if (spi_cs == 1)
		spidev1_fd= this->m_iAdxl345File;
	signal(SIGINT, func1);
	signal(SIGTERM, func1);	
	signal(SIGKILL, func1);	//无法捕获kill -9 ,应用层不能kill -9 退出，不然会导致/dev/spidev1.x没有释放	
	
	
	this->m_sPath = ADXL345_EVENT_PATH;
	
	this->m_iEventFile = open(ADXL345_EVENT_PATH, O_RDONLY);  
    if (this->m_iEventFile < 0) {  
        perror("ADXL345: open file failed\n");  
    }  
}

int ADXL345::readData(void)
{
	int ret;
	struct input_event ev;
	
	ret = read(this->m_iEventFile , &ev, sizeof(struct input_event));  
	if (ret < 0) {  
		perror("IRDA: read event error!\n");  
	}  
		
	if (ev.type == EV_KEY) 
	{
		this->touch_value = ev.value;
		//cout<<"code:"<<ev.code<<"value:"<<ev.value<<endl; //BTN_TOUCH
	}
	
	if (ev.type == EV_ABS) 
	{
		if (ev.code == 0)
			this->x_value =  ev.value;
		else if (ev.code == 1)
			this->y_value =  ev.value;
		else if (ev.code == 2)
			this->z_value =  ev.value;
		
		//cout<<"code:"<<ev.code<<"value:"<<ev.value<<endl; //BTN_TOUCH
	}
	
	return 0;
}

ADXL345::~ADXL345()
{
	struct adxl34x_info_msg ad_info_msg;
	
	ad_info_msg.chip_select = spi_cs;
	if (spi_cs == 0)
		ad_info_msg.irq_pin = 12;
	else 
		ad_info_msg.irq_pin = 12; //待改为两一个SPI接口对应的GPIO	
	
	if (spidev0_fd > 0)
	{
		if(ioctl(spidev0_fd, ADXL34X_IOCEXIT, &ad_info_msg) < 0) 
			perror("ADXL34X: Failed to exit to the device\n");
		spidev0_fd = -1;
	}
	
	if (spidev1_fd > 0)
	{
		if(ioctl(spidev1_fd, ADXL34X_IOCEXIT, &ad_info_msg) < 0) 
			perror("ADXL34X: Failed to exit to the device\n");
		spidev1_fd = -1;
	}
}
