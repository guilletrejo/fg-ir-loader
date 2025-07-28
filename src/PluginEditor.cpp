#include "PluginProcessor.h"
#include "PluginEditor.h"

SimplePluginAudioProcessorEditor::SimplePluginAudioProcessorEditor(SimplePluginAudioProcessor& p)
    : AudioProcessorEditor(&p), processor(p)
{
    setSize(400, 200);
    helloLabel.setText("Hello, JUCE!", juce::dontSendNotification);
    helloLabel.setJustificationType(juce::Justification::centred);
    addAndMakeVisible(helloLabel);
}

void SimplePluginAudioProcessorEditor::paint(juce::Graphics& g)
{
    g.fillAll(juce::Colours::darkgrey);
}

void SimplePluginAudioProcessorEditor::resized()
{
    helloLabel.setBounds(getLocalBounds());
}