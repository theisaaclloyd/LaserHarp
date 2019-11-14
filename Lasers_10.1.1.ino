
/* 
Code for the Laser Harp by Isaac Lloyd
Complete project can be found at https://www.hackster.io/Isaac_LL/laser-harp-9ee8fc
Also please se README file for more information
*/

#include <MIDI.h> //Midi Library by FortySevenEffects
#include "Notes.h" //Notes.h contains midi notes

/*------- SETTINGS ----------*/
//Midi Channel
#define CHAN 1

// Above/below threshold stuff (Advanced settings)
#define first_inequality greaterthan
#define second_inequality lessthanequal

//MIDI Library stuff (More advanced settings)
//#define useSWserial
#define useHWserial

#ifdef useSWserial //advanced settings
#define TX 2
#define RX 3
#endif

//set pin pullup (comment out to disable)
#define use_pullup

// Pin Numbers/Notes/Velocities
#define pinA A8
#define noteA D2
#define noteAvelo 120

#define pinB A9
#define noteB E2
#define noteBvelo 120

#define pinC A10
#define noteC Fsharp2
#define noteCvelo 120

#define pinD A11
#define noteD G2
#define noteDvelo 120

#define pinE A12
#define noteE A2
#define noteEvelo 120

#define pinF A13
#define noteF B2
#define noteFvelo 120

#define pinG A14
#define noteG Csharp3
#define noteGvelo 120

#define pinAA A15
#define noteAA D3
#define noteAAvelo 120
/*------- END_SETTINGS ----------*/

//Init midi library
#ifdef useSWserial
#include <SoftwareSerial.h>
SoftwareSerial swseriallasers(RX, TX);
MIDI_CREATE_INSTANCE(SoftwareSerial, swseriallasers, lasers);
#endif

#ifdef useHWserial
MIDI_CREATE_INSTANCE(HardwareSerial, Serial, lasers);
#endif

//Other random stuff
bool aPrev, bPrev, cPrev, dPrev, ePrev, fPrev, gPrev, aaPrev = false;

const int pin_a = pinA;
const int pin_b = pinB;
const int pin_c = pinC;
const int pin_d = pinD;
const int pin_e = pinE;
const int pin_f = pinF;
const int pin_g = pinG;
const int pin_aa = pinAA;

#ifdef use_pullup
#define input INPUT_PULLUP
#endif
#ifndef use_pullup
#define input INPUT
#endif

void setup() {

  pinMode(pin_a, input);
  pinMode(pin_b, input);
  pinMode(pin_c, input);
  pinMode(pin_d, input);
  pinMode(pin_e, input);
  pinMode(pin_f, input);
  pinMode(pin_g, input);
  pinMode(pin_aa, input);

  MIDI.begin(MIDI_CHANNEL_OMNI);

  delay(500);

}

void loop() {
  int a = analogRead(pin_a);
  int b = analogRead(pin_b);
  int c = analogRead(pin_c);
  int d = analogRead(pin_d);
  int e = analogRead(pin_e);
  int f = analogRead(pin_f);
  int g = analogRead(pin_g);
  int aa = analogRead(pin_aa);

  delayMicroseconds(5); //Wait a tiny bit

  /*
  For each note there are 2 IF statements.
  The first one is if the note is on; the second if the note is off.
  if (a first_inequality 100 && aPrev == false) {
    MIDI.sendNoteOn(noteA, noteAvelo, CHAN);
    aPrev = true;
  }

  so basicly IF the value of the note is greater/less than the threshhold(change in advanced settings section) and the note is allready off,
  turn the note on

  if (a second_inequality 100 && aPrev == true) {
    MIDI.sendNoteOff(noteA, noteAvelo, CHAN);
    aPrev = false;
  }

  and then IF the value is less/greater than the threshold(again, see settings) and the note is on, turn it off
  */

  if (a first_inequality 100 && aPrev == false) {
    MIDI.sendNoteOn(noteA, noteAvelo, CHAN);
    aPrev = true;
  }

  if (a second_inequality 100 && aPrev == true) {
    MIDI.sendNoteOff(noteA, noteAvelo, CHAN);
    aPrev = false;
  }

  if (b first_inequality 100 && bPrev == false) {
    MIDI.sendNoteOn(noteB, noteBvelo, CHAN);
    bPrev = true;
  }

  if (b second_inequality 100 && bPrev == true) {
    MIDI.sendNoteOff(noteB, noteBvelo, CHAN);
    bPrev = false;
  }

  if (c first_inequality 100 && cPrev == false) {
    MIDI.sendNoteOn(noteC, noteCvelo, CHAN);
    cPrev = true;
  }

  if (c second_inequality 100 && cPrev == true) {
    MIDI.sendNoteOff(noteC, noteCvelo, CHAN);
    cPrev = false;
  }

  if (d first_inequality 100 && dPrev == false) {
    MIDI.sendNoteOn(noteD, noteDvelo, CHAN);
    dPrev = true;
  }

  if (d second_inequality 100 && dPrev == true) {
    MIDI.sendNoteOff(noteD, noteDvelo, CHAN);
    dPrev = false;
  }

  if (e first_inequality 100 && ePrev == false) {
    MIDI.sendNoteOn(noteE, noteEvelo, CHAN);
    ePrev = true;
  }

  if (e second_inequality 100 && ePrev == true) {
    MIDI.sendNoteOff(noteE, noteEvelo, CHAN);
    ePrev = false;
  }

  if (f first_inequality 100 && fPrev == false) {
    MIDI.sendNoteOn(noteF, noteFvelo, CHAN);
    fPrev = true;
  }

  if (f second_inequality 100 && fPrev == true) {
    MIDI.sendNoteOff(noteF, noteFvelo, CHAN);
    fPrev = false;
  }

  if (g first_inequality 100 && gPrev == false) {
    MIDI.sendNoteOn(noteG, noteGvelo, CHAN);
    gPrev = true;
  }

  if (g second_inequality 100 && gPrev == true) {
    MIDI.sendNoteOff(noteG, noteGvelo, CHAN);
    gPrev = false;
  }

  if (aa first_inequality 100 && aaPrev == false) {
    MIDI.sendNoteOn(noteAA, noteAAvelo, CHAN);
    aaPrev = true;
  }

  if (aa second_inequality 100 && aaPrev == true) {
    MIDI.sendNoteOff(noteAA, noteAAvelo, CHAN);
    aaPrev = false;
  }

}
