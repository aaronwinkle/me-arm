#include <Servo.h>
int leftPin = 8; //angle B
int rightPin = 11; //A

int hInitial = 70; // = 10 when it should be 30, 20 when it should be 40, therefore it is under by 20 and needs 20 added.
int rInitial = 70; //113 when it should be 100, 110 when it should be 90, therefore it is over by 20 and needs 20 subtracted.

int h = hInitial; // +20; //add 20 when h is 50
int r = rInitial; // -15; //subtract 15 when r is 50

int l = 80;

Servo left;
Servo right;
void setup() {
  // put your setup code here, to run once:
  left.attach(leftPin);
  right.attach(rightPin);
  Serial.begin(9600);
}
int setRight(double rad, double hi) //A, determines rad? or 
{
  double angle;
  int d = hi*hi + rad * rad;
  angle =    180- ((acos((d/(2.0*l*l))-1)+2*atan(hi/rad))/2)*(180/3.1415);
  return (int)angle;
}
int setLeft(double rad, double hi) //B, determines h? or 
{
  double angle;
  int d = hi * hi + rad * rad;
  angle =  (((acos((d/(2.0*l*l))-1) - 2 * atan(hi/rad)))/2)*(180/3.1415);
  return (int)angle;
}
void loop() {
  // put your main code here, to run repeatedly:
  int rightAngle = setRight(r,h);
  int leftAngle = setLeft(r,h);
  right.write((rightAngle+25*rightAngle)); //A   ADJUST ANLGES HERE +35 for 50 r/h   //+25*rightAngle for 70h/50r
  left.write((leftAngle-5+10*leftAngle)); //B    ADJUST ANGLES HERE +10 for 50 r/h   //-5+10*leftAngle for 70h/50r
  Serial.print("A = ");
  Serial.print(rightAngle);
  Serial.print(", actual: ");
  Serial.print(right.read());
  Serial.println();
  Serial.print("B = ");
  Serial.print(leftAngle);
  Serial.print(", actual: ");
  Serial.print(left.read());
  Serial.println();
  Serial.print("Radius (in) = ");
  Serial.print(rInitial/25.4);
  Serial.print(", Radius [adjusted] (in) = ");
  Serial.print(r/25.4);
  Serial.println();
  Serial.print("Height (in) = ");
  Serial.print(hInitial/25.4);
  Serial.print(", Height [adjusted] (in) = ");
  Serial.print(h/25.4);
  delay(100000000);
}
