#include <REGX52.H>
#include <INTRINS.H>

void Delay1ms(unsigned int xms)	//@11.0592MHz
{
	unsigned char data i, j;
	while(xms)
	{
		_nop_();
		i = 2;
		j = 199;
		do
		{
			while (--j);
		} while (--i);
		xms -= 1;
	}
}

void LightUpOneSingleLED(unsigned int number)
{
	if(number == 1) P2 = 0xFE;
	else if(number == 2) P2 = 0xFD;
	else if(number == 3) P2 = 0xFB;
	else if(number == 4) P2 = 0xF7;
	else if(number == 5) P2 = 0xEF;
	else if(number == 6) P2 = 0xDF;
	else if(number == 7) P2 = 0xBF;
	else if(number == 8) P2 = 0x7F;
}

void main()
{
	unsigned int i, time, reverse;
	reverse = 0;
	time = 500;
	while(1)
	{
		if(reverse)
		{
			for(i = 8; i >= 1; i--)
			{
				LightUpOneSingleLED(i);
				Delay1ms(time);
			}
		}
		else
		{
			for(i = 1; i <= 8; i++)
			{
				LightUpOneSingleLED(i);
				Delay1ms(time);
			}
		}
	}
}