#include "../JuceLibraryCode/JuceHeader.h"
#include "PianoSynth.h"

PianoSynth::PianoSynth()
{
}

void PianoSynth::setup()
{
	clearVoices();

	for (int i = 0; i < 88; i++)
	{
		addVoice(new SamplerVoice());
	}

	clearSounds();

	formatManager.registerBasicFormats();

	for (int i = 21; i <= 108; i++)
	{
		std::string s = std::to_string(i);

		BigInteger note;
		note.setRange(i, 1, true);

		File* ppFile = new File(filePath + "/WeserPiano/ppSounds/pp" + s + ".wav");
		AudioFormatReader* ppReader = formatManager.createReaderFor(*ppFile);
		addSound(new SamplerSound("pp" + s, *ppReader, note, i, 0, 0.1, 12));
		delete ppReader;
		delete ppFile;

		File* pFile = new File(filePath + "/WeserPiano/pSounds/p" + s + ".wav");
		AudioFormatReader* pReader = formatManager.createReaderFor(*pFile);
		addSound(new SamplerSound("p" + s, *pReader, note, i, 0, 0.1, 12));
		delete pReader;
		delete pFile;

		File* mpFile = new File(filePath + "/WeserPiano/mpSounds/mp" + s + ".wav");
		AudioFormatReader* mpReader = formatManager.createReaderFor(*mpFile);
		addSound(new SamplerSound("mp" + s, *mpReader, note, i, 0, 0.1, 12));
		delete mpReader;
		delete mpFile;

		File* mfFile = new File(filePath + "/WeserPiano/mfSounds/mf" + s + ".wav");
		AudioFormatReader* mfReader = formatManager.createReaderFor(*mfFile);
		addSound(new SamplerSound("mf" + s, *mfReader, note, i, 0, 0.1, 12));
		delete mfReader;
		delete mfFile;

		File* fFile = new File(filePath + "/WeserPiano/fSounds/f" + s + ".wav");
		AudioFormatReader* fReader = formatManager.createReaderFor(*fFile);
		addSound(new SamplerSound("f" + s, *fReader, note, i, 0, 0.1, 12));
		delete fReader;
		delete fFile;

		File* ffFile = new File(filePath + "/WeserPiano/ffSounds/ff" + s + ".wav");
		AudioFormatReader* ffReader = formatManager.createReaderFor(*ffFile);
		addSound(new SamplerSound("ff" + s, *ffReader, note, i, 0, 0.1, 12));
		delete ffReader;
		delete ffFile;
	}
}

void PianoSynth::noteOn(int midiChannel, int midiNoteNumber, float velocity)
{
	const ScopedLock sl(lock);

	std::string midiNoteString = std::to_string(midiNoteNumber);

	String s = "mp" + midiNoteString;

	if (velocity <= 0.166)
	{
		s = "pp" + midiNoteString;
	}
	
	if (velocity <= 0.333 && velocity > 0.166)
	{
		s = "p" + midiNoteString;
	}
	
	if (velocity <= 0.5 && velocity > 0.333)
	{
		s = "mp" + midiNoteString;
	}
	
	if (velocity <= 0.666 && velocity > 0.5)
	{
		s = "mf" + midiNoteString;
	}
	
	if (velocity <= 0.833 && velocity > 0.666)
	{
		s = "f" + midiNoteString;
	}
	
	if (velocity <= 1 && velocity > 0.833)
	{
		s = "ff" + midiNoteString;
	}

	for (auto* sound : sounds)
	{
		if (dynamic_cast<SamplerSound*>(sound)->getName() == s && sound->appliesToChannel(midiChannel))
		{
			startPianoSound(midiChannel, midiNoteNumber, velocity, sound);
		}
	}
}

void PianoSynth::startPianoSound(int midiChannel, int midiNoteNumber, float velocity, SynthesiserSound* sound)
{
	for (auto* voice : voices)
		if (voice->getCurrentlyPlayingNote() == midiNoteNumber && voice->isPlayingChannel(midiChannel))
			stopVoice(voice, 1.0f, true);

	startVoice(findFreeVoice(sound, midiChannel, midiNoteNumber, true),
		sound, midiChannel, midiNoteNumber, velocity);
}
