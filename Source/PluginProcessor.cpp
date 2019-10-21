/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SuperegoGuiAudioProcessor::SuperegoGuiAudioProcessor()

#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", AudioChannelSet::stereo(), true)
                     #endif
                       ),
					//Roy - add Parameters to Automate
					speedMod(*this, nullptr),
					glissMod(*this,nullptr),
					dryMod(*this, nullptr),
					effectMod(*this, nullptr)
	
#endif
{
	//Roy - add Parameters to Automate
	NormalisableRange<float> modRange(0.0f, 1.0f);
	speedMod.createAndAddParameter("speed", "Speed", "Speed", modRange, 0.0f, nullptr, nullptr);
	glissMod.createAndAddParameter("gliss", "Gliss", "Gliss", modRange, 0.0f, nullptr, nullptr);
	dryMod.createAndAddParameter("dry", "Dry", "Dry", modRange, 0.0f, nullptr, nullptr);
	effectMod.createAndAddParameter("effect", "Effect", "Effect", modRange, 0.0f, nullptr, nullptr);

}

SuperegoGuiAudioProcessor::~SuperegoGuiAudioProcessor()
{

}

//==============================================================================
const String SuperegoGuiAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool SuperegoGuiAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool SuperegoGuiAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool SuperegoGuiAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double SuperegoGuiAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int SuperegoGuiAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int SuperegoGuiAudioProcessor::getCurrentProgram()
{
    return 0;
}

void SuperegoGuiAudioProcessor::setCurrentProgram (int index)
{
}

const String SuperegoGuiAudioProcessor::getProgramName (int index)
{
    return {};
}

void SuperegoGuiAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void SuperegoGuiAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
	

}

void SuperegoGuiAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool SuperegoGuiAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
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

void SuperegoGuiAudioProcessor::processBlock (AudioBuffer<float>& buffer, MidiBuffer& midiMessages)
{
    ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // This is here to avoid people getting screaming feedback
    // when they first compile a plugin, but obviously you don't need to keep
    // this code if your algorithm always overwrites all the output channels.
    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear (i, 0, buffer.getNumSamples());

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    // Make sure to reset the state if your inner loop is processing
    // the samples and the outer loop is handling the channels.
    // Alternatively, you can process the samples with the channels
    // interleaved by keeping the same state.
	
	//Roy:
	//addParameter(speed = new AudioParameterFloat("speed", "Speed", 0.0f, 1.0f, 0.0f));


    for (int channel = 0; channel < totalNumInputChannels; ++channel)
    {
        auto* channelData = buffer.getWritePointer (channel);

        // ..do something to the data...
    }
}

//==============================================================================
bool SuperegoGuiAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* SuperegoGuiAudioProcessor::createEditor()
{
    return new SuperegoGuiAudioProcessorEditor (*this);
}

//==============================================================================
void SuperegoGuiAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void SuperegoGuiAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new SuperegoGuiAudioProcessor();
}
