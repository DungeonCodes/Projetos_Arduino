int led = 3;
int i = 0;


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  for(i = 50; i<= 255; i++){
    analogWrite(led, i);
    delay(10);
  }
  delay(2000);
  for(i = 255; i>= 50; i--){
    analogWrite(led, i);
    delay(1);
  }
  i= 255;
  for(i = 255; i>= 50; i--){
    analogWrite(led, i);
    delay(1);
  }
  // put your main code here, to run repeatedly:

}
