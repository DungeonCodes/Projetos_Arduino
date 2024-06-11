
int D0 = 2;
int D1 = 3;
int D2 = 4;
int D3 = 5;
int b0 = 0;
int b1 = 0;
int b2 = 0;
int b3 = 0;


void setup() {
  Serial.begin(9600);
  int decimalNumber = 9;
  Serial.print("O número decimal ");
  Serial.print(decimalNumber);
  Serial.print(" em binário é: ");
  printBinary(decimalNumber);
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
}

void printBinary(int number) {
  if (number == 0) {
    Serial.print(0);
    return;
  }
  
  // Array para armazenar os bits do número binário
  int binary[32]; // Assumindo que o número é no máximo um inteiro de 32 bits
  int index = 0;
  
  // Converte o número decimal para binário
  while (number > 0) {
    binary[index] = number % 2;
    number = number / 2;
    index++;
  }
  
  // Imprime o número binário em ordem inversa
  for (int i = index - 1; i >= 0; i--) {
    Serial.print(binary[i]);
  }
}

void numero1() {
  digitalWrite(D0, b0);
  digitalWrite(D1, b1);
  digitalWrite(D2, b2);
  digitalWrite(D3, b3);
}

void loop() {
  numero1();
  b0 = 1;
}





