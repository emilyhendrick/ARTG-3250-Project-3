#include <Servo.h>

// boston AQ = 38, level 0
// paris AQ = 62, level 1
// beijing AQ = 229, level 2

Servo Servo1;
Servo Servo2;

void setup() {
  pinMode(12, OUTPUT);      // Set pin 12 to output, represents Boston air quality
  pinMode(11, OUTPUT);      // Set pin 11 to output, represents Paris air quality
  pinMode(10, OUTPUT);      // Set pin 10 to output, represents Beijing air quality
  pinMode(9, OUTPUT);      // Set pin 10 to output, represents City air quality
  Servo1.attach(3); // Servo 1
  Servo2.attach(6); // Servo 2
  pinMode(7, INPUT_PULLUP);        // Set pin 6 to input, for the button to control Beijing LED
  pinMode(5, INPUT_PULLUP);        // Set pin 5 to input, for the button to control Paris LED
  pinMode(4, INPUT_PULLUP);        // Set pin 4 to input, for the button to control Boston LED

}


void loop() { 
  digitalWrite(9, HIGH);

  // beijing
  if (digitalRead(7) == LOW){
    digitalWrite(10, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(11, LOW); 
    Servo1.write(10);
    Servo2.write(20);
  }

  // boston
  if (digitalRead(4) == LOW){
    digitalWrite(12, HIGH);
    digitalWrite(11, LOW);
    digitalWrite(10, LOW);
    Servo1.write(75);
    Servo2.write(90);
  }

  // paris
  if (digitalRead(5) == LOW){
    digitalWrite(11, HIGH);
    digitalWrite(10, LOW);
    digitalWrite(12, LOW);
    Servo1.write(5);
    Servo2.write(90);
  } 

}

