/*
  ==============================================================================

    This file was auto-generated by the Jucer!

    It contains the basic startup code for a Juce application.

  ==============================================================================
*/

#ifndef __PLUGINPROCESSOR_H_526ED7A9__
#define __PLUGINPROCESSOR_H_526ED7A9__

#include "JuceHeader.h"
#include "FilterGraph.h"


//==============================================================================
/**
    As the name suggest, this class does the actual audio processing.
*/
class JuceDemoHostAudioProcessor  : public AudioProcessor
{
public:
    //==============================================================================
    JuceDemoHostAudioProcessor();
    ~JuceDemoHostAudioProcessor();

    //==============================================================================
    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;
    void processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages) override;

    //==============================================================================
    bool hasEditor() const override                  { return true; }
    AudioProcessorEditor* createEditor() override;

    //==============================================================================
    const String getName() const override            { return JucePlugin_Name; }

    const String getInputChannelName (int channelIndex) const override;
    const String getOutputChannelName (int channelIndex) const override;
    bool isInputChannelStereoPair (int index) const override;
    bool isOutputChannelStereoPair (int index) const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool silenceInProducesSilenceOut() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override                                               { return 0; }
    int getCurrentProgram() override                                            { return 0; }
    void setCurrentProgram (int /*index*/) override                             {}
    const String getProgramName (int /*index*/) override                        { return ""; }
    void changeProgramName (int /*index*/, const String& /*newName*/) override  {}

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

private:
    //==============================================================================
    ScopedPointer<ApplicationProperties> appProperties;
    AudioPluginFormatManager formatManager;
    FilterGraph graph;

    MidiKeyboardState* midiKeyState;
    CriticalSection    midiKeyMutex;

    friend class JuceDemoHostAudioProcessorEditor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (JuceDemoHostAudioProcessor)
};

#endif  // __PLUGINPROCESSOR_H_526ED7A9__
