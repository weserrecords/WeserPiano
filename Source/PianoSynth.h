# pragma once

class PianoSynth : public Synthesiser
{
public:
	PianoSynth();

	void setup();

	void noteOn(int midiChannel, int midiNoteNumber, float velocity);

private:
	AudioFormatManager formatManager;

	void startPianoSound(int midiChannel, int midiNoteNumber, float velocity, SynthesiserSound* sound);

	String filePath = File::getCurrentWorkingDirectory().getFullPathName();
};