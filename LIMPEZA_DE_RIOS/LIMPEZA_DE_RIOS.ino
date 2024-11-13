// Programa: Controle de velocidade e direção de um motor Dc utilizando o módulo L298D

// Define os pinos de controle do motor ligados ao Arduino
#define PINO_IN1 5  // Pino responsável pelo controle no sentido horário
#define PINO_IN2 6  // Pino responsável pelo controle no sentido anti-horário

#include <Servo.h>
Servo myservo;// Cria um objeto baseado na biblioteca Servo
int serv = 5;
  
void setup(){ 
  // Configura os pinos de controle como saída
  pinMode(PINO_IN1, OUTPUT);  // Define o pino IN1 como saída
  pinMode(PINO_IN2, OUTPUT);  // Define o pino IN2 como saída

  myservo.attach(9);// Diz que o objeto "myservo" está ligado ao pino 9
  myservo.write(15);// Comando para mandar o servo para posição 15
  analogWrite(PINO_IN1, 0);
  
}
  
void loop() {   
  //Levando o cesto
  analogWrite(PINO_IN1, 240);
  delay(2000);

  //Girando o cesto
  analogWrite(PINO_IN1, 0);
  myservo.write(180);// Comando para mandar o servo para posição 180
  delay(4000);

//Girando de volta o cesto
  analogWrite(PINO_IN1, 0);
  myservo.write(15);// Comando para mandar o servo para posição 180
  
  delay(2000);
  myservo.write(15);// Comando para mandar o servo para posição 15



  analogWrite(PINO_IN2, 240);
  delay(2000);
  analogWrite(PINO_IN2, 0);
  delay(2000);
}
/*

  // Aumenta a velocidade gradualmente de 0% a 100% no sentido horário
  for (valor_pwm = 0; valor_pwm < 256; valor_pwm++) {
    analogWrite(PINO_IN1, valor_pwm);  // Aplica o valor PWM no pino IN1
    delay(100);  // Espera 100 ms antes de aumentar a velocidade
  }
 
  // Diminui a velocidade gradualmente de 100% a 0% no sentido horário
  for (valor_pwm = 255; valor_pwm >= 0; valor_pwm--) {
    analogWrite(PINO_IN1, valor_pwm);  // Reduz o valor PWM no pino IN1
    delay(100);  // Espera 100 ms antes de diminuir mais a velocidade
  }

  // Aumenta a velocidade gradualmente de 0% a 100% no sentido anti-horário
  for (valor_pwm = 0; valor_pwm < 256; valor_pwm++) {
    analogWrite(PINO_IN2, valor_pwm);  // Aplica o valor PWM no pino IN2
    delay(100);  // Espera 100 ms antes de aumentar a velocidade
  }
 
  // Diminui a velocidade gradualmente de 100% a 0% no sentido anti-horário
  for (valor_pwm = 255; valor_pwm >= 0; valor_pwm--) {
    analogWrite(PINO_IN2, valor_pwm);  // Reduz o valor PWM no pino IN2
    delay(100);  // Espera 100 ms antes de diminuir mais a velocidade
  } 
}*/