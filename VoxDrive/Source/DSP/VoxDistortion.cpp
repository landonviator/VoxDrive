/*
  ==============================================================================

    VoxDistortion.cpp
    Created: 5 May 2022 6:39:45pm
    Author:  Landon Viator

  ==============================================================================
*/

#include "VoxDistortion.h"

template <typename SampleType>
VoxDistortion<SampleType>::VoxDistortion()
{
    
}

template <typename SampleType>
void VoxDistortion<SampleType>::prepare(juce::dsp::ProcessSpec &spec)
{
    mSampleRate = spec.sampleRate;
    reset();
}

template <typename SampleType>
void VoxDistortion<SampleType>::reset() noexcept
{
    if (mSampleRate > 0)
    {
        mDrive.reset(mSampleRate, 0.02);
        mDrive.setTargetValue(0.0);
        setDrive(mDrive.getNextValue());
    }
}

template <typename SampleType>
void VoxDistortion<SampleType>::setDrive(SampleType newDrive)
{
    mDrive.setTargetValue(juce::Decibels::decibelsToGain(newDrive));
}

template class VoxDistortion<float>;
template class VoxDistortion<double>;
