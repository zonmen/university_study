#include <SFML/Graphics.hpp>
#include "Mshape.h"

using namespace sf;

constexpr  int WINDOW_WIDTH = 1400;
constexpr  int WINDOW_HEIGHT = 800;


//Composite
void Composite::add(Mshape* shape) {
	shapes.push_back(shape);
//показываем, что фигура теперь в агрегате
	shape->set_composite(true);
}
void Composite :: reset() {
	for (int i = 0; i < shapes.size(); i++)
	{
		shapes[i]->reset();
		shapes[i]->set_composite(false);
	}
	shapes.clear();
}
void Composite :: draw(RenderWindow& window) {
	for (int i = 0; i < shapes.size(); i++)
	{
		shapes[i]->draw(window);
	}
}
void Composite::move(float f1, float f2)
{
	for (int i = 0; i < shapes.size(); i++)
	{
		shapes[i]->move(f1, f2);
	}
}
void Composite::show()
{
	if (visible == true)
		visible = false;
	else
		visible = true;
	for (int i = 0; i < shapes.size(); i++)
	{
		shapes[i]->set_visible(visible);
	}
}
void Composite::change_color() {
	for (int i = 0; i < shapes.size(); i++)
	{
		shapes[i]->change_color();
	}
}
void Composite::write(std::ofstream& out) {
	out.close();
}
void Composite::read(std::ifstream& in) {
	in.close();
}
	
//Circle
Circle::Circle() : Mshape(15, 15), circle(50.f)
	{
		circle.setPosition(x, y);
		circle.setFillColor(Color::Green);
	}
void Circle :: draw(RenderWindow& window) {
		window.draw(circle);
	}
void Circle :: reset() {
		circle.setPosition(15, 15);
		circle.setFillColor(Color::Green);
		visible = false;
	};
void Circle :: move(float f1, float f2)
	{
		if (f2 == 0) {
			if ((circle.getPosition().x + f1 + 100 <= WINDOW_WIDTH) && (circle.getPosition().x + f1 >= 0))
				circle.move(f1, f2);
		}
		else {
			//координаты по у выглядят так, что нольнаходится в верхнем левом углу,
			//а положительная ось смотрит вниз
			if ((circle.getPosition().y + f2 >= 0) && (circle.getPosition().y + f2 + 100 <= WINDOW_HEIGHT))
				circle.move(f1, f2);
		}
	}
void Circle :: show()
	{
		if (visible == true)
			visible = false;
		else
			visible = true;
	}
void Circle :: change_color() {
		if (circle.getFillColor() == Color::Red)
			circle.setFillColor(Color::Blue);
		else
			if (circle.getFillColor() == Color::Blue)
				circle.setFillColor(Color::Black);
			else
				circle.setFillColor(Color::Red);
	}
void Circle::write(std::ofstream& out) {
	out << circle.getPosition().x << " " << circle.getPosition().y <<" "<< get_visible() << " "
		<< get_composite()<<" "<<circle.getFillColor().toInteger()<< std ::endl;
}
void Circle::read(std::ifstream& in) {
	bool f1,f2;
	unsigned color;
	in >> x >> y >> f1 >> f2 >> color;
	Color c(color);
	circle.setPosition(x, y);
	set_visible(f1);
	set_composite(f2);
	circle.setFillColor(c);
}

//Triangle
Triangle:: Triangle() : Mshape(125, 15), triangle(65.f, 3)
	{
		triangle.setPosition(x, y);
		triangle.setFillColor(Color::Blue);
	}
void Triangle :: draw(RenderWindow& window) {
		window.draw(triangle);
	}
void Triangle :: reset() {
		triangle.setPosition(125, 15);
		triangle.setFillColor(Color::Blue);
		visible = false;
	};
void Triangle :: move(float f1, float f2)
	{
		if (f2 == 0) {
			if ((triangle.getPosition().x + f1 + 150 <= WINDOW_WIDTH) && (triangle.getPosition().x + f1 >= 0))
				triangle.move(f1, f2);
		}
		else {
			if ((triangle.getPosition().y + f2 >= 0) && (triangle.getPosition().y + f2 + 100 <= WINDOW_HEIGHT))
				triangle.move(f1, f2);
		}
	}
void Triangle :: show()
	{
		if (visible == true)
			visible = false;
		else
			visible = true;
	}
void Triangle :: change_color() {
		if (triangle.getFillColor() == Color::Red)
			triangle.setFillColor(Color::Blue);
		else
			if (triangle.getFillColor() == Color::Blue)
				triangle.setFillColor(Color::Black);
			else
				triangle.setFillColor(Color::Red);
	}
