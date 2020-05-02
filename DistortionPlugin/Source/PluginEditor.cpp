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
	setSize(500, 350);

	

	// Input Gain
	inputGain.setSliderStyle(Slider::SliderStyle::LinearVertical);
	inputGain.addListener(this);
	inputGain.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	addAndMakeVisible(inputGain);
	sliderAttachInputGain.reset(new AudioProcessorValueTreeState::SliderAttachment(audioTree, "InputGain_ID", inputGain));
	inputGain.setLookAndFeel(&inputGainLookAndFeel);
	inputGainLabel.setText("Input Gain", dontSendNotification);
	inputGainLabel.setFont(Font("Strong Brain", 12, 1));
	inputGainLabel.setColour(Label::textColourId, Colour(255, 6, 119));
	addAndMakeVisible(inputGainLabel);

	// Output Gain
	outputGain.setSliderStyle(Slider::SliderStyle::LinearVertical);
	outputGain.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	outputGain.addListener(this);
	addAndMakeVisible(outputGain);
	sliderAttachOutputGain.reset(new AudioProcessorValueTreeState::SliderAttachment(audioTree, "OutputGain_ID", outputGain));
	outputGain.setLookAndFeel(&outputGainLookAndFeel);
	outputGainLabel.setText("Volume", dontSendNotification);
	outputGainLabel.setFont(Font("Strong Brain", 12.0f, 1));
	outputGainLabel.setColour(Label::textColourId, Colour(255, 6, 119));
	addAndMakeVisible(outputGainLabel);

	// Tone Controlle
	toneControlle.setSliderStyle(Slider::SliderStyle::Rotary);
	toneControlle.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	toneControlle.addListener(this);
	toneControlle.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
	addAndMakeVisible(toneControlle);
	sliderAttachToneControlle.reset(new AudioProcessorValueTreeState::SliderAttachment(audioTree, "ToneControlle_ID", toneControlle));
	toneControlle.setLookAndFeel(&rotaryLookAndFeel);
	cutOffLabel.setText("Tone Controlle", dontSendNotification);
	cutOffLabel.setFont(Font("Strong Brain", 12.0f, 1));
	cutOffLabel.setColour(Label::textColourId, Colour(255, 6, 119));
	addAndMakeVisible(cutOffLabel);
	
	// Combo menù

	comboDistortioType.addItem("Hard clipping", 1);
	comboDistortioType.addItem("Soft clipping", 2);
	comboDistortioType.addItem("Exponential", 3);
	comboDistortioType.addItem("Full-wave rectifier", 4);
	comboDistortioType.addItem("Half-wave rectifier", 5);
	comboDistortioType.setSelectedId(1, dontSendNotification);
	comboDistortioType.setLookAndFeel(&comboBoxLookAndFeel);
	comboDistortioType.addListener(this);
	addAndMakeVisible(comboDistortioType);
	comboDistortioType.setColour(ComboBox::textColourId, Colour(255, 6, 119));
	comboDistortioType.setColour(ComboBox::arrowColourId, Colour(255, 6, 119));
}

DistortionPluginAudioProcessorEditor::~DistortionPluginAudioProcessorEditor()
{
	//distruggere i puntatori 
	sliderAttachInputGain.reset();
	sliderAttachOutputGain.reset();
	sliderAttachToneControlle.reset();

	inputGain.setLookAndFeel(nullptr);
	outputGain.setLookAndFeel(nullptr);
	toneControlle.setLookAndFeel(nullptr);
	comboDistortioType.setLookAndFeel(nullptr);
}

//==============================================================================
void DistortionPluginAudioProcessorEditor::paint (Graphics& g)
{
    // Background
    g.fillAll (Colour(0, 81, 255));
	
	//Title
    g.setColour (Colour(255, 6, 119));
    g.setFont (Font("Strong Brain",35.0f,1));
	Rectangle <int> title = getLocalBounds().removeFromTop(getHeight() / 5);
	g.drawText("Distortion \'80", title, Justification::centred, true);




}

void DistortionPluginAudioProcessorEditor::resized()
{
	comboDistortioType.setBounds((getWidth() / 2 - getWidth() / 4) + 5 , 120, getWidth() / 2, getHeight() / 14);
	inputGain.setBounds(80, 87, 6, 220);
	outputGain.setBounds(420,87,6,220);
	toneControlle.setBounds(177,172,150,150);

	inputGainLabel.setBounds(45, 310, 80, 40);
	outputGainLabel.setBounds(395,310,60,40);
	cutOffLabel.setBounds(213,310,80,40);

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