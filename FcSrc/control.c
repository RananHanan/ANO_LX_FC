#include "control.h"



int my_code_control_flag;//模拟遥控输入标志位，代替遥控
int my_give_vel_x,	my_give_vel_y,	my_give_vel_z,	my_give_vel_yaw;//自定义的变量模仿代替遥控输入
int Task_time_dly_cnt_ms;//计时
unsigned int mission_step;//任务步骤


void all_data_init(void)
{
	Task_time_dly_cnt_ms=0;
}

void User_Task_Delay(int ms)
{
	if(Task_time_dly_cnt_ms<ms)
	{
		Task_time_dly_cnt_ms+=20;
	}
	else
	{
		Task_time_dly_cnt_ms=0;;
		mission_step++;
	}

}