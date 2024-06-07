int D0 = 2;
int D1 = 3;
int D2 = 4;
int D3 = 5;


void setup() {
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);

  
}

void loop() {
  digitalWrite(D0, 1);
  digitalWrite(D1, 0);
  digitalWrite(D2, 0);
  digitalWrite(D3, 0);
  

}
