#include <Servo.h>
#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10); // radio(CE, CS);
const uint64_t kod = 0xE8E8F0F0E101;
int sayi[1];

Servo servo;
int servoPin = 3;

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openReadingPipe(1, kod);
  radio.startListening();
  servo.attach(servoPin);
}

void loop() {
  if (radio.available()) {
    if ( radio.read(sayi, 1))
    {
      servo.write(sayi[0]);
      Serial.println(sayi[0]);
    }
  }
}
