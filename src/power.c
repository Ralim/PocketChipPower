#include <errno.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/i2c-dev.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
char readReg(int file,char address);
void printREG0(int file);


int main(int argc, char *argv[])
{
int file;
char *filename = "/dev/i2c-0";
if ((file = open(filename, O_RDWR)) < 0) {
    perror("Failed to open the i2c bus");
    exit(1);
}
printf("Bus Opened\r\n");
if (ioctl(file,I2C_SLAVE_FORCE,0x34) < 0) {
        printf("Failed to acquire bus access and/or talk to slave.\n");
        exit(1);
    }
printf("Slave Opened\r\n");
if(argc >1)
{
	for(int i=1;i<argc;i++)
	{
		switch(argv[i][0])
		{
		case 'I':
			printREG0(file);
		break;
		default:
		break;
		}
	}
}
//printREG0(file);
close(file);
}

char readReg(int file,char address)
{
char buffer[1]={0};
buffer[0]=address;
if(i2c_smbus_write_byte(file,address)<0)
{ 

printf("Error writing the address: %d \r\n",(write(file,buffer,1)));
}
	if(read(file,buffer,1)==1)
		return buffer[0];
	else
	{
	printf("Error reading register\r\n");		
	return 0;
	}
}
void printREG0(int file)
{
char reg = readReg(file,0);
if(reg &&(1<<0))
	printf("Boot Power Source was ACIN/VBUS\r\n");

if(reg && (1<<1))
	printf("ACIN/VBUS is shorted\r\n");
if(reg && (1<<2))
	printf("Battery is charging\r\n");
else
	printf("Battery is not charging\r\n");
if(reg && (1<<3))
	printf("VBus is above VHold\r\n");
if(reg && (1<<4))
	printf("VBus is useable\r\n");
if(reg && (1<<5))
	printf("VBus exists\r\n");
if(reg && (1<<6))
	printf("ACIN is available\r\n");
if(reg && (1<<7))
	printf("ACIN Exists");
}
