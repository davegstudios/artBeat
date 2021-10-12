
/*  PulseSensor Based LED or Relay blinker driver
 *  Here is a link to the tutorial where the code is based on and for the Pulse Sensor that was used
 *  https://pulsesensor.com/pages/code-and-guide
 * Copyright 2021 DavegStudios
*/


int PulseSensorPurplePin = 0;        // Pulse Sensor PURPLE WIRE connected to ANALOG PIN 0
int LEDOUT = 6;   //  The pin for the LED or Relay, in our case it is a relay on digital pin 6


int Signal;                // holds the incoming raw data. Signal value can range from 0-1024
int Threshold = 520;            // Determine which Signal to "count as a beat", and which to ingore.
                                //  Tweat this to a range that works for your application. 
                                //  Open Arduino IDE's Serial Plotter to help determine this value


// The SetUp Function:
void setup() {
  pinMode(LEDOUT,OUTPUT);         // pin that will blink to your heartbeat!
   Serial.begin(9600);         // Set's up Serial Communication at certain speed.

}

// The Main Loop Function
void loop() {

  Signal = analogRead(PulseSensorPurplePin);  // Read the PulseSensor's value.
                                              // Assign this value to the "Signal" variable.

   Serial.println(Signal);                    // Send the Signal value to Serial Plotter.


   if(Signal > Threshold){                          // If the signal is above Threshold, then "turn-on" LED/Relay.
     digitalWrite(LEDOUT,HIGH);
   } else {
     digitalWrite(LEDOUT,LOW);                //  Else, the sigal must be below Threshold, then "turn-off" LED/Relay.
   }


delay(10);    //  Tweak this value to help with noise filtering. 
              //    Sometimes the signal will be erratic and smoothing it out with a higher delay helps


}
