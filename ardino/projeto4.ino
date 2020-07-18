
unsigned long millisLed = millis();
int tempoleds = 250;
int num ;
volatile int a = 0;
int cont = 0 ;
String b ;
void setup() {
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(5,INPUT);
  pinMode(2,INPUT);
  Serial.begin (9600);
}
void (*Reset) () = 0;
void loop() {
   digitalWrite(11,1);
   delay(200);
   digitalWrite(11,0);
   digitalWrite(12,1);
   delay(200);
   digitalWrite(12,0);
  if (Serial.available()){
     b = Serial.readStringUntil('\n');
    if(b = "start"){
       millisLed = millis();
       while(cont < 4){
       Blink();
     }
    funcPrinc();
   }
 }
}
void funcPrinc(){
  while(1){
     if (Serial.available()){
       num = Serial.parseInt();
       if (num > 0 ){
         while(1){
           if(digitalRead(5)){
             tempoleds = 100;
             millisLed = millis();
           while(digitalRead(5)){}
             while(1){
              Blink();
              encurta();
              if (num == a){
                 detachInterrupt(digitalPinToInterrupt(2));
                 digitalWrite(11,0);
                 digitalWrite(12,0);
                 while(1){
                 if(Serial.available()){
                   b = Serial.readStringUntil('\n');
                   if (b == "again"){
                   Reset();
                    }
                   }
                 }
               }
             }
           }
         }
       }
     }
   }
}
void Blink(){
    if ((millis () - millisLed) < tempoleds){
     digitalWrite(11,1);
     digitalWrite(12,1);
     }
    else{
     digitalWrite(11,0);
     digitalWrite(12,0);
     }
    if ((millis() - millisLed) > tempoleds*2){
     millisLed = millis();
     cont ++;
 }
}
void ZC(){
 a++;
 }
void encurta(){
  attachInterrupt(digitalPinToInterrupt(2),ZC,HIGH);
}
