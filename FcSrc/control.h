#ifndef __CONTROL_H
#define __CONTROL_H

	
extern int my_code_control_flag;//模拟遥控输入标志位，代替遥控
extern int my_give_vel_x,	my_give_vel_y,	my_give_vel_z,	my_give_vel_yaw;//自定义的变量模仿代替遥控输入
extern int Task_time_dly_cnt_ms;//计时
extern unsigned int mission_step;//任务步骤


void all_data_init(void);
void User_Task_Delay(int ms);
		
		
#endif