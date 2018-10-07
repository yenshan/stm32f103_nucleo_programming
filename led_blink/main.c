#include "stm32f10x.h"

void ConfigureGPIOB3(void)
{
    RCC->AHBENR |= RCC_APB2ENR_IOPAEN;

    GPIOB->ODR = GPIO_MODER_MODER3_0;
    GPIOB->OTYPER = 0x0000;
    GPIOB->PUPDR = 0x000000000;
}

// Main -----------------------------------------------------------------------
int main(void)
{
    ConfigureGPIOB3();
    
    // Loop forever
    while(1){
		if(GPIOB->ODR & GPIO_ODR_3){
			GPIOB->ODR &= ~GPIO_ODR_3;
		}else{
			GPIOB->ODR |= GPIO_ODR_3;
		}

		for (int i = 0; i < 1000; i++)
			;
    }
    return 0;
}
