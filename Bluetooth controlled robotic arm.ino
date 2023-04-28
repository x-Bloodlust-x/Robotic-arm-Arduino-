/*
// Bluetooth controlled robotic arm
*/
#include<SoftwareSerial.h>
#include <Servo.h>

Servo S1;
Servo S2;
Servo S3; 
Servo SG; 

SoftwareSerial bluetooth(12,13); // initialising pins RX before TX // RX of bluetooth to TX of arduino

// making a function happens before set up
//RX TX are used for communication but only for Arduino

// a function is a line of code written before setup which is not executed unless u call it inside the program
//code starts running from void setup 
//void setup only runs once when the code is uploaded, then it goes to the loop

void zeroset ()
{
  // initialising the servos to 0th position
  S1.write(90); // bottom 2 have 90
  S2.write(90);
  S3.write(40); // this is top servo
  
  SG.write(0);
  delay(1000);
}
// we only want to run the code and not return a value so not use int 

void setup() {
  S1.attach(9); 
  S2.attach(10); 
  S3.attach(11); // connects each servo to the board
  SG.attach(6);
  
  zeroset();
  delay(1000);
  Serial.begin(9600);
  bluetooth.begin(9600);
}

void loop() {
  
  //app/software sends values through bluetooth 
  //for every servo, there is a specific range of values to use
  //if the the value matches, we want the servo to execute a certain action rotation - using if function
  //. available function will get values and see whether BT is getting data 
  // app will send data of 2 bits per sec, we will check this
  
  if (bluetooth.available() >= 2)
  {
S1.detach(); // this will deattach the servo from the pin for a certain period of time until we reattach it
S2.detach(); // this function will redirect the current to specific servos
S3.detach();
SG.detach();  
  
  unsigned int bit1 = bluetooth.read(); // when it is not an integer - accepts all decimal values
  unsigned int bit2 = bluetooth.read();
  
  unsigned int bits = (bit2*256) + bit1; // stores both bits together 
  Serial.println(bits); //ln prints the value on every new line 
  //range of data sent by app - S1 will send data from 1000 to 1180
  
  int servo = bits; // data is already stored in bits, but we want to compare it to the values sent by app from 0 to 180
  
  Servo reatach; // will allow reattaching again 
  
  if (bits >= 1000 && bits < 1180)
  {
   S1.attach(9); //
   servo = map(servo, 1000, 1180, 0, 180); // map function requires 5 values to work
   reatach = S1;
  }
  
  if (bits >= 2000 && bits < 2180)
  {
   S2.attach(10); //
   servo = map(servo, 2000, 2180, 0, 180); // map function requires 5 values to work
   reatach = S2;
  }
  
  if (bits >= 3000 && bits < 3180)
  {
   S3.attach(11); //
   servo = map(servo, 3000, 3180, 0, 180); // map function requires 5 values to work
   reatach = S3;
  }
  
  if (bits >= 4000 && bits < 4180)
  {
   SG.attach(6); //
   servo = map(servo, 4000, 4180, 0, 180); // map function requires 5 values to work
   reatach = SG;
  }
  //only one if loop will be executed, this value will go the servo 
  reatach.write(servo); 
  //same lines are done for each servo
  //S2 from 2000 to 2180
  //S3 from 3000 to 3180
  //SG from 4000 to 4180 
  }
    
    
}
