#ifndef __NIMING_UPPERCOMPUTER_H
#define __NIMING_UPPERCOMPUTER_H

#include "stdint.h"

//在SysConfig.h有定义            数据拆分
//#define BYTE0(dwTemp)   (*(char *)(&dwTemp))       //定义数据拆分
//#define BYTE1(dwTemp)   (*((char *)(&dwTemp)+1))
//#define BYTE2(dwTemp)   (*((char *)(&dwTemp)+2))
//#define BYTE3(dwTemp)   (*((char *)(&dwTemp)+3))

void ANODT_SendF4(int Data_A,int Data_B,int Data_C,int Data_D);
void ANODT_SendF1(int Data_A);	

#endif
