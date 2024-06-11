//Vetor com os bytes relacionados aos números que serão exibidos em cada segmento
int numero[10]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};

void setup() {
  for (int i=0; i<=6; i++){
    pinMode(i,OUTPUT); 
  }
}

void loop() {
  for(int i=0; i<=9; i++){
    PORTD = numero[i];
    delay(1000); 
  }
}
