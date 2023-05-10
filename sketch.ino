// int rightIR=2;// purple wire
// int leftIR=3;// black wire
// // 5th pin 3 and 4th mototr red
// //9th pin 1 and 2 motor dark green
int A=9; // dark green
int B=5;
int speed;

int x;
int y;

char input;     // to store input character received via BT.

void setup()
{
  Serial.begin(9600);  
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  // pinMode(2,INPUT);
  // pinMode(3,INPUT);
  pinMode(A0,INPUT);
  pinMode(9, OUTPUT); // dark green 3rd and 4th motor
  pinMode(5,OUTPUT); // red 1 and 2nd motor
}

void loop()
{
  speed = analogRead(A0);
  speed = speed * 0.249;
  analogWrite(A,speed);
  analogWrite(B,speed);

  //speed = 255;
  while(Serial.available())
  {
    //declared the a0 pin from which the data will be take input 
  // x = analogRead(A0);
  // y = map(x,0,1023,0,255);
    input = Serial.read();
    
    if(input == 'F')
    {
      forward();
    }

    else if (input == 'R')
    {
      right();  
    }

    else if (input == 'L')
    {
      left();
    }  

    else if (input == 'G')
    {
      backward();
    }  
    else if (input == 'S')
    {
      stop();
    }
  // analogWrite(6,y);
  // analogWrite(11,y);
  } 
}  
void forward()
  {
  digitalWrite(4, LOW	);
  digitalWrite(6, HIGH);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
}

void stop()
  {
  digitalWrite(4, LOW	);
  digitalWrite(6, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
}

void backward()
  {
  digitalWrite(4, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
}

void left()
  {
  digitalWrite(4, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
}

void right()
  {
  digitalWrite(4, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(10, LOW);
  digitalWrite(11, HIGH);
}