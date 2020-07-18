#include "Wire.h"

byte x = 0;
String texto = "";
unsigned long leds11 = millis ();
unsigned long leds12 = millis ();
volatile int tempo1 = 100;
volatile int a = 0;
void (*funcReset) () = 0;

void interrupcao(){
  funcReset();
}

void setup() {
  Wire.begin();
  Serial.begin(9600);
  Serial.println(" ROTINA DE INICIALIZACAO");
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  attachInterrupt(digitalPinToInterrupt(3),interrupcao,RISING); 
}

void principal(){
  Serial.println("ROTINA PRINCIPAL");
  while(1){
    if (Serial.available()){
      texto = Serial.readStringUntil('\n');
      if(texto = "ldr"){
      Wire.beginTransmission(8);
        x = 1;
      Wire.write(x);              
      Wire.endTransmission();
      Wire.requestFrom(8, 2);}
      if(texto = "pot"){
      Wire.beginTransmission(8);
        x = 2;
      Wire.write(x);              
      Wire.endTransmission();
      Wire.requestFrom(8, 2);}   
      if(texto = "int"){
      Wire.beginTransmission(8);
        x = 3;
      Wire.write(x);              
      Wire.endTransmission();
      Wire.requestFrom(8, 2);}   
      if(texto = "led"){
      Wire.beginTransmission(8);
        x = 4;
      Wire.write(x);              
      Wire.endTransmission();
      Wire.requestFrom(8, 2);}   
  while(1 < Wire.available())    
  { 
    byte c = Wire.read(); 
    Serial.println(c);
  }
   } 
  }    
 }  

  


void piscaLeds1(){
  if (millis()- leds11 <= tempo1){
    digitalWrite(11,1);
    digitalWrite(12,1);
    }
    else{
    digitalWrite(11,0);
    digitalWrite(12,0);  
   }
   if(millis()- leds11 > tempo1*2){
    leds11 = millis();
    leds12 = millis();
   }
  }

void piscaLeds2(){
  if (millis() - leds12 <= tempo1){
    digitalWrite(12,1);
    digitalWrite(11,0);
    }
   else{
    digitalWrite(12,0);
    digitalWrite(11,1);
    
    }
   if(millis()- leds12 > tempo1*2){
    leds11 = millis();
    leds12 = millis();
   } 
}

void loop(){
 piscaLeds1();
 if(digitalRead(2)){
  a++;
  while(digitalRead(2)){} 
  leds11 = millis ();
  leds12 = millis ();
  tempo1 = 100;
 }
 if(a == 1){
  while(1){
   piscaLeds2();
   if(digitalRead(2)){
   a++;
  while(digitalRead(2)){} 
  leds11 = millis ();
  leds12 = millis ();
  tempo1 = 100;
  break;
  }
 }
}
 if (a == 2){
 Serial.println("ROTINA DE INICIALIZACAO ENCERRADA");
 digitalWrite(11,0);
 digitalWrite(12,0);
 principal();

 }
}