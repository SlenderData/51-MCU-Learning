#include <REGX52.H>
#include <INTRINS.H>

unsigned char NumTable[] = {0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x6F, 0x00};

void Delay(unsigned int xms)	//@11.0592MHz
{
	unsigned char data i, j;
	while(xms--)
	{
		_nop_();
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);
	}
}

void DigitalDisplay(unsigned char Location, Number, Dot)
{
	if(Location > 7 || Number > 10) return;
	P2 = ~(4 * Location);
	P0 = NumTable[Number];
	if(Dot) P0 += 0x80;
	Delay(1);
}

void main()
{
	while(1)
	{
		DigitalDisplay(0,1,0);
		DigitalDisplay(1,1,0);
		DigitalDisplay(2,4,1);
		DigitalDisplay(3,5,0);
		DigitalDisplay(4,1,0);
		DigitalDisplay(5,4,0);
	}
}