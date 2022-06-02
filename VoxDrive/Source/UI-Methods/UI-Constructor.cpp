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
    
    startTimerHz(5);
    
    //Dials
    addAndMakeVisible(driveDial);
    driveDial.setTooltip("This knob drives the input harder into the exciter circuit, which gives you mid and upper range harmonic distortion.");
    driveAttach = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, inputID, driveDial);
    
    addAndMakeVisible(rangeDial);
    rangeDial.setTooltip("This knob sets the range of frequencies affected by the harmonic distortion. Any frequencies above this range seting will be distorted and anything below will be left unprocessed.");
    rangeDial.setLabelAsInt(true);
    rangeAttach = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, cutoffID, rangeDial);
    
    addAndMakeVisible(lowpassDial);
    lowpassDial.setTooltip("A high cut filter to reduce harsh high frequencies.");
    lowpassDial.setLabelAsInt(true);
    lowpassAttach = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, lowpassID, lowpassDial);
    
    addAndMakeVisible(trimDial);
    trimDial.setTooltip("A master output volume control.");
    trimAttach = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, trimID, trimDial);
    
    addAndMakeVisible(mixFader);
    mixFader.setTooltip("The Mix fader mixes the uneffected input from the DAW with the effected processing from the plugin. At the center, the signal will be equal parts processed and processed, while the bottom half will have more uneffected input and the top half with more effected processing.");
    mixAttach = std::make_unique<juce::AudioProcessorValueTreeState::SliderAttachment>(audioProcessor.treeState, mixID, mixFader);
    
    addAndMakeVisible(osButton);
    osButton.setTooltip("This turns on oversampling, which raises the quality of the effect and avoids aliasing in the non-linear processing.");
    hqAttach = std::make_unique<juce::AudioProcessorValueTreeState::ButtonAttachment>(audioProcessor.treeState, hqID, osButton);
    
    addAndMakeVisible(phaseButton);
    phaseButton.setTooltip("This flips the phase of your audio.");
    phaseAttach = std::make_unique<juce::AudioProcessorValueTreeState::ButtonAttachment>(audioProcessor.treeState, phaseID, phaseButton);
    
    tooltipWindow.getLookAndFeel().setColour(juce::TooltipWindow::ColourIds::backgroundColourId, juce::Colour::fromRGB(0, 0, 0));
    tooltipWindow.getLookAndFeel().setColour(juce::TooltipWindow::ColourIds::outlineColourId, juce::Colours::whitesmoke.withAlpha(0.5f));
    tooltipWindow.getLookAndFeel().setColour(juce::TooltipWindow::ColourIds::textColourId, juce::Colours::whitesmoke.withAlpha(0.75f));
    
    addAndMakeVisible(headerComponent);
    
    addAndMakeVisible(settingsPage);
    showToolTip(settingsPage.getShouldUseToolTips());
}
