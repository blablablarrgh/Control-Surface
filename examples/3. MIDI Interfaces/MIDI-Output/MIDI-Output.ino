/** 
 * This is an example on how to send MIDI messages.
 *
 * @boards  AVR, AVR USB, Nano Every, Due, Nano 33, Teensy 3.x, ESP32
 * 
 * For a full list of available MIDI send functions, see @ref MIDI_Sender.
 * 
 * Connections
 * -----------
 * 
 * None.
 * 
 * Behavior
 * --------
 * 
 * - Sends a pair of MIDI note on/off messages every second.
 * 
 * Mapping
 * -------
 * 
 * None.
 * 
 * Written by PieterP, 2020-06-11  
 * https://github.com/tttapa/Control-Surface
 */

#include <Control_Surface.h> // Include the Control Surface library

// The MIDI over USB interface to use
USBMIDI_Interface midi;

void setup() {
  midi.begin(); // Initialize the MIDI interface
}

using namespace MIDI_Notes;
// MIDI note number, channel, and velocity to use
const MIDIAddress address = {note(C, 4), CHANNEL_1};
const uint8_t velocity = 0x7F;

void loop() {
  midi.sendNoteOn(address, velocity);
  delay(500);
  midi.sendNoteOff(address, velocity);
  delay(500);

  midi.update(); // Handle or discard MIDI input
}
