/*
  ==============================================================================

    PianoSound.cpp
    Created: 24 Apr 2019 12:46:11pm
    Author:  Kai

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "PianoSound.h"
#include "PianoVoice.h"

PianoSound::PianoSound()
{
}

PianoSound::~PianoSound()
{
}

bool PianoSound::appliesToNote(int midiNoteNumber)
{
	return true;
}

bool PianoSound::appliesToChannel(int midiChannel)
{
	return true;
}