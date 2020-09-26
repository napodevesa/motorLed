
#include <pt.h>
#include <Stepper.h>


struct pt hilo1;

const int stepsPerRevolution = 32*64;  
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

void setup() 
{
  
  PT_INIT(&hilo1);  
  // set the speed at 15 rpm:
  myStepper.setSpeed(15);
  // initialize the serial port:
  Serial.begin(9600);
  
}



void loop() 
{
  parpadeo (&hilo1);
  
  // step one revolution  in one direction:
  Serial.println("clockwise");
  myStepper.step(stepsPerRevolution);
  delay(500);

  // step one revolution in the other direction:
  Serial.println("counterclockwise");
  myStepper.step(-stepsPerRevolution);
  delay(500);
   
}

void parpadeo(struct pt *pt) {
  PT_BEGIN(pt);
  // void setup() {
  static long t = 0;
  pinMode(7, OUTPUT);
  // }
  
  do {
  // void loop() {
    digitalWrite(10, HIGH);
    t = millis();
    PT_WAIT_WHILE(pt, (millis()-t)<1000);
    
    digitalWrite(10, LOW);
    t = millis();
    PT_WAIT_UNTIL(pt, (millis()-t)>=1000);
  // }
  } while(true);
  PT_END(pt);
}
