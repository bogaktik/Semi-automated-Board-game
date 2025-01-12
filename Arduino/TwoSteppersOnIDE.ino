#include <Stepper.h>  // include stepper library

String Stepper_1;  //initialize stepper1 as a string variable
String Stepper_1_Steps;  //initialize steps as a string variable
String Stepper_2;
String Stepper_2_Steps;

const int stepsPerRevolution=2052;  //define a rotation

Stepper myStepper1=Stepper(stepsPerRevolution, 8, 10, 9, 11);  // define first stepper
Stepper myStepper2=Stepper(stepsPerRevolution, 4, 6, 5, 7);  

void setup() {
  Serial.begin(9600); // set serial port communications
  myStepper1.setSpeed(10); //set speed for stepper 1
  myStepper2.setSpeed(10); // set speed for stepper 2

}

void loop() {
  if (Serial.available()>0) {
    Stepper_1=Serial.readStringUntil(',');// read string from MATLAB
    Stepper_1_Steps=Serial.readStringUntil(','); 
    int Steps_for_Stepper_1=Stepper_1_Steps.toInt(); // convert steps to string

    myStepper1.step(Steps_for_Stepper_1); 
    Steps_for_Stepper_1=0;

    Stepper_2=Serial.readStringUntil(',');
    Stepper_2_Steps=Serial.readStringUntil(',');
    int Steps_for_Stepper_2=Stepper_2_Steps.toInt();

    myStepper2.step(Steps_for_Stepper_2);
    Steps_for_Stepper_2=0;

  }

}
