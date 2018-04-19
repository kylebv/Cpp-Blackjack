/*Name: Kyle Vincent
Course: SENG1120
Student no.: 3166360*/

#include "Card.h"

using namespace std;
using namespace kyle_assignment_2;

namespace kyle_assignment_2
{
	//Construct/Destruct
	Card::Card()
	{
		face = "";
		value = 0;
		faceUp = false;
	}
	
	Card::Card(string _face, int _value)
	{
		face = _face;
		value = _value;
		faceUp = false;
	}
	
	Card::~Card(){}
	
	//Accessors
	string Card::getFace() const
	{
		return face;
	}
	
	int Card::getValue() const
	{
		return value;
	}
	
	bool Card::getFaceUp() const
	{
		return faceUp;
	}
	
	//Mutators
	void Card::setFace(string _face)
	{
		face = _face;
	}
	
	void Card::setValue(int _value)
	{
		value = _value;
	}
	
	void Card::setFaceUp(bool _faceUp)
	{
		faceUp = _faceUp;
	}
	
	//Overloaded operators
	ostream& operator <<(ostream& os, const Card& _Card)
	{
		return os << _Card.getFace();
	}
	
	bool operator ==(const Card& c1, const Card& c2)
	{
		return c1.getFace()==c2.getFace();
	}
}