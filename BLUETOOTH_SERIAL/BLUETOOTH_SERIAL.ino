 
int mic = A0; // é atribuida a variável 'sensor' o valor da intensidade do som captado
int som = 0;

void setup()
{
  Serial.begin(9600);
  // Aguarda 1 seg antes de acessar as informações do sensor
  delay(1000);
  
}
 
void loop()
{
  
 /*if(sensor > 70){ // acende o primeiro led se a intensidade do som passar de 70
    digitalWrite(led1, HIGH);
  }else{
    digitalWrite(led1, LOW);
  }*/
  // Mostra os valores lidos, na serial
  som = analogRead(mic);
  //Serial.println(som);
  delay(200);

  if(som > 25){ // acende o primeiro led se a intensidade do som passar de 70
    Serial.println("PERIGO");
  }else{
    Serial.println("SEGURO");
  }
}