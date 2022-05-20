/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "./LookAndFeel/DialLAF.h"

//==============================================================================
/**
*/
class VoxDriveAudioProcessorEditor  : public juce::AudioProcessorEditor
{
public:
    VoxDriveAudioProcessorEditor (VoxDriveAudioProcessor&);
    ~VoxDriveAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    VoxDriveAudioProcessor& audioProcessor;
    
    /** Boiler plate UI stuff */
    void uiConstructor();
    void initWindow();
    void uiPaint(juce::Graphics &g);
    void uiResized();
    void saveWindowSize();
    bool constructorFinished = false;
    
    juce::Slider inputDial;
    juce::Slider cutoffDial;
    juce::Slider mixDial;
    juce::Slider lowpassDial;
    
    juce::Slider fader;
    
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> inputDialAttach;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> cutoffDialAttach;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> mixDialAttach;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> lowpassDialAttach;
    
    CustomDial customDialLAF;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (VoxDriveAudioProcessorEditor)
};
