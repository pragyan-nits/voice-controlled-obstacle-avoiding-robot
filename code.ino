#include <Servo.h>
#include <SoftwareSerial.h>

SoftwareSerial BT(2, 4);   // HC-05 TX->D2 RX->D4
Servo myservo;

// Ultrasonic
#define trigPin A1
#define echoPin A0

// Rear IR
#define rearIR 7

// Buzzer
#define BUZZER 12

// L298N
#define ENA 5
#define ENB 6

#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11

String currentCommand = "stop";

void setup()
{
  Serial.begin(9600);
  BT.begin(9600);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  pinMode(rearIR, INPUT);

  pinMode(BUZZER, OUTPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  analogWrite(ENA, 180);
  analogWrite(ENB, 180);

  myservo.attach(3);
  myservo.write(90);

  stopRobot();

  Serial.println("Robot Ready");
}

void loop()
{
  // Continuous rear obstacle protection
  if(currentCommand == "backward" && digitalRead(rearIR) == 0)
  {
    stopRobot();
    currentCommand = "stop";
    longBeep();
    Serial.println("Rear Obstacle");
  }

  // Continuous front obstacle protection
  if(currentCommand == "forward" && frontDistance() < 20)
  {
    stopRobot();
    currentCommand = "stop";
    beep();
    Serial.println("Front Obstacle");
  }

  if(BT.available())
  {
    String cmd = BT.readStringUntil('\n');

    cmd.trim();
    cmd.toLowerCase();

    Serial.print("Received: ");
    Serial.println(cmd);

    if(cmd == "forward")
    {
      if(frontDistance() > 25)
      {
        forward();
        currentCommand = "forward";
      }
      else
      {
        stopRobot();
        beep();
      }
    }

    else if(cmd == "backward")
    {
      if(digitalRead(rearIR) == 1)
      {
        backward();
        currentCommand = "backward";
      }
      else
      {
        stopRobot();
        longBeep();
      }
    }

    else if(cmd == "left")
    {
      myservo.write(160);
      delay(400);

      if(frontDistance() > 25)
      {
        leftTurn();
        currentCommand = "left";
      }
      else
      {
        stopRobot();
        beep();
      }

      myservo.write(90);
    }

    else if(cmd == "right")
    {
      myservo.write(20);
      delay(400);

      if(frontDistance() > 25)
      {
        rightTurn();
        currentCommand = "right";
      }
      else
      {
        stopRobot();
        beep();
      }

      myservo.write(90);
    }

    else if(cmd == "stop")
    {
      stopRobot();
      currentCommand = "stop";
    }
  }
}

// =====================
// DISTANCE FUNCTION
// =====================

int frontDistance()
{
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);

  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000);

  if(duration == 0)
    return 300;

  return duration * 0.034 / 2;
}

// =====================
// BUZZER
// =====================


void beep()
{
  digitalWrite(BUZZER, HIGH);
  delay(100);
  digitalWrite(BUZZER, LOW);
}

void longBeep()
{
  digitalWrite(BUZZER, HIGH);
  delay(500);
  digitalWrite(BUZZER, LOW);
}

// =====================
// MOTOR FUNCTIONS
// =====================

void forward()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void backward()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void leftTurn()
{
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void rightTurn()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void stopRobot()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);

  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
