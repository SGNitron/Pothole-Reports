#include "Point.h"

Point::Point()//Constructor sets both mX and mY to 0
{
	mX = 0;
	mY = 0;
}

Point::Point(int inX, int inY)//Parameterized Constructor sets mX and mY to equal inX and inY when called
{
	mX = inX;
	mY = inY;
}

Point::Point(int divR)
{
	mX = divR;
	mY = rand() % 10;
}

int Point::genRandNum()
{
	return(rand() % 11);
}



void Point::display() const //Prints out integers as coordinates 
{
	cout << "Point: " << "(" << mX << "," << mY << ")";
}

void Point::setXPoint(int setX) //Function used to set values for mX
{
	mX = setX;
}

void Point::setYPoint(int setY)
{
	mY = setY;
}

int Point::getXPoint()
{
	return mX;
}

int Point::getYPoint()
{
	return mY;
}

double Point::distance(const Point& otherPoint)const //Function used to calculate distance
{
	double dist;
	dist = sqrt(pow((mX - otherPoint.mX), 2) + pow((mY - otherPoint.mY), 2));
	return dist;

}

void Point::placeCursorAt(Point coordinate) {

	COORD coord;
	coord.X = coordinate.getXPoint()*1.95;
	coord.Y = 20 - coordinate.getYPoint();
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord);
}

void Point::setCursorAt(int placeCorX, int placeCorY)
{
	COORD coord;
	coord.X = placeCorX;
	coord.Y = placeCorY;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord);
}
