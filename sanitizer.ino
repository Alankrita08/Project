#include <Servo.h>

const int trigger = 9;
const int echo = 8;
long timeperiod;
int distance;
Servo motor;
void setup()
{
motor.attach(7);
pinMode(trigger, OUTPUT); 
pinMode(echo, INPUT);
Serial.begin(9600);
Serial.println("LABEL,Date, Time,Distance (in cm),Servomotor Status");
}

void loop() 
{
Serial.print("DATA, DATE, TIME,");
distance = getdistance();
Serial.print(distance);
Serial.print(",");
motor.write(0);
if ( distance < 5)
{ motor.attach(7);
motor.write(160);
Serial.println(1);
delay(500);
motor.write(0);
delay(1000);

}
else
{
motor.detach();
Serial.println(0);
}
}

int getdistance(){

digitalWrite(trigger, LOW);
delayMicroseconds(5);
digitalWrite(trigger, HIGH);
delayMicroseconds(10);
digitalWrite(trigger, LOW);
timeperiod = pulseIn(echo, HIGH);
distance= timeperiod*0.034/2;
return distance;
}
