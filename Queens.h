#pragma once
#include "Game.h"
class Queens : public Game
{
private:
public:
	Queens(int px, int py, int pwidth, int plength, int ptype) {
		x = px;
		y = py;
		width = pwidth;
		length = plength;
		type = 0;
	}
	~Queens() {}
	void DrawIm(Graphics^ g) {
		g->DrawEllipse(gcnew Pen(Color::Black), x, y, width, length);
	}
};