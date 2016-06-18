#include <PS2X_lib.h>
PS2X ps2x; 
int error = 0;
byte vibrate = 0;
int pin1 = 2;
int pin2 = 3;
int pin3 = 16;
int pin4 = 17;
void setup()
{
 pinMode(pin1, OUTPUT);
 pinMode(pin2, OUTPUT);
 pinMode(pin3, OUTPUT);
 pinMode(pin4, OUTPUT);
 Serial.begin(57600);
error = ps2x.config_gamepad(13,11,10,12, true, true); 
}
void loop(){
 ps2x.read_gamepad(false, vibrate);
if(ps2x.Button(PSB_PAD_UP)) 
 { 
 analogWrite(pin1,ps2x.Analog(PSAB_PAD_UP)); 
 analogWrite(pin2, 0);
 analogWrite(pin3,ps2x.Analog(PSAB_PAD_UP));
 analogWrite(pin4, 0);
 }
 if(ps2x.ButtonReleased(PSB_PAD_UP)) 
 {
 analogWrite(pin1, 0); 
 analogWrite(pin2, 0);
 analogWrite(pin3, 0); 
 analogWrite(pin4, 0);
 }
if(ps2x.Button(PSB_PAD_RIGHT))
 { 
 analogWrite(pin1,ps2x.Analog(PSAB_PAD_RIGHT)); 
 analogWrite(pin2, 0);
 }
 if(ps2x.ButtonReleased(PSB_PAD_RIGHT)) 
 {
 analogWrite(pin1, 0); 
 analogWrite(pin2, 0);
 analogWrite(pin3, 0); 
 analogWrite(pin4, 0);
 }
if(ps2x.Button(PSB_PAD_LEFT))
 {
 analogWrite(pin3, ps2x.Analog(PSAB_PAD_LEFT)); 
 analogWrite(pin4, 0);
 }
 if(ps2x.ButtonReleased(PSB_PAD_LEFT)) 
 {
 analogWrite(pin1, 0); 
 analogWrite(pin2, 0);
 analogWrite(pin3, 0); 
 analogWrite(pin4, 0);
 }
if(ps2x.Button(PSB_PAD_DOWN))
 {
 analogWrite(pin2, ps2x.Analog(PSAB_PAD_DOWN)); 
 analogWrite(pin1, 0);
 analogWrite(pin4, ps2x.Analog(PSAB_PAD_DOWN)); 
 analogWrite(pin3, 0);
 } 
 if(ps2x.ButtonReleased(PSB_PAD_DOWN)) 
 {
 analogWrite(pin1, 0); 
 analogWrite(pin2, 0);
 analogWrite(pin3, 0); 
 analogWrite(pin4, 0);
 }
}
