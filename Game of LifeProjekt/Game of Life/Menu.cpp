#include "Menu.h"
#include <SFML/Graphics.hpp>
#include <iostream>
#include <time.h>
#include <windows.h>
#include <string>
#include "Tab.h"
using namespace sf;
using namespace std;

Menu::Menu()
{
}


Menu::~Menu()
{
}

void Menu::menu()
{

	
	sf::Font Czcionka;
	Czcionka.loadFromFile("arial.ttf");
	sf::Text RozmiarX;
	RozmiarX.setFont(Czcionka);
	RozmiarX.setPosition(40, 150);
	RozmiarX.setCharacterSize(30);
	RozmiarX.setString(to_string(d1)+" "+to_string(j1));
	RozmiarX.setColor(sf::Color::Blue);
	RozmiarX.setStyle(sf::Text::Bold);

	sf::Text RozmiarY;
	RozmiarY.setFont(Czcionka);
	RozmiarY.setPosition(120, 150);
	RozmiarY.setCharacterSize(30);
	RozmiarY.setString(to_string(d2) + " " + to_string(j2));
	RozmiarY.setColor(sf::Color::Red);
	RozmiarY.setStyle(sf::Text::Bold);

	sf::Text xXXx;
	xXXx.setFont(Czcionka);
	xXXx.setPosition(100, 150);
	xXXx.setCharacterSize(30);
	xXXx.setString("x");
	xXXx.setColor(sf::Color::Black);
	xXXx.setStyle(sf::Text::Bold);

	Texture gora, dol,pstart;
	gora.loadFromFile("images/gora.png");
	dol.loadFromFile("images/dol.png");
	pstart.loadFromFile("images/button_start.png");
	Sprite przycisk1(gora);
	Sprite przycisk2(dol);
	Sprite przycisk3(pstart);
	Texture skroty;
	skroty.loadFromFile("images/skroty.png");
	Sprite skroty1;
	skroty1.setTexture(skroty);

	RenderWindow me(VideoMode(200, 300), "Menu");
	while (me.isOpen())
	{
		me.clear(Color(0, 0, 0, 255));
		me.draw(skroty1);
		RozmiarX.setString(to_string(d1) + " " + to_string(j1));
		RozmiarY.setString(to_string(d2) + " " + to_string(j2));
		me.draw(RozmiarX);
		me.draw(RozmiarY);
		me.draw(xXXx);
		przycisk1.setPosition(40, 130);
		przycisk2.setPosition(40, 190);
		me.draw(przycisk1);
		me.draw(przycisk2);
		przycisk1.setPosition(70, 130);
		przycisk2.setPosition(70, 190);
		me.draw(przycisk1);
		me.draw(przycisk2);
		przycisk1.setPosition(120, 130);
		przycisk2.setPosition(120, 190);
		me.draw(przycisk1);
		me.draw(przycisk2);
		przycisk1.setPosition(150, 130);
		przycisk2.setPosition(150, 190);
		me.draw(przycisk1);
		me.draw(przycisk2);
		przycisk3.setPosition(50, 230);
		me.draw(przycisk3);
		Event ev;
		while (me.pollEvent(ev))
		{
			switch (ev.type)
			{
			case Event::Closed: me.close();
				break;
			case Event::KeyPressed:
				switch (ev.key.code)
				{
				case Keyboard::Q:
					me.close();
					break;
				}
				case Event::MouseButtonPressed:
				switch (ev.key.code)
				{
				case Mouse::Left:
					x = Mouse::getPosition(me).x;
					y = Mouse::getPosition(me).y;
					Wymiary(x,y,d1,j1,d2,j2);
					if (x > 50 && x < 150 && y>230 && y < 280) {
						H = d1 * 10 + j1;
						W = d2 * 10 + j2;
						me.close();
						int** now = new int*[H];
						for (int i = 0; i < H; ++i) {
							now[i] = new int[W];
						}
						int** next = new int*[H];
						for (int i = 0; i < H; ++i) {
							next[i] = new int[W];
						}
						game(H, W, now, next);
					}
				}
			}
		}
		me.display();
	}
}


