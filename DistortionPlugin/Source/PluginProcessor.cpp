/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
DistortionPluginAudioProcessor::DistortionPluginAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       ),
					audioTree(*this, nullptr, Identifier("PARAMETERS"),
						{ std::make_unique<AudioParameterFloat>("InputGain_ID","InputGain",NormalisableRange<float>(1.0, 10.0,0.1),1.0),
						  std::make_unique<AudioParameterFloat>("OutputGain_ID","OutputGain",NormalisableRange<float>(0.0, 1.0,0.1),0),
						  std::make_unique<AudioParameterFloat>("ToneControlle_ID","ToneControlle",NormalisableRange<float>(5000, 150000,10),0)
						})
#endif
{
	/*
	NormalisableRange <float> inputGainNormRange(1.0, 10.0);
	NormalisableRange <float> outputGainNormRange(0.0, 1.0);
	NormalisableRange <float> toneControlleNormRange(5000, 15000);
	*/
	//Deprecated
	/*audioTree.createAndAddParameter("InputGain_ID", "InputGain", "Input Gain", inputGainNormRange,1.0, nullptr,nullptr);
	audioTree.createAndAddParameter("OutputGain_ID","OutputGain" ,"Output Gain", outputGainNormRange, 1.0, nullptr, nullptr);
	audioTree.createAndAddParameter("ToneControlle_ID", "ToneControlle", "Tone Controlle", toneControlleNormRange, 5000, nullptr,nullptr);
	*/
	
	audioTree.addParameterListener("InputGain_ID", this);
	audioTree.addParameterListener("OutputGain_ID", this);
	audioTree.addParameterListener("ToneControlle_ID", this);


	distortionType = 1;
}

DistortionPluginAudioProcessor::~DistortionPluginAudioProcessor()
{
}

//==============================================================================
const String DistortionPluginAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool DistortionPluginAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool DistortionPluginAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool DistortionPluginAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double DistortionPluginAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int DistortionPluginAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int DistortionPluginAudioProcessor::getCurrentProgram()
{
    return 0;
}

void DistortionPluginAudioProcessor::setCurrentProgram (int index)
{
}

const String DistortionPluginAudioProcessor::getProgramName (int index)
{
    return {};
}

void DistortionPluginAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void DistortionPluginAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void DistortionPluginAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool DistortionPluginAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
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


void DistortionPluginAudioProcessor::parameterChanged(const String &parameterID, float newValue)
{
	//Parameters update  when sliders moved
	if (parameterID=="InputGain_ID") {
		inputGainValue = newValue;
	}
	else if (parameterID =="OutputGain_ID") {
		outputGainValue = newValue;
	}
	else if (parameterID =="ToneControlle_ID") {
		toneControlleValue = newValue;
	}


}

void DistortionPluginAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

	int intDistortionType = 0;
	for (int channel = 0; channel < buffer.getNumChannels(); channel++) {
		auto* channelData = buffer.getWritePointer(channel);
		for (int sample = 0; sample < buffer.getNumSamples(); sample++) {
			//Input Gain
			//float* gainInput = audioTree.getRawParameterValue("InputGain_ID");
			const float in = channelData[sample] * inputGainValue;

			//Distortion Type
			float out;


			if (distortionType== 1) {
				// Simple hard clipping
				float threshold = 1.0f;
				if (in > threshold)
					out = threshold;
				else if (in < -threshold)
					out = -threshold;
				else
					out = in;
			}
			else if (distortionType == 2) {
				// Soft clipping based on quadratic function
				float threshold1 = 1.0f / 3.0f;
				float threshold2 = 2.0f / 3.0f;
				if (in > threshold2)
					out = 1.0f;
				else if (in > threshold1)
					out = (3.0f - (2.0f - 3.0f*in) *
					(2.0f - 3.0f*in)) / 3.0f;
				else if (in < -threshold2)
					out = -1.0f;
				else if (in < -threshold1)
					out = -(3.0f - (2.0f + 3.0f*in) *
					(2.0f + 3.0f*in)) / 3.0f;
				else
					out = 2.0f* in;
			}
			else if (distortionType == 3)
			{
				// Soft clipping based on exponential function
				if (in > 0)
					out = 1.0f - expf(-in);
				else
					out = -1.0f + expf(in);
			}
			else if (distortionType == 4) {
				// Full-wave rectifier (absolute value)
				out = fabsf(in);
			}
			else if (distortionType == 5) {
				// Half-wave rectifier
				if (in > 0)
					out = in;
				else
					out = 0;
			}

			//Tone Controlle

			//Output Gain
			//float* value = audioTree.getRawParameterValue("OutputGain_ID");
			parameterOutputGainSmoothed = parameterOutputGainSmoothed - 0.004*(parameterOutputGainSmoothed - outputGainValue);
			channelData[sample] = out * parameterOutputGainSmoothed;
		}
	}


}

//==============================================================================
bool DistortionPluginAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* DistortionPluginAudioProcessor::createEditor()
{
    return new DistortionPluginAudioProcessorEditor (*this, audioTree);
}

//==============================================================================
void DistortionPluginAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void DistortionPluginAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new DistortionPluginAudioProcessor();
}


