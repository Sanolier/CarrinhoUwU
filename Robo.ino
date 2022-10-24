#include <SoftwareSerial.h>
SoftwareSerial bluetooth(2, 3);
 
int motord_e = 4;
int motord_d  = 5;
int motore_e  = 6;
int motore_d  = 7;
char comando;
 
void setup() {
  bluetooth.begin(9600);
  pinMode(motord_e, OUTPUT);
  pinMode(motord_d, OUTPUT);
  pinMode(motore_e, OUTPUT);
  pinMode(motore_d, OUTPUT);
}
 
void loop() {
  while (bluetooth.available()) {
    comando = bluetooth.read();
    if (comando == 'F') {
      digitalWrite(motord_e, HIGH);
      digitalWrite(motord_d, LOW);
      digitalWrite(motore_e, LOW);
      digitalWrite(motore_d, HIGH);
    }
    else if (comando == 'B') {
      digitalWrite(motord_e, LOW);
      digitalWrite(motord_d, HIGH);
      digitalWrite(motore_e, HIGH);
      digitalWrite(motore_d, LOW);
    }
    else if (comando == 'L') {
       digitalWrite(motord_e, LOW);
       digitalWrite(motord_d, HIGH);
       digitalWrite(motore_e, LOW);
       digitalWrite(motore_d, HIGH);
    } 
    else if (comando == 'R') {
      digitalWrite(motord_e, HIGH);
      digitalWrite(motord_d, LOW);
      digitalWrite(motore_e, HIGH);
      digitalWrite(motore_d, LOW);
    } else {
       digitalWrite(motord_e, LOW);
       digitalWrite(motord_d, LOW);
       digitalWrite(motore_e, LOW);
       digitalWrite(motore_d,LOW);
    }
  }
}
 
