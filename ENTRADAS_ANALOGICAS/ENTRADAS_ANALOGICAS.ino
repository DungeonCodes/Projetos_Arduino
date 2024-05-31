int sensorx = A0;
int sensory = A1;
int valorx = 0;
int valory = 0;


void setup() {
 // pinMode (sensorx, INPUT);
  //pinMode (sensory, INPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
   
  //valorx = analogRead(sensorx);
  //valory = analogRead(sensory);
  Serial.begin(9600);


}

void loop() {
  valorx = analogRead(sensorx);
  valory = analogRead(sensory);

  Serial.print("valor x = ");
  Serial.println(valorx);
  Serial.print("valor y = ");
  Serial.println(valory);
  if (valorx <= 600 && valorx >=400 ){
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);

  }
  if (valorx <= 350 ){
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);

  }
  if (valorx >= 700 ){
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);

  }
  if (valory <= 600 && valory >=400 ){
    digitalWrite(5, LOW);
    digitalWrite(6, HIGH);
    digitalWrite(7, LOW);

  }
  if (valory <= 350 ){
    digitalWrite(5, HIGH);
    digitalWrite(6, LOW);
    digitalWrite(7, LOW);

  }
  if (valory >= 700 ){
    digitalWrite(5, LOW);
    digitalWrite(6, LOW);
    digitalWrite(7, HIGH);

  }
  
  //digitalWrite(2, HIGH);
  //digitalWrite(3, HIGH);
  //digitalWrite(4, HIGH);
  //digitalWrite(5, HIGH);
  //digitalWrite(6, HIGH);
  //digitalWrite(7, HIGH);

  delay(100);

}
