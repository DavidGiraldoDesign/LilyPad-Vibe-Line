#include "pitches.h"

int inicio_notas[] = {
  NOTE_C5, NOTE_E5, NOTE_E5, NOTE_D4, NOTE_D5, NOTE_C4
};
int inicio_tiempos[] = {
  2, 4, 3, 4, 3, 2
};

int acceso_notas[] = {
  NOTE_G5, NOTE_E4
};
int acceso_tiempos[] = {
  4, 6
};


int llego_notas[] = {
  NOTE_A5, NOTE_A4, NOTE_A5
};
int llego_tiempos[] = {
  6, 4, 4
};

int hapticos[] = {5, 6, 9, 10, 11};

boolean sound = true;

void setup() {

  Serial.begin(9600);

  for (int i = 0; i < 5; i++) {
    pinMode(hapticos[i], OUTPUT);
  }

  for (int i = 0; i < 5; i++) {
    digitalWrite(hapticos[i], HIGH);
    Serial.print("Haptico No ");
    Serial.print(i);
    Serial.print("\n");
    delay(500);
    digitalWrite(hapticos[i], LOW);
    delay(500);
  }

  Serial.print("Estamos listos ;)");
  Serial.print("\n");
  playTono(inicio_notas, inicio_tiempos, 6, 0.7);
  delay(500);
}

void loop() {
  if ( Serial.available() > 0 ) {

    switch (Serial.read()) {
      case 'a':
        playTono(acceso_notas, acceso_tiempos, 2, 0.5);
        vibrar(0);
        break;
      case 'q':
        playTono(acceso_notas, acceso_tiempos, 2, 0.5);
        vibrar(1);
        break;
      case 'w':
        playTono(acceso_notas, acceso_tiempos, 2, 0.5);
        vibrar(2);
        break;
      case 'e':
        playTono(acceso_notas, acceso_tiempos, 2, 0.5);
        vibrar(3);
        break;
      case 'd':
        playTono(acceso_notas, acceso_tiempos, 2, 0.5);
        vibrar(4);
        break;
      case ' ':
        sound = !sound;
        playTono(acceso_notas, acceso_tiempos, 2, 0.5);
        break;
      default:
        playTono(llego_notas, llego_tiempos, 3, 0.6);
        break;
    }
  }
}

void playTono(int notas[], int tiempos[], int tam, float tempo) {
  if (sound == true) {
    for (int nota = 0; nota < tam; nota++) {
      int tiempo = 1000 / tiempos[nota];
      tone(A2, notas[nota], tiempo);
      int pauseBetweenNotes = tiempo * tempo;
      delay(pauseBetweenNotes);
      noTone(A2);
    }
  }

}

void vibrar(int cual) {
  digitalWrite(hapticos[cual], HIGH);
  delay(400);
  digitalWrite(hapticos[cual], LOW);
  delay(500);
  digitalWrite(hapticos[cual], HIGH);
  delay(400);
  digitalWrite(hapticos[cual], LOW);
  delay(500);
}
