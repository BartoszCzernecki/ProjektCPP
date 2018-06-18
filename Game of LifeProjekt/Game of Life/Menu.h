#pragma once
#include "Tab.h"
class Menu
{
public:
	int H;
	int W;
	int x;
	int y;
	int d1 = 1;
	int j1 = 0;
	int d2 = 1;
	int j2 = 0;

	Menu();
	~Menu();
	void menu();
	void game(int H, int W,int ** now,int ** next);
private:
	void Wymiary(int x, int y, int& d1, int& j1, int& d2, int& j2);
	void Ustawienia(int x, int y, int& klik, int& kolor, int& tryb, int& sleep);
};

