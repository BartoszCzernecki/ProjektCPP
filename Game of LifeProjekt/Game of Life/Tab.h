#pragma once
class Tab
{
public:
	Tab();
	~Tab();
	void clear(int **& mat, int H, int W);

	void calculate(int **& mata, int **& matb, int H, int W, int tryb);
	void gen(int ** mata, int H, int W);
	void swap(int ** mata, int ** matb, int H, int W);
	int licz(int ** mata, int a, int H, int W);
	void toggle(int xx, int yy, int **& mata, int menu, int size,int W, int H, int klik);
	
private:
	int tx(int x, int H);
	int f(int ** tab, int y, int x, int H, int W);
};

