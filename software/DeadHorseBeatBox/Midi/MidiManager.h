// MidiManager.h

#ifndef _MIDI_MIDIMANAGER_h
#define _MIDI_MIDIMANAGER_h

#include "../DHBB_Options.h"
#include "../DHBB_Types.h"
#include "arduino.h"
#include <MIDI.h>

namespace Midi {
	struct MidiEvent {
		USHORT Track = 0;
		USHORT RootNote = 60;
		USHORT Channel = 0;
		USHORT Velocity = 100;
		USHORT PulseLife = PULSE_PER_STEP / 2;
		bool Playing = false;
		bool Hold = false;
	};

	class MidiManager {
	private:
		midi::MidiInterface<HardwareSerial> * p_midi_ = 0;
		MidiEvent midi_events_[NUM_OF_TRACKS];
		void NoteOn(MidiEvent& midi_event);
		void NoteOff(MidiEvent& midi_event);

	public:
		MidiManager(midi::MidiInterface<HardwareSerial> * p_midi);
		~MidiManager();
		void AddEvent(MidiEvent& midi_event);
		void ProcessPulse(ULONG pulse);
		void AllNotesOff();
		MidiEvent& GetEvent(USHORT track);
	};
}
#endif