void Menu::game(int H,int W,int ** now, int ** next)
{
	int a = 0;
	bool pause = true;
	Text t_ilosc, t_pauza, t_tryb, t_klik,t_sleep ;
	Texture pole, zywe, background, p_zmien,prawo,lewo;

	Font Czcionka;
	Czcionka.loadFromFile("arial.ttf");

	string tryb1[5] = { "Convay","Narosl","Seeds","34","Ruch" };
	string klik1[5] = { "Punkt","Glider","Dakota","Blinker","Krysztal" };

	t_ilosc.setString(to_string(a));
	t_ilosc.setColor(sf::Color::Yellow);
	t_ilosc.setFont(Czcionka);
	t_ilosc.setPosition(110, 5);
	t_ilosc.setCharacterSize(20);
	t_ilosc.setStyle(sf::Text::Bold);

	t_pauza.setFont(Czcionka);
	t_pauza.setPosition(170, 10);
	t_pauza.setCharacterSize(20);
	t_pauza.setString(to_string(1));
	t_pauza.setColor(sf::Color::Red);
	t_pauza.setStyle(sf::Text::Bold);
	
	int tryb = 0;
	t_tryb.setFont(Czcionka);
	t_tryb.setPosition(20, 93);
	t_tryb.setCharacterSize(20);
	t_tryb.setString(tryb1[tryb]);
	t_tryb.setColor(sf::Color::Green);
	t_tryb.setStyle(sf::Text::Bold);
	int klik = 0;
	t_klik.setFont(Czcionka);
	t_klik.setPosition(20, 130);
	t_klik.setCharacterSize(20);
	t_klik.setString(klik1[klik]);
	t_klik.setColor(sf::Color::Red);
	t_klik.setStyle(sf::Text::Bold);

	int sleep = 10;
	t_sleep.setFont(Czcionka);
	t_sleep.setPosition(70, 60);
	t_sleep.setCharacterSize(20);
	t_sleep.setString(to_string(sleep)+" kl/s");
	t_sleep.setColor(sf::Color::Black);
	t_sleep.setStyle(sf::Text::Bold);

	pole.loadFromFile("images/white.png");
	zywe.loadFromFile("images/red.png");
	background.loadFromFile("images/indeks.png");
	p_zmien.loadFromFile("images/zmien.png");
	prawo.loadFromFile("images/prawo.png");
	lewo.loadFromFile("images/lewo.png");
	Sprite sprite1(pole), pole_zywe(zywe), image(background);
	Sprite s_zmien(p_zmien), s_prawo(prawo),s_lewo(lewo);

	int x,y;
	Tab tab;
	tab.clear(now, H, W);
	tab.clear(next, H, W);
	srand(time(0));
	int size = 16;
	int menu = 240;
	s_prawo.setPosition(140, 62);
	s_lewo.setPosition(20, 62);
	int kolor = 1;
	RenderWindow window(VideoMode(size*H+menu, size*W), "Gra w zycie", sf::Style::Titlebar);
	while (window.isOpen())
	{
		Event e;
		while (window.pollEvent(e))
		{
			switch (e.type)
			{
			case Event::Closed: window.close();
				break;
			case Event::KeyPressed:
				switch (e.key.code)
				{
				case Keyboard::P:
					if (pause == true) { pause = false; }
					else pause = true;
					cout << pause;
					break;
				case Keyboard::R:
					tab.clear(now, H, W);
					break;
				case Keyboard::G:
					tab.gen(now, H, W);
					break;
				case Keyboard::Q:
					window.close();
					break;
				case Keyboard::Z:
					if (sleep <= 2) {}
					else { sleep = sleep - 2; }
					break;
				case Keyboard::X:
					if (sleep >= 60) {}
					else { sleep = sleep + 2; }
					break;
				case Keyboard::T:
					if (tryb == 4) { tryb = 0; }
					else tryb++;
					break;
				case Keyboard::K:
					if (klik == 4) { klik = 0; }
					else klik++;
					break;
				}
			case Event::MouseButtonPressed:
				switch (e.key.code)
				{
				case Mouse::Left:
					x = Mouse::getPosition(window).x;
					y = Mouse::getPosition(window).y;
					tab.toggle(x, y, now, menu, size, H, W, klik);
					Ustawienia(x, y, klik, kolor, tryb, sleep);
				}
			}
		}
		switch (kolor)
		{
		case 1:
			zywe.loadFromFile("images/red.png");
			break;
		case 2:
			zywe.loadFromFile("images/yellow.png");
			break;
		case 3:
			zywe.loadFromFile("images/blue.png");
			break;
		case 4:
			zywe.loadFromFile("images/green.png");
			break;
		}
		
		tab.swap(next, now, H, W);
		window.clear(Color(0, 0, 133, 238));
		window.draw(image);
		window.draw(s_prawo);
		window.draw(s_lewo);
		s_zmien.setPosition(110, 97);
		window.draw(s_zmien);
		s_zmien.setPosition(110, 133);
		window.draw(s_zmien);
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++)
			{
				if (next[i][j] == 1) { pole_zywe.setPosition(menu + i*size, j*size);  window.draw(pole_zywe); }
				else
					if (next[i][j] == 0) { sprite1.setPosition(menu + i*size, j*size);  window.draw(sprite1); }
			}
		}
		a = tab.licz(next, a,H,W);
		t_ilosc.setString(to_string(a));
		if (pause==1){ t_pauza.setString("Pauza"); } else t_pauza.setString("   ...");
		t_sleep.setString(to_string(sleep) + " kl/s");

		t_tryb.setString(tryb1[tryb]);

		t_klik.setString(klik1[klik]);
		window.draw(t_ilosc);
		window.draw(t_pauza);
		window.draw(t_tryb);
		window.draw(t_klik);
		window.draw(t_sleep);
		pole_zywe.setPosition(70,30);  window.draw(pole_zywe);

		window.display();
		if (pause == true) {}
		else {
			tab.calculate(next, now, H, W, tryb);
			Sleep(1000 / sleep);

			tab.swap(next, now, H, W);
		}
	}
}

