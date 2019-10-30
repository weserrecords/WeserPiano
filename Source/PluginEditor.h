/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

//==============================================================================
/**
*/
class WeserPianoAudioProcessorEditor  : public AudioProcessorEditor,
										public Slider::Listener
{
public:
    WeserPianoAudioProcessorEditor (WeserPianoAudioProcessor&);
    ~WeserPianoAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

	void sliderValueChanged(Slider* slider);

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    WeserPianoAudioProcessor& processor;

	Slider volumeSlider;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WeserPianoAudioProcessorEditor)
};
