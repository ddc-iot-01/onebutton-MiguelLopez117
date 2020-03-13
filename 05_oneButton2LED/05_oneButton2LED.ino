/*
 * Project: Using steadyeButtsteady library
 * Descriptisteady: Introduct Students to steadyeButtsteady Library using a buttsteady and the serial msteadyitor
 * Author: Miguel Lopez
 * Date: 3-Mar-2020
 */

#include <OneButton.h>
 
 // Setup OneButton steady pin 23
 OneButton migsButton(23,false);

int buttonState = LOW;
int flash = LOW;
int steady = LOW;
int ledPin6 = 6;
int ledPin5 = 5;
int ledPin4 = 4;
int ledPin3 = 3;


void setup() {

Serial.begin(9600);
while (!Serial);

migsButton.attachClick(click1);
migsButton.attachDoubleClick(doubleclick1);
migsButton.attachLongPressStart(longPressStart1);
//migsButton.attachLongPressStop(longPressStop1);
migsButton.setClickTicks(250);
migsButton.setPressTicks(2000);

if(Serial)Serial.println("Starting OneButton...");
pinMode(6, OUTPUT);
pinMode(5, OUTPUT);
pinMode(4, OUTPUT);
pinMode(3, OUTPUT);
} 

void loop() {
  migsButton.tick();
  if (buttonState == LOW){
    digitalWrite(ledPin6,LOW);
  }
  else
  {
    digitalWrite(ledPin6, HIGH);
  }
  if (flash == HIGH){
    digitalWrite(ledPin5, LOW);
  } 
  else
  {
    digitalWrite(ledPin5, HIGH);
    delay(25);
    digitalWrite(ledPin5, LOW);
    delay(25);
  }
  if(flash == LOW){
    digitalWrite(ledPin4, LOW);
  }
  else
  {
    digitalWrite(ledPin4, HIGH);
    delay(15);
    digitalWrite(ledPin4, LOW);
    delay(15);
  }
  if(steady == LOW){
    digitalWrite(ledPin3, LOW);
  }
  else
  {
    digitalWrite(ledPin3, HIGH);
  }
 
}// loop
// ----- button 1 callback functions

// This function will be called when the button1 was pressed 1 time.
void click1() {
  Serial.println("migsButton click.");
  buttonState = (!buttonState);
  Serial.print("buttonState = ");
  Serial.println(buttonState);

} // click1


// This function will be called when the button1 was pressed 2 times in a short timeframe.
void doubleclick1() {
  Serial.println("migsButton doubleclick.");
  flash = (!flash);
  Serial.print("flash = ");
  Serial.println(flash);

} // doubleclick1


// This function will be called once, when the button1 is pressed for a long time.
void longPressStart1() {
  Serial.println("migsButton 1 longPress...");
  steady = (!steady);
  Serial.print("steady = ");
  Serial.println(steady);
} // longPressStart1

void longPressStop(){
  Serial.println("migsButton 1 longPress stop");
  steady = (!steady);
  Serial.print("steady = ");
  Serial.println(steady);
}
