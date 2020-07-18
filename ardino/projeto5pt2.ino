#include <Wire.h>

void setup() {
  Wire.begin(8);                
  Wire.onRequest(requestEvent); 
  pinMode(5,OUTPUT);
  pinMode(4,INPUT);
}
int a,i,e ;
bool d;
char c;
void loop() {
  a = analo
}


void requestEvent() {gRead(A0);
  i = analogRead(A1);
  d=0;
  e = digitalRead(4);
  

  Wire.write(a);
  while(1 < Wire.available()) 
  {
    c = Wire.read();
    Serial.print(c);         
  }
  if(c == 1){
  Wire.write(a);
  }
  if(c==2){
    Wire.write(i);
  }
  if(c==3){
    digitalWrite(5,d);
    d=!d;
  }
  if(c==4){
    Wire.write(e);
  }
}