#include "allShapes.h"
#include "Circle.h"
#include "Quad.h"
#include "Square.h"

allShapes::allShapes() : m_arr(nullptr), m_size(0) {}					//constructor, zero elements
allShapes::allShapes(const allShapes& other) {

	for (int i = 0; i < other.m_size; i++)
		this->addShape(other.m_arr[i]);

} //copy c'tor - deep copy
allShapes::~allShapes(){

	//for (int i = 0; i < m_size; i++)
	//	delete m_arr[i];
	//delete[] m_arr;

	//m_arr = nullptr;

}					//destructor to all elements


int allShapes::getSize() const { return m_size; }		//returns the number of shapes;

void allShapes::addShape(Shape* newShape) {

	int size = this->getSize();

	Shape** temp = new Shape * [size + 1];

	// copy everything to temp
	for (int i = 0; i < size; i++) {
		if (typeid(*m_arr[i]) == typeid(Circle))
			temp[i] = new Circle(*(Circle*)m_arr[i]);

		else if (typeid(*m_arr[i]) == typeid(Square))
			temp[i] = new Square(*(Square*)m_arr[i]);

		else if (typeid(*m_arr[i]) == typeid(Quad))
			temp[i] = new Quad(*(Quad*)m_arr[i]);
	}
	
	if (typeid(*newShape) == typeid(Circle))
		temp[size] = new Circle(*(Circle*)newShape);
	else if (typeid(*newShape) == typeid(Square))
		temp[size] = new Square(*(Square*)newShape);
	else if (typeid(*newShape) == typeid(Quad))
		temp[size] = new Quad(*(Quad*)newShape);

	// delete old array
	for (int i = 0; i < size; i++)
		delete m_arr[i];
	delete[] m_arr;
	
	m_arr = temp;
	++m_size;


}	//add a new shape (deep copy) to the end of array

void allShapes::removeShape(int index) {

	int size = this->getSize();
	Shape** temp = new Shape * [size - 1];

	// copy everything to temp except index
	int k = 0;
	for (int i = 0; i < size; i++) {
		if (i == index) continue;

		if (typeid(*m_arr[i]) == typeid(Circle))
			temp[k++] = new Circle(*(Circle*)m_arr[i]);

		else if (typeid(*m_arr[i]) == typeid(Square))
			temp[k++] = new Square(*(Square*)m_arr[i]);

		else if (typeid(*m_arr[i]) == typeid(Quad))
			temp[k++] = new Quad(*(Quad*)m_arr[i]);
	}

	// delete old array
	for (int i = 0; i < size; i++)
		delete m_arr[i];
	delete[] m_arr;

	m_arr = temp;
	--m_size;

}//remove shape by index

int allShapes::totalArea() const{
	
	int totalArea = 0;

	for (int i = 0; i < m_size; i++)
	{
		totalArea += m_arr[i]->calcArea();
	}
	return totalArea;
}		//returns the total area of all the shapes (rounded to int)

int allShapes::totalPerimeter() const{
	int totalPerimeter = 0;

	for (int i = 0; i < m_size; i++)
	{
		totalPerimeter += m_arr[i]->calcPerimeter();
	}
	return totalPerimeter;

	
}	//returns the total Perimeter of all the shapes (rounded to int)

int allShapes::totalCircleArea() const{

	int totalAreaCircles = 0;
	for (int i = 0; i < m_size; i++) {
		if (typeid(*m_arr[i]) == typeid(Circle))
			totalAreaCircles += m_arr[i]->calcArea();
	}
	return totalAreaCircles;
}//returns the total sum of circle areas (rounded to int)

int allShapes::totalSquarePerimeter() const {
	int totalAreaSquares = 0;

	for (int i = 0; i < m_size; i++) {
		if (typeid(*m_arr[i]) == typeid(Square))
			totalAreaSquares += m_arr[i]->calcPerimeter();
	}
	return totalAreaSquares;



}	//returns the total sum of squar Perimeter (rounded to int)

const allShapes& allShapes::operator+=(Shape* newS){

	this->addShape(newS);

	return *this;
}		//adds a new shape

Shape* allShapes::operator[](int ind) const{

	if (ind >= m_size || ind < 0) return nullptr;

	return m_arr[ind];

}				//returns the shape located at index ind

allShapes allShapes::operator+(const allShapes& other) const {

	int allSize = this->getSize() + other.getSize();

	allShapes temp;
	int k;
	for (int i = 0,k = 0; i+k < allSize; i++,k++) {
		temp.addShape(other.m_arr[i]);
		temp.addShape(this->m_arr[k]);
	}
	return temp;
}	//returns a new allShape with all elements located at this and other

allShapes::operator int() const { return m_size; }
							//returns the number of elements	
