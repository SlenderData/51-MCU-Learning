#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"

unsigned char KeyNum;  // 当前矩阵键盘按键
unsigned char Password[16];  // 与课程视频不同的数组实现，不受密码位数限制
unsigned char *PasswordPtr = Password;  // 指向当前输入的密码位的指针
unsigned char CorrectPassword[] = "1145141919810";  // 正确密码
unsigned char i;  // 用于循环

// 密码输入，成功返回 1，失败返回 0
// 不可以使用 bool 类型，编译器不支持
unsigned char AddPassword(unsigned char InputNum)
{
	if(InputNum > 10) return 0;  // 大于 10 时均为非数字输入
	if(PasswordPtr >= Password + 16) return 0;  // 超出LCD显示范围
	*PasswordPtr = (InputNum == 10) ? 0 : InputNum;  // 按键 10 代表 0
	PasswordPtr++;
	LCD_ShowString(2, 1, "                ");  // 清空密码显示
	for(i = 0; i < PasswordPtr - Password; i++)  // 显示密码
	{
		LCD_ShowNum(2, 1 + i, Password[i], 1);
	}
	return 1;
}

// 退格，成功返回 1，失败返回 0
unsigned char Backspace(unsigned char InputKey)
{
	if(InputKey != 12) return 0;  // 非退格键
	if(PasswordPtr == Password) return 0;  // 无密码可退格
	PasswordPtr--;
	LCD_ShowString(2, 1, "                ");  // 清空密码显示
	for(i = 0; i < PasswordPtr - Password; i++)  // 显示密码
	{
		LCD_ShowNum(2, 1 + i, Password[i], 1);
	}
	return 1;
}

// 检查密码是否正确，成功检查返回 1，失败返回 0
unsigned char CheckPassword(unsigned char InputKey)
{
	if(InputKey != 11) return 0;  // 非确认键
	if((PasswordPtr - Password) != (sizeof(CorrectPassword) - 1))  // 密码位数不符
	{
		LCD_ShowString(1, 10, "  Wrong");  // 显示密码错误提示
		return 1;
	}
	for(i = 0; i < sizeof(CorrectPassword) - 1; i++)
	{
		if(Password[i] != (CorrectPassword[i] - '0'))  // 密码错误
		{
			LCD_ShowString(1, 10, "  Wrong");  // 显示密码错误提示
			return 1;
		}
	}
	LCD_ShowString(1, 10, "Correct");  // 显示密码正确提示
	return 1;
}

// 主函数
void main()
{
	LCD_Init();
	LCD_ShowString(1, 1, "Password:");
	while(1)
	{
		KeyNum = MatrixKey();
		if(KeyNum)
		{
			if(AddPassword(KeyNum)) continue;
			if(Backspace(KeyNum)) continue;
			if(CheckPassword(KeyNum));
		}
	}
}