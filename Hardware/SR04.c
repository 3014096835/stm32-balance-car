#include "stm32f10x.h" 
#include <Delay.h>
#include <OLED.h>
int8_t num = 0;

void SR04Init(void)
{
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC,ENABLE);
	
	GPIO_InitTypeDef GPIO_SR;
	GPIO_SR.GPIO_Mode = GPIO_Mode_Out_PP;
	GPIO_SR.GPIO_Pin = GPIO_Pin_13;
	GPIO_SR.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC,&GPIO_SR);
	
	GPIO_InitTypeDef GPIO_SR1;
	GPIO_SR1.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_SR1.GPIO_Mode = GPIO_Mode_IPD;
	GPIO_SR1.GPIO_Pin = GPIO_Pin_14;
	GPIO_Init(GPIOC,&GPIO_SR1);
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM3,ENABLE);
	TIM_InternalClockConfig(TIM3);	
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;				//定义结构体变量
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;		//时钟分频，选择不分频，此参数用于配置滤波器时钟，不影响时基单元功能
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;	//计数器模式，选择向上计数
	TIM_TimeBaseInitStructure.TIM_Period = 1000 - 1;				//计数周期，即ARR的值
	TIM_TimeBaseInitStructure.TIM_Prescaler = 72 - 1;				//预分频器，即PSC的值		//重复计数器，高级定时器才会用到
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseInitStructure);	

	TIM_ClearFlag(TIM3, TIM_FLAG_Update);
	TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	NVIC_InitTypeDef NVIC_InitStructure;						//定义结构体变量
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;				//选择配置NVIC的TIM2线
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//指定NVIC线路使能
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;	//指定NVIC线路的抢占优先级为2
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;			//指定NVIC线路的响应优先级为1
	NVIC_Init(&NVIC_InitStructure);
	
	TIM_Cmd(TIM3, ENABLE);
}


void TIM3_IRQHandler(void)
{
	if (TIM_GetITStatus(TIM3, TIM_IT_Update) == SET)
	{
		num = ~num;
		if(num == 0)
		{
			GPIO_WriteBit(GPIOC,GPIO_Pin_13,1);
		}
		else
		{
			GPIO_WriteBit(GPIOC,GPIO_Pin_13,0);
		}
		TIM_ClearITPendingBit(TIM3, TIM_IT_Update);
	}
}

void GPIO_SR04(void)
{

	
}