/*
  ==============================================================================

    PianoSynth.cpp
    Created: 28 Apr 2019 4:12:06pm
    Author:  Kai

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "PianoSynth.h"

PianoSynth::PianoSynth()
{
	setup();
}

void PianoSynth::setup()
{
	clearVoices();

	for (int i = 0; i < 10; i++)
	{
		addVoice(new SamplerVoice());
	}

	clearSounds();

	formatManager.registerBasicFormats();
	File* file = new File("ppSounds/pp21.wav");
	AudioFormatReader* reader = formatManager.createReaderFor(*file);
	BigInteger note_21;
	note_21.setRange(21, 1, true);
	addSound(new SamplerSound("firstSound", *reader, note_21, 21, 0, 0, 12));

	delete reader;
	delete file;
}
