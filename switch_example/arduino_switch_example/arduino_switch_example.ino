#include <SoftwareSerial.h>

SoftwareSerial dwinSerial(10, 11);  // RX, TX

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

    address = String(startAdd) + String(endAdd);
    Serial.println("Address " + address + " Data " + String(dataVal));

    if (String(address) == "160") {
      if (String(dataVal) == "1") {
        digitalWrite(LED_BUILTIN, HIGH);
      } else if (String(dataVal) == "0") {
        digitalWrite(LED_BUILTIN, LOW);
      }
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
}