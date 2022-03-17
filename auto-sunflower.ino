
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards

int pos = 0;    // variable to store the servo position
int sensorPin1 = A1;
int sensorPin2 = A2;
int sensorPin3 = A3;

int sensorValue1 = 0;
int sensorValue2 = 0;
int sensorValue3 = 0;

void setup() {
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
  myservo.write(0); // reset servo position
  Serial.begin(9600);
}

void loop() {
  sensorValue1 = analogRead(sensorPin1);
  sensorValue2 = analogRead(sensorPin2);
  sensorValue3 = analogRead(sensorPin3);

  // find highest light sensor value
  int highest = sensorValue1;
  int highestPin = sensorPin1;
  if(highest < sensorValue2) { highest = sensorValue2; highestPin = sensorPin2; }
  if(highest < sensorValue3) { highest = sensorValue3; highestPin = sensorPin3; }
  Serial.println(highestPin);
  
  if(highestPin == 15){ pos = 0; }
  else if (highestPin == 16) { pos = 90; }
  else if (highestPin == 17) { pos = 180; }
  myservo.write(pos); 
//  Serial.println(pos);
  delay(1000);
}
