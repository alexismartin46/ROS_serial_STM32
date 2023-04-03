/*
 * main.cpp

 *
 *  Created on: 2018/01/17
 *      Author: yoneken
 */
#include <mainpp.h>
#include <ros.h>
#include <std_msgs/String.h>
#include "main.h"	// added by A. Martin
#include "stdio.h"

ros::NodeHandle nh;
int i=0;

std_msgs::String str_msg;
ros::Publisher chatter("chatter", &str_msg);
char hello[32];

void HAL_UART_TxCpltCallback(UART_HandleTypeDef *huart){
  nh.getHardware()->flush();
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart){
  nh.getHardware()->reset_rbuf();
}

void setup(void)
{
  nh.initNode();
  nh.advertise(chatter);
}

void loop(void)
{
#ifdef STM32F4xx
  HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
#endif
#ifdef STM32F3xx
  HAL_GPIO_TogglePin(GPIOB, GPIO_PIN_3);
#endif
#ifdef STM32G4xx	// added by A. Martin
  HAL_GPIO_TogglePin(LD2_GPIO_Port, LD2_Pin);
#endif

  //str_msg.data = hello;
  snprintf(hello,32,"hello world %d",i);
  str_msg.data = hello;
  chatter.publish(&str_msg);
  nh.spinOnce();
  i++;

  HAL_Delay(1000);
}
