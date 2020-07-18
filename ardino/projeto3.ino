unsigned long al = millis();
unsigned long ab = millis();
int t;
int c=0;
int cl;
String txt;
bool k;
int verde=2,vermelho=3,b1=9,b2=10,buzz=8;
void setup()
{
  pinMode(verde, OUTPUT);
  pinMode(vermelho, OUTPUT);
  pinMode(buzz, OUTPUT);
  pinMode(b1, INPUT);
  pinMode(b2,INPUT);
  Serial.begin(9600);
}

void loop()
{
  inicial();
}
void inicial(){
  while(true){
    digitalWrite(vermelho, HIGH);
    delay(250);
    digitalWrite(vermelho, LOW);
    digitalWrite(verde, HIGH);
    delay(250);
    digitalWrite(verde, LOW);
    if(Serial.available()){
      txt=Serial.readStringUntil('\n');
      if(txt=="start"){
        start();
      }
    }
  }
}
void start(){
  al=millis();
  t=250;
  cl=0;
 
  while(c<5){
    pisca();
  }
  if(c==5){
    t=900;
    c=0;
    bo1();
    
  }
}
void pisca(){
  
  if((millis() - al) < t){
  	digitalWrite(vermelho, HIGH);
  	digitalWrite(verde, HIGH);
	}
  else{
  	digitalWrite(vermelho, LOW);
  	digitalWrite(verde, LOW);
	}
	if((millis() - al) > 2*t){
  	c += 1 ;
  	al = millis();
	}
}
void bo1(){
  while(true){
    if(digitalRead(9)){
     
      al=millis();
      ab=millis();
      while(digitalRead(9)){
        k=t_est();
      }
      t-=180;
      cl+=1;
      
      if(cl==4){
        cl=0;
        t=920;
      }
    }
     if(cl>-1){
      pisca();
    }
  }
}
void bo2(){
  digitalWrite(vermelho, LOW);
  digitalWrite(verde, LOW);
  while(true){
    if(digitalRead(10)){
      ab=millis();
      while(digitalRead(10)){
          k=t_est2();
          
         }
       start();
      }
   }
}
bool t_est(){
  if((millis() - al) >= 2000){
    digitalWrite(buzz,1);
    delay(500);
    digitalWrite(buzz,0);
    bo2();
    return true;
  }
  else{
    return false;
  }
}
bool t_est2(){
  if((millis() - ab) >= 2000){
    inicial();
   return true;
  }
  else{
    return false;
  }
}