int distance;
long duration;
int ir1 = 10;
int ir2 = 11;
int ir3 = 12;
int a1 = 2;
int a2 = 3;
int b1 = 5;
int b2 = 6;
int m,n,o;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ir1,INPUT);
  pinMode(ir2, INPUT);
  pinMode(a1,OUTPUT);
  pinMode(a2,OUTPUT);
  pinMode(b1,OUTPUT);
  pinMode(b2,OUTPUT);
}

void stop1()
{
  digitalWrite(a1,LOW);
  digitalWrite(a2,LOW);
  digitalWrite(b1,LOW);
  digitalWrite(b2,LOW);
}
void left()
{
  digitalWrite(a1,LOW);
  digitalWrite(a2,HIGH);
  digitalWrite(b1,HIGH);
  digitalWrite(b2,LOW);
  //delay(500);
}
void right()
{
  
  digitalWrite(a1,HIGH);
  digitalWrite(a2,LOW);
  digitalWrite(b1,LOW);
  digitalWrite(b2,HIGH);
  delay(500);  
}
void move1()
{
  digitalWrite(a1,HIGH);
  digitalWrite(a2,LOW);
  digitalWrite(b1,HIGH);
  digitalWrite(b2,LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  m = digitalRead(ir1);
  n = digitalRead(ir2);
  o = digitalRead(ir3);
  if (m==1 || n==1 )
  {
    if(m==0)
    {
      right();
    }
    else if(n==0)
    {
      left();
    }
    else if(m==1||n==1)
    {
      move1();
    }

  }
      else if(m==0 ||n==0||o==0)
    {
      move1();
    }
  else
  {
    stop1();   
  }
}
