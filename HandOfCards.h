/*Name: Kyle Vincent
Course: SENG1120
Student no.: 3166360*/

#ifndef KYLE_HANDOFCARDS_H_
#define KYLE_HANDOFCARDS_H_
#include <iostream>
#include "LinkedList.h"
#include "Card.h"

using namespace std;
using namespace kyle_assignment_2;

namespace kyle_assignment_2
{
	class HandOfCards
	{
		private:
			LinkedList<Card>* hand;
		public:
			//Constructor
			
			/* Precondition:
			Postcondition: An instance of HandOfCards has been created, creating a Linked List of type Card 
			called hand */
			HandOfCards();
			
			
			//Destructor
			
			/* Precondition: An instance of HandOfCards called hand has been created
			Postcondition: hand is deleted */
			~HandOfCards();
			
			
			//Accessor member functions
			
			/* Precondition: An instance of HandOfCards has been created
			Postcondition: The data in each Node of hand is printed sequentially in a single string, 
			separated by a space, with face down cards being printed as "?-?" */
			string value() const;
			
			/* Precondition: An instance of HandOfCards has been created
			Postcondition: The value of each face up Card in each Node of hand is summed and returned*/
			int count() const;
			
			/* Precondition: An instance of HandOfCards has been created
			Postcondition: The value of each Card in each Node of hand is summed and returned*/
			int countAll() const;

			
			//Mutator member functions 
			
			/* Precondition: An instance of HandOfCards has been created
			Postcondition: Each Card in the Nodes of hand have their faceUp values set to true */
			void faceUp();
			
			/* Precondition: An instance of HandOfCards has been created
			Postcondition:  _card's faceUp is set to true, then _card's data is appended onto hand */
			void add(Card _card, bool _faceUp);
			
			//Overloaded operators
			
			/* Precondition: An instance of HandOfCards has been created, <iostream>
			has been included
			Postcondition: value() is called on _hand, and the result is returned */
			friend ostream& operator<<(ostream& out, const HandOfCards& _hand);
	};
}
#endif