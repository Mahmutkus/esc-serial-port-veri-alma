#include <Servo.h>
#include "ESC.h"

int tamSayi = 0;

ESC myESC (3, 1000, 2000, 500);                 // ESC_Name (ESC PIN, Minimum Value, Maximum Value, Default Speed, Arm Value)

int oESC;
void setup() {
  pinMode(13, OUTPUT);                               // LED Visual Output

  // Attach the ESC on pin 9
  Serial.begin(9600);
  myESC.arm();                                            // Send the Arm value so the ESC will be ready to take commands
  digitalWrite(13, HIGH);                            // LED High Once Armed
  delay(5000);                                            // Wait for a while
  myESC.speed(0);
  digitalWrite(13, LOW);
}
void loop() {
  if (Serial.available()) { // Serial Porta girdi değerinin olup olmadığını kontrol et
    tamSayi = Serial.parseInt(); // veri dizisindeki tam sayıları oku
    Serial.println(tamSayi);
    myESC.speed(tamSayi);
  }
}
