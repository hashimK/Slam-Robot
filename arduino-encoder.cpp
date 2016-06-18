#include<ros.h>
#include<geometry_msgs/Vector3.h>
#include<Encoder.h>
ros::NodeHandle nh;
geometry_msgs::Vector3 data;
ros::Publisher pos("pos",&data);
int real_data[4];
int motor_left_f = 7;//IN1 of motor 1
int motor_left_r = 11;//IN2 of motor 1
int enable_left = 12;//1
int motor_right_f = 10;//IN1 of motor 2
int motor_right_r= 8;//IN2 of motor 2
int enable_right = 9;//2
Encoder r_encoder(2,3);
Encoder l_encoder(20,21);
long r_oldPosition=-999;
long l_oldPosition=-999;
void setup()
{
 Serial.begin(57600);
 nh.initNode();
 nh.advertise(pos);
 pinMode(motor_left_f,OUTPUT);
 pinMode(motor_left_r,OUTPUT);
 pinMode(motor_right_r,OUTPUT);
 pinMode(motor_right_f,OUTPUT);
 pinMode(enable_left,OUTPUT);
 pinMode(enable_right,OUTPUT);
}
void loop()
{
 long r_newPosition=r_encoder.read();
 long l_newPosition=l_encoder.read();
 if (r_newPosition != r_oldPosition) {
 r_oldPosition = r_newPosition;
 data.x=r_newPosition;
 }
 if (l_newPosition != l_oldPosition) {
 l_oldPosition = l_newPosition; 
 data.y=l_newPosition;
 }
 wheel_encoder.publish(&data);
 nh.spinOnce();
 delay(25);
}
