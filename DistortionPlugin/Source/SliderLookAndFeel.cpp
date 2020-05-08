/*
  ==============================================================================

    NewLookAndFeel.cpp
    Created: 2 May 2020 1:27:03pm
    Author:  conci

  ==============================================================================
*/

#include "SliderLookAndFeel.h"


void InputGainLookAndFeel::drawLinearSlider(Graphics& g, int x, int y, int width, int height, float sliderPos,
	float minSliderPos, float maxSliderPos, const Slider::SliderStyle stile, Slider& slider)
{
	//g.fillAll(slider.findColour(Slider::backgroundColourId));
	drawLinearSliderBackground(g, x, y, width, height, sliderPos,
		minSliderPos, maxSliderPos, stile, slider);


	/*
	Path p;
	p.addRoundedRectangle((float)x, sliderPos, (float)width, 5 + height - sliderPos, 5, 3);
	g.setColour(Colour(24, 57, 43));
	g.fillPath(p);
	*/
	Path p;
	Rectangle<float> area((float)x, sliderPos, (float)width, 5 + height - sliderPos);
	p.addRoundedRectangle(area, 5, 3);
	ColourGradient gradiente(Colour(255, 0, 0), x, y - (height / 3), Colour(15, 167, 33), x, y + height, false);
	g.setGradientFill(gradiente);
	//g.fillRect(area);
	g.fillPath(p);

	
}


void InputGainLookAndFeel::drawLinearSliderBackground(Graphics& g, int x, int y, int width, int height, float sliderPos,
	float minSliderPos, float maxSliderPos, const Slider::SliderStyle style, Slider& slider)
{
	Rectangle<float> dialArea(x, y + 5, width, height - 9);
	g.setColour(Colour(59, 59, 59));
	//g.drawRect(dialArea);
	g.drawRoundedRectangle(dialArea, 10, 10);
}





void OutputGainLookAndFeel::drawLinearSlider(Graphics& g, int x, int y, int width, int height, float sliderPos,
	float minSliderPos, float maxSliderPos, const Slider::SliderStyle stile, Slider& slider)
{
	//g.fillAll(slider.findColour(Slider::backgroundColourId));
	drawLinearSliderBackground(g, x, y, width, height, sliderPos,
		minSliderPos, maxSliderPos, stile, slider);


	Path p;
	Rectangle<float> area((float)x, sliderPos, (float)width, 5 + height - sliderPos);
	p.addRoundedRectangle(area, 5, 3);
	ColourGradient gradiente(Colour(255, 0, 0), x, y- (height / 2), Colour(15, 167, 33), x, y + height, false);
	g.setGradientFill(gradiente);
	//g.fillRect(area);
	g.fillPath(p);
	
}


void OutputGainLookAndFeel::drawLinearSliderBackground(Graphics& g, int x, int y, int width, int height, float sliderPos,
	float minSliderPos, float maxSliderPos, const Slider::SliderStyle style, Slider& slider)
{
	Rectangle<float> dialArea(x, y + 5, width, height - 9);
	g.setColour(Colour(59, 59, 59));
	//g.drawRect(dialArea);
	g.drawRoundedRectangle(dialArea, 10, 10);

}


void RotaryLookAndFeel::drawRotarySlider(Graphics& g, int x, int y, int width, int height, float sliderPos,
	float rotaryStartAngle, float rotaryEndAngle, Slider& slider)
{
	//jmin restituisce il valore minore tra i due
	float diameter = jmin(width, height);
	float radius = diameter / 2;
	//punto centrale della finestra
	float centerX = x + width / 2;
	float centerY = y + height / 2;
	//coordinate del vertice alto sinistro
	float rx = centerX - radius;
	float ry = centerY - radius;
	//rotazione
	float angle = rotaryStartAngle + (sliderPos *(rotaryEndAngle - rotaryStartAngle));

	Rectangle<float> dialArea(rx, ry, diameter, diameter);
	g.setColour(Colour(59, 59, 59));
	Path pie;
	pie.addPieSegment(rx, ry, diameter, diameter, rotaryStartAngle, rotaryEndAngle, 0.92);
	g.fillPath(pie);

	
	g.setColour(Colour(15, 167, 33));
	Path pie2;
	pie2.addPieSegment(rx, ry, diameter, diameter, rotaryStartAngle, angle, 0.92);
	g.fillPath(pie2);

	// Value
	g.setFont(Font("Calibri", 30.0f, 1)); 
	g.setColour(Colour(242, 242, 242));
	
	g.drawSingleLineText(String(slider.getValue()), centerX, centerY+5, Justification::horizontallyJustified);
}



/*
void comboBoxLookAndFeel::drawComboBox(Graphics& g, int width, int height, bool isButtonDown,
	int buttonX, int buttonY, int buttonW, int buttonH, ComboBox& combo)
{

}

*/