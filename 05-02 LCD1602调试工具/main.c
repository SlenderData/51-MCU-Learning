#include <REGX52.H>
#include "LCD1602.h"

void main()
{
	LCD_Init();
	LCD_ShowString(1, 1, "I was born");
	LCD_ShowString(2, 9, "in 1989!");
	while(1)
	{
		
	}
}