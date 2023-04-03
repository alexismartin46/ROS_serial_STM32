# ROS_serial_STM32
Do ROS with STM32 on UART. This project is composed of two parts : 
- one for STM32 (*"STM32_project"* folder) 
- one for Raspberry Pi (*"RPI"* folder).

This example creates a ROS node *"/chatter"* on STM32 that can be seen by a Raspberry PI with UART connection.

## Note
This is a part of [rosserial](https://github.com/ros-drivers/rosserial) repository to communicate with ROS system through a USART for STM32 embedded system.

## Limitation
This is used with **STM32-NUCLEO-G431RB** board.

## Generation of c++ libraries for STM32 (messages etc ...)
    $ rosrun rosserial_stm32 make_libraries.py
 
## Install rosserial on RPI (with noetic)
    $ sudo apt-get install python-serial

http://wiki.ros.org/rosserial

## Start rosserial node on RPI
    $ rosrun rosserial_python serial_node.py /dev/serial0

Replace */serial0* by the port name of your RPi
Do not forget to activate UART communication on your RPi first (https://www.raspberrypi.com/documentation/computers/configuration.html#configuring-uarts)




