int count = 0;
int led = 11;
int i = 2, j = 3;

void setup() {
  // put your setup code here, to run once:
  pinMode(i,INPUT);
  pinMode(j,INPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);
  analogWrite(led,0);
}

void loop() {
  // put your main code here, to run repeatedly:
  Action:
  if(digitalRead(j)==0){
    int c=0;
    while(digitalRead(i)==0){
      c++;
      if(c>1000) goto Action;
    }
    count++;
  }
  if(digitalRead(i)==0){
    int c=0;
    while(digitalRead(j)==0){
      c++;
      if(c>1000) goto Action;
    }
    Serial.println("DOWN");
    count--;
   
  }
  if(count>5){
    Serial.println("Room Full");
  }
  else if(count<0){
    count=0;
  }
  else{
  analogWrite(led,count*51);
  }
   Serial.println(count);
   delay(500);
}
