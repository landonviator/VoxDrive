#pragma once
#include <JuceHeader.h>
#include "../LookAndFeel/MenuSliderLAF.h"
#include "../LookAndFeel/ToggleButtonLAF.h"
#include "../LookAndFeel/LabelLAF.h"
#include "../LookAndFeel/ColorButtonLAF.h"
#include "../Globals.h"
#include "SettingsComps/ToolTipSettingsComp.h"
#include "SettingsComps/MasterColorComp.h"
#include "SettingsComps/DiscordComp.h"
#include "SettingsComps/PatreonComp.h"

//==============================================================================

class SettingsPage  : public juce::Component
{
public:
    SettingsPage(VoxDriveAudioProcessor&);
    ~SettingsPage() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    bool getShouldUseToolTips();
private:
    
    VoxDriveAudioProcessor& audioProcessor;
    
    juce::Slider menuSlider1;
    MenuSliderLAF customMenuSlider;
    
    ToolTipSettingsComp tooltipSettingsComp;
    MasterColorComp masterColorComp;
    DiscordComp discordComp;
    PatreonComp patreonComp;
    
    LabelLAF customLabelLAF;
    
    float rowheight;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SettingsPage)
};
