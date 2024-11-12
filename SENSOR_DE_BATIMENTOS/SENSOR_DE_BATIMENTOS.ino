
/*  PulseSensor Starter Project and Signal Tester
 *  The Best Way to Get Started  With, or See the Raw Signal of, your PulseSensor.com™ & Arduino.
 *
 *  Here is a link to the tutorial
 *  https://pulsesensor.com/pages/code-and-guide
 *
 *  WATCH ME (Tutorial Video):
 *  https://www.youtube.com/watch?v=RbB8NSRa5X4
 *
 *
-------------------------------------------------------------
1) This shows a live human Heartbeat Pulse.
2) Live visualization in Arduino's Cool "Serial Plotter".
3) Blink an LED on each Heartbeat.
4) This is the direct Pulse Sensor's Signal.
5) A great first-step in troubleshooting your circuit and connections.
6) "Human-readable" code that is newbie friendly."

*/


//  Variables
int PulseSensorPurplePin = 0;        // Pulse Sensor PURPLE WIRE connected to ANALOG PIN 0
int LED = LED_BUILTIN;   //  The on-board Arduion LED


int Signal;                // holds the incoming raw data. Signal value can range from 0-1024
int Threshold = 335;       // Determine which Signal to "count as a beat", and which to ingore.

unsigned long lastBeatTime = 0; // Stores the time of the last beat detected
int BPM = 0;                    // Stores the Beats Per Minute value


#include <Wire.h>
#include <LiquidCrystal_I2C.h>
//Inicializa o display no endereco 0x27
LiquidCrystal_I2C lcd(0x27,16,2);


// The SetUp Function:
void setup() {
  pinMode(LED,OUTPUT);         // pin that will blink to your heartbeat!
  Serial.begin(115200);       // Set's up Serial Communication at certain speed.
  lcd.init();

}

// The Main Loop Function
void loop() {
  lcd.clear();
  lcd.setBacklight(HIGH);
  lcd.setCursor(0,0);
  lcd.print("BPM: ");
  lcd.print(BPM);

  unsigned long currentTime = millis();


  Signal = analogRead(PulseSensorPurplePin);  // Read the PulseSensor's value.
                                              // Assign this value to the "Signal" variable.

   Serial.println("Signal " + String(Signal)); // Send "reading " followed by the Signal value to Serial Plotter.*/


   if (Signal > Threshold) {
    if ((currentTime - lastBeatTime) > 600) { // To avoid counting multiple beats for the same pulse (debounce)
        BPM = 60000 / (currentTime - lastBeatTime); // Calculate BPM using the time difference
        Serial.println("BPM: " + String(BPM));     // Print BPM to Serial Monitor
        lastBeatTime = currentTime;
    }
    digitalWrite(LED, HIGH);
} else {
    digitalWrite(LED, LOW);
}



delay(20);


}
