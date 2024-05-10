#pragma once
#include"common.h"
class Widget
{
public:
	Widget(int width,int height);
	void Show();
	~Widget();
protected:
	int width;
	int height;
};