#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(9, 10); //radio(CE, CS);
const uint64_t kod = 0xE8E8F0F0E101;
int sayi[1];
int pot;

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(kod);

}

void loop()
{
  if (Serial.read())
  {
    pot = analogRead(A0);
    sayi[0] = map(pot, 0, 1023, 0, 180);
    

    /*
    int deger;
    double sicaklik;
    deger = analogRead(0);
    sicaklik = Termistor(deger);
    sayi[0] = sicaklik;
    */
    
    radio.write(sayi, 1);
    Serial.println(sayi[0]);
  }
}

double Termistor(int analogOkuma)
{
  double sicaklik;
  sicaklik = log((10240000 / analogOkuma) - 10000);
  sicaklik = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * sicaklik * sicaklik)) * sicaklik);
  sicaklik = sicaklik - 273.15;
  return sicaklik;
}
