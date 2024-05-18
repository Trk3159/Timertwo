# Timertwo
very useful library that allow you to manipulate easly Timer 2 interruptions on Arduino UNO, MEGA and NANO

-----------------How to import the library at the Arduino IDE-------------------
Copy-past the header and the cpp code in a file called Timertwo.
Put the Timertwo file containig Timertwo.h and Timertwo.cpp with the other library files.
It will appear in with the other libraries in : sktech -> includ a library

------------------------------How to test it-----------------------------------
You have an exemple file that allow you to blink the internal Ardunio Uno/Mega/Nano LED(pin 13)
includ the Timertwo library and be sure at the line 22 that you have 23 that you are on the Timertwo::start()
To shut it down change the line 23 to Timertwo::stop()

