# Gesture-controlled-Robotic-Arm
The focus of this project is to design and build a robotic arm that can mimic a person’s arm movements. This overall system is composed of Control, Software, Communications, and Hand/Myo Subsystems. The robotic arm system utilizes the Kinect technology to send the arm movement sampling signal to the mechanical robotic arm. Two Graphical User Interfaces (GUI) were developed using the Python TkInter and the C++ Fast Light Toolkit (FLTK) library. The Python TkInter GUI provides the user the options to run different functions of the entire system. The C++ FLTK GUI integrates the Kinect sampling algorithm and displays the skeletal tracking data. The Kinect is used to capture the user’s skeleton data, then it’s further processed to define the Pulse Width Modulation (PWM) signal used to drive several servo motors on the robotic arm. Five of these servo motors in total are integrated on the robotic arm. Three of which are controlled using Kinect data, while the other two are controlled using the data from the Myo armband. A joystick is integrated to control the movements of the vehicle. A camera module was added and placed on the vehicle to provide visual feedback on the interface screen. In addition, all data and instructions are transmitted wirelessly among the subsystems over Wi-Fi. This proof-of-concept robot creates a better user interface for people that work in dangerous situations while still capturing human perspective and interactions.

# System Overview
![1687471510948](https://github.com/yuantian94/Gesture-controlled-Robotic-Arm/assets/13746207/286bab32-3457-4306-92f8-afa21645d873)
![1687471738096](https://github.com/yuantian94/Gesture-controlled-Robotic-Arm/assets/13746207/242f8333-18e9-4988-a7d4-0d7c2a9a99f0)
![1687472434910](https://github.com/yuantian94/Gesture-controlled-Robotic-Arm/assets/13746207/3a59cb54-de14-498f-bbb9-fe848b39c657)

This collaborative project for ECEN 404 involves the contributions of Kevin Bradshaw, Fuhua Song, Yuan Tian, and Zhengshuai Zhang. The author of this repository assumes responsibility for designing the Kinect software, implementing the sampling algorithm, and contributing to the communication subsystem. The code in this repository solely encompasses the work attributed to the author.

In addition to the code, this repository also contains the comprehensive final project report. This report serves as a complete record, documenting the entire project journey from initial planning to the development of the final product.

# Subsystem Application Demo
- Inverse-kinematics Algorithm
  ![image](https://github.com/yuantian94/Gesture-controlled-Robotic-Arm/assets/13746207/975a8731-7923-42e7-87e6-425e7bd8f320)

- User interface for Calibration and Data Sampling
  ![1687895404695](https://github.com/yuantian94/Gesture-controlled-Robotic-Arm/assets/13746207/bde7fedd-a628-49e6-8473-5ed22f889a77)
  ![image](https://github.com/yuantian94/Gesture-controlled-Robotic-Arm/assets/13746207/c7c50720-2a9e-4a90-b7ac-a79c69910e59)
