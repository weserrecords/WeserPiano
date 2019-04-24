/*
  ==============================================================================

    PianoVoice.cpp
    Created: 24 Apr 2019 12:46:04pm
    Author:  Kai

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Maximilian/maximilian.h"
#include "PianoVoice.h"
#include "PianoSound.h"

PianoVoice::PianoVoice()
{
}

PianoVoice::~PianoVoice()
{
}

bool PianoVoice::canPlaySound(SynthesiserSound* sound)
{
	return dynamic_cast<PianoSound*>(sound) != nullptr;
}

void PianoVoice::startNote(int midiNoteNumber, float velocity, SynthesiserSound* sound, int currentPitchWheelPosition)
{
	level = velocity;
	frequency = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
}

void PianoVoice::stopNote(float velocity, bool allowTailOff)
{
	level = 0;
}

bool PianoVoice::isVoiceActive()
{
	return true;
}

void PianoVoice::pitchWheelMoved(int newPitchWheelValue)
{
}

void PianoVoice::controllerMoved(int controllerNumber, int newControllerValue)
{
}

void PianoVoice::aftertouchChanged(int newAftertouchValue)
{
}

void PianoVoice::channelPressureChanged(int newChannelPressureValue)
{
}

void PianoVoice::renderNextBlock(AudioBuffer<float>& outputBuffer, int startSample, int numSamples)
{
	for (int sample = 0; sample < numSamples; ++sample)
	{
		double theWave = osc1.sinewave(440) * level;

		for (int channel = 0; channel < outputBuffer.getNumChannels(); ++channel)
		{
			outputBuffer.addSample(channel, startSample, theWave);
		}
		++startSample;
	}
}

void PianoVoice::renderNextBlock(AudioBuffer<double>& outputBuffer, int startSample, int numSamples)
{
}

void PianoVoice::setCurrentPlaybackSampleRate(double newRate)
{
}

bool PianoVoice::isPlayingChannel(int midiChannel)
{
	return true;
}