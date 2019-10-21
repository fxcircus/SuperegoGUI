/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SuperegoGuiAudioProcessorEditor::SuperegoGuiAudioProcessorEditor (SuperegoGuiAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (620, 250);

	//Roy - slider attach for parameter automation:
	speedAttach = new AudioProcessorValueTreeState::SliderAttachment(processor.speedMod, "speed", speed);
	glissAttach = new AudioProcessorValueTreeState::SliderAttachment(processor.glissMod, "gliss", gliss);
	dryAttach = new AudioProcessorValueTreeState::SliderAttachment(processor.dryMod, "dry", dry);
	effectAttach = new AudioProcessorValueTreeState::SliderAttachment(processor.effectMod, "effect", effect);
	
	//Roy - Set Slider&Button Attributes
	addAndMakeVisible(speed);
	speed.setLookAndFeel(&ehxDial);
	speed.setSliderStyle(Slider::Rotary);
	speed.setTextBoxStyle(Slider::TextBoxBelow, false, 0,0);


	addAndMakeVisible(gliss);
	gliss.setLookAndFeel(&ehxDial);
	gliss.setSliderStyle(Slider::Rotary);
	gliss.setTextBoxStyle(Slider::TextBoxBelow, false, 0, 0);

	addAndMakeVisible(dry);
	dry.setLookAndFeel(&ehxDial);
	dry.setSliderStyle(Slider::Rotary);
	dry.setTextBoxStyle(Slider::TextBoxBelow, false, 0, 0);

	addAndMakeVisible(effect);
	effect.setLookAndFeel(&ehxDial);
	effect.setSliderStyle(Slider::Rotary);
	effect.setTextBoxStyle(Slider::TextBoxBelow, false, 0, 0);
	
	addAndMakeVisible(bypass);
	bypass.setButtonText("BYPASS");
	bypass.setToggleState(true, true);
	
}

SuperegoGuiAudioProcessorEditor::~SuperegoGuiAudioProcessorEditor()
{
}

//==============================================================================
void SuperegoGuiAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (Colours::azure);
    g.setColour (Colours::darkslategrey);
	g.setFont(Font("Arial", 15, Font::bold));
	//g.setOpacity(0.8);
    g.drawText ("SPEED", collumOne+textPos,rowOne,100,30, Justification::topLeft, true);
	g.drawText("GLISS", collumTwo + textPos, rowOne, 100, 30, Justification::topLeft, true);
	g.drawText("DRY", collumThree + textPos + 10, rowOne, 100, 30, Justification::topLeft, true);
	g.drawText("EFFECT", collumFour + textPos, rowOne, 100, 30, Justification::topLeft, true);

}

void SuperegoGuiAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
	
	//Roy - Set Size for GUI components

	speed.setBounds(collumOne, rowTwo, dialSize, dialSize);
	gliss.setBounds(collumTwo, rowTwo, dialSize, dialSize);
	dry.setBounds(collumThree, rowTwo, dialSize, dialSize);
	effect.setBounds(collumFour, rowTwo, dialSize, dialSize);

	bypass.setBounds(0, rowThree, getWidth(), buttonHight);
}
