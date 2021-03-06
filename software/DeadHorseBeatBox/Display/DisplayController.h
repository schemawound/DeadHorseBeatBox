#ifndef _DISPLAY_DISPLAYCONTROLLER_h
#define _DISPLAY_DISPLAYCONTROLLER_h

#include "../DHBB_Options.h"
#include "../DHBB_Types.h"
#include "DisplayView.h"
#include "../Song/Clock.h"
#include "../Song/Pattern.h"
#include "../Grid.h"
#include "string.h"
#include "TempoLed.h"

namespace Display {
	class DisplayController
	{
	private:
		Midi::MidiManager * p_midi_manager_ = 0;
		Song::Pattern * p_pattern_ = 0;
		Song::Clock * p_clock_ = 0;
		Display::TempoLed tempo_led_ = Display::TempoLed(TEMPO_LED_PIN);
		Display::Led track_select_led_ = Display::Led(TRACK_SELECT_LED_PIN);
		Grid * p_grid_ = 0;
		Display::DisplayView view = Display::DisplayView();

		//Used to track the current values of the bargraph
		USHORT track_playing_bargraph_[16] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
		ULONG last_bargraph_update_ = millis();
		USHORT fall_speed = 10;

		void DisplayTrack(USHORT track_number, USHORT y);
		void DisplayTrackPlayingBargraph(USHORT y, USHORT graph_height);
		void DisplaySingleTrackView(USHORT track_number);
		void DisplayFourTrackView(USHORT track_number);
		void ProcessTrackPlayingBargraphFall();
		void UpdateSelectButtonDisplay(ULONG pulse);

	public:
		DisplayController(Midi::MidiManager * p_midi_manager, Grid * p_grid, Song::Pattern * p_pattern, Song::Clock * p_clock);
		~DisplayController();
		void UpdateDisplay(ULONG pulse);
	};
}
#endif
