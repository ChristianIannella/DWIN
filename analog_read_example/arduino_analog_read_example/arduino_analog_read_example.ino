#include <SoftwareSerial.h>

SoftwareSerial dwinSerial(10, 11);  // RX, TX

byte DataToDisplay[] = { 0x5A, 0xA5, 0x05, 0x82, 0x30, 0x00, 0x00, 0X00 };

int data = 0;
const int analogInPin = A0;
int sensorValue = 0;
unsigned long previousMillis = 0;
const long interval = 100;


void dwinListen() {

  int startAdd = 00;
  int endAdd = 00;
  int dataVal = 0;
  String address;

  while (dwinSerial.available()) {
    int inhex = dwinSerial.read();

    if (inhex == 90 || inhex == 165) {
      continue;
    }

    for (int i = 1; i <= inhex; i++) {
      while (!dwinSerial.available())
        ;
      int incomingByte = dwinSerial.read();
      if (i == 2) {
        startAdd = incomingByte;
      }
      if (i == 3) {
        endAdd = incomingByte;
      }

      if (i == inhex) {
        dataVal = incomingByte;
      }
    }
  }
}

void sendAnalog() {
  sensorValue = analogRead(analogInPin);
  data = map(sensorValue, 0, 1023, 0, 99);
  DataToDisplay[6] = highByte(data);
  DataToDisplay[7] = lowByte(data);
  dwinSerial.write(DataToDisplay, sizeof(DataToDisplay));
  delay(50);

  while (dwinSerial.available()) {
    int inhex = dwinSerial.read();
    if (inhex == 90 || inhex == 165) {
      continue;
    }
  }
}



void setup() {
  Serial.begin(115200);
  dwinSerial.begin(115200);
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {

  dwinListen();

  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    sendAnalog();
  }
}