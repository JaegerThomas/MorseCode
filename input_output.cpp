#include <stdlib.h>
#include <string>
#include <iostream>
#include <wiringPi.h>

#define OUTPUT_PIN 0
#define INPUT_PIN 2

using namespace std;

char decodeMorse(string s) {
  const string morse("SOS");
  int p = -1;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '-') p += 1 << (4 - i);
    else p++;
  }
  return morse[p];
}


void wait(int n) {
  delay(100 * n);
}

void dot() {
  digitalWrite(OUTPUT_PIN, HIGH);
  wait(1);
  digitalWrite(OUTPUT_PIN, LOW);
  wait(1);
}

void dash() {
  digitalWrite(OUTPUT_PIN, HIGH);
  wait(3);
  digitalWrite(OUTPUT_PIN, LOW);
  wait(1);
}

void sendMorse(char character) {
  switch (character) {
    case ('A'):
      dot();  dash();
      break;
    case ('B'):
      dash();  dot(); dot(); dot();
      break;
    case ('C'):
      dash(); dot(); dash(); dot();
      break;
    case ('D'):
      dash(); dot(); dot();
      break;
    case ('E'):
      dot();
      break;
    case ('F'):
      dot(); dot(); dash(); dot();
      break;
    case ('G'):
      dash(); dash(); dot();
      break;
    case ('H'):
      dot(); dot(); dot(); dot();
      break;
    case ('I'):
      dot(); dot();
      break;
    case ('J'):
      dot(); dash(); dash(); dash();
      break;
    case ('K'):
      dash(); dot(); dash();
      break;
    case ('L'):
      dot(); dash(); dot(); dot();
      break;
    case ('M'):
      dash(); dash();
      break;
    case ('N'):
      dash(); dot();
      break;
    case ('O'):
      dash(); dash(); dash();
      break;
    case ('P'):
      dot(); dash(); dash(); dot();
      break;
    case ('Q'):
      dash(); dash(); dot(); dash();
      break;
    case ('R'):
      dot(); dash(); dot();
      break;
    case ('S'):
      dot(); dot(); dot();
      break;
    case ('T'):
      dash();
      break;
    case ('U'):
      dot(); dot(); dash();
      break;
    case ('V'):
      dot(); dot(); dot(); dash();
      break;
    case ('W'):
      dot(); dash(); dash();
      break;
    case ('X'):
      dash(); dot(); dot(); dash();
      break;
    case ('Y'):
      dash(); dot(); dash(); dash();
      break;
    case ('Z'):
      dash(); dash();dot(); dot();
      break;
    case ('0'):
      dash(); dash(); dash(); dash(); dash();
      break;
    case ('1'):
      dot(); dash(); dash(); dash(); dash();
      break;
    case ('2'):
      dot();  dot(); dash(); dash(); dash();
      break;
    case ('3'):
      dot(); dot();  dot(); dash(); dash();
      break;
    case ('4'):
      dot();  dot();  dot(); dot(); dash();
      break;
    case ('5'):
      dot();  dot();  dot(); dot();  dot();
      break;
    case ('6'):
      dash(); dot();  dot();  dot(); dot();
      break;
    case ('7'):
      dash(); dash(); dot();  dot();  dot();
      break;
    case ('8'):
      dash(); dash(); dash(); dot();  dot();
      break;
    case ('9'):
      dash(); dash(); dash(); dash(); dot();
      break;
    default:
          // hier kom je als je verkeerde imput hebt gegeven
      break;
  }
  wait(2); // wait 1 + 2 = 3 dots in total
}

int main() {

  // to do
  cout << "in main" << "\n";
  pullUpDnControl(INPUT_PIN, PUD_UP);
  //wiringPiISR(INPUT_PIN, INT_EDGE_BOTH, &switchChanged);
  int character;
  while (true) {
    character = getchar();
    if (character == ' ') {
      wait(6);
    }
    else {
      sendMorse(character);
    }
  }
}

/*
void switchChanged() {
  static string buffer;
  static unsigned int previousTime = 0, currentTime, timePassed;
  currentTime = millis();
  if (previousTime == 0) { // first pulse
    previousTime = currentTime;
    return;
  }
  timePassed = currentTime - previousTime;
  previousTime = currentTime;
  if (digitalRead(INPUT_PIN) == HIGH)
  {
    if (timePassed > 200) {

      // TO DO

    }
    if (timePassed > 600) {

      // TO DO

    }
  }

  if(digitalRead(INPUT_PIN) == LOW)
  {
    if (timePassed > 200) {

      // TO DO

    }
    else {

      // TO DO

    }
  }
}
*/
