#include <stm32f10x.h>
#include <OLED.h>
#include <Delay.h>
#include <SR04.h>
#include "MPU6050.h"

int8_t key = 0;
uint8_t number = 0;
uint8_t ID;								//定义用于存放ID号的变量
int16_t AX, AY, AZ, GX, GY, GZ;	

void Stop(void);
void Left(void);
void Middle(void);
void Right(void);
void LED(void);
void later(void);

int main(void)
{
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB,ENABLE);
	
	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_InitStructure);
	
	GPIO_InitTypeDef GPIO_Initcmd;
	GPIO_Initcmd.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Initcmd.GPIO_Pin = GPIO_Pin_4 | GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7 | GPIO_Pin_8;
	GPIO_Initcmd.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOA,&GPIO_Initcmd);
	
	GPIO_InitTypeDef GPIO_Initcmd2;
	GPIO_Initcmd2.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_Initcmd2.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_10 | GPIO_Pin_11;
	GPIO_Initcmd2.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_Initcmd2);
	
	GPIO_InitTypeDef GPIO_Initkey;
	GPIO_Initkey.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_Initkey.GPIO_Pin = GPIO_Pin_12;
	GPIO_Initkey.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_Initkey);
	
	GPIO_InitTypeDef GPIO_InitLED;
	GPIO_InitLED.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitLED.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;//R 蓝色(B13) M 绿色(B14) L 黄色(B15)
	GPIO_InitLED.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB,&GPIO_InitLED);
	
	TIM_InternalClockConfig(TIM2);
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitstructure;
	TIM_TimeBaseInitstructure.TIM_ClockDivision = TIM_CKD_DIV1;
	TIM_TimeBaseInitstructure.TIM_CounterMode = TIM_CounterMode_Up;
	TIM_TimeBaseInitstructure.TIM_Period = 100-1;//ARR
	TIM_TimeBaseInitstructure.TIM_Prescaler = 1500 - 1;//PSC
	TIM_TimeBaseInitstructure.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM2,&TIM_TimeBaseInitstructure);
	
	TIM_Cmd(TIM2,ENABLE);
	
	TIM_OCInitTypeDef TIM_OCInitStructure1;
	TIM_OCStructInit(&TIM_OCInitStructure1);
	TIM_OCInitStructure1.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure1.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitStructure1.TIM_Pulse = 0;//CCR
	TIM_OCInitStructure1.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OC1Init(TIM2,&TIM_OCInitStructure1);
	
	TIM_OCInitTypeDef TIM_OCInitStructure2;
	TIM_OCStructInit(&TIM_OCInitStructure2);
	TIM_OCInitStructure2.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure2.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitStructure2.TIM_Pulse = 0;//CCR
	TIM_OCInitStructure2.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OC2Init(TIM2,&TIM_OCInitStructure2);

	TIM_OCInitTypeDef TIM_OCInitStructure3;
	TIM_OCStructInit(&TIM_OCInitStructure3);
	TIM_OCInitStructure3.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure3.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitStructure3.TIM_Pulse = 0;//CCR
	TIM_OCInitStructure3.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OC3Init(TIM2,&TIM_OCInitStructure3);

	TIM_OCInitTypeDef TIM_OCInitStructure4;
	TIM_OCStructInit(&TIM_OCInitStructure4);
	TIM_OCInitStructure4.TIM_OCMode = TIM_OCMode_PWM1;
	TIM_OCInitStructure4.TIM_OCPolarity = TIM_OCPolarity_High;
	TIM_OCInitStructure4.TIM_Pulse = 0;//CCR
	TIM_OCInitStructure4.TIM_OutputState = TIM_OutputState_Enable;
	TIM_OC4Init(TIM2,&TIM_OCInitStructure4);
	
				/*模块初始化*/
	OLED_Init();		//OLED初始化
	MPU6050_Init();		//MPU6050初始化
	
	/*显示ID号*/
	OLED_ShowString(1, 1, "ID:");		//显示静态字符串
	ID = MPU6050_GetID();				//获取MPU6050的ID号
	OLED_ShowHexNum(1, 4, ID, 2);		//OLED显示ID号
	


	while(1)
	{
		MPU6050_GetData(&AX, &AY, &AZ, &GX, &GY, &GZ);		//获取MPU6050的数据
		OLED_ShowSignedNum(2, 1, AX, 5);					//OLED显示数据
		OLED_ShowSignedNum(3, 1, AY, 5);
		OLED_ShowSignedNum(4, 1, AZ, 5);
		OLED_ShowSignedNum(2, 8, GX, 5);
		OLED_ShowSignedNum(3, 8, GY, 5);
		OLED_ShowSignedNum(4, 8, GZ, 5);
		if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_12) == 0)
		{
			while(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_12) == 0);
			key = ~key;
		}
		
		if(key == 0)
		{
			Stop();
		}
		else if(key == -1)
		{
//			if(AX<200)
//			{
//				Middle();
//			}
			if(AY>50)
			{
				Middle();
				Delay_ms(100);
				Stop();
				Delay_ms(200);
			}
//			if(AY<-200)
//			{
//				later();
//			}
			if(AY<-50)
			{
				later();
				Delay_ms(100);
				Stop();
				Delay_ms(200);
			}
			

		}
		
