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
    auto rightMargin = getWidth() * 0.73f;
    auto dialTopMargin = getHeight() * 0.25f;
    auto dialSize = getWidth() * 0.12f;
    auto spaceBetwween = 1.25f;
    
    topMargin = getHeight() * 0.06;
    
    //Header
    headerComponent.setBounds(0, 0, getWidth(), topMargin);
    
    //Settings Page
    setSettingsPageBounds();
    
    //Dials
    rangeDial.setBounds(rightMargin, dialTopMargin, dialSize, dialSize);
    auto space1 = rangeDial.getY() + rangeDial.getHeight() * spaceBetwween;
    
    lowpassDial.setBounds(rightMargin, space1, dialSize, dialSize);
    auto space2 = lowpassDial.getY() + lowpassDial.getHeight() * spaceBetwween;

    trimDial.setBounds(rightMargin, space2, dialSize, dialSize);

    
    // Save plugin size in the tree
    saveWindowSize();
}

void VoxDriveAudioProcessorEditor::setSettingsPageBounds()
{
    auto settingsWidth = getWidth() * 0.5;
    auto settingsHeight = getHeight() * 0.95;
    
    auto settingsPageBounds = juce::Rectangle<float>(settingsWidth, topMargin, settingsWidth, settingsHeight).toNearestInt();
    auto settingsPageOutBounds = juce::Rectangle<float>(getWidth(), topMargin, settingsWidth, settingsHeight).toNearestInt();
    
    headerComponent.getSettingsButtonToggleState() ? settingsPage.setBounds(settingsPageBounds) : settingsPage.setBounds(settingsPageOutBounds);
    
    driveDial.setBounds(getLocalBounds().withSizeKeepingCentre(getWidth() * 0.25, getWidth() * 0.25).withY(getWidth() * 0.18f));
}
