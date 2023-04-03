# ROS_serial_STM32
Do ROS with STM32 on UART. This project is composed of two parts : one for STM32 ("STM32_project" folder) and one for Raspberry Pi ("RPI" folder). This example creates a ROS node "/chatter" on STM32 that can be seen by a Raspberry PI with UART connectivity.

## Note
This is a part of [rosserial](https://github.com/ros-drivers/rosserial) repository to communicate with ROS system through a USART for STM32 embedded system.

## Limitation
This is used with STM32-NUCLEO-G431RB board.

## Generation of c++ libraries for STM32 (messages etc ...)
$ rosrun rosserial_stm32 make_libraries.py
 
## 
 