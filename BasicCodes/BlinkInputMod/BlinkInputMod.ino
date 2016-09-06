/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://www.arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald

  edited 05 Sep 2016
  by René Richter
 */


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
  
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // send an intro:
  Serial.println("Tell me: Shall I start blinking?");
  Serial.println("[1] - on");
  Serial.println("[0] - off");
}

// the loop function runs over and over again forever
void loop() {
  if (Serial.available() > 0) {
    int thisChar = Serial.read();
    if (isDigit(thisChar)){
      if(thisChar == 1){
        digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
        delay(1000);              // wait for a second
        digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
        delay(1000);              // wait for a second
      }
      else if(thisChar == 0){
        digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
        delay(1000);              // wait for a second
      }
      Serial.print("Pressed ");
      Serial.print(thisChar);
      Serial.print("\n");
    }
  }
}
