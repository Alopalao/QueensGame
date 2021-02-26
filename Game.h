#pragma once

using namespace System::Drawing;
using namespace System::Windows::Forms;

class Game {
protected:
	int x;
	int y;
	int width;
	int length;
	int n;
	int type;
public:
	Game() {}
	~Game() {}
	virtual void DrawIm(Graphics^ g) abstract;
};