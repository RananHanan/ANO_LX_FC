#include "NiMing_UpperComputer.h"

#include "Drv_Uart.h"

//在SysConfig.h有定义            数据拆分
//#define BYTE0(dwTemp)   (*(char *)(&dwTemp))       //定义数据拆分
//#define BYTE1(dwTemp)   (*((char *)(&dwTemp)+1))
//#define BYTE2(dwTemp)   (*((char *)(&dwTemp)+2))
//#define BYTE3(dwTemp)   (*((char *)(&dwTemp)+3))

uint8_t DataSend[30];

void ANODT_SendF4(int Data_A,int Data_B,int Data_C,int Data_D)
{
	uint8_t data_cnt=0;
	//帧头 地址
	DataSend[data_cnt++]=0xAA;
	DataSend[data_cnt++]=0xFF;
	//功能码 数据长度
	DataSend[data_cnt++]=0xF1;
	DataSend[data_cnt++]=0x08;
	
	DataSend[data_cnt++]=BYTE0(Data_A);
	DataSend[data_cnt++]=BYTE1(Data_A);
	
	DataSend[data_cnt++]=BYTE0(Data_B);
	DataSend[data_cnt++]=BYTE1(Data_B);
	
	DataSend[data_cnt++]=BYTE0(Data_C);
	DataSend[data_cnt++]=BYTE1(Data_C);
	
	DataSend[data_cnt++]=BYTE0(Data_D);
	DataSend[data_cnt++]=BYTE1(Data_D);
	
	uint8_t sc = 0;
    uint8_t ac = 0;
    for(uint8_t i=0;i<DataSend[3]+4;i++)
    {
        sc +=DataSend[i];
        ac +=sc;
    }
    DataSend[data_cnt++] = sc;//和校验位
    DataSend[data_cnt++] = ac;//附加 校验位

    DrvUart1SendBuf(DataSend,DataSend[3]+6);
}

void ANODT_SendF1(int Data_A)
{
	uint8_t data_cnt=0;
	
	//帧头 地址
	DataSend[data_cnt++]=0xAA;
	DataSend[data_cnt++]=0xFF;
	//功能码 数据长度
	DataSend[data_cnt++]=0xF1;
	DataSend[data_cnt++]=0x02;
	
	DataSend[data_cnt++]=BYTE0(Data_A);
	DataSend[data_cnt++]=BYTE1(Data_A);
	
	uint8_t sc = 0;
    uint8_t ac = 0;
	for(uint8_t i=0;i<DataSend[3]+4;i++)
    {
        sc +=DataSend[i];
        ac +=sc;
    }
    DataSend[data_cnt++] = sc;//和校验位
    DataSend[data_cnt++] = ac;//附加 校验位

    DrvUart1SendBuf(DataSend,DataSend[3]+6);
}
