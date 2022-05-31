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
, driveDial(2, " dB", "Drive", 0.0, 24.0)
, rangeDial(1, " Hz", "Range", 500.0, 20000.0)
, lowpassDial(1, " Hz", "LP", 1000.0, 20000.0)
, trimDial(1, " dB", "Trim", -24.0, 24.0)
, mixFader(129, false, "Mix")
, osButton(true, "OS")
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

void VoxDriveAudioProcessorEditor::showToolTip(bool shouldShowTips)
{
    tooltipWindow.setEnabled(shouldShowTips);
    tooltipWindow.setVisible(shouldShowTips);
}
