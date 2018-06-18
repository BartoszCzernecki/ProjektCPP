#include "Tab.h"
#include <time.h>
#include <windows.h>

Tab::Tab()
{
}

Tab::~Tab()
{
}

void Tab::clear(int **& mat,int H, int W)
{
	for (int m = 0; m < H; m++)
	{
		for (int n = 0; n < W; n++)
			mat[m][n] = 0;
	}
}

int Tab::f(int ** tab, int y, int x, int H, int W)
{
	if (y < 1) { y = H + y; }
	if (y >= H) { y = H - y; }
	if (x < 1) { x = W + x; }
	if (x >= W) { x = W - x; }
	return tab[y][x];
}

void Tab::calculate(int **& mata, int **& matb, int H, int W, int tryb)
{
	unsigned int neighbors;
	for (int m = 0; m < H; m++)
	{
		for (int n = 0; n < W; n++)
		{
			neighbors = 0;
			if (Tab::f(mata, m - 1, n - 1,H,W) == 1) neighbors += 1;
			if (Tab::f(mata, m - 1, n, H, W) == 1) neighbors += 1;
			if (Tab::f(mata, m - 1, n + 1, H, W) == 1) neighbors += 1;
			if (Tab::f(mata, m, n - 1, H, W) == 1) neighbors += 1;
			if (Tab::f(mata, m, n + 1, H, W) == 1) neighbors += 1;
			if (Tab::f(mata, m + 1, n - 1, H, W) == 1) neighbors += 1;
			if (Tab::f(mata, m + 1, n, H, W) == 1) neighbors += 1;
			if (Tab::f(mata, m + 1, n + 1, H, W) == 1) neighbors += 1;

			switch (tryb) {
			case 0:
				if (mata[m][n] == 1 && neighbors < 2)
					matb[m][n] = 0;
				else if (mata[m][n] == 1 && neighbors > 3)
					matb[m][n] = 0;
				else if (mata[m][n] == 1 && (neighbors == 2 || neighbors == 3))
					matb[m][n] = 1;
				else if (mata[m][n] == 0 && neighbors == 3)
					matb[m][n] = 1;
				break;
			case 1:
				if (mata[m][n] == 1 && neighbors == 1)
					matb[m][n] = 0;
				else if (mata[m][n] == 1 && neighbors > 1)
					matb[m][n] = 0;
				else if (mata[m][n] == 1 && neighbors < 1)
					matb[m][n] = 1;
				else if (mata[m][n] == 0 && neighbors == 1)
					matb[m][n] = 1;
				break;
			case 2:
				if (mata[m][n] == 1)	matb[m][n] = 0;
				else if (mata[m][n] == 0 && neighbors == 2)
					matb[m][n] = 1;
				break;
			case 3:
				if (mata[m][n] == 1 && neighbors < 3)
					matb[m][n] = 0;
				else if (mata[m][n] == 1 && neighbors > 4)
					matb[m][n] = 0;
				else if (mata[m][n] == 1 && (neighbors == 3 || neighbors == 4))
					matb[m][n] = 1;
				else if (mata[m][n] == 0 && (neighbors == 3 || neighbors == 4))
					matb[m][n] = 1;
				break;
			case 4:
				if (mata[m][n] == 1 && neighbors < 2 || neighbors > 5)
					matb[m][n] = 0;
				else if (mata[m][n] == 1 && neighbors == 3)
					matb[m][n] = 0;
				else if (mata[m][n] == 1 && (neighbors == 2 || neighbors == 4 || neighbors == 5))
					matb[m][n] = 1;
				else if (mata[m][n] == 0 && (neighbors == 3 || neighbors == 6 || neighbors == 8))
					matb[m][n] = 1;
				break;

			}


		}
	}
}

void Tab::gen(int ** mata, int H, int W)
{
	int s = rand() % H*W + 1;
	int l = 0;
	while (l < s) {
		for (int m = 0; m < H; m++)
		{
			for (int n = 0; n < W; n++)
			{
				s = rand() % 5 + 1;
				if (s == 1) {
					mata[m][n] = 1;
					l++;
				}


			}
		}
	}

}

void Tab::swap(int ** mata, int ** matb, int H, int W)
{
	for (int m = 0; m < H; m++)
	{
		for (int n = 0; n < W; n++)
			mata[m][n] = matb[m][n];

	}
}

int Tab::licz(int ** mata, int a, int H, int W)
{
	a = 0;
	for (int m = 0; m < H; m++)
	{
		for (int n = 0; n < W; n++) {
			if (mata[m][n] == 1) { a++; }

		}


	}
	return a;
}

void Tab::toggle(int xx, int yy, int **& mata, int menu, int size,int H, int W,int klik)
{
	if (xx > menu&&xx < size*H + menu&&yy>0 && yy < size*W) {
		xx = (xx - menu) / size;
		yy = yy / size;
		switch (klik) {
		case 0:
			if (f(mata, xx, yy, H, W) == 0) { mata[xx][yy] = 1; }
			else mata[xx][yy] = 0;
			break;
		case 1:
			mata[xx][yy] = 1;
			mata[tx(xx + 1, H)][tx(yy, W)] = 1;
			mata[tx(xx + 2, H)][tx(yy, W)] = 1;
			mata[tx(xx, H)][tx(yy+1, W)] = 1;
			mata[tx(xx + 1, H)][tx(yy+2, W)] = 1;
			break;
		case 2:
			mata[tx(xx + 1, H)][tx(yy, W)] = 1;
			mata[tx(xx + 4, H)][tx(yy, W)] = 1;
			mata[tx(xx, H)][tx(yy+1, W)] = 1;
			mata[tx(xx, H)][tx(yy+2, W)] = 1;
			mata[tx(xx, H)][tx(yy+3, W)] = 1;
			mata[tx(xx + 4, H)][tx(yy+2, W)] = 1;
			mata[tx(xx + 1, H)][tx(yy+3, W)] = 1;
			mata[tx(xx + 2, H)][tx(yy+3, W)] = 1;
			mata[tx(xx + 3, H)][tx(yy+3, W)] = 1;
			break;
		case 3:
			mata[xx][yy] = 1;
			mata[tx(xx + 1, H)][tx(yy, W)] = 1;
			mata[tx(xx + 2, H)][tx(yy, W)] = 1;

			break;
		case 4:

			mata[tx(xx + 1, H)][tx(yy, W)] = 1;
			mata[tx(xx, H)][tx(yy+1, W)] = 1;
			mata[tx(xx, H)][tx(yy+2, W)] = 1;
			mata[tx(xx + 1, H)][tx(yy+3, W)] = 1;
			mata[tx(xx + 2, H)][tx(yy+1, W)] = 1;
			mata[tx(xx + 2, H)][tx(yy+2, W)] = 1;

			break;
		}


	}
}

int Tab::tx(int x,int H) {
	if (x > H - 1) { x = x - H; }
	else if (x < 0) { x = x + H; }
	return x;
}

