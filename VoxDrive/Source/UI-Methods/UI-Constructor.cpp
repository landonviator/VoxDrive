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
    
    setName("Editor");
    
    //Dials
    addAndMakeVisible(driveDial);
    driveDial.addListener(this);
    driveDial.addMouseListener(this, false);
    driveAttach = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, inputID, driveDial);
    
    addAndMakeVisible(rangeDial);
    rangeDial.setLabelAsInt(true);
    rangeDial.addListener(this);
    rangeDial.addMouseListener(this, false);
    rangeAttach = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, cutoffID, rangeDial);
    
    addAndMakeVisible(lowpassDial);
    lowpassDial.setLabelAsInt(true);
    lowpassDial.addListener(this);
    lowpassDial.addMouseListener(this, false);
    lowpassAttach = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, lowpassID, lowpassDial);
    
    addAndMakeVisible(trimDial);
    trimDial.addListener(this);
    trimDial.addMouseListener(this, false);
    trimAttach = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, trimID, trimDial);
    
    addAndMakeVisible(mixFader);
    mixFader.addListener(this);
    mixFader.addMouseListener(this, false);
    mixAttach = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, mixID, mixFader);
    
    addAndMakeVisible(osButton);
    osButton.addMouseListener(this, false);
    hqAttach = std::make_unique<juce::AudioProcessorValueTreeState::ButtonAttachment>(audioProcessor.treeState, hqID, osButton);
    
    addAndMakeVisible(phaseButton);
    phaseButton.addMouseListener(this, false);
    phaseAttach = std::make_unique<juce::AudioProcessorValueTreeState::ButtonAttachment>(audioProcessor.treeState, phaseID, phaseButton);
    
    addAndMakeVisible(headerComponent);
    addAndMakeVisible(settingsPage);
    
    addAndMakeVisible(tooltipContent);
    tooltipContent.setColour(0x1000280, juce::Colours::transparentBlack);
    tooltipContent.setColour(0x1000282, juce::Colours::transparentBlack);
    tooltipContent.setColour(juce::Label::ColourIds::textColourId, juce::Colours::whitesmoke.withAlpha(0.5f));
    tooltipContent.setJustificationType(juce::Justification::horizontallyCentred);
    tooltipContent.setFont(juce::Font ("Helvetica", getHeight() * 0.02f, juce::Font::FontStyleFlags::bold));

    
}
