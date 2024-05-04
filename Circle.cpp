#include "Circle.h"

Circle::Circle(double r, const char* sn) 
	: Shape(sn)
{

	cout << "circle ctor " << endl;
	this->setRadius(r);
}	//create a circle with radius=1, name=sn and center=(0,0)

Circle::Circle(const Circle& other) : Shape(other){
	
	*this = other;
}					//copy constructor

Circle::~Circle(){

	cout << "circle dtor" << endl;
}								//destructor


double Circle::getRadius() const { return m_radius; }						//returns the circle's radius

void Circle::setRadius(double r) { m_radius = r; }						//set the radius

int Circle::calcArea() const{

	return m_radius * m_radius * PI;
}					//returns the circle's area (rounded to int)

int Circle::calcPerimeter() const{

	return 2 * PI * this->getRadius();

}				//returns the circle's Perimeter (rounded to int)

const Circle& Circle::operator=(const Circle& other){

	if (this == &other) return *this;

	this->setRadius(other.getRadius());
	this->setName(other.getName());
	return *this;

}		//operator= that copies all

const Circle& Circle::operator=(const char* name){

	this->setName(name);
	return *this;
}		//updates only the name of the shape and returns the updated shape

Circle operator+(int r, const Circle& other){

	return Circle(r + other.getRadius());

}//returns a new Circle with added radius