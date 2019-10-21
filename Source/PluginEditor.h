/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

//Roy - create costum dial class
class ehxDial : public LookAndFeel_V4
{
public:
	ehxDial()
	{
		setColour(Slider::thumbColourId, Colours::white);
	}

	void drawRotarySlider(Graphics& g, int x, int y, int width, int height, float sliderPos,
		const float rotaryStartAngle, const float rotaryEndAngle, Slider&) override
	{
		auto radius = jmin(width / 2, height / 2) - 4.0f;
		auto centreX = x + width * 0.5f;
		auto centreY = y + height * 0.5f;
		auto rx = centreX - radius;
		auto ry = centreY - radius;
		auto rw = radius * 2.0f;
		auto angle = rotaryStartAngle + sliderPos * (rotaryEndAngle - rotaryStartAngle);

		// fill
		g.setColour(Colours::grey);
		g.fillEllipse(rx, ry, rw, rw);

		// outline
		g.setColour(Colours::dimgrey);
		g.drawEllipse(rx, ry, rw, rw, 4.0f);

		Path p;
		auto pointerLength = radius * 0.33f;
		auto pointerThickness = 5.0f;
		p.addRectangle(-pointerThickness * 0.5f, -radius, pointerThickness, pointerLength);
		p.applyTransform(AffineTransform::rotation(angle).translated(centreX, centreY));

		// pointer
		g.setColour(Colours::antiquewhite);
		g.fillPath(p);
	}
	
};

//==============================================================================
/**
*/
class SuperegoGuiAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    SuperegoGuiAudioProcessorEditor (SuperegoGuiAudioProcessor&);
    ~SuperegoGuiAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;

	//Roy - Slider Listeners for parameter automation
	ScopedPointer <AudioProcessorValueTreeState::SliderAttachment> speedAttach;
	ScopedPointer <AudioProcessorValueTreeState::SliderAttachment> glissAttach;
	ScopedPointer <AudioProcessorValueTreeState::SliderAttachment> dryAttach;
	ScopedPointer <AudioProcessorValueTreeState::SliderAttachment> effectAttach;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SuperegoGuiAudioProcessor& processor;

	//Roy - Create GUI Components:
	ehxDial ehxDial;
	Slider speed;
	Slider gliss;
	Slider dry;
	Slider effect;
	TextButton bypass;

	int collumOne = 0;
	int collumTwo = 160;
	int collumThree = 320;
	int collumFour = 480;

	int textPos = 45;

	int rowOne = 10;
	int rowTwo = 25;
	int rowThree = 185;
	
	int dialSize = 140;
	
	int buttonWidth = 80;
	int buttonHight = 40;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SuperegoGuiAudioProcessorEditor)
};

