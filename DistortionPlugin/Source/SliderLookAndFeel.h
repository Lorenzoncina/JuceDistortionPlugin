/*
  ==============================================================================

    NewLookAndFeel.h
    Created: 2 May 2020 1:27:03pm
    Author:  conci

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class InputGainLookAndFeel : public LookAndFeel_V4
{
public:

	//SecondLookAndFeel();


	void drawLinearSlider(Graphics &, int x, int y, int width, int height, float sliderPos,
		float minSliderPos, float maxSliderPos, const Slider::SliderStyle stile, Slider &slider) override;

	void drawLinearSliderBackground(Graphics &, int x, int y, int width, int height, float sliderPos,
		float minSliderPos, float maxSliderPos, const Slider::SliderStyle style, Slider& slider) override;

};


class OutputGainLookAndFeel : public LookAndFeel_V4
{
public:

	//SecondLookAndFeel();


	void drawLinearSlider(Graphics &, int x, int y, int width, int height, float sliderPos,
		float minSliderPos, float maxSliderPos, const Slider::SliderStyle stile, Slider &slider) override;

	void drawLinearSliderBackground(Graphics &, int x, int y, int width, int height, float sliderPos,
		float minSliderPos, float maxSliderPos, const Slider::SliderStyle style, Slider& slider) override;


};

class RotaryLookAndFeel : public LookAndFeel_V4
{
public:


	void drawRotarySlider(Graphics &, int x, int y, int width, int height, float sliderPosProportional,
		float rotaryStartAngle, float rotaryEndAngle, Slider &) override;


};


class comboBoxLookAndFeel : public LookAndFeel_V4
{

public:
	Font getComboBoxFont(ComboBox& /*box*/) override
	{
		return getCommonMenuFont();
	}

	Font getPopupMenuFont() override
	{
		return getCommonMenuFont();
	}

private:
	Font getCommonMenuFont()
	{
		return Font("Multicolore", 15, 1);
	}
};