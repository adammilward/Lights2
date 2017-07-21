
#include "config.h"
#include "Arduino.h"
#include "IRremote.h"
#include "Controller.h"

IRrecv irrecv(CONFIG::IREC_PIN);      // from the ir decode library
decode_results Results; // from the ir decode library
Controller RemoteCtr;      // handles the remotes
unsigned long waitMillisLights; // for timeing the next event.

void setup() {
    randomSeed(analogRead(0)); // initialise for random numbers
    irrecv.enableIRIn(); // Start the receiver
    // initialize serial communication at 9600 bits per second:
    Serial.begin(9600);

    //Timer0 is already used for millis() - we'll just interrupt somewhere
    //in the middle and call the "Compare A" function below
    //OCR0A = 0x80;
    //TIMSK0 |= _BV(OCIE0A);
    waitMillisLights = millis() + RemoteCtr.LightRemote.delay;

    delay(100);
    RemoteCtr.LightRemote.Red.set(0);
    RemoteCtr.LightRemote.Green.set(0);
    RemoteCtr.LightRemote.Blue.set(0);
}

// Interrupt is called once a millisecond,
SIGNAL(TIMER0_COMPA_vect) {
/*    if (RemoteCtr.LightRemote.ctrMode != LightCtr::STATIC) {
        if ((long) (millis() - waitMillisLights) >= 0) {
            waitMillisLights += RemoteCtr.LightRemote.delay;  // set the time for next interupt
            RemoteCtr.LightRemote.interrupt();
        }
    }*/
}

// The loop function is called in an endless loop
void loop() {
    if (RemoteCtr.LightRemote.ctrMode != LightCtr::STATIC) {
        if ((long) (millis() - waitMillisLights) >= 0) {
            waitMillisLights = millis() + RemoteCtr.LightRemote.delay;  // set the time for next interupt
            RemoteCtr.LightRemote.interrupt();
        }
    }
    if (irrecv.decode(&Results)) {
        RemoteCtr.receive(Results.value);
        irrecv.resume(); // Receive the next value
    }
}
