// pins 4 to 11
// remember to change arduino type to leonardo
//use autoHotKey in windows to execute shortcuts when an specific key is pressed

#include <HID-Project.h>
#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns

// the library will return the character inside this array
// when the appropriate button is pressed.
char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'},
};

byte rowPins[ROWS] = {4, 5, 6, 7}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {8, 9, 10, 11 }; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup() {
  Serial.begin(9600);
  Consumer.begin();
  Keyboard.begin();
}

void loop() {
  //Getting the key that was pressed.
  char key = keypad.getKey();

  if (key) {
    Serial.println(key);
    switch (key) {
      case '1':
        Keyboard.println("Key '1' was pressed");
        break;

      case '2':
        Keyboard.println("Key '2' was pressed");
        break;

      case '3':
        // https://github.com/arduino-libraries/Keyboard/blob/master/src/Keyboard.h
        Keyboard.println("Key '3' was pressed");
        break;

      case '4':
        Keyboard.println("Key '4' was pressed");
        break;

      case '5':
        Keyboard.println("Key '5' was pressed");
        break;

      case '6':
        Keyboard.println("Key '6' was pressed");
        break;

      case '7':
        Keyboard.println("Key '7' was pressed");
        break;

      case '8':
        Keyboard.println("Key '8' was pressed");
        break;

      case '9':
        Keyboard.println("Key '9' was pressed");
        break;

      case '0':
        Keyboard.println("Key '0' was pressed");
        break;

      case '*':
        Consumer.write(MEDIA_VOLUME_MUTE);
        break;

      case '#':
       Consumer.write(MEDIA_VOLUME_UP);
       break;

      case 'A':
        // https://github.com/NicoHood/HID/wiki/Consumer-API
        Consumer.write(MEDIA_VOLUME_DOWN);
        break;

      case 'B':
        Consumer.write(MEDIA_PLAY_PAUSE);
        break;

      case 'C':
        Consumer.write(MEDIA_NEXT);
        break;

      case 'D':
        Consumer.write(MEDIA_PREVIOUS);
        break;

    }

    delay(100);
    Keyboard.releaseAll(); // this releases the buttons
  }
}
