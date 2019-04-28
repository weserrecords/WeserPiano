/*
  ==============================================================================

    PianoSynth.h
    Created: 28 Apr 2019 4:12:12pm
    Author:  Kai

  ==============================================================================
*/

#pragma once

class PianoSynth : public Synthesiser
{
public:
	PianoSynth();

	void setup();

private:
	AudioFormatManager formatManager;

};