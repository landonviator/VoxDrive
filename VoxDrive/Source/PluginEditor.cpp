/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
VoxDriveAudioProcessorEditor::VoxDriveAudioProcessorEditor (VoxDriveAudioProcessor& p)
    : AudioProcessorEditor (&p), audioProcessor (p)
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
