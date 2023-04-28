# Robotic-arm

This code is for a Bluetooth controlled robotic arm using an Arduino board. It makes use of four servos to control the movement of the arm, and a Bluetooth module to receive instructions from a mobile application.

The program starts with the initialization of the necessary libraries and objects for the servos and Bluetooth module. A function called zeroset() is also defined to initialize the servos to a neutral position.

In the setup() function, the servos are attached to their corresponding pins on the board, the zeroset() function is called, and the Bluetooth module is started.

In the loop() function, the program checks if data is available through the Bluetooth module. If so, the function detaches all the servos from their pins, reads the two bytes of data sent by the mobile application, and stores them as a single unsigned integer called 'bits'. This value is printed to the serial monitor for debugging purposes.

The program then compares the received value with specific ranges for each servo. If the value falls within a range, the corresponding servo is attached to its pin and the value is mapped from the range sent by the mobile application (1000-1180 for S1, 2000-2180 for S2, 3000-3180 for S3, 4000-4180 for SG) to the range of the servo (0-180 degrees). The mapped value is then written to the servo and the servo is reattached to its pin.

This process repeats continuously, allowing the user to control the arm through the mobile application.

![WhatsApp Image 2023-01-03 at 19 35 02](https://user-images.githubusercontent.com/127997008/235251729-3e215d06-83ad-4477-a6f3-7e135bfa2cf1.jpeg)


