# Robotic-arm

This code is for a Bluetooth controlled robotic arm using an Arduino board. It makes use of four servos to control the movement of the arm, and a Bluetooth module to receive instructions from a mobile application.

The program starts with the initialization of the necessary libraries and objects for the servos and Bluetooth module. A function called zeroset() is also defined to initialize the servos to a neutral position.

In the setup() function, the servos are attached to their corresponding pins on the board, the zeroset() function is called, and the Bluetooth module is started.

In the loop() function, the program checks if data is available through the Bluetooth module. If so, the function detaches all the servos from their pins, reads the two bytes of data sent by the mobile application, and stores them as a single unsigned integer called 'bits'. This value is printed to the serial monitor for debugging purposes.

The program then compares the received value with specific ranges for each servo. If the value falls within a range, the corresponding servo is attached to its pin and the value is mapped from the range sent by the mobile application (1000-1180 for S1, 2000-2180 for S2, 3000-3180 for S3, 4000-4180 for SG) to the range of the servo (0-180 degrees). The mapped value is then written to the servo and the servo is reattached to its pin.

This process repeats continuously, allowing the user to control the arm through the mobile application.

![WhatsApp Image 2023-01-03 at 19 35 02](https://user-images.githubusercontent.com/127997008/235251729-3e215d06-83ad-4477-a6f3-7e135bfa2cf1.jpeg)

**Stages of building the product:**

![bd887b57-7731-4991-97dd-2eae56004ef9](https://github.com/x-Bloodlust-x/Robotic-arm-Arduino-/assets/127997008/748893ba-433f-4c3e-a736-113297dd375b)
![e6ce27c6-5f51-4d2f-91a3-25c68b0674fe](https://github.com/x-Bloodlust-x/Robotic-arm-Arduino-/assets/127997008/41a3de95-041f-4233-ae87-ec7c9f5229e7)
![ca36b8a3-b925-43d7-8e57-1ccae3fa67ff](https://github.com/x-Bloodlust-x/Robotic-arm-Arduino-/assets/127997008/a23cf32f-694d-4d17-b74f-908467fc7939)
![80c7a8ee-e4e2-4f38-8fbe-b7a78e2f4589](https://github.com/x-Bloodlust-x/Robotic-arm-Arduino-/assets/127997008/15047591-b461-4da0-b846-f6a243cf7a8c)
![6fa09df3-2b67-4fe5-866d-cbe665fad90e](https://github.com/x-Bloodlust-x/Robotic-arm-Arduino-/assets/127997008/913c3d39-7664-4abc-a684-0a1abccdbad0)
![124741c0-3507-40a6-b39a-0b9c2b1b14ad](https://github.com/x-Bloodlust-x/Robotic-arm-Arduino-/assets/127997008/e53475f6-fa52-41d2-adcb-2245e779e527)
![1940f92e-2f33-46a8-ad58-7d6c0b34f2b2](https://github.com/x-Bloodlust-x/Robotic-arm-Arduino-/assets/127997008/d2268b6b-2ecd-4d7f-9568-030e39cb92cb)

