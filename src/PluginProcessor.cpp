#include "PluginProcessor.h"
#include "PluginEditor.h"

SimplePluginAudioProcessor::SimplePluginAudioProcessor()
    : AudioProcessor(BusesProperties()
        .withInput("Input", juce::AudioChannelSet::stereo(), true)
        .withOutput("Output", juce::AudioChannelSet::stereo(), true))
{}

void SimplePluginAudioProcessor::prepareToPlay(double, int) {}
void SimplePluginAudioProcessor::releaseResources() {}

void SimplePluginAudioProcessor::processBlock(juce::AudioBuffer<float>& buffer, juce::MidiBuffer&)
{
    for (int channel = 0; channel < getTotalNumOutputChannels(); ++channel)
        buffer.clear(channel, 0, buffer.getNumSamples());
}

juce::AudioProcessorEditor* SimplePluginAudioProcessor::createEditor()
{
    return new SimplePluginAudioProcessorEditor(*this);
}

bool SimplePluginAudioProcessor::hasEditor() const { return true; }
const juce::String SimplePluginAudioProcessor::getName() const { return "SimplePlugin"; }
bool SimplePluginAudioProcessor::acceptsMidi() const { return false; }
bool SimplePluginAudioProcessor::producesMidi() const { return false; }
bool SimplePluginAudioProcessor::isMidiEffect() const { return false; }
double SimplePluginAudioProcessor::getTailLengthSeconds() const { return 0.0; }

int SimplePluginAudioProcessor::getNumPrograms() { return 1; }
int SimplePluginAudioProcessor::getCurrentProgram() { return 0; }
void SimplePluginAudioProcessor::setCurrentProgram(int) {}
const juce::String SimplePluginAudioProcessor::getProgramName(int) { return {}; }
void SimplePluginAudioProcessor::changeProgramName(int, const juce::String&) {}

void SimplePluginAudioProcessor::getStateInformation(juce::MemoryBlock&) {}
void SimplePluginAudioProcessor::setStateInformation(const void*, int) {}