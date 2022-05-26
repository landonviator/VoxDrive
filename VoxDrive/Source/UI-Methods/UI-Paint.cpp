#include "../PluginEditor.h"

void VoxDriveAudioProcessorEditor::uiPaint(juce::Graphics &g)
{
    g.fillAll(juce::Colours::black);
    
    auto scale = 0.85f;
    auto leftMargin = getWidth() * (1.0 - scale) * 0.5;
    auto topMargin = getHeight() * (1.0 - scale * 0.9f) * 0.5;
    
    //Init color
    masterColor = juce::Colour::fromString(audioProcessor.variableTree.getProperty("mastercolor").toString());
    
    // Background
    auto background = juce::ImageCache::getFromMemory(BinaryData::background_png, BinaryData::background_pngSize);
    g.drawImageWithin(background, leftMargin, topMargin, getWidth() * scale, getHeight() * scale, juce::RectanglePlacement::stretchToFit);
    
    driveDial.updateLabelColor(masterColor);
    rangeDial.updateLabelColor(masterColor);
    lowpassDial.updateLabelColor(masterColor);
    trimDial.updateLabelColor(masterColor);
    
    headerComponent.repaint();
}
