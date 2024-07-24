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
	
	TIM_TimeBaseInitTypeDef TIM_TimeBaseInitStructure;				//����ṹ�����
	TIM_TimeBaseInitStructure.TIM_ClockDivision = TIM_CKD_DIV1;		//ʱ�ӷ�Ƶ��ѡ�񲻷�Ƶ���˲������������˲���ʱ�ӣ���Ӱ��ʱ����Ԫ����
	TIM_TimeBaseInitStructure.TIM_CounterMode = TIM_CounterMode_Up;	//������ģʽ��ѡ�����ϼ���
	TIM_TimeBaseInitStructure.TIM_Period = 1000 - 1;				//�������ڣ���ARR��ֵ
	TIM_TimeBaseInitStructure.TIM_Prescaler = 72 - 1;				//Ԥ��Ƶ������PSC��ֵ		//�ظ����������߼���ʱ���Ż��õ�
	TIM_TimeBaseInit(TIM3, &TIM_TimeBaseInitStructure);	

	TIM_ClearFlag(TIM3, TIM_FLAG_Update);
	TIM_ITConfig(TIM3, TIM_IT_Update, ENABLE);
	
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
	
	NVIC_InitTypeDef NVIC_InitStructure;						//����ṹ�����
	NVIC_InitStructure.NVIC_IRQChannel = TIM3_IRQn;				//ѡ������NVIC��TIM2��
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;				//ָ��NVIC��·ʹ��
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 2;	//ָ��NVIC��·����ռ���ȼ�Ϊ2
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;			//ָ��NVIC��·����Ӧ���ȼ�Ϊ1
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