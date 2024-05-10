#include "widget.h"
Widget::Widget(int width,int height)
{
	this->width = width;
	this->height = height;
}

void Widget::Show()
{
	initgraph(width, height);
}

Widget::~Widget()
{
	closegraph();
}
