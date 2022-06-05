#pragma once
#include <JuceHeader.h>
#include "../LookAndFeel/MenuSliderLAF.h"
#include "../LookAndFeel/ToggleButtonLAF.h"
#include "../LookAndFeel/LabelLAF.h"
#include "../LookAndFeel/ColorButtonLAF.h"
#include "../Globals.h"
#include "SettingsComps/MasterColorComp.h"
#include "SettingsComps/DiscordComp.h"
#include "SettingsComps/PatreonComp.h"
#include "SettingsComps/TwitchComp.h"

//==============================================================================

class SettingsPage  : public juce::Component
{
public:
    SettingsPage(VoxDriveAudioProcessor&);
    ~SettingsPage() override;

    void paint (juce::Graphics&) override;
    void resized() override;
private:
    
    VoxDriveAudioProcessor& audioProcessor;
    
    juce::Slider menuSlider1;
    MenuSliderLAF customMenuSlider;
    
    MasterColorComp masterColorComp;
    DiscordComp discordComp;
    PatreonComp patreonComp;
    TwitchComp twitchComp;
    
    LabelLAF customLabelLAF;
    
    float rowheight;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SettingsPage)
};
