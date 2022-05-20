/*
  ==============================================================================

    UI-Resized.cpp
    Created: 24 Oct 2021 1:41:10am
    Author:  Landon Viator

  ==============================================================================
*/

#include "../PluginEditor.h"

void VoxDriveAudioProcessorEditor::uiResized()
{
    auto leftMargin = getWidth() * 0.1;
    auto topMargin = getHeight() * 0.25;
    auto dialSize = getWidth() * 0.2;
    auto faderWidth = dialSize;
    auto faderHeight = getHeight() * 0.2;
    auto spaceBetween = 1.25;
    
    inputDial.setBounds(leftMargin, topMargin, dialSize, dialSize);
    cutoffDial.setBounds(inputDial.getX() + inputDial.getWidth(), topMargin, dialSize, dialSize);
    mixDial.setBounds(cutoffDial.getX() + cutoffDial.getWidth(), topMargin, dialSize, dialSize);
    lowpassDial.setBounds(mixDial.getX() + mixDial.getWidth(), topMargin, dialSize, dialSize);
    
    fader.setBounds(inputDial.getX(), inputDial.getY() + inputDial.getHeight() * spaceBetween, faderWidth, faderHeight);
    
    // Save plugin size in the tree
    saveWindowSize();
}
