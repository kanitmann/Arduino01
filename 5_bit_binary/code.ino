/*Code by Kanit Mann*/
int button = 2;      // pin to connect the button
int presses = 0;    // variable to store number of presses
const byte pin_num = 8; // how many leds
int state;        // used for HIGH or LOW
byte pins[] = {9, 10, 11, 12 , 13};

void setup()
{
 
  for(int i = 0; i < pin_num; i++) {
    pinMode(pins[i], OUTPUT);
  }
  pinMode(button, INPUT);
 
}

void loop()
{
 
  String bin1 = String(presses, BIN);
  int bin_len = bin1.length(); 
  if(presses <= 31) {  
    for(int i = 0, x = 1; i < bin_len; i++, x+=2) { 
      if(bin1[i] == '0') state = LOW;
      if(bin1[i] == '1') state = HIGH;
      digitalWrite(pins[i] + bin_len - x, state);
    } 
  } else {
      //well, nothing to do in else, leave it be. 
  }
}