#pragma once

#include <JuceHeader.h>
#include "../LookAndFeel/SettingsButtonLAF.h"
#include "../LookAndFeel/LabelLAF.h"
#include "../PluginProcessor.h"
#include "../Globals.h"

//==============================================================================
class HeaderComponent  : public juce::Component
{
public:
    HeaderComponent(VoxDriveAudioProcessor&);
    ~HeaderComponent() override;

    void paint (juce::Graphics&) override;
    void resized() override;
    
    bool getSettingsButtonToggleState();
    
    void updateBGColor();
    
    void setUIInUse(bool uiIsInUse) { uiInUse = uiIsInUse; };

private:
    
    VoxDriveAudioProcessor& audioProcessor;
    
    SettingsButtonLAF customSettingsButtonLAF;
    
    juce::TextButton settingsButton;
    void settingsButtonProps();

    LabelLAF customLabelLAF;
    
    //Patreon link
    juce::HyperlinkButton mWebLink;
    juce::URL mWebUrl {"https://www.patreon.com/ViatorDSP"};
    
    bool uiInUse = false;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (HeaderComponent)
};
