#pragma once

#include <juce_audio_processors/juce_audio_processors.h>

class SimplePluginAudioProcessor;

class SimplePluginAudioProcessorEditor : public juce::AudioProcessorEditor
{
public:
    explicit SimplePluginAudioProcessorEditor(SimplePluginAudioProcessor&);
    ~SimplePluginAudioProcessorEditor() override = default;

    void paint(juce::Graphics&) override;
    void resized() override;

private:
    SimplePluginAudioProcessor& processor;
    juce::Label helloLabel;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(SimplePluginAudioProcessorEditor)
};