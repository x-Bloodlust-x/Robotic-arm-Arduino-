/*

*/

#include <Servo.h>
// we have to call servo header file to use its function
Servo S1;
Servo S2;
Servo S3; 
Servo SG; 

void setup() {
  
  S1.attach(9); 
  S2.attach(10); 
  S3.attach(11); // connects each servo to the board
  SG.attach(6);
  // initialising the servos to 0th position
  S1.write(90); // bottom 2 have 90
  S2.write(90);
  S3.write(40); // this is top servo
  
  SG.write(0);
  delay(1000)
}

void loop() {
  
  digitalWrite(11,HIGH); 
  
    
}
