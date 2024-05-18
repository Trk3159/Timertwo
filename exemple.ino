#include <Timertwo.h>


bool allume = false;
int i = 0;

void clignotte(){
  if (allume==false){
    digitalWrite(13,HIGH);
    allume=true;
  }
  else {
    digitalWrite(13,LOW);
    allume=false;
  }
  i+=1;
}

void setup() {
  // put your setup code here, to run once:
  pinMode(13,OUTPUT);
  Timertwo::set(1000,clignotte);
  Timertwo::stop();
  sei();
}

void loop() {
  // put your main code here, to run repeatedly:
  //digitalWrite(13,HIGH);
}
