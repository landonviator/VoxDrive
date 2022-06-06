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
    topMargin = getHeight() * 0.06;
    
    //Header
    headerComponent.setBounds(0, 0, getWidth(), topMargin);
    
    //Settings Page
    setSettingsPageBounds();
    
    //Dials
    auto rightMargin = getWidth() * 0.73f;
    auto dialTopMargin = getHeight() * 0.25f;
    auto dialSize = getWidth() * 0.12f;
    auto spaceBetwween = 1.25f;
    
    rangeDial.setBounds(rightMargin, dialTopMargin, dialSize, dialSize);
    auto space1 = rangeDial.getY() + rangeDial.getHeight() * spaceBetwween;
    lowpassDial.setBounds(rightMargin, space1, dialSize, dialSize);
    auto space2 = lowpassDial.getY() + lowpassDial.getHeight() * spaceBetwween;
    trimDial.setBounds(rightMargin, space2, dialSize, dialSize);

    //Mix fader
    auto x = getWidth() * 0.425f;
    auto y = getHeight() * 0.69f;
    dialSize *= 1.25;
    mixFader.setBounds(x, y, dialSize, dialSize);
    
    //Buttons
    auto leftButtonMargin = getWidth() * 0.095f;
    auto topButtonMargin = getHeight() * 0.85f;
    auto buttonWidth = getWidth() * 0.1;
    auto buttonHeight = getHeight() * 0.08f;
    auto buttonSpaceBetween = 1.25f;
    
    osButton.setBounds(leftButtonMargin, topButtonMargin, buttonWidth, buttonHeight);
    phaseButton.setBounds(osButton.getX() + osButton.getWidth() * buttonSpaceBetween, topButtonMargin, buttonWidth, buttonHeight);
    
    auto toolHeight = getHeight() * 0.06f;
    tooltipContent.setFont(juce::Font ("Helvetica", getHeight() * 0.02f, juce::Font::FontStyleFlags::bold));
    tooltipContent.setBounds(0, topMargin, getWidth(), toolHeight);
    
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
