# 🤖 Voice-controlled-obstacle-avoiding-robot

## 🎯 Overview

This project is an Arduino-based smart robot controlled using voice commands transmitted via Bluetooth.

The robot continuously monitors its surroundings and automatically prevents collisions using ultrasonic and IR sensors while remaining under voice control.

---

## 🌟 Features

 - ✅ Voice control using smartphone
-  ✅ Bluetooth communication with HC-05
-  ✅Forward, backward, left and right movement
 - ✅Front obstacle detection using ultrasonic sensor
-  ✅ Rear obstacle detection using IR sensor
 - ✅ Buzzer warning system
 - ✅ Collision prevention during operation
 - ✅ L298N motor control

---

## ⚙️ Components Used

- Arduino UNO
- HC-05 Bluetooth Module
- HC-SR04 Ultrasonic Sensor
- SG90 Servo Motor
- IR Obstacle Sensor
- L298N Motor Driver
- Active Buzzer
- BO Motors

---

## 🪛 Working Principle

The robot receives voice commands from a smartphone through Bluetooth.

Supported commands:

- Forward
- Backward
- Left
- Right
- Stop

Safety features operate automatically:

### Front Protection

The ultrasonic sensor detects obstacles in front of the robot.

If an object is detected within the safety range, the robot stops and alerts the user.

### Rear Protection

The IR sensor monitors the rear side of the robot.

If an obstacle is detected while reversing, the robot immediately stops and activates the buzzer for some time.

---

## 📌 Pin Configuration

| Component | Arduino Pin |
|------------|------------|
| HC-05 TX | D2 |
| HC-05 RX | D4 |
| Servo | D3 |
| ENA | D5 |
| ENB | D6 |
| Rear IR Sensor | D7 |
| IN1 | D8 |
| IN2 | D9 |
| IN3 | D10 |
| IN4 | D11 |
| Buzzer | D12 |
| Ultrasonic Echo | A0 |
| Ultrasonic Trigger | A1 |

## 🔋 Power Connections 

| From | To |
|------|----|
| Battery (+) | L298N 12V Terminal |
| Battery (-) | L298N GND Terminal |
| L298N GND, HC-05 GND, HC-SR04 GND, Servo GND, IR Sensor GND, Buzzer GND | Arduino Uno GND |
| HC-05 VCC, HC-SR04 VCC, Servo VCC, IR Sensor VCC, Buzzer VCC | Arduino Uno 5V |
| L298N 5V | Arduino Uno 5V |
---

## 🈸 Applications

- Robotics Learning
- Educational Projects
- Smart Vehicle Prototypes
- Robotics Club Demonstrations

---

