#ifndef Arduino_h
#define Arduino_h

#include <unistd.h>
#include <fcntl.h>
#include <stdio.h> 

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <sstream>
#include <fstream>

#include <iomanip>
#include <getopt.h>

#include <sys/ioctl.h>
#include <linux/input.h>

#include <sys/time.h>

#include <stdint.h>



#define msleep(n) usleep(n*1000)

using namespace std;

#endif
