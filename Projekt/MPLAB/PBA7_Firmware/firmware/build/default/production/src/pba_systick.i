# 1 "src/pba_systick.c"
# 1 "<built-in>" 1
# 1 "<built-in>" 3
# 288 "<built-in>" 3
# 1 "<command line>" 1
# 1 "<built-in>" 2
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.30\\pic\\include\\language_support.h" 1 3
# 2 "<built-in>" 2
# 1 "src/pba_systick.c" 2
# 42 "src/pba_systick.c"
# 1 "src/../inc/pba_systick.h" 1
# 46 "src/../inc/pba_systick.h"
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.30\\pic\\include\\c99\\stdint.h" 1 3



# 1 "C:\\Program Files\\Microchip\\xc8\\v2.30\\pic\\include\\c99\\musl_xc8.h" 1 3
# 4 "C:\\Program Files\\Microchip\\xc8\\v2.30\\pic\\include\\c99\\stdint.h" 2 3
# 22 "C:\\Program Files\\Microchip\\xc8\\v2.30\\pic\\include\\c99\\stdint.h" 3
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.30\\pic\\include\\c99\\bits/alltypes.h" 1 3
# 127 "C:\\Program Files\\Microchip\\xc8\\v2.30\\pic\\include\\c99\\bits/alltypes.h" 3
typedef unsigned long uintptr_t;
# 142 "C:\\Program Files\\Microchip\\xc8\\v2.30\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long intptr_t;
# 158 "C:\\Program Files\\Microchip\\xc8\\v2.30\\pic\\include\\c99\\bits/alltypes.h" 3
typedef signed char int8_t;




typedef short int16_t;




typedef __int24 int24_t;




typedef long int32_t;





typedef long long int64_t;
# 188 "C:\\Program Files\\Microchip\\xc8\\v2.30\\pic\\include\\c99\\bits/alltypes.h" 3
typedef long long intmax_t;





typedef unsigned char uint8_t;




typedef unsigned short uint16_t;




typedef __uint24 uint24_t;




typedef unsigned long uint32_t;





typedef unsigned long long uint64_t;
# 229 "C:\\Program Files\\Microchip\\xc8\\v2.30\\pic\\include\\c99\\bits/alltypes.h" 3
typedef unsigned long long uintmax_t;
# 22 "C:\\Program Files\\Microchip\\xc8\\v2.30\\pic\\include\\c99\\stdint.h" 2 3


typedef int8_t int_fast8_t;

typedef int64_t int_fast64_t;


typedef int8_t int_least8_t;
typedef int16_t int_least16_t;

typedef int24_t int_least24_t;
typedef int24_t int_fast24_t;

typedef int32_t int_least32_t;

typedef int64_t int_least64_t;


typedef uint8_t uint_fast8_t;

typedef uint64_t uint_fast64_t;


typedef uint8_t uint_least8_t;
typedef uint16_t uint_least16_t;

typedef uint24_t uint_least24_t;
typedef uint24_t uint_fast24_t;

typedef uint32_t uint_least32_t;

typedef uint64_t uint_least64_t;
# 144 "C:\\Program Files\\Microchip\\xc8\\v2.30\\pic\\include\\c99\\stdint.h" 3
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.30\\pic\\include\\c99\\bits/stdint.h" 1 3
typedef int16_t int_fast16_t;
typedef int32_t int_fast32_t;
typedef uint16_t uint_fast16_t;
typedef uint32_t uint_fast32_t;
# 144 "C:\\Program Files\\Microchip\\xc8\\v2.30\\pic\\include\\c99\\stdint.h" 2 3
# 47 "src/../inc/pba_systick.h" 2
# 1 "C:\\Program Files\\Microchip\\xc8\\v2.30\\pic\\include\\c99\\stdbool.h" 1 3
# 48 "src/../inc/pba_systick.h" 2
# 60 "src/../inc/pba_systick.h"
void SYSTICK_TimerLoadAndRun(uint8_t descriptor, uint32_t loadValue);
void SYSTICK_TimerRun(uint8_t descriptor);
void SYSTICK_TimerLoad(uint8_t descriptor, uint32_t loadValue);
void SYSTICK_TimerStop(uint8_t descriptor);
_Bool SYSTICK_Timeout(uint8_t descriptor);
void SYSTICK_AddTimeoutHandler(uint8_t descriptor, void (*p_Function)(void));
void SYSTICK_Handler(void);
# 43 "src/pba_systick.c" 2







typedef enum
{
    NOT_RUNNING,
    RUNNING
}timer_state_t;







typedef struct
{
    uint32_t tickCnt;
    timer_state_t state;
    void (*p_callbackFunction)(void);
}soft_timer_t;







volatile static soft_timer_t softTimer[6];
# 85 "src/pba_systick.c"
void SYSTICK_TimerRun(uint8_t descriptor)
{

    if(descriptor < 6)
    {
        softTimer[descriptor].state = RUNNING;
    }
}







void SYSTICK_TimerLoadAndRun(uint8_t descriptor, uint32_t loadValue)
{

    SYSTICK_TimerLoad(descriptor, loadValue);
    SYSTICK_TimerRun(descriptor);
}






void SYSTICK_TimerLoad(uint8_t descriptor, uint32_t loadValue)
{

    if(descriptor < 6)
    {
        softTimer[descriptor].tickCnt = loadValue;
    }
}





void SYSTICK_TimerStop(uint8_t descriptor)
{

    if(descriptor < 6)
    {
        softTimer[descriptor].state = NOT_RUNNING;
    }
}






_Bool SYSTICK_Timeout(uint8_t descriptor)
{
    _Bool isTimeout = 0;

    if(descriptor < 6)
    {
        if(softTimer[descriptor].state == RUNNING && softTimer[descriptor].tickCnt == 0)
        {
            SYSTICK_TimerStop(descriptor);
            isTimeout = 1;
        }
    }
    return isTimeout;
}







void SYSTICK_AddTimeoutHandler(uint8_t descriptor, void (*p_Function)(void)){
    softTimer[descriptor].p_callbackFunction = p_Function;
}





void SYSTICK_Handler(void)
{


    for (uint8_t i = 0; i < 6; i++)
    {
        if (softTimer[i].state == RUNNING && softTimer[i].tickCnt > 0)
        {
            softTimer[i].tickCnt--;
            if(softTimer[i].tickCnt == 0 && softTimer[i].p_callbackFunction != 0){
                softTimer[i].p_callbackFunction();
            }
        }
    }
}
