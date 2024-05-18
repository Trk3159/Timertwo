#ifndef Timertwo_h
#define Timertwo_h


#include<avr/interrupt.h>

namespace Timertwo {
    extern unsigned long periode;
	extern void (*func)();
	extern volatile unsigned long count;
	extern volatile char overflowing;
	extern volatile unsigned int tcnt2;
	
	void set(unsigned long pr, void (*f)());
	void start();
	void stop();
	void _overflow();
}
#endif
