#pragma warning(disable : 4996) 
#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
using namespace std;

#define PI 3.14159265358979323846

int n = 9;
double y[9] = { 0,1,2,3,4,5,6,7,8 };
double x[9] = { 0,2,4,9,16,25,36,49,64 };
int h = 4;
int X = 12;

double Trig(double X)
{
	double res = 0;
	int m = n + 1;
	double b0 = 0;
	for (int i = 0; i < m - 1; i++)
	{
		b0 += y[i] / m;
	}
	for (int i = 1; i < m; i++)
	{
		double bj = 0, aj = 0;
		for (int j = 0; j < m - 1; j++)
		{
			bj += y[j] * cos(2 * PI * i * j / m) / m;
			aj += y[j] * sin(2 * PI * i * j / m) / m;
		}
		res += bj * cos(2 * PI * i * (X - x[0]) / (m * h)) + aj * sin(2 * PI * i * (X - x[0]) / (m * h));
	}
	res += b0;
	//--n;
	return res;
}

string toStr(double x)
{
	string s = to_string(x);
	if (s[s.size() - 1] == '0')
		for (size_t i = s.size() - 1; s[i] == '0'; i--)
			s.erase(i, 1);

	if (s[s.size() - 1] == ',')
		s.erase(s.size() - 1, 1);
	return s;
}


int main()
{
	double S = Trig(X);
	sf::RenderWindow window(sf::VideoMode(1200, 800), "9 laba");
	sf::RectangleShape fon;
	fon.setSize({ 1200, 800 });
	fon.setFillColor(sf::Color(0xFF, 0xFF, 0xFF));

	sf::Font font;//шрифт 
	font.loadFromFile("CyrilicOld.ttf");//передаем нашему шрифту файл шрифта

	while (window.isOpen())
	{
		window.clear();
		window.draw(fon);
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		sf::VertexArray line(sf::Lines, 4);
		line[0].position = sf::Vector2f(0, 400);
		line[1].position = sf::Vector2f(1200, 400);
		line[2].position = sf::Vector2f(600, 0);
		line[3].position = sf::Vector2f(600, 800);
		line[0].color = sf::Color(0x0, 0x0, 0x0);
		line[1].color = sf::Color(0x0, 0x0, 0x0);
		line[2].color = sf::Color(0x0, 0x0, 0x0);
		line[3].color = sf::Color(0x0, 0x0, 0x0);


		/*sf::VertexArray graf(sf::LinesStrip, n + 1);
		graf[0].position = sf::Vector2f(600, 400);
		graf[0].color = sf::Color(0x0, 0x0, 0x0);
		sf::Text* text = new sf::Text[n];

		sf::Text ttext("", font, 12);
		for (int i = 0; i < n; ++i)
		{
			graf[i + 1].color = sf::Color(0x0, 0x0, 0x0);
			graf[i + 1].position = sf::Vector2f(600 + x[i] * 20, 400 - y[i] * 20);

			ttext.setPosition(600 + x[i] * 20, 400);
			ttext.setColor(sf::Color::Red);
			ttext.setString(toStr(x[i]));
			window.draw(ttext);

			ttext.setPosition(598 + x[i] * 20, 391);
			ttext.setString("|");
			window.draw(ttext);

			ttext.setPosition(598 + x[i] * 20, 387 - y[i] * 20);
			ttext.setString("|\n|");
			window.draw(ttext);

			ttext.setPosition(600, 387 - y[i] * 20);
			ttext.setColor(sf::Color::Red);
			ttext.setString(toStr(y[i]));
			window.draw(ttext);

			ttext.setPosition(594 + x[i] * 20, 387 - y[i] * 20);
			ttext.setString("__");
			window.draw(ttext);

			ttext.setPosition(596, 387 - y[i] * 20);
			ttext.setString("_");
			window.draw(ttext);
		}
		ttext.setColor(sf::Color::Blue);

		ttext.setPosition(600 + X * 20, 400);
		ttext.setString(toStr(X));
		window.draw(ttext);

		ttext.setPosition(600, 387 - S * 20);
		ttext.setString(toStr(S));
		window.draw(ttext);

		ttext.setPosition(598 + X * 20, 391);
		ttext.setString("|");
		window.draw(ttext);

		ttext.setPosition(598 + X * 20, 387 - S * 20);
		ttext.setString("|\n|");
		window.draw(ttext);

		ttext.setPosition(594 + X * 20, 387 - S * 20);
		ttext.setString("__");
		window.draw(ttext);

		ttext.setPosition(596, 387 - S * 20);
		ttext.setString("_");
		window.draw(ttext);*/

		sf::VertexArray grafic(sf::LinesStrip, (x[n - 1]) * 10);
		grafic[0].position = sf::Vector2f(600, 400);
		grafic[0].color = sf::Color::Green;
		int j = 1;
		for (double i = 0; i < x[n - 1] - 0.1; i += 0.1)
		{
			double y = Trig(i);
			grafic[j].position = sf::Vector2f(600 + i*20, 400 - y*20);
			grafic[j].color = sf::Color::Green;
			++j;
		}
		window.draw(grafic);
		window.draw(line);
		//window.draw(graf);
		window.display();
	}
}