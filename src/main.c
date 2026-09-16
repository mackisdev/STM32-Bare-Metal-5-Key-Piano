#include "stm32f7xx.h"
#include "timer.h"

int main(void)
{
    TIM2_INIT();
    (*RCC).AHB1ENR |= (1U << 0);
    (*RCC).AHB1ENR |= (1U << 2);
    (*RCC).AHB1ENR |= (1U << 5);
    (*RCC).AHB1ENR |= (1U << 1);

    (*GPIOA).MODER &= ~(0x3U << 6); // 1st Button (A0)
    (*GPIOC).MODER &= ~(0x3U << 0); // 2nd Button (A1)
    (*GPIOC).MODER &= ~(0x3U << 6); // 3rd Button (A2)
    (*GPIOF).MODER &= ~(0x3U << 6); // 4th Button (A3)
    (*GPIOF).MODER &= ~(0x3U << 10); // 5th Button (A4)
    
    (*GPIOB).MODER &= ~(0x3U << 16); // Buzzer pin (D15)
    (*GPIOB).MODER |= (1U << 16);

    while(1)
    {
        if ((*GPIOA).IDR & (1U << 3))
        {
            TIM2_CHANGE_FREQUENCY(262);
            
            while(!((*TIM2).SR & (1 << 0)))
            {
            }
            (*GPIOB).BSRR = (1 << 8);
            (*TIM2).SR &= ~(1 << 0);
            while(!((*TIM2).SR & (1 << 0)))
            {
            }
            (*GPIOB).BSRR = (1 << 24);
            (*TIM2).SR &= ~(1 << 0);
        }
        

        if ((*GPIOC).IDR & (1U << 0))
        {
            TIM2_CHANGE_FREQUENCY(294);
            
            while(!((*TIM2).SR & (1 << 0)))
            {
            }
            (*GPIOB).BSRR = (1 << 8);
            (*TIM2).SR &= ~(1 << 0);
            while(!((*TIM2).SR & (1 << 0)))
            {
            }
            (*GPIOB).BSRR = (1 << 24);
            (*TIM2).SR &= ~(1 << 0);
        }

        if ((*GPIOC).IDR & (1U << 3))
        {
            TIM2_CHANGE_FREQUENCY(330);
            
            while(!((*TIM2).SR & (1 << 0)))
            {
            }
            (*GPIOB).BSRR = (1 << 8);
            (*TIM2).SR &= ~(1 << 0);
            while(!((*TIM2).SR & (1 << 0)))
            {
            }
            (*GPIOB).BSRR = (1 << 24);
            (*TIM2).SR &= ~(1 << 0);
        }

        if ((*GPIOF).IDR & (1U << 3))
        {
            TIM2_CHANGE_FREQUENCY(392);
            
            while(!((*TIM2).SR & (1 << 0)))
            {
            }
            (*GPIOB).BSRR = (1 << 8);
            (*TIM2).SR &= ~(1 << 0);
            while(!((*TIM2).SR & (1 << 0)))
            {
            }
            (*GPIOB).BSRR = (1 << 24);
            (*TIM2).SR &= ~(1 << 0);
        }

        if ((*GPIOF).IDR & (1U << 5))
        {
            TIM2_CHANGE_FREQUENCY(440);
            
            while(!((*TIM2).SR & (1 << 0)))
            {
            }
            (*GPIOB).BSRR = (1 << 8);
            (*TIM2).SR &= ~(1 << 0);
            while(!((*TIM2).SR & (1 << 0)))
            {
            }
            (*GPIOB).BSRR = (1 << 24);
            (*TIM2).SR &= ~(1 << 0);
        }

    }
}