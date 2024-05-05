#include "Shape.h"
int Shape::s_totalNumOfShapes = 0;

Shape::Shape(const char* sn) : m_centerPoint(0, 0), m_shapeName(nullptr) {

	this->setName(sn);
	++s_totalNumOfShapes;

}
//Creates a new shape (name=sn,centerPoint = (0,0))

Shape::Shape(const Shape& other) : m_centerPoint(other.m_centerPoint) {
	
	*this = other;
	++s_totalNumOfShapes;
}			//copy constructor of shape


Shape::~Shape() {

	//if (m_shapeName)
	//	delete[] m_shapeName;

	--s_totalNumOfShapes;



}				//shape destructor


void Shape::setName(const char* name) { 
	
	//if (m_shapeName)
	//	delete[] m_shapeName;

	m_shapeName = strdup(name); 

}	//sets the shape's name

void Shape::setCenter(const Point& p){ m_centerPoint.setPoint(p); }//sets the center point

const char* Shape::getName() const { return m_shapeName; }	//returns the shape's name

Point Shape::getCenter() const { return m_centerPoint; }		//returns the center point

void Shape::setShape(const char* sn, const Point& other) {

	this->setName(sn);
	this->setCenter(other);

} //set the shape's name and the center point

int Shape::numOfShapes() { return s_totalNumOfShapes; }		//returnS the total number of shapes

const Shape& Shape::operator=(const Shape& other) {

	if (this == &other) return *this;

	this->setName(other.getName());
	this->setCenter(other.getCenter());

	return *this;
}
//operator=
