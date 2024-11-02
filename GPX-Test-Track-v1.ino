/*
September 2024 - first code development on UNO
October 2024 - working code with i2c 14seg display. Deploy on a Nano.  Serial output can be enabled for debugging.
*/
#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"
Adafruit_AlphaNum4 alpha4 = Adafruit_AlphaNum4();  // i2c display, use SCA and SCL
int startPin = 2;  // IR detector for start position
int endPin = 3; // IR detector for end position
int restartPin = 4; // pin to reset timer loop
int running = 0; //run state for each section of code
float lane_time_sec; //microseconds
char lane_time_str[5]; // string for LED printing the time
float lanestart = 0; // micros for start time
float lanefinish = 0; // micros for end time
char displaybuffer[4] = {' ', ' ', ' ', ' '}; // for the startup banner
char *message = "     AWANA  GRAND  PRIX     "; // scrolling message to display on boot - add spaces for effect

void setup() {
pinMode(startPin, INPUT); // start sensor 
digitalWrite(startPin, HIGH);  //enable pull-up resistor
pinMode(endPin, INPUT); // end sensor
digitalWrite(endPin, HIGH); //enable pull-up resistor
pinMode(restartPin, INPUT); // the reset pin after a race
digitalWrite(restartPin, HIGH); //enable pull-up resistor
alpha4.begin(0x70);  // pass in the address for the i2c backpack
//Serial.begin(9600); // for development
//Serial.println("0.000");
scrolling(); // the power on welcome message
delay(1000);
ledprint("0.000"); // all zeroes
running = 1; // set the run state
digitalWrite(restartPin, LOW);
}

void loop() { // 940nm IR LED.  Matching detector will report LOW when saturated with IR light because 10k pullup resistor attached to +5v
if (digitalRead(startPin) == HIGH && running == 1) { //wait for the start sensor to go high if runstate 1
  lanestart=micros(); // capture the time now
  //Serial.println("----");
  ledprint("----"); // display while running
  running = 2; // change runstate during the event
}
  if (digitalRead(endPin) == HIGH && running == 2) { // after the start sensor is tripped and runstate 2, collect the time when the endPin goes HIGH
    lanefinish = micros() - lanestart; // calculate the finish time
    lane_time_sec = (float)(lanefinish / 1000000.0); // make it a 4 digit number 
    //Serial.println(lane_time_sec, 3); 
    dtostrf(lane_time_sec, 4, 3, lane_time_str); // convert the float to a string so we can ledprint
    ledprint(lane_time_str);
    running = 3; // change runstate after time is collected
  }
  if (running == 2 && (lanestart + 9999999) <= micros()) { // if the time goes over 9.999 seconds, end the routine, print 9.999 and wait for the reset
    running = 3;
    //Serial.println("OVERTIME"); 
    //Serial.println("9.999");
    ledprint("9.999");
  }
  //wait for a reset pin then change runstate=1
  if (running != 2 && running == 3 && digitalRead(restartPin) == LOW) {
    ledprint("0.000"); // all zeroes
    running = 1;
  }
}  // loop will wait here while runstate = 3.  Press the chip reset button to begin a new run.

void ledprint(char* str) // print the number -- got this from the support forums.  very nice!
{
  byte shift = 0;
    for (int i = 0; i < strlen(str); i++)      //for each character in str
    {
    if (str[i] == '.')  // if there is a decimal point
      {
      alpha4.writeDigitAscii(i-1, str[i-1], true);  // go back and rewrite the last digit with the dec point
      shift++;  // increment the shift counter
      }
    else
      {
      alpha4.writeDigitAscii(i-shift, str[i]);  //write the character
      }
    } 
  alpha4.writeDisplay();  //write to the display.
}

void scrolling() { // print a scrolling text message -- got this from the examples
    for (uint8_t i=0; i<strlen(message)-4; i++) {
    alpha4.writeDigitAscii(0, message[i]);
    alpha4.writeDigitAscii(1, message[i+1]);
    alpha4.writeDigitAscii(2, message[i+2]);
    alpha4.writeDigitAscii(3, message[i+3]);
    alpha4.writeDisplay();
    delay(200);
  }
}
