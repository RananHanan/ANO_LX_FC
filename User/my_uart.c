#include "my_uart.h"
#include "Drv_Uart.h"

int16_t test_data_1,test_data_2;
int16_t OpenMV_data_0,OpenMV_data_1,OpenMV_data_2,OpenMV_data_3,OpenMV_data_4,OpenMV_data_5,OpenMV_data_6,OpenMV_data_7;

void My_uart1_Recive(uint8_t data)
{
    static int cnt=0;
    static uint8_t data_1,data_2,data_3,data_4;

    if((data==0x0A)&&(cnt==0))
    {
        cnt=1;
    }
    else if(cnt==1)
    {
        data_1=data;
        cnt=2;
    }
    else if(cnt==2)
    {
        data_2=data;
        cnt=3;
    }
    else if(cnt==3)
    {
        data_3=data;
        cnt=4;
    }
    else if(cnt==4)
    {
        data_4=data;
        cnt=0;
    }
    test_data_1=data_2;
    test_data_1<<=8;
    test_data_1|=data_1;
    test_data_2=data_4;
    test_data_2<<=8;
    test_data_2|=data_3;   
}

//void My_uart2_Send(void)
//{
//    u8 Buf[]={1,0x0A};
//    Drv_Uart2SendBuf(Buf,sizeof(Buf));
//}
