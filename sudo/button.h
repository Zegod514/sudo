#pragma once
#include"common.h"
class Button 
{
public:
	Button(int x, int y, int w, int h, COLORREF curColor, string text);
	void Show();
	bool InButton(ExMessage& msg);
	bool MouseEvent(ExMessage& msg);
	void SetText();
protected:
	int x;
	int y;
	int w;
	int h;

	COLORREF curColor;
	COLORREF outColor;

	string text;
};