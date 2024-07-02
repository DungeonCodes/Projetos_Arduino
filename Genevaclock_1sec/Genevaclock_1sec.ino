// wait for a single step of stepper
int delaytime = 3;
#define STEP_PER_ROTATION 2048

// ports used to control the stepper motor
// if your motor rotate to the opposite direction, 
// change the order as {4, 5, 6, 7};
int port[4] = {7, 6, 5, 4};

// sequence of stepper motor control
int seq[4][4] = {
  {  LOW,  LOW, HIGH,  LOW},
  {  LOW,  LOW,  LOW, HIGH},
  { HIGH,  LOW,  LOW,  LOW},
  {  LOW, HIGH,  LOW,  LOW}
};

void rotate(int step) {
  static int phase = 0;
  int i, j;
  int delta = (step > 0) ? 1 : 3;
  int dt = 20;

  step = (step > 0) ? step : -step;
  for(j = 0; j < step; j++) {
    phase = (phase + delta) % 4;
    for(i = 0; i < 4; i++) {
      digitalWrite(port[i], seq[phase][i]);
    }
    delay(dt);
    if(step - j < 20) dt+=1;
    else if(dt > delaytime) dt--;
  }
  // power cut
  for(i = 0; i < 4; i++) {
    digitalWrite(port[i], LOW);
  }
}

void setup() {
  pinMode(port[0], OUTPUT);
  pinMode(port[1], OUTPUT);
  pinMode(port[2], OUTPUT);
  pinMode(port[3], OUTPUT);
}
void loop() {
  static long pos, prev_pos;
  long count = millis() / 1000L;

  pos = (count * STEP_PER_ROTATION) / 10;
  rotate(pos - prev_pos);
  prev_pos = pos;
  count++;
}
