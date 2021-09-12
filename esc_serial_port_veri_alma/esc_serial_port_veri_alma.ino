#include <Servo.h>
#include "ESC.h"

int tamSayi = 0;                             

ESC myESC (3, 1000, 2000, 500);                 // ESC_Name (ESC PIN, Minimum Value, Maximum Value, Default Speed, Arm Value)

int oESC;
void setup() {
  pinMode(13, OUTPUT);                                    // LED'imizi çıkış olarak ayarlıyoruz

  // Attach the ESC on pin 9
  Serial.begin(9600);
  myESC.arm();                                            // esc'mize arm etme komutunu gönderiyoruz
  digitalWrite(13, HIGH);                                 // LED aktifleştiriyoruz
  delay(5000);                                            // 5 sn bekliyoruz
  myESC.speed(0);
  digitalWrite(13, LOW);
}
void loop() {
  if (Serial.available()) { // Serial Porta girdi değerinin olup olmadığını kontrol et
    tamSayi = Serial.parseInt(); // veri dizisindeki tam sayıları oku
    Serial.println(tamSayi);    //okuduğumuz tamsayı değişkeni serial porta yazdırıyoruz
    myESC.speed(tamSayi);       //yazmış olduğumuz tam sayı değerini esc'mize gönderiyoruz  
  }
}
