#include <SFML/Graphics.hpp>
#include <fstream>
using namespace sf;


class Mshape
{
protected:
	int x;
	int y;
	bool visible;
	bool composite;
public:
	Mshape() : x(0), y(0), visible(0), composite(false) {};
	Mshape(int x, int y) : x(x), y(y), visible(0), composite(false){};
	virtual void draw(RenderWindow& window) = 0;
	virtual void reset() = 0;
	virtual void move(float x, float y) = 0;
	virtual void show() = 0;
	virtual void change_color() = 0;
	virtual void write(std::ofstream& out) = 0;
	virtual void read(std::ifstream& in) = 0;
	void set_visible(bool x)
	{
		visible = x;
	};
	bool get_visible()
	{
		return visible;
	};
	void set_composite(bool x)
	{
		composite = x;
	};
	bool get_composite()
	{
		return composite;
	};

};

class Composite :public Mshape
{
	std::vector<Mshape*> shapes;
public:
	void add(Mshape* shape);
	void reset();
	void draw(RenderWindow& window);
	void move(float f1, float f2);
	void show();
	void change_color();
	void write(std::ofstream& out);
	void read(std::ifstream& in);
};

class Circle : public Mshape
{
	CircleShape circle;

public:
	Circle();
	void draw(RenderWindow& window);
	void reset();
	void move(float f1, float f2);
	void show();
	void change_color();
	void write(std::ofstream& out);
	void read(std::ifstream& in);
};

class Triangle : public Mshape
{
	CircleShape triangle;
public:
	Triangle();
	void draw(RenderWindow& window);
	void reset();
	void move(float f1, float f2);
	void show();
	void change_color();
	void write(std::ofstream& out);
	void read(std::ifstream& in);
};

class Square : public Mshape
{
	CircleShape square;
public:
	Square();
	void draw(RenderWindow& window);
	void reset();
	void move(float f1, float f2);
	void show();
	void change_color();
	void write(std::ofstream& out);
	void read(std::ifstream& in);
};

class Rectangle : public Mshape
{
	int type;
	RectangleShape rectangle;
public:
	Rectangle(int t);
	void draw(RenderWindow& window);
	void reset();
	void move(float f1, float f2);
	void show();
	void change_color();
	void write(std::ofstream& out);
	void read(std::ifstream& in);
};