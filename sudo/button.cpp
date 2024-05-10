#include "button.h"
Button::Button(int x, int y, int w, int h, COLORREF curColor, string text)
{
	this->x = x;
	this->y = y;
	this->w = w;
	this->h = h;
	this->curColor = curColor;
	this->outColor = curColor;
	this->text = text;
}

void Button::Show()
{
	setfillcolor(this->curColor);
	setlinecolor(BLACK);
	fillrectangle(x, y, x + w, y + h);
	settextstyle(h * 2 / 3, 0, "ºÚÌå");
	setbkmode(TRANSPARENT);
	settextcolor(BLACK);
	setlinestyle(PS_SOLID, 1);
	int xx = x + (w - textwidth(text.c_str())) / 2;
	int yy = y + (h - textheight(text.c_str())) / 2;
	outtextxy(xx, yy, text=="0"?"":text.c_str());
}

bool Button::InButton(ExMessage& msg)
{
	if (msg.x >= x && msg.x <= x + w && msg.y >= y && msg.y <= y + h) {
		this->curColor = LIGHTBLUE;
		return true;
	}
	this->curColor = outColor;
	return false;
}

bool Button::MouseEvent(ExMessage& msg)
{
	if (InButton(msg) && msg.message == WM_LBUTTONUP) {
		return true;
	}
	return false;
}

void Button::SetText()
{
	int num = text[0] - '0';
	num++;
	if (num > 9) {
		num = 0;
	}
	this->text = to_string(num);
}
