/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"
#include "SliderLookAndFeel.h"

//==============================================================================
/**
*/
class DistortionPluginAudioProcessorEditor  : public AudioProcessorEditor,
											  public Slider::Listener,
											  public ComboBox::Listener
{
public:
    DistortionPluginAudioProcessorEditor (DistortionPluginAudioProcessor&, AudioProcessorValueTreeState&);
    ~DistortionPluginAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

	void sliderValueChanged(Slider *slider) override;
	void comboBoxChanged(ComboBox *comboBoxThatHasChanged) override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    DistortionPluginAudioProcessor& processor;
	AudioProcessorValueTreeState& audioTree;

	Slider inputGain;
	Label inputGainLabel;

	Slider outputGain;
	Label outputGainLabel;

	Slider toneControlle;
	Label cutOffLabel;
	
	ComboBox comboDistortioType;
	Label comboLabel;

	std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> sliderAttachInputGain;
	std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> sliderAttachOutputGain;
	std::unique_ptr <AudioProcessorValueTreeState::SliderAttachment> sliderAttachToneControlle;

	InputGainLookAndFeel inputGainLookAndFeel;
	OutputGainLookAndFeel outputGainLookAndFeel;
	RotaryLookAndFeel rotaryLookAndFeel;
	comboBoxLookAndFeel comboBoxLookAndFeel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (DistortionPluginAudioProcessorEditor)
};
