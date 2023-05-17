//all grayscale sensors pins
int sensorPin1 = 0;
int sensorPin2 = 1;
int sensorPin3 = 2;
int sensorPin4 = 3;
int sensorPin5 = 4;
int sensorPin6 = 5;
int sensorPin7 = 6;

//left motor direction control
int m1 = 5;

//right motor direction control
int m2 = 6; 

//m1 speed control
int e1 = 4;  

//m2 speed control
int e2 = 7;  

//records number of stops
int i = 0;

void setup() 
{
  Serial.begin(9600);

  pinMode(sensorPin1, INPUT);
  pinMode(sensorPin2, INPUT);
  pinMode(sensorPin3, INPUT);
  pinMode(sensorPin4, INPUT);
  pinMode(sensorPin5, INPUT);
  pinMode(sensorPin6, INPUT);
  pinMode(sensorPin7, INPUT);

  pinMode (m1, OUTPUT);
  pinMode (e1, OUTPUT);
  pinMode (m2, OUTPUT);
  pinMode (e2, OUTPUT);
}

void halt() //stops the robot
{
  analogWrite(e1, 0);
  analogWrite(e2, 0);
  digitalWrite(m1, LOW);
  digitalWrite(m2, LOW);
}

void forward(int speed) //makes the robot go forward
{
  analogWrite(e1, speed);
  digitalWrite(m1, HIGH);
  analogWrite(e2, speed);
  digitalWrite(m2, HIGH);
}

void turnR(int speed) //makes the robot turn right
{
  analogWrite(e1, speed); 
  digitalWrite(m1, LOW);
  analogWrite(e2, speed);
  digitalWrite(m2, HIGH);
}

void turnL(int speed) //makes the robot turn left       
{
  analogWrite(e1, speed);
  digitalWrite(m1, HIGH);
  analogWrite(e2, speed);
  digitalWrite(m2, LOW);
}

void loop() 
{
  /* CHAR INSERTED BY THE USER
   * TO MANUALLY CONTROL THE ROBOT
  char in = Serial.read();
  */
  
  int value1 = analogRead(sensorPin1);
  int value2 = analogRead(sensorPin2);
  int value3 = analogRead(sensorPin3);
  int value4 = analogRead(sensorPin4);
  int value5 = analogRead(sensorPin5);
  int value6 = analogRead(sensorPin6);
  int value7 = analogRead(sensorPin7);
  
  if (value4 <= 10)
  {
     forward(1);
     Serial.println("Forward: ");
//     Serial.print(analogRead(e1));
//     Serial.print(", ");
//     Serial.println(analogRead(e2));
  }

  if (value1 <=10 || value2 <= 10 || value3 <= 10 && value5 > 10)
  {
     turnL(1);
     Serial.println("Left turn: ");
//     Serial.print(analogRead(e1));
//     Serial.print(", ");
//     Serial.println(analogRead(e2));
  }
    
  if (value5 <= 10 || value6 <= 10 || value7 <= 10 && value3 > 10)
  {
     turnR(1);
     Serial.println("Right turn: ");
//     Serial.print(analogRead(e1));
//     Serial.print(", ");
//     Serial.println(analogRead(e2));
     
  }

  if (value1 > 10 && value2 > 10 && value3 > 10 && value4 > 10 && 
      value5 > 10 && value6 > 10 && value7 > 10)
  {
     halt();
     i++;
     
     Serial.println("Stop");
  }

  /* TURNS THE ROBOT  
   * WITH THE USER INPUT
 
  if (in == 'l' && i < 10)
  {
      turnL(10); 
      Serial.println("Turn left");
  }

  if (in == 'r' && i < 10)
  {
     turnR(10);
     Serial.println("Turn right");
  }
 */

  delay (200);
}
