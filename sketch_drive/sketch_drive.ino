#include <Stepper.h>

int enA = 3; // Counterclockwise for A
int dirA = 12; //Counterclockwise for A

int enB  = 11; // Clockwise for B
int dirB  = 13; // Counterclockwise for B

//const int stepsPerRevolution = ;  // Change this to fit the number of steps per revolution
                                     // for your motor

// Initialize the stepper library on pins 12 and 13:
//Stepper myStepper(stepsPerRevolution, dirA, dirB);            


void setup() {
  // set the speed at 60 rpm:
  //myStepper.setSpeed(30);
  
  pinMode(enA, OUTPUT);
  pinMode(dirA, OUTPUT); 
  pinMode(enB, OUTPUT);
  pinMode(dirB, OUTPUT); 
}

void loop() {
  // Step five revolutions into one direction:
  //myStepper.step(stepsPerRevolution*100000000);
  // Step five revolutions in the other direction:
  //myStepper.step(-stepsPerRevolution*5);
  //delay(2000); 
  
  // 6 volts - turning: 300
  
  // FORWARD
  digitalWrite (enA, HIGH); 
  digitalWrite (dirA, HIGH);
  digitalWrite (enB, HIGH); 
  digitalWrite (dirB, HIGH);
  
  delay(10000); 
  
  // RIGHT
  digitalWrite (enA, HIGH); 
  digitalWrite (dirA, LOW);
  digitalWrite (enB, HIGH); 
  digitalWrite (dirB, HIGH);
  
  delay(300); 
  
  // FORWARD
  digitalWrite (enA, HIGH); 
  digitalWrite (dirA, HIGH);
  digitalWrite (enB, HIGH); 
  digitalWrite (dirB, HIGH);
  
  delay(500); 
  
  // LEFT
  digitalWrite (enA, HIGH); 
  digitalWrite (dirA, HIGH);
  digitalWrite (enB, HIGH); 
  digitalWrite (dirB, LOW);
  
  delay(300); 
  
  // FORWARD
  digitalWrite (enA, HIGH); 
  digitalWrite (dirA, HIGH);
  digitalWrite (enB, HIGH); 
  digitalWrite (dirB, HIGH);
  
  delay(500); 
  
  // BACKWARD
  digitalWrite (enA, HIGH); 
  digitalWrite (dirA, LOW);
  digitalWrite (enB, HIGH); 
  digitalWrite (dirB, LOW);
  
  delay(500); 
}
