#include <Servo.h>

Servo sg90;
int ledPin = 13;

void setup() {
  sg90.attach(9); // Servo motorunun bağlı olduğu pin (örneğin pin 9)
  pinMode(ledPin, OUTPUT); // LED pinini çıkış olarak ayarla
  Serial.begin(9600); // Seri iletişimi başlat
}

void loop() {
  // Seri porttan gelen komutları işleme
  if (Serial.available() > 0) {
    char command = Serial.read();
    if (command == '0') {
      sg90.write(90); // Servo motorunu 90 dereceye döndür (aç)
    } else if (command == '1') {
      sg90.write(0); // Servo motorunu 0 dereceye döndür (kapat)
    } else if (command == '2') {
      digitalWrite(ledPin, HIGH); // LED'i yak
    } else if (command == '3') {
      digitalWrite(ledPin, LOW); // LED'i söndür
    }
  }

  delay(15); // Kısa bir gecikme ekleyerek işlemleri yumuşat
}
