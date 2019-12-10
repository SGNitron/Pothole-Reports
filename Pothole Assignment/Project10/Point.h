#pragma once
//typedef double TYPE;

template <class TYPE>
class Point {
public:
	Point();
	Point(TYPE, TYPE);
	void display();
	bool operator ==(const Point<TYPE>)const;

	friend void bagTester();
	TYPE getX() const;
	TYPE getY() const;
	TYPE setX(TYPE);
	TYPE setY(TYPE);
	//double distance(Point);
private:
	TYPE mX;
	TYPE mY;
};
#include "Point.inl"