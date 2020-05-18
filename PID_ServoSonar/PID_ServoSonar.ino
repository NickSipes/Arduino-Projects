#include <Servo.h>
Servo myServo;

// Pin defenitions
const int trigPin = 9;
const int echoPin = 10;
const int servoPin = 13;


const int middle = 23;

// State Parameters
long duration;
int distance;
int setpoint = 22;

void setup() {
  // Set up sonar
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  //Set up servo
  myServo.attach(servoPin);

  // Start serial connection
  Serial.begin(9600);
}

void loop() {

  myServo.write(middle);
  delay(1000);
  //myServo.write(0);
  //delay(1000);
  
}

int adjustServo(int d) {
  error = d - setpoint;
}

int getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);

  distance = duration*0.034/2;

  Serial.print("Distance: ");
  Serial.println(distance);
  return distance;
}
