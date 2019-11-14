# LaserHarp

 Settings:
 CHAN - Master channel that all midi notes will be sent on
 first/second inequality - the inequality that the if statements use for the threshold.
 first_inequality is the one used to turh the note on => IF val first_inequality threshold => if the value of the note is __ than the thresh, turn on the note
 second_inequality - same as first, only turns note off
 coms port for MIDI library:
 useSWserial - uncomment if your using software serial
 
 if your using software serial then please specify the pins under #define TX __ and #define RX __
 useHWserial - [default] use basic arduino usb port for midi. Note: if using hardware serial, you cannot open a serial port [Serial.begin(xxx)]
 because it is already being used by the midi library
 pin numbers/notes/velocities
 as he name sugests, this section defines the pin number of every note, what note it actually plays, and the velocity of the note
