
#include <pt.h>

#include <Stepper.h>

#define LED_1_PIN 7

const int stepsPerRevolution = 32*64;  // change this to fit the number of steps per revolution
Stepper myStepper(stepsPerRevolution, 8, 10, 9, 11);

static struct pt pt1, pt2;


static int protothreadBlinkLED1(struct pt *pt)
{
  static unsigned long lastTimeBlink = 0;
  PT_BEGIN(pt);
  while(1) {
    lastTimeBlink = millis();
    PT_WAIT_UNTIL(pt, millis() - lastTimeBlink > 1000);
    digitalWrite(LED_1_PIN, HIGH);
    lastTimeBlink = millis();
    PT_WAIT_UNTIL(pt, millis() - lastTimeBlink > 1000);
    digitalWrite(LED_1_PIN, LOW);
  }
  PT_END(pt);
}

static int protothreadMotor(struct pt *pt)
{
  static unsigned long lastTimeBlink = 0;
  PT_BEGIN(pt);
  while(1) {
    lastTimeBlink = millis();
    PT_WAIT_UNTIL(pt, millis() - lastTimeBlink > 1000);
    myStepper.step(stepsPerRevolution);
    lastTimeBlink = millis();
    PT_WAIT_UNTIL(pt, millis() - lastTimeBlink > 1000);
    myStepper.step(-stepsPerRevolution);
  }
  PT_END(pt);
}



void setup() {
  
  Serial.begin(9600);
  
  myStepper.setSpeed(10);
  pinMode(LED_1_PIN, OUTPUT);
  
  
  PT_INIT(&pt1);
  PT_INIT(&pt2);
  
  
}
void loop() {
  
 protothreadBlinkLED1(&pt1);
 protothreadMotor(&pt2);
 protothreadBlinkLED1(&pt1);
}
