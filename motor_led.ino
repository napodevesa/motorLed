
#include <Stepper.h>
const int ledPIN = 7;
const int stepsPerRevolution = 32*64;  // change this to fit the number of steps per revolution

// initialize the stepper library on pins 8 through 11:
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() {
  pinMode(ledPIN , OUTPUT);  //definir pin como salida
  // set the speed at 15 rpm:
  myStepper.setSpeed(15);
  // initialize the serial port:
  Serial.begin(9600);
}



void loop() {
  // step one revolution  in one direction:
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  
  delay(500);

  digitalWrite(ledPIN , HIGH);   // poner el Pin en HIGH
  delay(500);                   // esperar un segundo
  digitalWrite(ledPIN , LOW);    // poner el Pin en LOW
  delay(500);

  digitalWrite(ledPIN , HIGH);   // poner el Pin en HIGH
  delay(500);                   // esperar un segundo
  digitalWrite(ledPIN , LOW);    // poner el Pin en LOW
  delay(500);

  // step one revolution in the other direction:
  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
  delay(500);

   
}
