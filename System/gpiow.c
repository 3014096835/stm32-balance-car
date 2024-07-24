#include "stm32f10x.h"
/**
  * @brief  对GPIOA口的初始化与控制（最高速度，推挽输出）
  * @param  对应的Pin引脚
  * @param  高电平1，低电平0
  * @retval 无
  */
void GPIOA_Write(uint8_t Pin,uint8_t Val)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA,ENABLE);
	switch (Pin)
	{
	case 0:
		if(Val == 1)
		{
			GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;
			GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
			GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
			GPIO_Init(GPIOA,&GPIO_InitStruct);
			GPIO_WriteBit(GPIOA,GPIO_Pin_0,Bit_SET);
		}else if(Val == 0)
		{
			GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0;
			GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
			GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
			GPIO_Init(GPIOA,&GPIO_InitStruct);
			GPIO_WriteBit(GPIOA,GPIO_Pin_0,Bit_RESET);
		}
		
		break;
	case 1:
		if(Val == 1)
		{
			GPIO_InitStruct.GPIO_Pin = GPIO_Pin_1;
			GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
			GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
			GPIO_Init(GPIOA,&GPIO_InitStruct);
			GPIO_WriteBit(GPIOA,GPIO_Pin_1,Bit_SET);
		}else if(Val == 0)
		{
			GPIO_InitStruct.GPIO_Pin = GPIO_Pin_1;
			GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
			GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
			GPIO_Init(GPIOA,&GPIO_InitStruct);
			GPIO_WriteBit(GPIOA,GPIO_Pin_1,Bit_RESET);
		}
		break;
		case 3:
		if(Val == 1)
		{
			GPIO_InitStruct.GPIO_Pin = GPIO_Pin_3;
			GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
			GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
			GPIO_Init(GPIOA,&GPIO_InitStruct);
			GPIO_WriteBit(GPIOA,GPIO_Pin_3,Bit_SET);
		}else if(Val == 0)
		{
			GPIO_InitStruct.GPIO_Pin = GPIO_Pin_3;
			GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
			GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
			GPIO_Init(GPIOA,&GPIO_InitStruct);
			GPIO_WriteBit(GPIOA,GPIO_Pin_3,Bit_RESET);
		}
		break;
		case 4:
		if(Val == 1)
		{
			GPIO_InitStruct.GPIO_Pin = GPIO_Pin_4;
			GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
			GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
			GPIO_Init(GPIOA,&GPIO_InitStruct);
			GPIO_WriteBit(GPIOA,GPIO_Pin_4,Bit_SET);
		}else if(Val == 0)
		{
			GPIO_InitStruct.GPIO_Pin = GPIO_Pin_4;
			GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
			GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
			GPIO_Init(GPIOA,&GPIO_InitStruct);
			GPIO_WriteBit(GPIOA,GPIO_Pin_4,Bit_RESET);
		}
		break;
		case 5:
		if(Val == 1)
		{
			GPIO_InitStruct.GPIO_Pin = GPIO_Pin_5;
			GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
			GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
			GPIO_Init(GPIOA,&GPIO_InitStruct);
			GPIO_WriteBit(GPIOA,GPIO_Pin_5,Bit_SET);
		}else if(Val == 0)
		{
			GPIO_InitStruct.GPIO_Pin = GPIO_Pin_5;
			GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
			GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
			GPIO_Init(GPIOA,&GPIO_InitStruct);
			GPIO_WriteBit(GPIOA,GPIO_Pin_5,Bit_RESET);
		}
		break;
		case 6:
		if(Val == 1)
		{
			GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6;
			GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
			GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
			GPIO_Init(GPIOA,&GPIO_InitStruct);
			GPIO_WriteBit(GPIOA,GPIO_Pin_6,Bit_SET);
		}else if(Val == 0)
		{
			GPIO_InitStruct.GPIO_Pin = GPIO_Pin_6;
			GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
			GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
			GPIO_Init(GPIOA,&GPIO_InitStruct);
			GPIO_WriteBit(GPIOA,GPIO_Pin_6,Bit_RESET);
		}
		break;
		case 7:
		if(Val == 1)
		{
			GPIO_InitStruct.GPIO_Pin = GPIO_Pin_7;
			GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
			GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
			GPIO_Init(GPIOA,&GPIO_InitStruct);
			GPIO_WriteBit(GPIOA,GPIO_Pin_7,Bit_SET);
		}else if(Val == 0)
		{
			GPIO_InitStruct.GPIO_Pin = GPIO_Pin_7;
			GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
			GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
			GPIO_Init(GPIOA,&GPIO_InitStruct);
			GPIO_WriteBit(GPIOA,GPIO_Pin_7,Bit_RESET);
		}
		break;
		case 8:
		if(Val == 1)
		{
			GPIO_InitStruct.GPIO_Pin = GPIO_Pin_8;
			GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
			GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
			GPIO_Init(GPIOA,&GPIO_InitStruct);
			GPIO_WriteBit(GPIOA,GPIO_Pin_8,Bit_SET);
		}else if(Val == 0)
		{
			GPIO_InitStruct.GPIO_Pin = GPIO_Pin_8;
			GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
			GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
			GPIO_Init(GPIOA,&GPIO_InitStruct);
			GPIO_WriteBit(GPIOA,GPIO_Pin_8,Bit_RESET);
		}
		break;
		case 9:
		if(Val == 1)
		{
			GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9;
			GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
			GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
			GPIO_Init(GPIOA,&GPIO_InitStruct);
			GPIO_WriteBit(GPIOA,GPIO_Pin_9,Bit_SET);
		}else if(Val == 0)
		{
			GPIO_InitStruct.GPIO_Pin = GPIO_Pin_9;
			GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
			GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
			GPIO_Init(GPIOA,&GPIO_InitStruct);
			GPIO_WriteBit(GPIOA,GPIO_Pin_9,Bit_RESET);
		}
		break;
		case 10:
		if(Val == 1)
		{
			GPIO_InitStruct.GPIO_Pin = GPIO_Pin_10;
			GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
			GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
			GPIO_Init(GPIOA,&GPIO_InitStruct);
			GPIO_WriteBit(GPIOA,GPIO_Pin_10,Bit_SET);
		}else if(Val == 0)
		{
			GPIO_InitStruct.GPIO_Pin = GPIO_Pin_10;
			GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
			GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
			GPIO_Init(GPIOA,&GPIO_InitStruct);
			GPIO_WriteBit(GPIOA,GPIO_Pin_10,Bit_RESET);
		}
		break;
		case 11:
		if(Val == 1)
		{
			GPIO_InitStruct.GPIO_Pin = GPIO_Pin_11;
			GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
			GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
			GPIO_Init(GPIOA,&GPIO_InitStruct);
			GPIO_WriteBit(GPIOA,GPIO_Pin_11,Bit_SET);
		}else if(Val == 0)
		{
			GPIO_InitStruct.GPIO_Pin = GPIO_Pin_11;
			GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
			GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
			GPIO_Init(GPIOA,&GPIO_InitStruct);
			GPIO_WriteBit(GPIOA,GPIO_Pin_11,Bit_RESET);
		}
		break;
		case 12:
		if(Val == 1)
		{
			GPIO_InitStruct.GPIO_Pin = GPIO_Pin_12;
			GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
			GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
			GPIO_Init(GPIOA,&GPIO_InitStruct);
			GPIO_WriteBit(GPIOA,GPIO_Pin_12,Bit_SET);
		}else if(Val == 0)
		{
			GPIO_InitStruct.GPIO_Pin = GPIO_Pin_12;
			GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
			GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
			GPIO_Init(GPIOA,&GPIO_InitStruct);
			GPIO_WriteBit(GPIOA,GPIO_Pin_12,Bit_RESET);
		}
		break;
		case 13:
		if(Val == 1)
		{
			GPIO_InitStruct.GPIO_Pin = GPIO_Pin_13;
			GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
			GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
			GPIO_Init(GPIOA,&GPIO_InitStruct);
			GPIO_WriteBit(GPIOA,GPIO_Pin_13,Bit_SET);
		}else if(Val == 0)
		{
			GPIO_InitStruct.GPIO_Pin = GPIO_Pin_13;
			GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
			GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
			GPIO_Init(GPIOA,&GPIO_InitStruct);
			GPIO_WriteBit(GPIOA,GPIO_Pin_13,Bit_RESET);
		}
		break;
		case 14:
		if(Val == 1)
		{
			GPIO_InitStruct.GPIO_Pin = GPIO_Pin_14;
			GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
			GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
			GPIO_Init(GPIOA,&GPIO_InitStruct);
			GPIO_WriteBit(GPIOA,GPIO_Pin_14,Bit_SET);
		}else if(Val == 0)
		{
			GPIO_InitStruct.GPIO_Pin = GPIO_Pin_14;
			GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
			GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
			GPIO_Init(GPIOA,&GPIO_InitStruct);
			GPIO_WriteBit(GPIOA,GPIO_Pin_14,Bit_RESET);
		}
		break;
		case 15:
		if(Val == 1)
		{
			GPIO_InitStruct.GPIO_Pin = GPIO_Pin_15;
			GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
			GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
			GPIO_Init(GPIOA,&GPIO_InitStruct);
			GPIO_WriteBit(GPIOA,GPIO_Pin_15,Bit_SET);
		}else if(Val == 0)
		{
			GPIO_InitStruct.GPIO_Pin = GPIO_Pin_15;
			GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
			GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
			GPIO_Init(GPIOA,&GPIO_InitStruct);
			GPIO_WriteBit(GPIOA,GPIO_Pin_15,Bit_RESET);
		}
		break;

	}
}
