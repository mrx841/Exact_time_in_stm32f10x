/*
 1-By default, the main frequency is equal to 72 million, and if your micro frequency is different, change it in the <const double sysclock> section.
 2-the <time_now> func will overflow after  1.7E+308 second .
 3- for work by <time_now> func and giving time . time beetwean 2 calling func might be smaller than 59.9 second.
  *If this is not the case, there is no guarantee for the accuracy of this function and its accuracy will decrease to about 0.5 seconds*
 4- when call <now> func for the first time <time_now>  start at 0.000 second.
*/
#include "main.h"
uint32_t t2,t1;
double now=0.0,fdt,dt;
const double sysclock =72000000.00000000;
double period_us=(double)(1000000.00000000/sysclock);
unsigned char step=0;

__STATIC_INLINE void DWT_Init(void)
{
	CoreDebug->DEMCR |= CoreDebug_DEMCR_TRCENA_Msk; //enable the dwt(set zero bit of DEMCR register to 1 )
	DWT->CTRL |= DWT_CTRL_CYCCNTENA_Msk;
	DWT->CYCCNT = 0U;
}

__STATIC_INLINE void delay_us(uint32_t us)
{

	uint32_t end =  us * (sysclock / 1000000U);
	DWT->CYCCNT = 0U;
	while(DWT->CYCCNT < end);
}



double time_now()
{

	if (step==0)
	{

		t1=DWT->CYCCNT;
		t2=DWT->CYCCNT;
		fdt=(double)(t2-t1);
		dt=fdt*period_us;
		now+=dt;
		t1=t2;
		step=1;

	}
	else
	{
		t2=DWT->CYCCNT;
		if(t2<t1)
		{
			fdt=(double)((4294967295-t1)+t2);    //2^32 -1 =4294967295
			dt=(fdt*period_us);
			now+=dt;
			t1=t2;
			step=1;

		}
		else
		{

			fdt=(double)(t2-t1);
			dt=(fdt*period_us);
			now+=dt;
			t1=t2;
			step=1;

	  }
	}
		return (double)(now/1000000.00000000);

}


