int count = 0;
int led = 11;
int i = 2, j = 3;
int n,m;
void setup() {
  // put your setup code here, to run once:
  pinMode(i,INPUT);
  pinMode(j,INPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);
  analogWrite(led,0);
}

void loop() 
{
  if(m == digitalRead(i))
  {
    delay(500);
    if(n == digitalRead(j))
    {
      count++;  
    }  
  } 
  if(n == digitalRead(j))
  {
    delay(500);
    if(m == digitalRead(i))
    {
      count--;  
    }  
  }
  Serial.println(count);
  analogWrite(led,51*count);
}
 
 
