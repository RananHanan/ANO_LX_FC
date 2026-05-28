#include "stm32f4xx.h"
#include "SysConfig.h"
#include "Drv_Uart.h"
#include "ANO_DT_LX.h"
#include "Drv_Uart.h"

#include "computer.h"


static u8 COM_RxBuffer[100], COM_data_cnt = 0;
void Computer_GetByte(u8 data)
{
  //长度只是被用来赋值后,方便数据区的数据接收，而cnt是用来接收数据的地址偏移
	static u8 _data_len = 0, _data_cnt = 0;
	//state 是用来判断数据接收状态。
	static u8 rxstate = 0;

	//判断帧头是否满足匿名协议的0xAA
	if (rxstate == 0 && data == 0xAA)
	{
		rxstate = 1;
		COM_RxBuffer[0] = data;
	}
	//判断是不是发送给本模块的数据或者是广播数据
	else if (rxstate == 1 && (data == HW_TYPE || data == HW_ALL))//可以根据自己自定义的  地址来改写
	{
		rxstate = 2;
		COM_RxBuffer[1] = data;
	}
	//接收帧CMD字节
	else if (rxstate == 2)
	{
		rxstate = 3;
		COM_RxBuffer[2] = data;
	}
	//接收数据长度字节
	else if (rxstate == 3 && data < 250)
	{
		rxstate = 4;
		COM_RxBuffer[3] = data;
		_data_len = data;
		
		_data_cnt = 0;//数据接收地址偏移
	}
	//接收数据区
	else if (rxstate == 4 && _data_len > 0)
	{
		_data_len--;
		COM_RxBuffer[4 + _data_cnt++] = data;
		if (_data_len == 0){rxstate = 5;}
			
	}
	//接收校验字节1
	else if (rxstate == 5)
	{
		rxstate = 6;
		COM_RxBuffer[4 + _data_cnt++] = data;
	}
	//接收校验字节2，表示一帧数据接收完毕，调用数据解析函数
	else if (rxstate == 6)
	{
		rxstate = 0;
		COM_RxBuffer[4 + _data_cnt] = data;
		COM_data_cnt = _data_cnt + 5;
		
	
		//COM_dt_data_ok = 1;
		Computer_Receiver_anl(COM_RxBuffer, COM_data_cnt);
		//DrvUart1SendBuf(COM_RxBuffer, COM_data_cnt);
		
	}
	else
	{
		rxstate = 0;
	}
}



void Computer_Receiver_anl(u8 *data, u8 len)
{
	//对数据进行解析，分别对数据区长度、校验位、帧头和地址进行验证。
	u8 sc=0,ac=0;
	if(*(data + 3)!=(len - 6))
		return;
	for(int i=0;i<len-2;i++)
	{
		sc+=*(data+i);
		ac+=sc;
	}
	if((sc!=*(data + len - 2))||(ac!=*(data + len - 1)))
		return;
	if(*(data) != 0xAA|| ( *(data+1) != 0xFF && *(data+1) != 0x11) )
		return;
	
	//验证完后，开始对数据进行处理。
	//安装发的数据的格式
	//lr: flag  x y z ....对数据进行处理
	if(*(data+2)==0x00)
	{
		
		
	}	
}
