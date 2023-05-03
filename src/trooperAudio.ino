#include "SerialMP3Player.h"

// constants won't change. They're used here to set pin numbers:
const int button1Pin = 2;     // starts at D02
const int button2Pin = 3;     // the number of the pushbutton pin
const int button3Pin = 4;     // the number of the pushbutton pin
const int button4Pin = 5;     // the number of the pushbutton pin
// Add 4 more buttons.

int sndId;

int sounds1 = [0x01, 0x02, 0x03];
int sounds2 = [0x04, 0x05, 0x06];
int sound3 = [6,7,8];
int sound4 = [9,10];

void setup() {
  Serial.begin(9600);
  
  pinMode(button1Pin, INPUT_PULLUP);
  pinMode(button2Pin, INPUT_PULLUP);
  pinMode(button3Pin, INPUT_PULLUP);
  pinMode(button4Pin, INPUT_PULLUP);
}

void loop() {

  sndId = 0;
  
  int btn1 = digitalRead(button1Pin);
  int btn2 = digitalRead(button2Pin);
  int btn3 = digitalRead(button3Pin);
  int btn4 = digitalRead(button4Pin);

  if (btn1 + btn2 + btn3 + btn4 > 4) {
  Serial.print("Btn1: "); Serial.print(btn1);
  Serial.print("  \tBtn2: "); Serial.print(btn2);
  Serial.print("  \tBtn3: "); Serial.print(btn3);
  Serial.print("  \tBtn4: "); Serial.print(btn4);
  Serial.println(" ");    
  }



  if (btn1 == LOW) { sndId = soundChooser(1,2); }
  else if (btn2 == LOW) { sndId = soundChooser(2,3); }
  else if (btn3 == LOW) { sndId = soundChooser(3,4); }
  else if (btn4 == LOW) { sndId = soundChooser(4,5); }
  else { 
    sndId = 0;
  }

  if (sndId > 0) { 
    Serial.print("Button: "); 
    Serial.print(sndId); 
    Serial.println(" was pressed.");
    delay(1000);
  }

  delay(10);
}

/*
 * Pick a random sound from a list of potential choices.
 */
int soundChooser(int first, int last) {
  // FOR TESTING: just return the value passed in
  Serial.println("Choosing value");
  return first;
}
