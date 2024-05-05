#include "Square.h"

Square::Square(double up, double down, double right, double left, const char* sn)
	: Quad(up, down, right, left, sn)
{ }

Square::~Square() {}			//destructor

void Square::shiftX(int x) {

	this->setCenter(Point(this->getCenter().getX() + x, this->getCenter().getY()));

}		//shifts the center of the square by x (right and left)
void Square::shiftY(int y) {
	this->setCenter(Point(this->getCenter().getX(), this->getCenter().getY()+y));
}	//shifts the center of the square by y (up and down)
