/*
 * Project: Using OneButton library
 * Description: Introduct Students to OneButton Library using a button and the serial monitor
 * Author: Miguel Lopez
 * Date: 3-Mar-2020
 */

#include <OneButton.h>
 
 // Setup OneButton on pin 23
 OneButton migsButton(23,false);

int buttonState = LOW;
int ledPin6 = 6;
int ledPin5 = 5;
int ledPin4 = 4;
int flash = LOW;

void setup() {

Serial.begin(9600);
while (!Serial);

migsButton.attachClick(click1);
migsButton.attachDoubleClick(doubleclick1);
//migsButton.attachLongPressStart(longPressStart1);
//migsButton.attachLongPressStop(longPressStop1);
migsButton.setClickTicks(250);
migsButton.setPressTicks(2000);

if(Serial)Serial.println("Starting OneButton...");
pinMode(6, OUTPUT);
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
  if (flash == LOW){
    digitalWrite(ledPin6, LOW);
  } 
  else
  {
    digitalWrite(ledPin6, HIGH);
    delay(50);
    digitalWrite(ledPin6, LOW);
    delay(50);
   
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
  flash = !flash;
  Serial.print("flash = ");
  Serial.println(flash);

} // doubleclick1


// This function will be called once, when the button1 is pressed for a long time.
void longPressStart1() {
Serial.println("Button 1 longPress...");
} // longPressStart1

void longPressStop(){
  Serial.println("Button 1 longPress stop");
}
