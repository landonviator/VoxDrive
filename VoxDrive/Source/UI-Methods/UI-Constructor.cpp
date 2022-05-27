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
    
    startTimerHz(30);
    
    //Dials
    addAndMakeVisible(driveDial);
    driveDial.setTooltip("This knob drives the input harder into the exciter circuit, which gives you mid and upper range harmonic distortion.");
    driveAttach = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, inputID, driveDial);
    
    addAndMakeVisible(rangeDial);
    rangeDial.setTooltip("This knob sets the range of frequencies affected by the harmonic distortion. Any frequencies above this range seting will be distorted and anything below will be left unprocessed.");
    rangeDial.setRange(500.0, 20000.0);
    DBG(rangeDial.getValue());
    rangeAttach = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, cutoffID, rangeDial);
    
    addAndMakeVisible(lowpassDial);
    lowpassDial.setTooltip("A high cut filter to reduce harsh high frequencies.");
    lowpassAttach = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, lowpassID, lowpassDial);
    
    addAndMakeVisible(trimDial);
    trimDial.setTooltip("A master output volume control.");
    trimAttach = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, trimID, trimDial);
    
    addAndMakeVisible(mixFader);
    mixFader.onValueChange = [this]()
    {
        DBG(mixFader.getValue());
    };
    
    addAndMakeVisible(osButton);
    addAndMakeVisible(phaseButton);
    
    tooltipWindow.getLookAndFeel().setColour(juce::TooltipWindow::ColourIds::backgroundColourId, juce::Colour::fromRGB(0, 0, 0));
    tooltipWindow.getLookAndFeel().setColour(juce::TooltipWindow::ColourIds::outlineColourId, juce::Colours::whitesmoke.withAlpha(0.5f));
    tooltipWindow.getLookAndFeel().setColour(juce::TooltipWindow::ColourIds::textColourId, juce::Colours::whitesmoke.withAlpha(0.75f));
    
    addAndMakeVisible(headerComponent);
    
    addAndMakeVisible(settingsPage);
    showToolTip(settingsPage.getShouldUseToolTips());
}
