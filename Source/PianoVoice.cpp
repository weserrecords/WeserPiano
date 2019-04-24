/*
  ==============================================================================

    PianoVoice.cpp
    Created: 24 Apr 2019 12:46:04pm
    Author:  Kai

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "PianoVoice.h"

PianoVoice::PianoVoice()
{
}

PianoVoice::~PianoVoice()
{
}

bool canPlaySound(SynthesiserSound*)
{
	return true;
}

void startNote(int midiNoteNumber, float velocity, SynthesiserSound* sound, int currentPitchWheelPosition)
{
}

void stopNote(float velocity, bool allowTailOff)
{
}

bool isVoiceActive()
{
	return true;
}

void pitchWheelMoved(int newPitchWheelValue)
{
}

void controllerMoved(int controllerNumber, int newControllerValue)
{
}

void aftertouchChanged(int newAftertouchValue)
{
}

void channelPressureChanged(int newChannelPressureValue)
{
}

void renderNextBlock(AudioBuffer< float >& outputBuffer, int startSample, int numSamples)
{
}

void renderNextBlock(AudioBuffer< double >& outputBuffer, int startSample, int numSamples)
{
}

void setCurrentPlaybackSampleRate(double newRate)
{
}

bool isPlayingChannel(int midiChannel)
{
}