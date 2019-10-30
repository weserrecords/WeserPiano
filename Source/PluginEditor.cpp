/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "PianoSynth.h"
#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
WeserPianoAudioProcessorEditor::WeserPianoAudioProcessorEditor (WeserPianoAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 200);

	volumeSlider.setSliderStyle(Slider::LinearHorizontal);
	volumeSlider.setRange(0.0f, 1.0f);
	volumeSlider.setTextBoxStyle(Slider::TextBoxRight, true, 90, 0);
	volumeSlider.setPopupDisplayEnabled(true, false, this);
	volumeSlider.setValue(1.0f);
	volumeSlider.addListener(this);

	addAndMakeVisible(&volumeSlider);
}

WeserPianoAudioProcessorEditor::~WeserPianoAudioProcessorEditor()
{
}

//==============================================================================
void WeserPianoAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (15.0f);
    g.drawFittedText ("WeserPiano by weserrecords (2019)", getLocalBounds(), Justification::topLeft, 1);
}

void WeserPianoAudioProcessorEditor::resized()
{
	volumeSlider.setBounds(40, 100, 220, 20);
}

void WeserPianoAudioProcessorEditor::sliderValueChanged(Slider* slider)
{
	processor.volume = volumeSlider.getValue();
}
