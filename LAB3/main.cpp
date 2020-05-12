#include <SFML/Graphics.hpp>
#include "Mshape.h"
#include <iostream>
#include <fstream>

using namespace sf;
using namespace std;

constexpr  int WINDOW_WIDTH = 1400;
constexpr  int WINDOW_HEIGHT = 800;
const int STEP = 20;

void menu() {
	setlocale(LC_ALL, "russian");
	cout << "1 - ��� ��������� �����" << endl;
	cout << "2 - ��� ��������� ������������" << endl;
	cout << "3 - ��� ��������� ��������" << endl;
	cout << "4 - ��� ��������� ��������������" << endl;
	cout << "5 - ��� ��������� ������" << endl;
	cout << "6 - ��� ��������� ��������" << endl;
	cout << "��� ��������� ������� - �������������� ������ ����������" <<endl;
	cout << endl;
	cout << "W - ��� ����������� ��������������� ������� �����" << endl;
	cout << "S - ��� ����������� ��������������� ������� ����" << endl;
	cout << "A - ��� ����������� ��������������� ������� �����" << endl;
	cout << "D - ��� ����������� ��������������� ������� ������" << endl;
	cout << endl;
	cout <<"R - ��� ����������� ��������������� ������� �� ��������� �������"<< endl;
	cout <<"T - ��� �������� �������� �� ������������ �������"<< endl;
	cout <<"F - ��� ����� ����� ��������������� �������"<< endl;
	cout << endl;
	cout <<"X - ��� ������ � ����"<< endl;
	cout <<"C - ��� ������ �� �����"<< endl;
}

int main(){
	int x;
	string s;
	ifstream in;
	ofstream out;

	menu();
	int index = 0;
Circle circle; Triangle triangle; Square square;
Rectangle rectangle(0); Rectangle line(1); Composite composite;
vector<Mshape*> shapes = { &circle, &triangle, &square, &rectangle, &line, &composite };
RenderWindow window({ WINDOW_WIDTH, WINDOW_HEIGHT }, "Lab_3", Style::Default);

while (window.isOpen())
{	setlocale(LC_ALL, "russian");
	Event event;
	while (window.pollEvent(event))
	{
		if (event.type == sf::Event::KeyPressed)
		{
			switch (event.key.code) {
			case Keyboard::Escape:
				window.close();
				break;
			case Keyboard::Num1:
//�������� �� ��, ���� �� �������� ������ �� �����, ���� ��, �� ������
//��,���� ��� �� ���������� � ����� ���������� ��� ��� + ��������
//�� ��, ��������� �� ������ � ��������, ���� ��, ������
//�� ���� ���������� ��� ���
				if (shapes[0]->get_composite() == false) {
					if (index == 0) {
						shapes[index]->show();
					}
					else {
						index = 0;
						shapes[index]->set_visible(true);
					}
				}
				break;
			case Keyboard::Num2:
				if (shapes[1]->get_composite() == false) {
					if (index == 1) {
						shapes[index]->show();
					}
					else {
						index = 1;
						shapes[index]->set_visible(true);
					}
				}
				break;
			case Keyboard::Num3:
				if (shapes[2]->get_composite() == false) {
					if (index == 2) {
						shapes[index]->show();
					}
					else {
						index = 2;
						shapes[index]->set_visible(true);
					}
				}
				break;
			case Keyboard::Num4:
				if (shapes[3]->get_composite() == false) {
					if (index == 3) {
						shapes[index]->show();
					}
					else {
						index = 3;
						shapes[index]->set_visible(true);
					}
				}
				break;
			case Keyboard::Num5:
				if (shapes[4]->get_composite() == false) {
					if (index == 4) {
						shapes[index]->show();
					}
					else {
						index = 4;
						shapes[index]->set_visible(true);
					}
				}
				break;
			case Keyboard::Num6:
				if (index == 5) {
					shapes[index]->show();
				}
				else {
					index = 5;
					shapes[index]->set_visible(true);
				}
				break;
			case Keyboard::W:
				if (shapes[index]->get_visible() == true) {
					shapes[index]->move(0, -STEP);
					shapes[index]->draw(window);
				}
				break;
			case Keyboard::S:
				if (shapes[index]->get_visible() == true) {
					shapes[index]->move(0, STEP);
					shapes[index]->draw(window);
				}
				break;
			case Keyboard::A:
				if (shapes[index]->get_visible() == true) {
					shapes[index]->move(-STEP, 0);
					shapes[index]->draw(window);
				}
				break;
			case Keyboard::D:
				if (shapes[index]->get_visible() == true) {
					shapes[index]->move(STEP, 0);
					shapes[index]->draw(window);
				}
				break;
			case Keyboard::T:
				index = 5;
				shapes[index]->set_visible(true);
				for (int i = 0; i < shapes.size() - 1; i++)
				{
					if (shapes[i]->get_visible() == true) {
						composite.add(shapes[i]);
					}
				}
				break;
			case Keyboard::R:
				shapes[index]->reset();
				break;
			case Keyboard::F:
				shapes[index]->change_color();
				break;
			case Keyboard::X:
				out.open("out_put.txt");
				for (int i = 0; i < shapes.size(); i++)
				{
					shapes[i]->write(out);
				}
				break;
			case Keyboard::C:
//				cin >> s;
				in.open("out_put.txt");
				for (int i = 0; i < shapes.size(); i++)
				{
					shapes[i]->read(in);
					if (shapes[i]->get_composite() == true)
						composite.add(shapes[i]);
				}
				break;
			}
		}
	}

	window.clear(Color(250, 220, 100, 0));
		for (int i = 0; i < shapes.size(); i++)
		{
			if (shapes[i]->get_visible() == true) {
				shapes[i]->draw(window);
			}
		}

	window.display();
}

return 0;
}
