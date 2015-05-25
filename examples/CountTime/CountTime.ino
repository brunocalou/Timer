/*
  Created by Bruno Calou Alves, May, 2015.
  Read LICENSE for more information.
*/

#include "timer.h"

//Timer object
Timer timer;

void setup()
{
  Serial.begin(9600);

  //Start the timer
  timer.start();
}

void loop()
{
  //Print the elapsed time
  Serial.println(timer.getElapsedTime());

  //Update the timer
  timer.update();
}