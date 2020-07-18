int blink1=1000;
int blink2=1000; 
int blink3=1000; 
void setup() {
 pinMode(13,OUTPUT);
 pinMode(A0, INPUT);
 Serial.begin(9600);
}
void loop(){
 menu();
 }
 
  void menu(){
int escolha;
Serial.println("=========MENU=========");
Serial.println("0---------------config");
Serial.println("1---------------blink1");
Serial.println("2---------------blink2");
Serial.println("3---------------blink3");
Serial.println("4---------------blink4");
Serial.println("======================");
while(true){
  if(Serial.available()){
    escolha=Serial.parseInt();
  
if(escolha == 0){
  Config();
}
else if(escolha == 1){
 blinkled1(blink1);
}
else if(escolha == 2){
   blinkled2(blink1);
}
else if(escolha == 3){
  blinkled3(blink3);
}
else if(escolha == 4){
   blinkled4();
}
else{
  Serial.println("escolha invalida");
  menu();
}
  
        }
    }
}
 
void Config(){
  int escolha2;
 Serial.println("======config=======");
 Serial.println("1---alterar tempo 1");
 Serial.println("2---alterar tempo 2");
 Serial.println("3---alterar tempo 3");
 Serial.println("4---voltar  ao menu");
 Serial.println("===================");
 while(true){
  if(Serial.available()>0){
    escolha2=Serial.parseInt();
  if(escolha2==1){
    Serial.println("digite o novo valor de 1:");
    while(true){
      if(Serial.available()>0){
        blink1=Serial.parseInt();
        break;
      }
    }
    
  Config(); 
  }

  if(escolha2==2){
    Serial.println("digite o novo valor de 2:");
    while(true){
      if(Serial.available()>0){
        blink2=Serial.parseInt();
        break;
      }
    }
    
   Config();
   }

  if(escolha2==3){
    Serial.println("digite o novo valor de 3:");
    while(true){
      if(Serial.available()>0){
        blink3=Serial.parseInt();
        break;
      }
    }
    
   Config();
   }
   if(escolha2==4){
        menu();
  
  }
 }
 }


  
}


void blinkled1(int tempo){
   Serial.println("=====blink led 1=====");
    Serial.println("para voltar ao menu digite menu");
  while(true){
    digitalWrite(13, 1);
    delay(tempo);
    digitalWrite(13,0);
    delay(tempo);
    if(Serial.available()>0){
      String vtr= Serial.readStringUntil("\n");
      if(vtr=="menu"){
        menu();
      }
      
    }
  }
}
void blinkled2(int tempo){
   Serial.println("=====blink led 2=====");
   Serial.println("para voltar ao menu digite menu");
   while(true){
    digitalWrite(13, 1);
    delay(tempo);
    digitalWrite(13,0);
    delay(tempo);
    if(Serial.available()>0){
      String vtr = Serial.readStringUntil("\n");
      if(vtr == "menu"){
        menu();
      }
      
    }
  }
}
void blinkled3(int tempo){
   Serial.println("=====blink led 3=====");
   Serial.println("para voltar ao menu digite menu");
   while(true){
    digitalWrite(13, 1);
    delay(tempo);
    digitalWrite(13,0);
    delay(tempo);
    if(Serial.available()>0){
      String vtr= Serial.readStringUntil("\n");
      if(vtr=="menu"){
      menu();
      }
      
    }
  }
}

void blinkled4(){
  Serial.println("=====blink led 4=====");
  Serial.println("para voltar ao menu digite menu");
   while(true){
    int potenciometro;
    potenciometro = analogRead(A0);
    digitalWrite(13, 1);
    delay(potenciometro);
    digitalWrite(13,0);
    delay(potenciometro);
    if(Serial.available()>0){
      String vtr= Serial.readStringUntil("\n");
      if(vtr=="menu"){
      menu();
      }
      
    }
  }
  
}