void Menu::Wymiary(int x,int y,int& d1, int& j1,int& d2, int& j2)
{
	if (x > 40 && x < 60 && y>130 && y < 150) {
		if (d1 < 9) { d1++; }
	}
	if (x > 40 && x < 60 && y>190 && y < 210) {
		if (d1 > 1) { d1--; }
	}
	if (x > 70 && x < 90 && y>130 && y < 150) {
		if (j1 < 9) { j1++; }
	}
	if (x > 70 && x < 90 && y>190 && y < 210) {
		if (j1 > 0) { j1--; }
	}
	if (x > 120 && x < 140 && y>130 && y < 150) {
		if (d2 < 9) { d2++; }
	}
	if (x > 120 && x < 140 && y>190 && y < 210) {
		if (d2 > 1) { d2--; }
	}
	if (x > 150 && x < 170 && y>130 && y < 150) {
		if (j2 < 9) { j2++; }
	}
	if (x > 150 && x < 170 && y>190 && y < 210) {
		if (j2 > 0) { j2--; }
	}
}

void Menu::Ustawienia(int x, int y, int& klik, int& kolor, int& tryb, int& sleep) {
	if (x > 69 && x < 86 && y > 29 && y < 46) {
		if (kolor == 4) { kolor =0; }
		else kolor++;
	}
	if (x > 139 && x < 188 && y>61 && y < 83) { if (sleep >= 60) {} else { sleep = sleep + 2; } }
	if (x > 19 && x < 68 && y>61 && y < 83) { if (sleep <= 2) {} else { sleep = sleep - 2; } }
	if (x > 109 && x < 162 && y > 96 && y < 118) {
		if (tryb == 4) { tryb = 0; }
		else tryb++;
	}
	if (x > 109 && x < 162 && y > 132 && y < 154) {
		if (klik == 4) { klik = 0; }
		else klik++;
	}
}