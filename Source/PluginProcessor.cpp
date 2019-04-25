/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
WeserPianoAudioProcessor::WeserPianoAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
	pianoSynth.clearVoices();

	pianoSynth.addVoice(new SamplerVoice());

	pianoSynth.clearSounds();

	audioFormatManager.registerBasicFormats();
	File* file = new File("file.wav");
	AudioFormatReader* reader = audioFormatManager.createReaderFor(*file);
	BigInteger allNotes;
	allNotes.setRange(0, 127, true);
	pianoSynth.addSound(new SamplerSound("firstSound", *reader, allNotes, 60, 0.0, 0.0, 10.0));
	delete reader;
	delete file;
}

WeserPianoAudioProcessor::~WeserPianoAudioProcessor()
{
}

//==============================================================================
const String WeserPianoAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool WeserPianoAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool WeserPianoAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool WeserPianoAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double WeserPianoAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int WeserPianoAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int WeserPianoAudioProcessor::getCurrentProgram()
{
    return 0;
}

void WeserPianoAudioProcessor::setCurrentProgram (int index)
{
}

const String WeserPianoAudioProcessor::getProgramName (int index)
{
    return {};
}

void WeserPianoAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void WeserPianoAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
	ignoreUnused(samplesPerBlock);
	lastSampleRate = sampleRate;
	pianoSynth.setCurrentPlaybackSampleRate(lastSampleRate);
}

void WeserPianoAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool WeserPianoAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    if (layouts.getMainOutputChannelSet() != AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void WeserPianoAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
	buffer.clear();

	pianoSynth.renderNextBlock(buffer, midiMessages, 0, buffer.getNumSamples());
}

//==============================================================================
bool WeserPianoAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* WeserPianoAudioProcessor::createEditor()
{
    return new WeserPianoAudioProcessorEditor (*this);
}

//==============================================================================
void WeserPianoAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void WeserPianoAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new WeserPianoAudioProcessor();
}
