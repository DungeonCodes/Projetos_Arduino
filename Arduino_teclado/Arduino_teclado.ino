int bot1 = 2;
int bot2 = 3;
int bot3 = 4;
int bot4 = 5;
int buzzer = 9;
int bdo = 0;
int bre = 0;
int bmi = 0;
int bfa = 0;

void setup() {
  pinMode(bot1, INPUT);
  pinMode(bot2, INPUT);
  pinMode(bot3, INPUT);
  pinMode(bot4, INPUT);

  

}

void loop() {
  bdo = digitalRead(bot1);
  bre = digitalRead(bot2);
  bmi = digitalRead(bot3);
  bfa = digitalRead(bot4);
  //tone(buzzer, 297, 100);

  if(bdo == HIGH){
    tone(buzzer, 264, 100);
  }
  if(bre == HIGH){
    tone(buzzer, 297, 100);
  }
  if(bmi == HIGH){
    tone(buzzer, 330, 100);
  }
  if(bfa == HIGH){
    tone(buzzer, 352, 100);
  }
  // put your main code here, to run repeatedly:

}
