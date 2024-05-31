int sensor = A0;
int buzzer = 3;
int valor = 0;
int leitura = 0;

void setup() {
  // NÃO PRECISA COLOCAR NADA AQUI
  
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  
  valor = analogRead(sensor);
  leitura = analogRead(sensor);
  valor = map(valor, 200, 700, 0, 4000);
  tone(buzzer, valor, 100);
  Serial.print("Leitura:");
  Serial.println(leitura);
  Serial.print("Valor:");
  Serial.println(valor);
  


}
