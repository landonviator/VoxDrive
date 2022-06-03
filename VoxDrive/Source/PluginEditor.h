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
class VoxDriveAudioProcessorEditor  : public juce::AudioProcessorEditor, public juce::Slider::Listener
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
    
    void sliderValueChanged(juce::Slider* slider) override;
    void sliderDragStarted (juce::Slider*) override;
    void sliderDragEnded (juce::Slider*) override;

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
    
    viator_gui::FilmStripFader mixFader;
    
    viator_gui::ToggleButton osButton;
    viator_gui::ToggleButton phaseButton;
    
    bool imageAlphaChanged = false;
    
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> driveAttach;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> rangeAttach;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> lowpassAttach;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> trimAttach;
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment> mixAttach;
    
    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> hqAttach;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment> phaseAttach;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (VoxDriveAudioProcessorEditor)
};
