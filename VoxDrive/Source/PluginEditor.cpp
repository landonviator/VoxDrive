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
, largeDial(2, " dB", "Drive")
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
