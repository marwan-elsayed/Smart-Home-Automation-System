# Smart Home Automation System

This project implements a **Smart Home Automation System** using the **ATmega32** microcontroller. It controls lighting and fan speed based on environmental conditions and includes fire detection and alerts.

## Features
- **Automatic Lighting Control**: Adjusts LEDs based on ambient light (LDR).
- **Temperature-based Fan Control**: Fan speed changes according to room temperature (LM35).
- **Fire Detection and Alarm**: Flame sensor triggers alarm and LCD alerts.
- **Real-time Monitoring**: Displays temperature, light intensity, and fan status on a 16x2 LCD.

## Project On Proteus
![image]![Screenshot 2024-10-11 182437](https://github.com/user-attachments/assets/efd56b6f-bf49-4c9b-b543-4d78b84b1bdb)

## Software Layers
- **MCAL**: Drivers for hardware interaction (ADC, PWM, GPIO).
- **HAL**: Abstraction for controlling sensors and actuators.
- **Application Layer**: Logic for adjusting fan speed, lights, and fire alerts.

## Hardware Components
- **Microcontroller**: ATmega32
- **Sensors**: LDR, LM35, Flame Sensor
- **Actuators**: Fan (PWM control), LEDs, Buzzer
- **Display**: 16x2 LCD for system status
