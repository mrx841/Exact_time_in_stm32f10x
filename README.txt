hello 

This library has two functions, the delay_us() function can create a time delay in microseconds and the time_now() function can give the exact time elapsed since the micro starts working with microsecond accuracy in seconds.

Basically, with the first call of the time_now(), it starts counting the time, and from then on, every time it is called, it gives the elapsed time in seconds, with accurately = 10^-8


To use this library:

1- import time.h in INC folder in your project files.(core/INC).
2- In the (main.c), include the header file :

 / * USER CODE BEGIN Includes * /
 #include "time.h"
 / * USER CODE END Includes * /

3-add in main function section for initial initialization of the DWT (Data Watchpoint)

/* USER CODE BEGIN 2 */
  DWT_Init();
/* USER CODE END 2 */

4- now you can use delay_us() and time_now() in your code.


****** If the frequency of your micro is not 72M HZ, you must enter the <time.h> and change the <const double sysclock =72000000.00000000> .
******to work by <time_now> func and giving time . time beetwean 2 calling func might be smaller than 59 second.
      If this is not the case, there is no guarantee for the accuracy of this function and its accuracy will decrease to about 0.5 seconds.

have good time.

gmail:mrx841148mrx@gmail.com
github:MRX841