#ifndef POWER_H_
#define POWER_H_
/*
	This is a small utility for interacting with the AXP209 in the chip by nextThing.co
	By Ben V. Brown <ralim@ralimtek.com>
	You will need to install the i2c tools package :
	apt-get install i2c-tools libi2c-dev

*/
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

const char *registerMessagesOn[][8] = {
	{"Boot Power Source was ACIN/VBUS","ACIN/VBUS is shorted","Battery is charging","VBus is above VHold","VBus is usable","VBus exists","ACIN is available","ACIN Exists"},
	{"","","Charge current is less than desired","Charger is in cell activated mode","","Battery Connected","Battery is Charging","Over temperature"},
	{"Session end satus : Valid","VBUS is valid","VBUS is valid","","","","",""}
};
const char *registerMessagesOff[][8] = {
	{"Boot Power Source was not ACIN/VBUS","ACIN/VBUS is not shorted","Battery is not charging","VBus is below VHold","VBus is not usable","VBus does not exist","ACIN is not available","ACIN does not exist"},
	{"","","Charging current is in regulation","Charger is not in cell activated mode","","No Battery Connected","Battery is not Charging","No Over Temp"},
	{"Session end satus : Invalid","VBUS is not valid","VBUS is not valid","","","","",""}
};
const char *registerNames[] = {
	"Input Power Status",
	"Power Mode and charge status",
	"USB OTG VBUS Status"
};

char readReg(int file,char address);
void printREG(int file,int reg);
#endif //POWER_H_
