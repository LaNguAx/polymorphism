#include "Quad.h"

Quad::Quad(double up, double down, double right, double left, const char* sn)
	: Shape(sn)
{
	m_up = up;
	m_down = down;
	m_right = right;
	m_left = left;
}
//constructor. center point = (0,0), name=sn

Quad::Quad(const Quad& other) : Shape(other.getName()) {

	m_up = other.m_up;
	m_down = other.m_down;
	m_right = other.m_right;
	m_left = other.m_left;
}		//copy constructr

Quad::~Quad(){}				//destructor

int Quad::calcArea() const{
		
	return m_right * m_up;

}	//returns the quad's area (right*up) (rounded to int)

int Quad::calcPerimeter() const{

	return m_right + m_left + m_up + m_down;

}//returns the quad's Perimeter (the sum of the four ribs) (rounded to int)
