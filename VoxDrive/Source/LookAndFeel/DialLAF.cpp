/*
  ==============================================================================

    DialLAF.cpp
    Created: 19 May 2022 6:53:47pm
    Author:  Landon Viator

  ==============================================================================
*/

#include "DialLAF.h"

CustomDial::CustomDial()
{
    
}

void CustomDial::drawRotarySlider(juce::Graphics &g, int x, int y, int width, int height, float sliderPos, const float rotaryStartAngle, const float rotaryEndAngle, juce::Slider &slider)
{
    float diameter = fmin(width, height) * .7;
    float radius = diameter * 0.5;
    float centerX = x + width * 0.5;
    float centerY = y + height * 0.5;
    float rx = centerX - radius;
    float ry = centerY - radius;
    float angle = rotaryStartAngle + (sliderPos * (rotaryEndAngle - rotaryStartAngle));
                    
    //Dial Area
    juce::Rectangle<float> dialArea (rx, ry, diameter, diameter);
    g.setColour(juce::Colour::fromFloatRGBA(0.392f, 0.584f, 0.929f, 1.0f).darker(1.0f));
    g.fillEllipse(dialArea);
                    
    //Dial Outline
    g.setColour(juce::Colours::black.brighter(0.1f));
    g.drawEllipse(rx, ry, diameter, diameter, 2.0f);
    
    //Dial Tick
    juce::Path dialTick;
    g.setColour(juce::Colours::whitesmoke.darker(0.5));
    dialTick.addRectangle(0, -radius + 6, 3.0f, radius * 0.6);
    g.fillPath(dialTick, juce::AffineTransform::rotation(angle).translated(centerX, centerY));
    
    //Shadow
    shadowProperties.radius = 24;
    shadowProperties.offset = juce::Point<int> (-1, 4);
    shadowProperties.colour = juce::Colours::black.withAlpha(0.5f);
    dialShadow.setShadowProperties (shadowProperties);
    
    slider.setComponentEffect(&dialShadow);
}
