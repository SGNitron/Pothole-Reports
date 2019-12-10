#include "Point.h"
#include <iostream>
using namespace std;
template <class TYPE>
Point<TYPE>::Point() {
	mX = 0;
	mY = 0;
}

template <class TYPE>
Point<TYPE>::Point(TYPE inX, TYPE inY) : mX(inX), mY(inY) {
	/*mX = inX;
	mY = inY;*/

}

template <class TYPE>
TYPE Point<TYPE>::getX() const {
	return mX;
}

template <class TYPE>
TYPE Point<TYPE>::getY() const {
	return mY;
}

template <class TYPE>
void Point<TYPE>::display() {
	cout << "(" << mX << "," << mY << ")";
}

template <class TYPE>
bool Point<TYPE>::operator==(const Point <TYPE> anEntry)const {
	return (mX == anEntry.mX && mY == anEntry.mY);
}

