/**
  ******************************************************************************
  * @file    main.c
  * @author
  * @version V1.00
  * @date    22-Sep-2020
  * @brief   ......
  ******************************************************************************
  * @attention
  *
  * ......
  *
  ******************************************************************************
  */


/* Define to prevent recursive inclusion -------------------------------------*/
#define __MAIN_C__


/* Includes ------------------------------------------------------------------*/
#include "main.h"


/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/
/* Private macro -------------------------------------------------------------*/
/* Private variables ---------------------------------------------------------*/
/* Private function prototypes -----------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
EXTERN uint16_t aSine12bit[32];

/* Exported variables --------------------------------------------------------*/
/* Exported function prototypes ----------------------------------------------*/


/**
  * @brief
  * @param  None
  * @retval None
  */
int main(void)
{

    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);     //设置系统中断优先级分组2

    delay_init(168);                                    //延时初始化

    uart_init(115200);                                  //串口初始化波特率为115200

    LED_Init();

    printf("EST\r\n");

    bsp_InitAdc();

    MX_CLK_Init();

    DAC_GPIO_Config();

    TIM6_Config();

    DAC_DeInit();

    DAC_Ch2_SineWaveConfig();

    Generate_Wave(Wave_Sin,4095,aSine12bit);

    while(1)
    {
        GPIO_SetBits(GPIOA, GPIO_Pin_15);
        delay_ms(200);
        GPIO_ResetBits(GPIOA, GPIO_Pin_15);
        delay_ms(200);
        Get_Adc();

    }
}


/******************* (C) COPYRIGHT 2020 *************************END OF FILE***/
