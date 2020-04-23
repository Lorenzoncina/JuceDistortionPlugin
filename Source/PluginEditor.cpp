/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
Distortion_tryAudioProcessorEditor::Distortion_tryAudioProcessorEditor (Distortion_tryAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    
    addAndMakeVisible(driveKnob = new Slider("Drive"));
    driveKnob->setSliderStyle(Slider::Rotary);
    driveKnob->setTextBoxStyle(Slider::NoTextBox, false, 100, 100);
    
    addAndMakeVisible(rangeKnob = new Slider("Range"));
    rangeKnob->setSliderStyle(Slider::Rotary);
    rangeKnob->setTextBoxStyle(Slider::NoTextBox, false, 100, 100);
    
    addAndMakeVisible(blendKnob = new Slider("Blend"));
    blendKnob->setSliderStyle(Slider::Rotary);
    blendKnob->setTextBoxStyle(Slider::NoTextBox, false, 100, 100);
    
    addAndMakeVisible(volumeknob = new Slider("Volume"));
    volumeknob->setSliderStyle(Slider::Rotary);
    volumeknob->setTextBoxStyle(Slider::NoTextBox, false, 100, 100);
    
    driveAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(),"drive", *driveKnob);
    rangeAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(),"range", *rangeKnob);
    blendAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(),"blend", *blendKnob);
    volumeAttachment = new AudioProcessorValueTreeState::SliderAttachment(p.getState(),"volume", *volumeknob);
    
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (500, 200);
}

Distortion_tryAudioProcessorEditor::~Distortion_tryAudioProcessorEditor()
{
}

//==============================================================================
void Distortion_tryAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (15.0f);
    //g.drawFittedText ("Hello World!", getLocalBounds(), Justification::centred, 1);

    g.drawText("drive", ((getWidth()/5)*1)-(100/2),(getHeight()/2)+5, 100, 100, Justification::centred, false);
    g.drawText("Range", ((getWidth()/5)*2)-(100/2),(getHeight()/2)+5, 100, 100, Justification::centred, false);
    g.drawText("Blend", ((getWidth()/5)*3)-(100/2),(getHeight()/2)+5, 100, 100, Justification::centred, false);
    g.drawText("Volume", ((getWidth()/5)*4)-(100/2),(getHeight()/2)+5, 100, 100, Justification::centred, false);
}

void Distortion_tryAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    
    driveKnob->setBounds(((getWidth()/5)*1)-(100/2),(getHeight()/2)-(100/2),100,100);
    rangeKnob->setBounds(((getWidth()/5)*2)-(100/2),(getHeight()/2)-(100/2),100,100);
    blendKnob->setBounds(((getWidth()/5)*3)-(100/2),(getHeight()/2)-(100/2),100,100);
    volumeknob->setBounds(((getWidth()/5)*4)-(100/2),(getHeight()/2)-(100/2),100,100);
}
