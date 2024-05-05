#include "Point.h"

Point::Point(int x, int y) : m_x(x), m_y(y) { }


Point::Point(const Point& other) { this->setPoint(other); }

Point::~Point(){}

int Point::getX() const { return m_x; }								//returns the x

int Point::getY() const { return m_y; }								//returns the y

void Point::setX(int x) { m_x = x; }								//sets the x

void Point::setY(int y) { m_y = y; }								//sets the y

void Point::setPoint(int x, int y) {								//sets the x and y
	this->setX(x);
	this->setY(y);
}	

void Point::setPoint(const Point& other)
{
	this->setPoint(other.getX(), other.getY());

}					//sets the point with other values
bool Point::operator==(const Point& other) const{

	if (this->getX() != other.getX() || this->getY() != other.getY()) return false;
	else
		return true;

}			//returns true if and only if the two points are equal
bool Point::operator!=(const Point& other) const{

	if (this->getX() != other.getX() || this->getY() != other.getY()) return true;
	else
		return false;

}			//returns true if and only if the two points are not equal
Point Point::operator+(int num) const{
	return Point(this->getX()*(this->getX() + num), this->getY()*(this->getY() + num));

}						//returns a new point with updated x(x+num) and y(y+num)
const Point& Point::operator+=(int num){

	this->setPoint(this->getX() + num, this->getY() + num);
	return *this;
}						//updates the point with x(x+num) and y(y+num) and returns the updated point

Point::operator int() const{
	return this->getX() + this->getY();
}									//returns the sum of x and y

Point Point::operator+(const Point& other) const{
		
	return Point(this->getX() + other.getX(), this->getY() + other.getY());

}			//adds coordinates (x,y) and returns a new point

Point Point::operator++(int){

	Point temp(*this);
	this->setPoint(this->getX() + 1, this->getY() + 1);

	return temp;
}				//adds 1 to x and y and returns the updated point - postfix

const Point& Point::operator++(){
	
	this->setPoint(this->getX() + 1, this->getY() + 1);
	return *this;
}					//adds 1 to x and y and returns the updated point - prefix

Point operator*(int num, const Point& other) { 

	return Point(num * other.getX(), num * other.getY());

}	//returns a new point with (x,y)*num

