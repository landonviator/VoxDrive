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

//==============================================================================
/**
*/
class VoxDriveAudioProcessorEditor  : public juce::AudioProcessorEditor, public juce::Slider::Listener
{
public:
    VoxDriveAudioProcessorEditor (VoxDriveAudioProcessor&);
    ~VoxDriveAudioProcessorEditor() override;

    //==============================================================================
    void paint (juce::Graphics&) override;
    void resized() override;
    
    void sliderValueChanged(juce::Slider* slider) override;
    void sliderDragStarted (juce::Slider* slider) override;
    void sliderDragEnded (juce::Slider*) override;
    
    void mouseEnter(const juce::MouseEvent &event) override;
    void mouseExit(const juce::MouseEvent &event) override;
    
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
    
    viator_gui::Dial driveDial;
    viator_gui::Dial rangeDial;
    viator_gui::Dial lowpassDial;
    viator_gui::Dial trimDial;
    viator_gui::Dial mixFader;
    
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
    
    juce::String driveToolTip =
    {
        "This knob drives the input harder into the exciter circuit, which gives you mid and upper range harmonic distortion. Increasing the drive also increases a hard-coded low shelf."
    };
    
    juce::String rangeToolTip =
    {
        "This knob sets the range of frequencies affected by the harmonic distortion."
    };
    
    juce::String lowpassToolTip =
    {
        "This dial sets the cutoff for a lowpass (high cut) filter."
    };
    
    juce::String trimToolTip =
    {
        "A master output volume control."
    };
    
    juce::String mixToolTip =
    {
        "The Mix fader mixes the uneffected input from the DAW with the effected processing from the plugin."
    };
    
    juce::String hqToolTip =
    {
        "This turns on oversampling, which raises the quality of the effect and avoids aliasing in the non-linear processing."
    };
    
    juce::String phaseToolTip =
    {
        "This flips the phase of your audio."
    };
    
    juce::Rectangle<float> tooltipWindow;
    juce::Label tooltipContent;
    
    std::vector<juce::Slider*> sliders = {&driveDial, &rangeDial, &lowpassDial, &trimDial, &mixFader};
    std::vector<juce::String> sliderLabels = {driveToolTip, rangeToolTip, lowpassToolTip, trimToolTip, mixToolTip};
    
    std::vector<juce::ImageButton*> buttons = {&osButton, &phaseButton};
    std::vector<juce::String> buttonLabels = {hqToolTip, phaseToolTip};

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (VoxDriveAudioProcessorEditor)
};
