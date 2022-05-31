#include <JuceHeader.h>
#include "SettingsPage.h"

//==============================================================================

SettingsPage::SettingsPage(VoxDriveAudioProcessor& p) : audioProcessor(p), tooltipSettingsComp(audioProcessor), masterColorComp(audioProcessor)
{
    setName("Settings Page");
    addAndMakeVisible(tooltipSettingsComp);
    addAndMakeVisible(masterColorComp);
    addAndMakeVisible(discordComp);
    addAndMakeVisible(patreonComp);
}

SettingsPage::~SettingsPage()
{
    
}

void SettingsPage::paint (juce::Graphics& g)
{
    //Background
    g.fillAll(juce::Colours::black.withAlpha(0.7f));
    
    //Title Text
    g.setColour(juce::Colours::whitesmoke.withAlpha(0.5f));
    g.setFont(juce::Font ("Helvetica", getHeight() * 0.035, juce::Font::FontStyleFlags::bold));
    g.drawFittedText("Settings", getLocalBounds().withY(getHeight() * 0.02f), juce::Justification::centredTop, 1);
}

void SettingsPage::resized()
{
    rowheight = getHeight() * 0.075;
    
    tooltipSettingsComp.setBounds(0, rowheight, getWidth(), rowheight);
    masterColorComp.setBounds(0, tooltipSettingsComp.getY() + tooltipSettingsComp.getHeight(), getWidth(), rowheight);
    discordComp.setBounds(0, masterColorComp.getY() + masterColorComp.getHeight(), getWidth(), rowheight);
    patreonComp.setBounds(0, discordComp.getY() + discordComp.getHeight(), getWidth(), rowheight);
}

bool SettingsPage::getShouldUseToolTips()
{
    return tooltipSettingsComp.getShouldUseToolTips();
}
