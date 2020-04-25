/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
DistortionPluginAudioProcessorEditor::DistortionPluginAudioProcessorEditor (DistortionPluginAudioProcessor& p, AudioProcessorValueTreeState& vts)
    : AudioProcessorEditor (&p), processor (p), audioTree(vts)
{
	//setResizable(true, true);
	setSize(600, 400);

	

	// Input Gain
	inputGain.setSliderStyle(Slider::SliderStyle::Rotary);
	inputGain.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	inputGain.addListener(this);
	inputGainLabel.setText("Input Gain", dontSendNotification);
	addAndMakeVisible(inputGain);
	addAndMakeVisible(inputGainLabel);
	sliderAttachInputGain.reset(new AudioProcessorValueTreeState::SliderAttachment(audioTree, "InputGain_ID", inputGain));

	// Output Gain
	outputGain.setSliderStyle(Slider::SliderStyle::Rotary);
	outputGain.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	outputGain.addListener(this);
	outputGainLabel.setText("Output Gain", dontSendNotification);
	addAndMakeVisible(outputGain);
	addAndMakeVisible(outputGainLabel);
	sliderAttachOutputGain.reset(new AudioProcessorValueTreeState::SliderAttachment(audioTree, "OutputGain_ID", outputGain));

	// Tone Controlle
	toneControlle.setSliderStyle(Slider::SliderStyle::Rotary);
	toneControlle.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	toneControlle.addListener(this);
	toneControlleLabel.setText("Tone Controlle", dontSendNotification);
	addAndMakeVisible(toneControlle);
	addAndMakeVisible(toneControlleLabel);
	sliderAttachToneControlle.reset(new AudioProcessorValueTreeState::SliderAttachment(audioTree, "ToneControlle_ID", toneControlle));

	// Combo menù
	comboDistortioType.addItem("Hard clipping", 1);
	comboDistortioType.addItem("Soft clipping", 2);
	comboDistortioType.addItem("Exponential", 3);
	comboDistortioType.addItem("Full-wave rectifier", 4);
	comboDistortioType.addItem("Half-wave rectifier", 5);
	comboLabel.setText("Distortion type", dontSendNotification);
	comboLabel.attachToComponent(&comboDistortioType, true);
	comboDistortioType.addListener(this);
	addAndMakeVisible(comboDistortioType);
}

DistortionPluginAudioProcessorEditor::~DistortionPluginAudioProcessorEditor()
{
	//distruggere i puntatori 
	sliderAttachInputGain.reset();
	sliderAttachOutputGain.reset();
	sliderAttachToneControlle.reset();
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
	
}

void DistortionPluginAudioProcessorEditor::comboBoxChanged(ComboBox *comboBoxThatHasChanged)
{
	if (comboBoxThatHasChanged == &comboDistortioType) {
		processor.distortionType = comboDistortioType.getSelectedId();
	}
}