void Triangle::write(std::ofstream& out) {
	out << triangle.getPosition().x << " " << triangle.getPosition().y << " " << get_visible() << " "
		<< get_composite() << " " << triangle.getFillColor().toInteger() << std::endl;
}
void Triangle::read(std::ifstream& in) {
	bool f1, f2;
	unsigned color;
	in >> x >> y >> f1 >> f2 >> color;
	Color c(color);
	triangle.setPosition(x, y);
	set_visible(f1);
	set_composite(f2);
	triangle.setFillColor(c);
}

//Square
Square::Square() : Mshape(250, 15), square(65.f, 4)
	{
		square.setPosition(x, y);
		square.setFillColor(Color::Black);
	}
void Square :: draw(RenderWindow& window) {
		window.draw(square);
	}
void Square :: reset() {
		square.setPosition(250, 15);
		square.setFillColor(Color::Black);
		visible = false;
	};
void Square :: move(float f1, float f2)
	{
		if (f2 == 0) {
			if ((square.getPosition().x + f1 + 130 <= WINDOW_WIDTH) && (square.getPosition().x + f1 >= 0))
				square.move(f1, f2);
		}
		else {
			if ((square.getPosition().y + f2 >= 0) && (square.getPosition().y + f2 + 150 <= WINDOW_HEIGHT))
				square.move(f1, f2);
		}
	}
void Square :: show()
	{
		if (visible == true)
			visible = false;
		else
			visible = true;
	}
void Square :: change_color() {
		if (square.getFillColor() == Color::Red)
			square.setFillColor(Color::Blue);
		else
			if (square.getFillColor() == Color::Blue)
				square.setFillColor(Color::Black);
			else
				square.setFillColor(Color::Red);
	}
void Square::write(std::ofstream& out) {
	out << square.getPosition().x << " " << square.getPosition().y << " " << get_visible() << " "
		<< get_composite() << " " << square.getFillColor().toInteger() << std::endl;
}
void Square::read(std::ifstream& in) {
	bool f1, f2;
	unsigned color;
	in >> x >> y >> f1 >> f2 >> color;
	Color c(color);
	square.setPosition(x, y);
	set_visible(f1);
	set_composite(f2);
	square.setFillColor(c);
}


//Rectangle
Rectangle::Rectangle(int t) : type(t), Mshape(425, 15)
	{
		if (type == 1)
		{
			rectangle.setSize(Vector2f(150.f, 10.f));
			rectangle.setFillColor(Color::Red);
			x += 125;
		}
		else {
			rectangle.setSize(Vector2f(80.f, 120.f));
			rectangle.setFillColor(Color::Yellow);
		}
		rectangle.setPosition(x, y);
	}
void Rectangle :: draw(RenderWindow& window) {
		window.draw(rectangle);
	}
void Rectangle :: reset() {
	if (type == 1) {
		rectangle.setPosition(550, 15);
		rectangle.setFillColor(Color::Red);
	}
	else {
		rectangle.setPosition(425, 15);
		rectangle.setFillColor(Color::Yellow);
	}
	visible = false;
	};
void Rectangle :: move(float f1, float f2)
	{
		if (type == 1)
		{
			if (f2 == 0) {
				if ((rectangle.getPosition().x + f1 + 160 <= WINDOW_WIDTH) && (rectangle.getPosition().x + f1 >= 0))
					rectangle.move(f1, f2);
			}
			else {
				if ((rectangle.getPosition().y + f2 >= 0) && (rectangle.getPosition().y + f2 + 30 <= WINDOW_HEIGHT))
					rectangle.move(f1, f2);
			}
		}
		else {
			if (f2 == 0) {
				if ((rectangle.getPosition().x + f1 + 80 <= WINDOW_WIDTH) && (rectangle.getPosition().x + f1 >= 0))
					rectangle.move(f1, f2);
			}
			else {
				if ((rectangle.getPosition().y + f2 >= 0) && (rectangle.getPosition().y + f2 + 130 <= WINDOW_HEIGHT))
					rectangle.move(f1, f2);
			}
		}
	}
void Rectangle :: show()
	{
		if (visible == true)
			visible = false;
		else
			visible = true;
	}
void Rectangle :: change_color() {
		if (rectangle.getFillColor() == Color::Red)
			rectangle.setFillColor(Color::Blue);
		else
			if (rectangle.getFillColor() == Color::Blue)
				rectangle.setFillColor(Color::Black);
			else
				rectangle.setFillColor(Color::Red);
	}
void Rectangle::write(std::ofstream& out) {
	out << rectangle.getPosition().x << " " << rectangle.getPosition().y << " " << get_visible() << " "
		<< get_composite() << " " << rectangle.getFillColor().toInteger() << std::endl;
}
void Rectangle::read(std::ifstream& in) {
	bool f1, f2;
	unsigned color;
	in >> x >> y >> f1 >> f2 >> color;
	Color c(color);
	rectangle.setPosition(x, y);
	set_visible(f1);
	set_composite(f2);
	rectangle.setFillColor(c);
}