//		OLED_ShowString(1,1,"RUN:");
//		OLED_ShowSignedNum(2,5,key,1);
//		OLED_ShowString(2,1,"R:");
//		OLED_ShowString(3,1,"M:");
//		OLED_ShowString(4,1,"L:");
//		OLED_ShowNum(4,3,GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_13),1);//L
//		OLED_ShowNum(3,3,GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_14),1);//M
//		OLED_ShowNum(2,3,GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_15),1);//R
	}	
}

void Left(void)//左转
{
	TIM_SetCompare1(TIM2,100);//左1
	TIM_SetCompare2(TIM2,100);//左2
	TIM_SetCompare3(TIM2,100);
	TIM_SetCompare4(TIM2,100);

	GPIO_WriteBit(GPIOA,GPIO_Pin_4,0);
	GPIO_WriteBit(GPIOA,GPIO_Pin_5,1);//左1正转，A4 = 1,5 = 0
	
	GPIO_WriteBit(GPIOA,GPIO_Pin_6,1);
	GPIO_WriteBit(GPIOA,GPIO_Pin_7,0);//左2正转，A6 = 0,7 = 1
		
	GPIO_WriteBit(GPIOB,GPIO_Pin_0,0);
	GPIO_WriteBit(GPIOB,GPIO_Pin_1,1);//右2正转，B0 = 0,1 = 1
				
	GPIO_WriteBit(GPIOB,GPIO_Pin_10,1);
	GPIO_WriteBit(GPIOB,GPIO_Pin_11,0);//右1正转，B10 = 1,11 = 0
}

void Middle(void)//中间
{
	TIM_SetCompare1(TIM2,50);//左1
	TIM_SetCompare2(TIM2,50);//左2
	TIM_SetCompare3(TIM2,50);
	TIM_SetCompare4(TIM2,50);
	
	GPIO_WriteBit(GPIOA,GPIO_Pin_4,1);
	GPIO_WriteBit(GPIOA,GPIO_Pin_5,0);//左1正转，A4 = 1,5 = 0
	
	GPIO_WriteBit(GPIOA,GPIO_Pin_6,0);
	GPIO_WriteBit(GPIOA,GPIO_Pin_7,1);//左2正转，A6 = 0,7 = 1
		
	GPIO_WriteBit(GPIOB,GPIO_Pin_0,0);
	GPIO_WriteBit(GPIOB,GPIO_Pin_1,1);//右2正转，B0 = 0,1 = 1
				
	GPIO_WriteBit(GPIOB,GPIO_Pin_10,1);
	GPIO_WriteBit(GPIOB,GPIO_Pin_11,0);//右1正转，B10 = 1,11 = 0

}

