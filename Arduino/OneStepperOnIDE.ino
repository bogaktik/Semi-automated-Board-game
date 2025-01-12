#include <Stepper.h>

const int stepsPerRevolution = 2052;
int rotate = 0;

 Stepper myStepper = Stepper(stepsPerRevolution, 8, 10, 9, 11); 

void setup() {
  Serial.begin(9600);
  myStepper.setSpeed(10);
}

void loop() {
  if (Serial.available() > 0) {
    rotate = Serial.parseInt();
    myStepper.step(rotate);
    rotate = 0;
  }
}