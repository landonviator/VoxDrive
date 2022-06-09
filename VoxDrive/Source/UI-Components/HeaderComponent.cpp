#include <JuceHeader.h>
#include "HeaderComponent.h"

//==============================================================================

HeaderComponent::HeaderComponent(VoxDriveAudioProcessor& p) : audioProcessor(p)
{
    startTimerHz(1);
    setName("Header Page");
    
    addAndMakeVisible(settingsButton);
    settingsButtonProps();
    
    addAndMakeVisible(cpuLabel);
    cpuLabel.setColour(juce::Label::ColourIds::textColourId, juce::Colours::whitesmoke);
    cpuLabel.setColour(juce::Label::ColourIds::backgroundColourId, juce::Colours::transparentBlack);
    cpuLabel.setLookAndFeel(&customLabelLAF);
    
    addAndMakeVisible(cpuTitleLabel);
    cpuTitleLabel.setText("CPU", juce::dontSendNotification);
    cpuTitleLabel.setColour(juce::Label::ColourIds::textColourId, juce::Colours::whitesmoke);
    cpuTitleLabel.setColour(juce::Label::ColourIds::backgroundColourId, juce::Colours::transparentBlack);
    cpuTitleLabel.setJustificationType(juce::Justification::centred);
}

HeaderComponent::~HeaderComponent()
{
    stopTimer();
    cpuLabel.setLookAndFeel(nullptr);
}

void HeaderComponent::paint (juce::Graphics& g)
{
    //Header
    juce::Rectangle<float> headerRect;
    headerRect.setBounds(0.0f, 0.0f, getWidth(), getHeight());
    g.setColour(masterColor == juce::Colours::black ? juce::Colour::fromRGB(21, 21, 21) : masterColor);
    g.fillRect(headerRect);
    
    // Logo layer
    auto headerLogo = juce::ImageCache::getFromMemory(BinaryData::landon5504_png, BinaryData::landon5504_pngSize);
    g.drawImageWithin(headerLogo,
                      getWidth() * -0.22f,
                      getHeight() * 0.2f,
                      getWidth() * 0.6f,
                      getHeight() * 0.65f,
                      juce::RectanglePlacement::centred);

    // Patreon link
    mWebLink.setURL(mWebUrl);
    addAndMakeVisible(mWebLink);
    mWebLink.setBounds(getWidth() * -0.22f, getHeight() * 0.2f, getWidth() * 0.6f, getHeight() * 0.65f);


    g.setColour(juce::Colours::whitesmoke.darker(1.0f).darker(1.0f));
    g.drawLine(0, getHeight(), getWidth(), getHeight(), 2.0f);

    //Version string
    g.setColour(juce::Colours::whitesmoke);
    float x = getWidth() * 0.425f;
    float y = getHeight() * 0.45f;
    float width = getWidth() * 0.15f;
    float height = getHeight() * 0.2f;
    g.setFont(juce::Font ("Helvetica", getWidth() * 0.02f, juce::Font::FontStyleFlags::bold));
    g.drawFittedText("Vox Amp v1.0.1", x, y, width, height, juce::Justification::centred, 1);
}

void HeaderComponent::resized()
{
    auto rightMargin = getWidth() * 0.95;
    auto buttonTopMargin = getHeight() * 0.125f;
    auto buttonWidth = getHeight() * 0.75;
    auto buttonHeight = getHeight() * 0.75;
    auto spaceBetween = 1.7f;

    cpuLabel.setFont(juce::Font ("Helvetica", getHeight() * 0.35f, juce::Font::FontStyleFlags::bold));
    cpuTitleLabel.setFont(juce::Font ("Helvetica", getHeight() * 0.35f, juce::Font::FontStyleFlags::bold));
    settingsButton.setBounds(rightMargin, buttonTopMargin, buttonWidth, buttonHeight);
    cpuLabel.setBounds(settingsButton.getX() - settingsButton.getWidth() * spaceBetween, buttonTopMargin, buttonWidth * 1.5f, buttonHeight);
    cpuTitleLabel.setBounds(cpuLabel.getX() - cpuLabel.getWidth() * spaceBetween * 0.55f, buttonTopMargin, buttonWidth * 1.5f, buttonHeight);
}

bool HeaderComponent::getSettingsButtonToggleState()
{
    return settingsButton.getToggleState();
}

void HeaderComponent::updateBGColor()
{
    //repaint();
    //DBG("updateBGColor");
}
