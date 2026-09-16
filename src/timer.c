#include "stm32f7xx.h"

void TIM2_INIT(void)
{
    (*RCC).CR |= (1 << 0); // Turn on HSI
    while(!((*RCC).CR & (1U << 1)))
    {
        // Wait until HSI is on
    }
    (*RCC).CFGR &= ~(0x3U << 0); // Configure HSI as system clock
    (*RCC).CFGR &= ~(0xFU << 4); // Set AHB prescaler to 1
    (*RCC).CFGR &= ~(0x7U << 10); // Set APB prescaler to 1

    (*RCC).APB1ENR |= (1U << 0); // Turn on TIM2
    (*TIM2).PSC = 159U; // Prescale TIM2 to 100,000hz
    (*TIM2).ARR = 99999U; // Set the limit to where it over flows at 99,999 counts
    (*TIM2).CR1 = (1 << 0); // Start the counter
}
void TIM2_CHANGE_FREQUENCY(unsigned int frequency)
{
    // num is the frequency that you want
    // to get num we have to capture the oscillations that happen within that frequency
    // 1hz = 2state changes
    unsigned int state_change = frequency * 2U;
    unsigned int timer_frequency = 16000000U / ((*TIM2).PSC + 1U);
    unsigned int counts_per_ending = timer_frequency / state_change;
    (*TIM2).ARR = counts_per_ending - 1U;

    (*TIM2).CNT = 0;
    (*TIM2).SR &= ~(1U << 0);
}
