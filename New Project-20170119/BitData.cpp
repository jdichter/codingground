#include "BitData.h"


void BitData::setID(int id) {
unsigned int * p = (unsigned int *)data;

*p = *p & 0x00000fff;  // clear the ID field  (leave colors 1-3)

id = (id << 12) & 0xfffff000; // id shifted with trailing zeros

*p = *p | id;  // put into data storage member

}

int BitData::getID() {

unsigned int * p = (unsigned int *)data;
return (*p) >> 12; }

void BitData::setColor1(int color) {
if (color > 15) return;

data[2] = data[2] & (char)0xf0;   // clear out low nibble of byte #3
unsigned char mask =(unsigned char)0x0f  & (unsigned char)color;
data[2] = data[2] | mask;  }


int BitData::getColor1() {
	return (unsigned int)((unsigned char)0x0f & data[2]);   }


void BitData::setColor2(int color) {
if (color > 15) return;

data[3] = data[3] & (char)0x0f;   // clear out hi nibble of byte #3
unsigned char mask =(unsigned char)0xf0  & ((unsigned char)color << 4);
data[3] = data[3] | mask;  }


int BitData::getColor2() {
return (unsigned int)(data[3] >> 4); }
