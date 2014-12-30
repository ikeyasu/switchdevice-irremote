int ir_out = 2;
int led = 9;
 
unsigned int data[] = {329,600,580,549,575,500,500,558,566,506,493,505,495,534,589,579,545,500,514,545,564,530,626,633,585,507,491,518,481,535,590,499,499,589,536,499,524,619,481,540,591,566,552,500,507,619,497,589,536,559,565,530,595,499,499,517,482,515,484,532,593,499,500,586,539,536,587,518,482};
 
int last = 0;
unsigned long us = micros();
 
void setup() {
  pinMode(ir_out, OUTPUT);
  pinMode(led, OUTPUT);
}
 
void sendSignal() {
  int dataSize = sizeof(data) / sizeof(data[0]);
  for (int cnt = 0; cnt < dataSize; cnt++) {
    unsigned long len = data[cnt] * 10;
    unsigned long us = micros();
    do {
      digitalWrite(ir_out, 1 - (cnt & 1));
      delayMicroseconds(8);
      digitalWrite(ir_out, 0);
      delayMicroseconds(7);
    } while (long(us + len - micros()) > 0);
  }
}
 
void loop() {
  digitalWrite(led, HIGH);
  sendSignal();
  digitalWrite(led, LOW);
  delay(3000);
}
