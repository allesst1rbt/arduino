#include <SoftwareSerial.h>
SoftwareSerial Seriall(2, 3);
int b;
String ler1,ler2;
 int A;
void setup() {
  Serial.begin(9600);
  Seriall.begin(9600);
  Seriall.println("CHAT");
  pinMode(13 , OUTPUT);
  pinMode(A0, INPUT);
  A=1000;
}

void loop() {
 chat();
}

void blinkl(){
    digitalWrite(13, 1);
    delay(A);
    digitalWrite(13,0);
    delay(A);
}
void chat(){
  while(true){
    blinkl();
     if(Seriall.available()){
            ler1=Seriall.readStringUntil('\n');
            Serial.print("ele:");
            Serial.println(ler1);
            if (ler1.substring(0,1) == "%") {
              Seriall.print("o tempo do led esta definido em: ");
             
              Seriall.println(A);    
            }
            else if(ler1.substring(0,1) == "$"){
              Seriall.print("o potenciometro esta definido em: ");              
              b=analogRead(A0);
              Seriall.println(b);                                        
            }
               else if(ler1.substring(0,1) == "#"){
               A=ler1.substring(1).toInt();
               Seriall.print("o tempo do led foi mudado para: ");
               Seriall.println(A);                                         
            }
           }
          
                    
            
              if(Serial.available()){
               ler2=Serial.readStringUntil('\n');
              Serial.print("tu:");
              Serial.println(ler2);
              Seriall.println(ler2);
                
           }
       }
  }