void Right(void)//右转
{
	TIM_SetCompare1(TIM2,100);//左1
	TIM_SetCompare2(TIM2,100);//左2
	TIM_SetCompare3(TIM2,100);
	TIM_SetCompare4(TIM2,100);
	

	
	GPIO_WriteBit(GPIOA,GPIO_Pin_4,1);
	GPIO_WriteBit(GPIOA,GPIO_Pin_5,0);//左1正转，A4 = 1,5 = 0
	
	GPIO_WriteBit(GPIOA,GPIO_Pin_6,0);
	GPIO_WriteBit(GPIOA,GPIO_Pin_7,1);//左2正转，A6 = 0,7 = 1
		
	GPIO_WriteBit(GPIOB,GPIO_Pin_0,1);
	GPIO_WriteBit(GPIOB,GPIO_Pin_1,0);//右2正转，B0 = 0,1 = 1
				
	GPIO_WriteBit(GPIOB,GPIO_Pin_10,0);
	GPIO_WriteBit(GPIOB,GPIO_Pin_11,1);//右1正转，B10 = 1,11 = 0		
}
	
void Stop(void)
{
	GPIO_WriteBit(GPIOA,GPIO_Pin_4,0);
	GPIO_WriteBit(GPIOA,GPIO_Pin_5,0);//左1正转，A4 = 1,5 = 0
		
	GPIO_WriteBit(GPIOA,GPIO_Pin_6,0);
	GPIO_WriteBit(GPIOA,GPIO_Pin_7,0);//左2正转，A6 = 0,7 = 1
		
	GPIO_WriteBit(GPIOB,GPIO_Pin_0,0);
	GPIO_WriteBit(GPIOB,GPIO_Pin_1,0);//右2正转，B0 = 0,1 = 1
		
	GPIO_WriteBit(GPIOB,GPIO_Pin_10,0);
	GPIO_WriteBit(GPIOB,GPIO_Pin_11,0);//右1正转，B10 = 1,11 = 0
}

void later(void)//后退
{
	TIM_SetCompare1(TIM2,50);//左1
	TIM_SetCompare2(TIM2,50);//左2
	TIM_SetCompare3(TIM2,50);
	TIM_SetCompare4(TIM2,50);
	
	GPIO_WriteBit(GPIOA,GPIO_Pin_4,0);
	GPIO_WriteBit(GPIOA,GPIO_Pin_5,1);//左1正转，A4 = 1,5 = 0
	
	GPIO_WriteBit(GPIOA,GPIO_Pin_6,1);
	GPIO_WriteBit(GPIOA,GPIO_Pin_7,0);//左2正转，A6 = 0,7 = 1
		
	GPIO_WriteBit(GPIOB,GPIO_Pin_0,1);
	GPIO_WriteBit(GPIOB,GPIO_Pin_1,0);//右2正转，B0 = 0,1 = 1
				
	GPIO_WriteBit(GPIOB,GPIO_Pin_10,0);
	GPIO_WriteBit(GPIOB,GPIO_Pin_11,1);//右1正转，B10 = 1,11 = 0

}

void LED(void)
{
	if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_13) == 0 && GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_15) == 0 && GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_14) == 1)
	{
		Middle();
		
	}
	else if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_13) == 1 && GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_15) == 0 && GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_14) == 0)
	{
		Right();
	}
	else if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_13) == 0 && GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_15) == 1 && GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_14) == 0)
	{
		Left();
	}
	else if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_13) == 1 && GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_15) == 0 && GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_14) == 1)
	{
		Right();
	}
	else if(GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_13) == 0 && GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_15) == 1 && GPIO_ReadInputDataBit(GPIOB,GPIO_Pin_14) == 1)
	{
		Left();
	}
}
