#include<Servo.h>


int servo1 = 9;
int potPin = A0;
int potValue = 0;

Servo servo;
int angulo = 0;


void setup() {
  servo.attach(servo1);

}

void loop() {

    potValue =analogRead(potPin);
    angulo = map(potValue, 0, 700, 0, 180);
    servo.write(angulo);
    delay(30);
   

}
