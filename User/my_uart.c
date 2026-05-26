//////////////////////////////////////////////////////////////////////
/*
´®¿ÚÍ¨ĞÅ
*/
//////////////////////////////////////////////////////////////////////

#include "my_uart.h"
#include "Drv_Uart.h"

int16_t test_data_1,test_data_2;
int16_t OpenMV_data_0,OpenMV_data_1,OpenMV_data_2;

static u8 Openmv_Rxbuf[50]={0};
	
void My_uart1_Recive(uint8_t data)
{
    static int data_cnt=0;
    static uint8_t data_1,data_2,data_3,data_4;

    if((data==0x0A)&&(data_cnt==0))
    {
        data_cnt=1;
    }
    else if(data_cnt==1)
    {
        data_1=data;
        data_cnt=2;
    }
    else if(data_cnt==2)
    {
        data_2=data;
        data_cnt=3;
    }
    else if(data_cnt==3)
    {
        data_3=data;
        data_cnt=4;
    }
    else if(data_cnt==4)
    {
        data_4=data;
        data_cnt=0;
    }
    test_data_1=data_2;
    test_data_1<<=8;
    test_data_1|=data_1;
    test_data_2=data_4;
    test_data_2<<=8;
    test_data_2|=data_3;   
}

void My_uart2_Send(void)
{
    u8 Buf[]={1,0x0A};
    DrvUart2SendBuf(Buf,sizeof(Buf));
}

void MY_uart2_Recive(uint8_t data)
{
	static int data_cnt=0;
	static uint8_t data_1,data_2,data_3,data_4,data_5,data_6,data_7,data_8,data_9,data_10,data_11,data_12,data_13;
	
	if((data_cnt==0)&&(data==0xAA))
	{
		data_cnt=1;
	}
	//aa
	else if(data_cnt==1)
	{
		data_1=data;
		data_cnt=2;
	}
	//ff
	else if(data_cnt==2)
	{
		data_2=data;
		data_cnt=3;
	}
	//id
	else if(data_cnt==3)
	{
		data_3=data;
		data_cnt=4;
	}
	//len
	else if(data_cnt==4)
	{
		data_4=data;
		data_cnt=5;
	}
	//flag
	else if(data_cnt==5)
	{
		data_5=data;
		data_cnt=6;
	}
	///////////////////////////////
	//cx_l 
	
	else if(data_cnt==6)
	{
		data_6=data;
		data_cnt=7;
	}
	//cx_h 
	else if(data_cnt==7)
	{
		data_7=data;
		data_cnt=8;
	}
	//////////////////////////////
	//cy_l
	else if(data_cnt==8)
	{
		data_8=data;
		data_cnt=9;
	}
	
	//cy_h 
	else if(data_cnt==9)
	{
		data_9=data;
		data_cnt=10;
	}
	/////////////////////////////////
	//cz_l
	else if(data_cnt==10)
	{
		data_10=data;
		data_cnt=11;
	}
	//cz_h
	else if(data_cnt==11)
	{
		data_11=data;
		data_cnt=12;
	}
	///////////////////////////////////
	//sc
	else if(data_cnt==12)
	{
		data_12=data;
		data_cnt=13;
	}
	//ac
	else if(data_cnt==13)
	{
		data_13=data;
		data_cnt=0;
	}
	else
	{
		data_cnt=0;
	}

//	OpenMV_data_0=data_1;
//	
//	OpenMV_data_1=data_3;
//	OpenMV_data_1<<=8;
//	OpenMV_data_1|=data_2;
//	
//	OpenMV_data_2=data_5;
//	OpenMV_data_2<<=8;
//	OpenMV_data_2|=data_4;
	
	Openmv_Rxbuf[0] = data_1;
    Openmv_Rxbuf[1] = data_2;
    Openmv_Rxbuf[2] = data_3;
    Openmv_Rxbuf[3] = data_4;
    Openmv_Rxbuf[4] = data_5;
    Openmv_Rxbuf[5] = data_6;
    Openmv_Rxbuf[6] = data_7;
    Openmv_Rxbuf[7] = data_8;
    Openmv_Rxbuf[8] = data_9;
    Openmv_Rxbuf[9] = data_10;
    Openmv_Rxbuf[10] = data_11;
    Openmv_Rxbuf[11] = data_12;
    Openmv_Rxbuf[12] = data_13;
	DrvUart1SendBuf(Openmv_Rxbuf, 13);
}	
