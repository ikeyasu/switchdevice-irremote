#define READ_PIN 7
#define LOW_STATE 0
#define HIGH_STATE 1

unsigned int gData[1024];
unsigned int gDataCount = 0;

void setup(){
  Serial.begin(57600);
  pinMode(READ_PIN,INPUT);

  Serial.println("Ready to receive");
}

void waitLow() {
  while (digitalRead(READ_PIN)==LOW) {
    ;
  }
}

void waitHigh() {
  unsigned long start = micros();
  while (digitalRead(READ_PIN)==HIGH) {
    ;
  }
}

unsigned long now = micros();
unsigned long lastStateChangedMicros = micros();
int state = HIGH_STATE;

void loop() {
    if (state == LOW_STATE) {
      waitLow();
    } else {
      waitHigh();
    }

    now = micros();
    if (now - lastStateChangedMicros > 1 * 1000 * 1000) {
      Serial.print(".");
      Serial.print(gDataCount, DEC);
      Serial.print("\n");
      for (int i = 0; i < gDataCount; i++) {
        Serial.print(gData[i], DEC);
        Serial.print(",");
      }
      Serial.print("\n");
      gDataCount = 0;
      lastStateChangedMicros = now;
      //return;
    }

    gData[gDataCount] = (now - lastStateChangedMicros) / 10;
    gDataCount++;
    //Serial.print((now - lastStateChangedMicros) / 10, DEC);
    //Serial.print(",");
    lastStateChangedMicros = now;
    if (state == HIGH_STATE) {
      state = LOW_STATE;
    } else {
      state = HIGH_STATE;
    }
}
