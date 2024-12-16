#include <REGX52.H>

void main()
{
	// P2 = 0xFE;
	// P2_0 = 0; // Light up LED D1
	// P2_0 = 1; // Turn off LED D1
	while(1)
	{
		if(P3_1 == 0 || P3_0 == 0 || P3_2 == 0 || P3_3 == 0) P2 = 0x00;
		else P2 = 0xFF;
	}
}                          