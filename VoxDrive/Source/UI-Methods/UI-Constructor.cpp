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
    
    //Init color
    masterColor = juce::Colour::fromString(audioProcessor.variableTree.getProperty("mastercolor").toString());
    
    addAndMakeVisible(largeDial);
    largeDial.setTooltip("This knob drives the input harder into the exciter circuit, which gives you mid and upper range harmonic distortion.");
    
    tooltipWindow.getLookAndFeel().setColour(juce::TooltipWindow::ColourIds::backgroundColourId, juce::Colour::fromRGB(0, 0, 0));
    tooltipWindow.getLookAndFeel().setColour(juce::TooltipWindow::ColourIds::outlineColourId, juce::Colours::whitesmoke.withAlpha(0.5f));
    tooltipWindow.getLookAndFeel().setColour(juce::TooltipWindow::ColourIds::textColourId, juce::Colours::whitesmoke.withAlpha(0.75f));
    
    addAndMakeVisible(headerComponent);
    
    addAndMakeVisible(settingsPage);
    showToolTip(settingsPage.getShouldUseToolTips());
}
