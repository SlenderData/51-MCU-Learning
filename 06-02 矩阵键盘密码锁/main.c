#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"

unsigned char KeyNum;  // 当前矩阵键盘按键
unsigned char Password[16];  // 与课程视频不同的数组实现，不受密码位数限制
unsigned char *PasswordPtr = Password;  // 指向当前输入的密码位的指针
unsigned char CorrectPassword[] = "114514";  // 正确密码

// 密码输入，成功返回 true，失败返回 false
bool AddPassword(unsigned char InputNum)
{
	if(InputNum > 10) return false;  // 大于 10 时均为非数字输入
	if(PasswordPtr >= Password + 16) return false;  // 超出LCD显示范围
	*PasswordPtr = InputNum;
	PasswordPtr++;
	LCD_ShowString(2, 1, "                ");  // 清空密码显示
    for(unsigned char i = 0; i < PasswordPtr - Password; i++)  // 显示密码
	{
		LCD_ShowNum(2, 1 + i, Password[i], 1);
	}
	return true;
}

// 退格，成功返回 true，失败返回 false
bool Backspace(unsigned char InputKey)
{
	if(InputKey != 12) return false;  // 非退格键
	if(PasswordPtr == Password) return false;  // 无密码可退格
	PasswordPtr--;
	LCD_ShowString(2, 1, "                ");  // 清空密码显示
	for(unsigned char i = 0; i < PasswordPtr - Password; i++)  // 显示密码
	{
		LCD_ShowNum(2, 1 + i, Password[i], 1);
	}
	return true;
}

// 检查密码是否正确，成功检查返回 true，失败返回 false
bool CheckPassword(unsigned char InputKey)
{
	if(InputKey != 11) return false;  // 非确认键
	if(PasswordPtr - Password != sizeof(CorrectPassword) - 1)  // 密码位数不符
	{
		LCD_ShowString(2, 1, "                ");  // 清空密码显示
		LCD_ShowString(2, 1, "Wrong!");  // 显示密码错误提示
		return true;
	}
	for(unsigned char i = 0; i < sizeof(CorrectPassword) - 1; i++)
	{
		if(Password[i] != CorrectPassword[i])  // 密码错误
		{
			LCD_ShowString(2, 1, "                ");  // 清空密码显示
			LCD_ShowString(2, 1, "Wrong!");  // 显示密码错误提示
			return true;
		}
	}
	LCD_ShowString(2, 1, "                ");  // 清空密码显示
	LCD_ShowString(2, 1, "Correct!");  // 显示密码正确提示
	return true;
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