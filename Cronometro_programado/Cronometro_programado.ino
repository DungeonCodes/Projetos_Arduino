#define bt1 8
#define bt2 9
#define buzzer 10

int numero[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};
int counter = 0;
bool ativar_cont = 0;

void read_keyb();
void mostrar_disp(int num);

void setup() {
  for (int i=0; i<=6; i++){
    pinMode(i,OUTPUT); 
  }

  PORTD = numero[0];

  pinMode(bt1,INPUT_PULLUP);
  pinMode(bt2,INPUT_PULLUP);
  pinMode(buzzer,OUTPUT);
}

void loop() {
  read_keyb();

  if(ativar_cont == 1){
    delay(1000);
    counter -= 1;
    
    mostrar_disp(counter);

    if(counter == 0){
      ativar_cont = 0;

      for (int i=0; i<=2; i++){
        digitalWrite(buzzer,HIGH);
        delay(200);
        digitalWrite(buzzer,LOW);  
        delay(200);
      }
      
    } 
  }
}

void read_keyb(){
  bool f_b1 = 0;
  bool f_b2 = 0;

  //botão 1
  if(!digitalRead(bt1)){
    f_b1 = 1;
    delay(70);  
  }

  if (digitalRead(bt1) && f_b1){
    delay(70);  
    counter += 1; 
    
    if(counter == 10){
      counter = 0;  
    }
    mostrar_disp(counter);
  }

  //botão 2
   if(!digitalRead(bt2)){
    f_b2 = 1;
    delay(70);  
  }

  if (digitalRead(bt2) && f_b2){
    delay(70);  
    ativar_cont = 1;
  }
}

void mostrar_disp(int num){
   PORTD = numero[num];
}
