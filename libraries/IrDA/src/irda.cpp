
#include "irda.h"

IRDA::IRDA()
{	
	this->m_iPin = 0*32+6;
	this->m_sPath = IRDA_PATH;
	
	this->m_iFileIRDA = open(this->m_sPath.c_str(), O_RDWR);
	if (this->m_iFileIRDA < 0)
		perror("IRDA: can't open device");

	if(ioctl(this->m_iFileIRDA, IRDA_IOCINIT, &this->m_iPin) < 0) 
		perror("IRDA: Failed to init to the device\n");
	
	this->m_iFileEvent = open(IRDA_EVENT_PATH, O_RDONLY);  
    if (this->m_iFileEvent < 0) {  
        perror("IRDA: open file failed\n");  
    }  
}

IRDA::IRDA(int pin)
{	
	this->m_iPin = pin;
	this->m_sPath = IRDA_PATH;
	
	this->m_iFileIRDA = open(this->m_sPath.c_str(), O_RDWR);
	if (this->m_iFileIRDA < 0)
		perror("IRDA: can't open device");

	if(ioctl(this->m_iFileIRDA, IRDA_IOCINIT, &this->m_iPin) < 0) 
		perror("IRDA: Failed to init to the device\n");
	
	this->m_iFileEvent = open(IRDA_EVENT_PATH, O_RDONLY);  
    if (this->m_iFileEvent < 0) {  
        perror("IRDA: open file failed\n");  
    }  
}

IRDA::~IRDA(void)
{
	close(this->m_iFileIRDA);
	close(this->m_iFileEvent);
}


int IRDA::readKey(void)
{
	int ret;
	struct input_event ev;
	
	ret = read(this->m_iFileEvent , &ev, sizeof(struct input_event));  
	if (ret < 0) {  
		perror("IRDA: read event error!\n");  
	}  
		
	if (ev.type == EV_KEY) 
	{
		this->code  = ev.code;
		this->value = ev.value;
		
		//cout<<"code:"<<this->code<<endl;
		//cout<<"value:"<<this->value<<endl;
	}

	return 0;
}
