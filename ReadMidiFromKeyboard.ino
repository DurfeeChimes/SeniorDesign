#include <SoftwareSerial.h>

// We will use the SoftwareSerial library instead of the Serial library, as this will let us control which pins our MIDI interface is connected to.
SoftwareSerial mySerial(0, 1); // RX, TX

// constants

const byte midiNoteOn = 144;

const int midiSendDelay = 100; // give MIDI-device a short time to "digest" MIDI messages

#define PIN_LED 13

#define MIDI_NOTE_ON 144

byte midiByte;
byte midiChannel;
byte midiCommand;

void setup() {
    // setup SoftSerial for MIDI control
    mySerial.begin(31250);
    delay(midiSendDelay);
}

void loop () {
    if (mySerial.available() > 0) {
        midiByte = Serial.read();
        mySerial.println(midiByte);
        // remove channel info
        midiChannel = midiByte & B00001111;
        midiCommand = midiByte & B11110000;
    }
}
