#include <Arduino.h>

// put function declarations here:
void move(int motor, int speed, int direction);
void stop();

int STBY = 4; // activacion
// Motor A
int PWMA = 10; // control de vel
int AIN1 = 8;  // sentido
int AIN2 = 7;  // sentido
// Motor B
int PWMB = 11;
int BIN1 = 12;
int BIN2 = 13;

void setup()
{
  Serial.begin(921600);
  pinMode(STBY, OUTPUT);
  pinMode(PWMA, OUTPUT);
  pinMode(AIN1, OUTPUT);
  pinMode(AIN2, OUTPUT);
  pinMode(PWMB, OUTPUT);
  pinMode(BIN1, OUTPUT);
  pinMode(BIN2, OUTPUT);
}

void loop()
{
  // put your main code here, to run repeatedly:
}

// put function definitions here:
void move(int motor, int speed, int direction)
{
  digitalWrite(STBY, HIGH);
  boolean inPin1 = LOW;
  boolean inPin2 = HIGH;

  if (direction == 1)
  {
    inPin1 = HIGH;
    inPin2 = LOW;
  }
  if (motor == 1)
  {
    digitalWrite(AIN1, inPin1);
    digitalWrite(AIN2, inPin2);
    analogWrite(PWMA, speed);
  }
  else
  {
    digitalWrite(BIN1, inPin1);
    digitalWrite(BIN2, inPin2);
    analogWrite(PWMB, speed);
  }
}

void stop()
{
  // enable standby
  digitalWrite(STBY, LOW);
}