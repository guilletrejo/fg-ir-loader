cmake_minimum_required(VERSION 3.15)

project(SimplePlugin VERSION 0.1.0)

# Path to your JUCE checkout
set(JUCE_DIR "/path/to/JUCE") # CHANGE THIS

add_subdirectory(${JUCE_DIR} JUCE)

juce_add_plugin(SimplePlugin
    COMPANY_NAME "ExampleCompany"
    IS_SYNTH FALSE
    NEEDS_MIDI_INPUT FALSE
    NEEDS_MIDI_OUTPUT FALSE
    EDITOR_WANTS_KEYBOARD_FOCUS FALSE
    COPY_PLUGIN_AFTER_BUILD TRUE
    PLUGIN_MANUFACTURER_CODE ExCo
    PLUGIN_CODE SimP
    FORMATS VST3 Standalone
    PRODUCT_NAME "SimplePlugin"
)

target_sources(SimplePlugin PRIVATE
    Source/PluginProcessor.cpp
    Source/PluginProcessor.h
    Source/PluginEditor.cpp
    Source/PluginEditor.h
)

target_compile_features(SimplePlugin PRIVATE cxx_std_20)

target_link_libraries(SimplePlugin PRIVATE
    juce::juce_audio_utils
)