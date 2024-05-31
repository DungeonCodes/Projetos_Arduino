int valor = 0;


void setup() {
  Serial.begin(9600);
  }


void loop() {
  analogWrite(3, 10);  
  valor = analogRead(A0);
  valor = map(valor, 0, 1023, 0, 255);
  analogWrite(3, valor);
  Serial.println(valor);

}
