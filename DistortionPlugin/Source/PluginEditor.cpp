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
	inputGainLabel.setText(("Input Gain"), dontSendNotification);
	inputGainLabel.setFont(Font("Multicolore", 12, 0));
	inputGainLabel.setColour(Label::textColourId, Colour(255, 255, 255));
	addAndMakeVisible(inputGainLabel);

	// Output Gain
	outputGain.setSliderStyle(Slider::SliderStyle::LinearVertical);
	outputGain.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
	outputGain.addListener(this);
	addAndMakeVisible(outputGain);
	sliderAttachOutputGain.reset(new AudioProcessorValueTreeState::SliderAttachment(audioTree, "OutputGain_ID", outputGain));
	outputGain.setLookAndFeel(&outputGainLookAndFeel);
	outputGainLabel.setText("Volume", dontSendNotification);
	outputGainLabel.setFont(Font("Multicolore", 12, 1));
	outputGainLabel.setColour(Label::textColourId, Colour(242, 242, 242));
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
	cutOffLabel.setFont(Font("Multicolore", 12, 1));
	cutOffLabel.setColour(Label::textColourId, Colour(242, 242, 242));
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
	comboDistortioType.setColour(ComboBox::textColourId, Colour(242, 242, 242));
	//comboDistortioType.setColour(ComboBox::backgroundColourId, Colour(24, 57, 43));
	comboDistortioType.setColour(ComboBox::focusedOutlineColourId, Colour(24, 57, 43));


	//Buttons 
	lpfPosition1.setButtonText("Pre");
	lpfPosition1.setColour(TextButton::textColourOffId, Colour(255, 255, 255));
	lpfPosition1.setColour(TextButton::textColourOnId, Colour(255, 255, 255));
	lpfPosition1.setColour(TextButton::buttonColourId, Colour(59, 59, 59));
	lpfPosition1.setColour(TextButton::buttonOnColourId, Colour(15, 167, 33));
	lpfPosition1.setRadioGroupId(1, dontSendNotification);
	lpfPosition1.setClickingTogglesState(true);
	addAndMakeVisible(lpfPosition1);
	lpfPosition1.addListener(this);

	lpfPosition2.setButtonText("Post");
	lpfPosition2.setColour(TextButton::textColourOffId, Colour(255, 255, 255));
	lpfPosition2.setColour(TextButton::textColourOnId, Colour(255, 255, 255));
	lpfPosition2.setColour(TextButton::buttonColourId, Colour(59, 59, 59));
	lpfPosition2.setColour(TextButton::buttonOnColourId, Colour(15, 167, 33));
	lpfPosition2.setRadioGroupId(1, dontSendNotification);
	lpfPosition2.setClickingTogglesState(true);
	lpfPosition2.setToggleState(true, dontSendNotification);
	addAndMakeVisible(lpfPosition2);
	lpfPosition2.addListener(this);
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
    //g.fillAll (Colour(0,0,0));
	Rectangle<int> area(getWidth(), getHeight());
	ColourGradient gradiente(Colour(32, 32, 32), getWidth()/2 , (getHeight()/3)*1.85 , Colour(0,0,0), getWidth() / 10, getWidth() / 10, true);
	//gradiente.isRadial = true;
	g.setGradientFill(gradiente);
	g.fillRect(area);

	
	//Title
    g.setColour (Colour(242, 242, 242));
    g.setFont (Font("Slope Opera",35.0f,1));
	Rectangle <int> title = getLocalBounds().removeFromTop(getHeight() / 5);
	g.drawText("Distortion", title, Justification::centred, true);




}

void DistortionPluginAudioProcessorEditor::resized()
{
	comboDistortioType.setBounds((getWidth() / 2 - getWidth() / 4) + 5 , 90, getWidth() / 2, getHeight() / 14);
	inputGain.setBounds(80, 87, 6, 220);
	outputGain.setBounds(420,87,6,220);
	toneControlle.setBounds(177,142,150,150);

	inputGainLabel.setBounds(45, 310, 80, 40);
	outputGainLabel.setBounds(395,310,70,40);
	cutOffLabel.setBounds(204,310,100,40);

	lpfPosition1.setBounds(getWidth()/2 - 38, 293 ,40,15);
	lpfPosition2.setBounds(getWidth()/2 +3 , 293, 40, 15);
}


void DistortionPluginAudioProcessorEditor::sliderValueChanged(Slider *slider)
{
	
}


void DistortionPluginAudioProcessorEditor::buttonClicked(Button* button)
{
	
	if (button == &lpfPosition1) {
		processor.checkFilter = 0;
	}
	else if (button == &lpfPosition2) {
		processor.checkFilter = 1;
	}
	
}

void DistortionPluginAudioProcessorEditor::comboBoxChanged(ComboBox *comboBoxThatHasChanged)
{
	if (comboBoxThatHasChanged == &comboDistortioType) {
		processor.distortionType = comboDistortioType.getSelectedId();
	}
}