/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "PluginProcessor.h"
#include "./UI-Components/HeaderComponent.h"
#include "./UI-Components/SettingsPage.h"
#include "./UI-Components/SettingsComps/ToolTipSettingsComp.h"

//==============================================================================
/**
*/
class VoxDriveAudioProcessorEditor  : public juce::AudioProcessorEditor
, private juce::Timer
{
public:
    VoxDriveAudioProcessorEditor (VoxDriveAudioProcessor&);
    ~VoxDriveAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    
    void timerCallback() override
    {
        showToolTip(settingsPage.getShouldUseToolTips());
    }

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    VoxDriveAudioProcessor& audioProcessor;
    
    /** Boiler plate UI stuff */
    void uiConstructor();
    void initWindow();
    void uiPaint(juce::Graphics &g);
    void uiResized();
    void saveWindowSize();
    bool constructorFinished = false;
    
    float topMargin;
    
    //Header
    HeaderComponent headerComponent;
    
    //Settings Page
    SettingsPage settingsPage;
    void setSettingsPageBounds();
    juce::ComponentAnimator settingsPageAnimator;
    
    juce::TooltipWindow tooltipWindow{nullptr, 500};
    void showToolTip(bool shouldShowTips);
    
    viator_gui::FilmStripKnob driveDial;
    viator_gui::FilmStripKnob rangeDial;
    viator_gui::FilmStripKnob lowpassDial;
    viator_gui::FilmStripKnob trimDial;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (VoxDriveAudioProcessorEditor)
};
