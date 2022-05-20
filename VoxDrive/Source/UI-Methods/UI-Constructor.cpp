/*
  ==============================================================================

    UI-Constructor.cpp
    Created: 24 Oct 2021 1:40:44am
    Author:  Landon Viator

  ==============================================================================
*/

#include "../PluginEditor.h"

void VoxDriveAudioProcessorEditor::uiConstructor()
{
    // Window
    initWindow();
    
    addAndMakeVisible(inputDial);
    inputDial.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    inputDial.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 72, 36);
    inputDial.setRange(0.0, 24.0, 0.01);
    inputDial.setLookAndFeel(&customDialLAF);
    inputDialAttach = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, inputID, inputDial);
    
    addAndMakeVisible(cutoffDial);
    cutoffDial.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    cutoffDial.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 72, 36);
    cutoffDial.setRange(500.0, 20000.0, 1.0);
    cutoffDialAttach = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, cutoffID, cutoffDial);
    
    addAndMakeVisible(mixDial);
    mixDial.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    mixDial.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 72, 36);
    mixDial.setRange(0.0, 100.0, 1.0);
    mixDialAttach = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, mixID, mixDial);
    
    addAndMakeVisible(lowpassDial);
    lowpassDial.setSliderStyle(juce::Slider::SliderStyle::RotaryVerticalDrag);
    lowpassDial.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 72, 36);
    lowpassDial.setRange(1000.0, 20000.0, 1.0);
    lowpassDialAttach = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, lowpassID, lowpassDial);
    
    addAndMakeVisible(fader);
    fader.setTextBoxStyle(juce::Slider::TextBoxLeft, false, 72, 36);
    fader.setRange(0.0, 100.0, 1.0);
}
