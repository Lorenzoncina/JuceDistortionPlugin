/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
DistortionPluginAudioProcessorEditor::DistortionPluginAudioProcessorEditor (DistortionPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    
	//setResizable(true, true);
	setSize(600, 400);

	/*auto& params = processor.getParameters();
	AudioParameterFloat* inputGainParameter = (AudioParameterFloat*)params.getUnchecked(0);
	AudioParameterFloat* outputGainParameter = (AudioParameterFloat*)params.getUnchecked(1);
	AudioParameterFloat* toneControlleParameter = (AudioParameterFloat*)params.getUnchecked(2);
	*/

	// Input Gain
	/*inputGain.setRange(inputGainParameter->range.start, inputGainParameter->range.end);
	inputGain.setValue(inputGainParameter->get());*/
	inputGain.setSliderStyle(Slider::SliderStyle::Rotary);
	inputGain.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	inputGain.addListener(this);
	inputGainLabel.setText("Input Gain", dontSendNotification);
	addAndMakeVisible(inputGain);
	addAndMakeVisible(inputGainLabel);
	sliderAttachInputGain = new AudioProcessorValueTreeState::SliderAttachment(processor.audioTree, "InputGain_ID", inputGain);

	// Output Gain
	/*outputGain.setRange(outputGainParameter->range.start, outputGainParameter->range.end);
	outputGain.setValue(outputGainParameter->get());*/
	outputGain.setSliderStyle(Slider::SliderStyle::Rotary);
	outputGain.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	outputGain.addListener(this);
	outputGainLabel.setText("Output Gain", dontSendNotification);
	addAndMakeVisible(outputGain);
	addAndMakeVisible(outputGainLabel);
	sliderAttachOutputGain = new AudioProcessorValueTreeState::SliderAttachment(processor.audioTree, "OutputGain_ID", outputGain);

	// Tone Controlle
	/*toneControlle.setRange(toneControlleParameter->range.start, toneControlleParameter->range.end);
	toneControlle.setValue(toneControlleParameter->get());
	*/
	toneControlle.setSliderStyle(Slider::SliderStyle::Rotary);
	toneControlle.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	toneControlle.addListener(this);
	toneControlleLabel.setText("Tone Controlle", dontSendNotification);
	addAndMakeVisible(toneControlle);
	addAndMakeVisible(toneControlleLabel);
	sliderAttachToneControlle  = new AudioProcessorValueTreeState::SliderAttachment(processor.audioTree, "ToneControlle_ID", toneControlle);

	// Combo menù
	comboDistortioType.addItem("Soft quadratic clipping",1);
	comboDistortioType.addItem("Soft exponential clipping", 2);
	comboDistortioType.addItem("Hard clipping", 3);
	comboLabel.setText("Distortion type", dontSendNotification);
	comboLabel.attachToComponent(&comboDistortioType, true);
	addAndMakeVisible(comboDistortioType);
}

DistortionPluginAudioProcessorEditor::~DistortionPluginAudioProcessorEditor()
{
}

//==============================================================================
void DistortionPluginAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (15.0f);
}

void DistortionPluginAudioProcessorEditor::resized()
{
	Rectangle<int> area = getLocalBounds();
	Rectangle<int> top = area.removeFromTop(getHeight() / 4);
	Rectangle<int> bottom = area.removeFromBottom((getHeight() / 4) * 3);
	Rectangle<int> firstSlider = bottom.removeFromLeft(getWidth() / 3);
	Rectangle<int> secondSlider = bottom.removeFromLeft((getWidth() / 3));
	Rectangle<int> thirdSliedr = bottom.removeFromRight(getWidth() / 3);
	//Rectangle<int> comboRect = top.remove
	inputGain.setBounds(firstSlider);
	inputGainLabel.setBounds(60,310,70,60);
	outputGain.setBounds(secondSlider);
	outputGainLabel.setBounds(260,310,80,60);
	toneControlle.setBounds(thirdSliedr);
	toneControlleLabel.setBounds(460,310,110,60);
	comboDistortioType.setBounds(top);
	comboDistortioType.setBounds(getWidth()/2 - getWidth()/4, 40,getWidth() / 2, getHeight() / 14);
	
}


void DistortionPluginAudioProcessorEditor::sliderValueChanged(Slider *slider)
{
	/*auto& params = processor.getParameters();
	if (slider == &inputGain) {
		AudioParameterFloat* inputGainParameter = (AudioParameterFloat*)params.getUnchecked(0);
		*inputGainParameter = inputGain.getValue();
	}
	else if (slider == &outputGain) {
		AudioParameterFloat* outputGainParameter = (AudioParameterFloat*)params.getUnchecked(1);
		*outputGainParameter = outputGain.getValue();
	}
	else if (slider == &toneControlle) {
		AudioParameterFloat* toneControlleParameter = (AudioParameterFloat*)params.getUnchecked(2);
		*toneControlleParameter = toneControlle.getValue();
	}*/
}