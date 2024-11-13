

 
// Variáveis Úteis

int state_rec;

char state;

const int PINO_SENSOR = A0; // Pino A0 conectado ao sensor de som
 
void setup() {
  // Inicializa as portas como entrada e saída.
  pinMode(PINO_SENSOR, INPUT); // Pino A0 definido como saida
  Serial.begin(9600); // Inicializa a comunicacao serial

  
  // Inicializa a comunicação serial em 9600 bits.
  Serial.begin(9600);
}
 
void loop() {
  Serial.println(analogRead(PINO_SENSOR)); // Le as informacoes obtidas do sensor
  delay(50); // Tempo de atualizacao de informacoes
 
  if (Serial.available() > 0) {
    state_rec = Serial.read();
    state = state_rec;
    
  }
 
 if (state == '0') {
    
  }
  else if (state == '4') {
    
  }
  else if (state == '6') {
    
  }
  else if (state == '7') {
    
  }
  else if (state == '8') {
    
  }
  else if (state == '9') {
    
  }
  else if (state == 'q') {
    
  }
 
  // Se o estado recebido for igual a 'F', o carro se movimenta para frente.
  if (state == 'F') {
    


  }
 
    else if (state == 'I') {  // Se o estado recebido for igual a 'I', o carro se movimenta para Frente Esquerda.
    

  }
 
    else if (state == 'G') {   // Se o estado recebido for igual a 'G', o carro se movimenta para Frente Direita.
    

  }
 
  else if (state == 'B') { // Se o estado recebido for igual a 'B', o carro se movimenta para trás.
    

  }
 
   else if (state == 'H') {  // Se o estado recebido for igual a 'H', o carro se movimenta para Trás Esquerda.
    

  }
  
  else if (state == 'J') {  // Se o estado recebido for igual a 'J', o carro se movimenta para Trás Direita.
    

  }
 
  else if (state == 'L') {   // Se o estado recebido for igual a 'L', o carro se movimenta para esquerda.
    

  }
  else if (state == 'R') {   // Se o estado recebido for igual a 'R', o carro se movimenta para direita.
    
    

  }
  else if (state == 'S') {   // Se o estado recebido for igual a 'S', o carro permanece parado.
    

  }
 
 
}
