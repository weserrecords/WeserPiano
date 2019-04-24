/*
  ==============================================================================

    PianoSound.h
    Created: 24 Apr 2019 12:45:58pm
    Author:  Kai

  ==============================================================================
*/

#pragma once

class PianoSound : public SynthesiserSound
{
public:
	PianoSound();

	~PianoSound();

	bool appliesToNote(int midiNoteNumber);

	bool appliesToChannel(int midiChannel);

private:


};