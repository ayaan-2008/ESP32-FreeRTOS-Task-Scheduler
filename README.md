# ESP32 FreeRTOS Task Scheduler

## Overview

This project demonstrates multitasking on the ESP32 using FreeRTOS.

Multiple tasks execute concurrently while communicating through a FreeRTOS queue. The system simulates a temperature monitoring application with task scheduling, inter-task communication, and runtime statistics monitoring.

## Features

- FreeRTOS Multitasking
- Task Prioritization
- Queue-Based Communication
- Simulated Sensor Data
- System Heartbeat Monitoring
- Heap Memory Monitoring
- Real-Time Processing

## Tasks Implemented

### Sensor Task
Generates simulated temperature values and sends them to a queue.

### Processing Task
Receives temperature values from the queue and generates alerts for high temperatures.

### Heartbeat Task
Indicates that the system is running correctly.

### Statistics Task
Displays available heap memory and system status.

## FreeRTOS Concepts Demonstrated

- Task Creation
- Task Scheduling
- Priorities
- Queues
- Inter-Task Communication
- Delays
- Heap Monitoring

## Hardware

- ESP32
- USB Serial Monitor

## Technologies

- ESP32
- Arduino Framework
- FreeRTOS
