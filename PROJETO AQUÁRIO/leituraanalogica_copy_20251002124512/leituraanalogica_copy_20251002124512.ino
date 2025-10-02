// ====== SUAS DEFINIÇÕES ORIGINAIS ======
#define DS18B20_PIN 2
#define SensorBoia 3
#define LedVermelho 4
#define LedVerde 5
#define rele 6

int leiturasensor; // Variável da boia
unsigned long lastRelayToggle = 0;
const unsigned long relayInterval = 5000; // 5 segundos
bool relayState = false;

// ====== NOVO: I2C de hardware (A4=SDA, A5=SCL) + LCD I2C ======
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Endereço do seu módulo I2C (geralmente 0x27; se não aparecer nada no LCD, experimente 0x3F)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// ========= PROTÓTIPOS (originais) =========
bool readTemperature(byte* data);
bool resetPulse();
void writeByte(byte data);
byte readByte();
void writeBit(bool bitVal);
bool readBit();

// ========= FUNÇÃO AUXILIAR (NOVA): atualiza LCD =========
void atualizaLCD(float celsius, int nivelAlto) {
  // Linha 0: Temperatura
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  if (isnan(celsius)) {
    lcd.print("--.-");
  } else {
    lcd.print(celsius, 1); // 1 casa decimal
  }
  lcd.print((char)223); // símbolo de grau
  lcd.print("C   ");   // padding simples para limpar resto da linha

  // Linha 1: Nível
  lcd.setCursor(0, 1);
  lcd.print("Nivel: ");
  if (nivelAlto) {
    lcd.print("ALTO ");
  } else {
    lcd.print("BAIXO");
  }
  lcd.print("     "); // padding
}

void setup() {
  Serial.begin(9600);
  delay(1000);

  pinMode(SensorBoia, INPUT);
  pinMode(LedVermelho, OUTPUT);
  pinMode(LedVerde, OUTPUT);
  pinMode(rele, OUTPUT);

  // ====== NOVO: inicia I2C de hardware e LCD ======
  Wire.begin();       // Usa A4 (SDA) e A5 (SCL) no Uno/Nano
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0,0); lcd.print("Iniciando...");
  lcd.setCursor(0,1); lcd.print("Aguarde");
  delay(800);
  lcd.clear();
}

void loop() {
  // SENSOR DE TEMPERATURA
  byte data[9];
  float celsius = NAN;

  if (readTemperature(data)) {
    int16_t rawTemp = (data[1] << 8) | data[0];
    celsius = rawTemp / 16.0;
    Serial.print("Temperatura: ");
    Serial.print(celsius);
    Serial.println(" °C");
  } else {
    Serial.println("Erro ao ler o sensor de temperatura");
  }

  // SENSOR DE NÍVEL DE ÁGUA
  leiturasensor = digitalRead(SensorBoia);
  Serial.print("Leitura do sensor de nível: ");
  Serial.println(leiturasensor);

  if (leiturasensor == HIGH) {
    Serial.println("Nível de água alto");
    digitalWrite(LedVermelho, LOW);
    digitalWrite(LedVerde, HIGH);
  } else {
    Serial.println("Nível de água baixo");
    digitalWrite(LedVermelho, HIGH);
    digitalWrite(LedVerde, LOW);
  }

  // Atualiza LCD
  atualizaLCD(celsius, (leiturasensor == HIGH));

  // RELE (aciona alternadamente a cada 5 segundos)
  if (millis() - lastRelayToggle >= relayInterval) {
    relayState = !relayState;
    digitalWrite(rele, relayState ? HIGH : LOW);
    lastRelayToggle = millis();
  }

  delay(300);
}

// -------- FUNÇÕES AUXILIARES DS18B20 (originais) --------
bool readTemperature(byte* data) {
  if (!resetPulse()) return false;

  writeByte(0xCC); // SKIP ROM
  writeByte(0x44); // CONVERT T
  delay(750);

  if (!resetPulse()) return false;

  writeByte(0xCC); // SKIP ROM
  writeByte(0xBE); // READ SCRATCHPAD

  for (byte i = 0; i < 9; i++) {
    data[i] = readByte();
  }

  // (Opcional) checagem simples de CRC poderia ser adicionada aqui
  return true;
}

bool resetPulse() {
  pinMode(DS18B20_PIN, OUTPUT);
  digitalWrite(DS18B20_PIN, LOW);
  delayMicroseconds(480);
  pinMode(DS18B20_PIN, INPUT);
  delayMicroseconds(70);
  bool presence = !digitalRead(DS18B20_PIN);
  delayMicroseconds(410);
  return presence;
}

void writeByte(byte data) {
  for (byte i = 0; i < 8; i++) {
    writeBit(data & 0x01);
    data >>= 1;
  }
}

byte readByte() {
  byte value = 0;
  for (byte i = 0; i < 8; i++) {
    if (readBit()) value |= (1 << i);
  }
  return value;
}

void writeBit(bool bitVal) {
  pinMode(DS18B20_PIN, OUTPUT);
  digitalWrite(DS18B20_PIN, LOW);
  delayMicroseconds(bitVal ? 10 : 60);
  pinMode(DS18B20_PIN, INPUT);
  delayMicroseconds(bitVal ? 55 : 5);
}

bool readBit() {
  pinMode(DS18B20_PIN, OUTPUT);
  digitalWrite(DS18B20_PIN, LOW);
  delayMicroseconds(3);
  pinMode(DS18B20_PIN, INPUT);
  delayMicroseconds(10);
  bool bitVal = digitalRead(DS18B20_PIN);
  delayMicroseconds(53);
  return bitVal;
}
