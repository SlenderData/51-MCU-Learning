#include <REGX52.H>
#include "Delay.h"

unsigned char NumTable[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x00};

void DigitalDisplay(unsigned char Location, Number, Dot)
{
	if(Location > 7 || Number > 10) return;
	P2 = ~(4 * Location);
	P0 = NumTable[Number];
	if(Dot) P0 += 0x80;
	Delay(1);
}