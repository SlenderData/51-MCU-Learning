#include <REGX52.H>
#include "Delay.h"

/**
  * @brief  矩阵键盘读取按键键码
  * @param  无
  * @retval KeyNumber 按下按键的键码值
  * @note   如果按键按下不放，程序会停留在此函数
  * @note   松手的一瞬间，返回按键键码
  * @note   没有按键按下时，返回 `0`
  */

unsigned char MatrixKey()
{
	unsigned char KeyNumber = 0;
	
	// 扫描第 1 列按键
	P1 = 0xFF;
	P1_3 = 0;
	if(P1_7 == 0) {Delay(20); while(P1_7 == 0); Delay(20); KeyNumber = 1;}
	if(P1_6 == 0) {Delay(20); while(P1_6 == 0); Delay(20); KeyNumber = 5;}
	if(P1_5 == 0) {Delay(20); while(P1_5 == 0); Delay(20); KeyNumber = 9;}
	if(P1_4 == 0) {Delay(20); while(P1_4 == 0); Delay(20); KeyNumber = 13;}
	
	// 扫描第 2 列按键
	P1 = 0xFF;
	P1_2 = 0;
	if(P1_7 == 0) {Delay(20); while(P1_7 == 0); Delay(20); KeyNumber = 2;}
	if(P1_6 == 0) {Delay(20); while(P1_6 == 0); Delay(20); KeyNumber = 6;}
	if(P1_5 == 0) {Delay(20); while(P1_5 == 0); Delay(20); KeyNumber = 10;}
	if(P1_4 == 0) {Delay(20); while(P1_4 == 0); Delay(20); KeyNumber = 14;}
	
	// 扫描第 3 列按键
	P1 = 0xFF;
	P1_1 = 0;
	if(P1_7 == 0) {Delay(20); while(P1_7 == 0); Delay(20); KeyNumber = 3;}
	if(P1_6 == 0) {Delay(20); while(P1_6 == 0); Delay(20); KeyNumber = 7;}
	if(P1_5 == 0) {Delay(20); while(P1_5 == 0); Delay(20); KeyNumber = 11;}
	if(P1_4 == 0) {Delay(20); while(P1_4 == 0); Delay(20); KeyNumber = 15;}
	
	// 扫描第 4 列按键
	P1 = 0xFF;
	P1_0 = 0;
	if(P1_7 == 0) {Delay(20); while(P1_7 == 0); Delay(20); KeyNumber = 4;}
	if(P1_6 == 0) {Delay(20); while(P1_6 == 0); Delay(20); KeyNumber = 8;}
	if(P1_5 == 0) {Delay(20); while(P1_5 == 0); Delay(20); KeyNumber = 12;}
	if(P1_4 == 0) {Delay(20); while(P1_4 == 0); Delay(20); KeyNumber = 16;}
	
	return KeyNumber;
}