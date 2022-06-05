/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
VoxDriveAudioProcessorEditor::VoxDriveAudioProcessorEditor (VoxDriveAudioProcessor& p)
: AudioProcessorEditor (&p), audioProcessor (p), headerComponent(audioProcessor)
, settingsPage(audioProcessor)
, driveDial(2, " dB", "Drive", 0.0, 50.0)
, rangeDial(1, " Hz", "Range", 500.0, 20000.0)
, lowpassDial(1, " Hz", "LP", 1000.0, 20000.0)
, trimDial(1, " dB", "Trim", -24.0, 24.0)
, mixFader(129, false, "Mix")
, osButton(true, "HQ")
, phaseButton(true, "Phase")
{
    uiConstructor();
}

VoxDriveAudioProcessorEditor::~VoxDriveAudioProcessorEditor()
{
}

//==============================================================================
void VoxDriveAudioProcessorEditor::paint (juce::Graphics& g)
{
    uiPaint(g);
}

void VoxDriveAudioProcessorEditor::resized()
{
    uiResized();
}

void VoxDriveAudioProcessorEditor::sliderValueChanged(juce::Slider *slider)
{
}

void VoxDriveAudioProcessorEditor::sliderDragStarted(juce::Slider* slider)
{
    headerComponent.setUIInUse(true);
}

void VoxDriveAudioProcessorEditor::sliderDragEnded(juce::Slider*)
{
    headerComponent.setUIInUse(false);
}

void VoxDriveAudioProcessorEditor::mouseEnter(const juce::MouseEvent &event)
{
    //sliders
    for (int i = 0; i < sliders.size(); ++i)
    {
        if (event.eventComponent == sliders[i])
        {
            tooltipContent.setText(sliderLabels[i], juce::dontSendNotification);
        }
    }
    
    //buttons
    for (int i = 0; i < buttons.size(); ++i)
    {
        if (event.eventComponent == buttons[i])
        {
            tooltipContent.setText(buttonLabels[i], juce::dontSendNotification);
        }
    }
}

void VoxDriveAudioProcessorEditor::mouseExit(const juce::MouseEvent &event)
{
    //sliders
    for (int i = 0; i < sliders.size(); ++i)
    {
        if (event.eventComponent == sliders[i])
        {
            tooltipContent.setText("", juce::dontSendNotification);
        }
    }
    
    //buttons
    for (int i = 0; i < buttons.size(); ++i)
    {
        if (event.eventComponent == buttons[i])
        {
            tooltipContent.setText("", juce::dontSendNotification);
        }
    }
}
