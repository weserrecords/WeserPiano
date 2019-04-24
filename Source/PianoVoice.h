/*
  ==============================================================================

    PianoVoice.h
    Created: 24 Apr 2019 12:45:50pm
    Author:  Kai

  ==============================================================================
*/

#pragma once

class PianoVoice : public SynthesiserVoice
{
public:
	PianoVoice();

	~PianoVoice();

	bool canPlaySound(SynthesiserSound*);

	void startNote(int midiNoteNumber, float velocity, SynthesiserSound* sound, int currentPitchWheelPosition);

	void stopNote(float velocity, bool allowTailOff);

	bool isVoiceActive();

	void pitchWheelMoved(int newPitchWheelValue);

	void controllerMoved(int controllerNumber, int newControllerValue);

	void aftertouchChanged(int newAftertouchValue);

	void channelPressureChanged(int newChannelPressureValue);

	void renderNextBlock(AudioBuffer<float>& outputBuffer, int startSample, int numSamples);

	void renderNextBlock(AudioBuffer<double>& outputBuffer, int startSample, int numSamples);

	void setCurrentPlaybackSampleRate(double newRate);

	bool isPlayingChannel(int midiChannel);

private:
	double level;
	double frequency;
};