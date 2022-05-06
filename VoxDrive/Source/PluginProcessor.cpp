/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
VoxDriveAudioProcessor::VoxDriveAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       )
, treeState(*this, nullptr, "PARAMETERS", createParameterLayout())
#endif
{
    treeState.addParameterListener(inputID, this);
    treeState.addParameterListener(cutoffID, this);
    treeState.addParameterListener(mixID, this);
    treeState.addParameterListener(lowpassID, this);
}

VoxDriveAudioProcessor::~VoxDriveAudioProcessor()
{
    treeState.removeParameterListener(inputID, this);
    treeState.removeParameterListener(cutoffID, this);
    treeState.removeParameterListener(mixID, this);
    treeState.removeParameterListener(lowpassID, this);
}

juce::AudioProcessorValueTreeState::ParameterLayout VoxDriveAudioProcessor::createParameterLayout()
{
    std::vector <std::unique_ptr<juce::RangedAudioParameter>> params;
        
    auto pInput = std::make_unique<juce::AudioParameterFloat>(inputID, inputName, -24.0f, 24.0f, 0.0f);
    auto pCutoff = std::make_unique<juce::AudioParameterFloat>(cutoffID, cutoffName, juce::NormalisableRange<float>(500.0f, 20000.0f, 1.0f, 0.3), 500.0f);
    auto pMix = std::make_unique<juce::AudioParameterInt>(mixID, mixName, 0, 100, 100);
    auto pLowpass = std::make_unique<juce::AudioParameterFloat>(lowpassID, lowpassName, juce::NormalisableRange<float>(20.0f, 20000.0f, 1.0f, 0.2), 0.0f);
    
    params.push_back(std::move(pInput));
    params.push_back(std::move(pCutoff));
    params.push_back(std::move(pMix));
    params.push_back(std::move(pLowpass));
    
    return { params.begin(), params.end() };
}

void VoxDriveAudioProcessor::parameterChanged(const juce::String &parameterID, float newValue)
{
    updateParameters();
}

void VoxDriveAudioProcessor::updateParameters()
{
    voxDistortionModule.setDrive(treeState.getRawParameterValue(inputID)->load());
    voxDistortionModule.setCutoff(treeState.getRawParameterValue(cutoffID)->load());
    voxDistortionModule.setMix(treeState.getRawParameterValue(mixID)->load());
}

//==============================================================================
const juce::String VoxDriveAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool VoxDriveAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool VoxDriveAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool VoxDriveAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double VoxDriveAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int VoxDriveAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int VoxDriveAudioProcessor::getCurrentProgram()
{
    return 0;
}

void VoxDriveAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String VoxDriveAudioProcessor::getProgramName (int index)
{
    return {};
}

void VoxDriveAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void VoxDriveAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Initialize spec for dsp modules
    spec.maximumBlockSize = samplesPerBlock;
    spec.sampleRate = sampleRate;
    spec.numChannels = getTotalNumOutputChannels();
    
    voxDistortionModule.prepare(spec);
    updateParameters();
}

void VoxDriveAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool VoxDriveAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
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

void VoxDriveAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels  = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    juce::dsp::AudioBlock<float> audioBlock {buffer};
    
    voxDistortionModule.process(juce::dsp::ProcessContextReplacing<float>(audioBlock));
}

//==============================================================================
bool VoxDriveAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* VoxDriveAudioProcessor::createEditor()
{
    //return new VoxDriveAudioProcessorEditor (*this);
    return new juce::GenericAudioProcessorEditor (*this);
}

//==============================================================================
void VoxDriveAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void VoxDriveAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new VoxDriveAudioProcessor();
}
