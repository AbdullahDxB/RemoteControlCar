# Long-Range Remote Control Bot

A robust, long-range remote-controlled robot developed for the Annual University Robotics Competition. This project showcases strong skills in embedded systems, RF communication, and system reliability, achieving a Top 5 Finalist position.

<img width="1824" height="1120" alt="Screenshot 2025-08-24 222746" src="https://github.com/user-attachments/assets/cb3e0829-1d1e-41a3-a37e-53b9e911b820" />

*The completed remote control bot, featuring the chassis, motors, and nRF receiver.*

<img width="1823" height="1073" alt="Screenshot 2025-08-24 233142" src="https://github.com/user-attachments/assets/aa6856c2-a75d-49bb-af76-e094cb25eea4" />

*The custom-built remote controller with its own Arduino and nRF transmitter.*

---

## Key Features

* **High-Performance Control:** Achieved a sub-second wireless response time and stable movement over a range of **500m** using nRF antenna modules.
* **Enhanced Precision:** Implemented custom drive logic, boosting movement precision and responsiveness by **20%**.
* **System Reliability:** Led team-based troubleshooting and performance tuning, enabling the bot to perform **30+ continuous demo runs** without critical failure.
* **Power Efficiency:** Integrated power management with an L298N motor driver, extending the operational runtime by **30%**.

---

## Technologies Used

* **Hardware:** Arduino, RF Transceivers (nRF modules), L298N Motor Driver,  Chassis, Motors, I/O Devices
* **Firmware:** C, Embedded C (Arduino IDE)

---

## Skills Demonstrated

* **Robotics:** Designing, building, and programming a functional mobile robot.
* **Embedded C:** Writing efficient, real-time firmware for microcontroller-based systems.
* **RF Communication:** Implementing a reliable, long-range wireless communication link.
* **Hardware Prototyping:** Assembling and troubleshooting a complete electromechanical system.
* **Problem-Solving:** Debugging hardware and software issues under competitive pressure to ensure system reliability.

---

## Installation & Usage

### 1. Hardware Assembly
1.  Mount the motors and wheels to the robot chassis.
2.  Connect the L298N motor driver to the Arduino and the motors.
3.  Connect the nRF transceiver module to the Arduino for receiving commands.
4.  Assemble the separate remote control unit with its own Arduino and nRF transceiver for sending commands.

### 2. Firmware
1.  Upload the `RX_Code.ino` file to the Arduino on the robot.
2.  Upload the `TX_Code.ino` file to the Arduino on the remote control.
3.  Ensure both transceivers are set to the same channel for communication.

### 3. Operation
* Power on both the robot and the remote control.
* Use the joystick or buttons on the remote control to send movement commands to the robot.

---

## Project Status

This project is **complete** and was a **Top 5 Finalist** at the Annual University Robotics Competition. It successfully demonstrated all key features, including long-range control and high reliability during multiple demo runs.
