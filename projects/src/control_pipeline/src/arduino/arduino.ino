/*
 * rosserial Servo Control Example
 *
 * This sketch demonstrates the control of hobby R/C servos
 * using ROS and the arduiono
 * 
 * For the full tutorial write up, visit
 * www.ros.org/wiki/rosserial_arduino_demos
 *
 * For more information on the Arduino Servo Library
 * Checkout :
 * http://www.arduino.cc/en/Reference/Servo
 */

#if (ARDUINO >= 100)
 #include <Arduino.h>
#else
 #include <WProgram.h>
#endif

#include <Servo.h> 
#include <ros.h>
#include <std_msgs/UInt16.h>

ros::NodeHandle  nh;

Servo servo1, servo2;
int last_value1 = 90;
int last_value2 = 90;

void servo_cb1( const std_msgs::UInt16& cmd_msg){
  if(cmd_msg.data == 90)
  {
    
     servo1.write(last_value1); 
  }
  else
  {
    servo1.write(cmd_msg.data); 
    last_value1 = cmd_msg.data;  
  }
  //set servo angle, should be from 0-180  
  //Serial.print(cmd_msg.data);
  //digitalWrite(13, HIGH-digitalRead(13));  //toggle led  
}
void servo_cb2( const std_msgs::UInt16& cmd_msg){
  if(cmd_msg.data == 90)
  {
     servo2.write(last_value2); 
  }
  else
  {
    servo2.write(cmd_msg.data); 
    last_value2 = cmd_msg.data;  
  }
  //Serial.print("       ");
  //Serial.println(cmd_msg.data);
  //digitalWrite(13, HIGH-digitalRead(13));  //toggle led  
}


ros::Subscriber<std_msgs::UInt16> sub1("servo1", servo_cb1);

ros::Subscriber<std_msgs::UInt16> sub2("servo2", servo_cb2);

void setup(){
  pinMode(13, OUTPUT);
  
  //Serial.begin(9600);
  nh.initNode();
  nh.subscribe(sub1);
  nh.subscribe(sub2);
  
  servo1.attach(9); //attach it to pin 9
  servo2.attach(10); //attach it to pin 10
}

void loop(){
  nh.spinOnce();
  delay(1);
}
