#include "Timertwo.h"
#include<avr/interrupt.h>

/*
The mean idea of this program is to make an interruption each 1ms, if it is more increment a counter until we get the desired periode
*/

#define F_CPU 16000000

unsigned long Timertwo::periode;
void (*Timertwo::func)();
volatile unsigned long Timertwo::count;
volatile char Timertwo::overflowing;
volatile unsigned int Timertwo::tcnt2;
	

void Timertwo::set(unsigned long pr, void (*f)()) {
    //We could say tha this is a counstractor because it will initialise our most important variables
    float prescaler=256.0;
    TCCR2B |= (1 << CS22) | (0 << CS21) | (0 << CS20);
    /*
    Nous allons utiliser l'interruption à un débordement et donc il faudrait calculer le temps nécessaire pour TCNT2 déborde:
    -TCNT2=valeur_max_tcnt2(256)-temps_restant_pour_attendre_1ms(F_CPU*0.001/prescaler)
    We will use an overflow interruption, so we have to calculate the necessary time that TCNT2 need to attend 1ms:
    -.....................
    */
    tcnt2=256-(int)((float)F_CPU*0.001/prescaler);

    periode=pr;//periode d'interruption en ms

    func=f;//fonction à appeler une fois l'interruption déclenchée
}

void Timertwo::start(){

    count=0;//initialisation de compteur de ms à 0

    overflowing=0;//initlaliser le overflow à 0 (c'est plus un 0 binaire)

    TCNT2 = tcnt2;

	TIMSK2 |= (1<<TOIE2);

}

void Timertwo::stop(){
    //This function will stop the TIMER2 interruption

    TIMSK2 &= ~(1<<TOIE2);//IMSK2 of interruption register will get 0

}

void Timertwo::_overflow(){

    //This function will be called each time the tcnt2 will debord

    count+=1;

    //The overflow is a boolean here to make sure that an interrtuption will crate a confusion

    //we enter this loop each time we attend the desired periode
    if (count>=periode && !overflowing){
        overflowing=1;
        count=0;
        (*func)();
        overflowing=0;
    }
    
}


ISR(TIMER2_OVF_vect) {
    //TIMER2_OVF_vect is included in avr/interrupt.h. It is executed each time we have an overflow.

	TCNT2 = Timertwo::tcnt2;// each time an overflow happen we renitialise the TCNT2 register to the calculated value in order to keep a 1ms periode

	Timertwo::_overflow();//We call the function that count 
}
