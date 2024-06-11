
int D0 = 2;
int D1 = 3;
int D2 = 4;
int D3 = 5;
int b0 = 0;
int b1 = 0;
int b2 = 0;
int b3 = 0;


void setup() {
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
}



void numero1() {
  digitalWrite(D0, b0);
  digitalWrite(D1, b1);
  digitalWrite(D2, b2);
  digitalWrite(D3, b3);
}

void numero2() {
  digitalWrite(D0, 0);
  digitalWrite(D1, 1);
  digitalWrite(D2, 0);
  digitalWrite(D3, 0);
}

void loop() {
  numero1();
<<<<<<< HEAD
  b0 = 1;
}





=======
  delay(500);
  numero2();
  delay(500);
}
>>>>>>> b57c91ac3a4f8240412ca54f2f86f2805dbd7dd4
