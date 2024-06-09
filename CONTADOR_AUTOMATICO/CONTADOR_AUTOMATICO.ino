byte value = 0;
int D0 = 2;
int D1 = 3;
int D2 = 4;
int D3 = 5;

void setup() {
    pinMode(D0, OUTPUT);
    pinMode(D1, OUTPUT);
    pinMode(D2, OUTPUT);
    pinMode(D3, OUTPUT);
    Serial.begin(9600);

}

void loop(){
    
    digitalWrite(D0, bitRead(value, 0));
    digitalWrite(D1, bitRead(value, 1));
    digitalWrite(D2, bitRead(value, 2));
    digitalWrite(D3, bitRead(value, 3));
    value = value + 1;
    if (value == 10){
        value = 0;
    }
    delay(1000);
    //Serial.println(value);
    Serial.print(value, 0);
    Serial.print("__");
    Serial.print(value, 1);
    Serial.print("__");
    Serial.print(value, 2);
    Serial.print("__");
    Serial.print(value, 3);
    Serial.println("__");
    
    

}