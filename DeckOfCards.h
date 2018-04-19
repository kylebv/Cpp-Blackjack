/*Name: Kyle Vincent
Course: SENG1120
Student no.: 3166360*/

#ifndef KYLE_DECKOFCARDS_H_
#define KYLE_DECKOFCARDS_H_
#include <iostream>
#include "LinkedList.h"
#include "Card.h"

using namespace std;
using namespace kyle_assignment_2;

namespace kyle_assignment_2
{
	class DeckOfCards
	{
		private:
			LinkedList<Card>* deck;
			
		public:
			//Constructor
			
			/* Precondition:
			Postcondition: An instance od DeckOfCards has been created, creating 52 nodes in a LinkedList
			called deck. The data of each Node is set to a Card, representing a unique playing card */
			DeckOfCards();
			
			
			//Destructor
			
			/* Precondition: An instance of DeckOfCards called deck has been created
			Postcondition: deck is deleted */
			~DeckOfCards();
			
			
			//Accessor member functions
			
			/* Precondition: An instance of DeckOfCards called deck has been created
			Postcondition: The face of each Card in each Node of deck is printed sequentially in a single string, 
			separated by a space */
			string value();
			
			/* Precondition: An instance of DeckOfCards called deck has been created
			Postcondition: The number of Nodes in the deck is returned */
			int length();
			
			/* Precondition: An instance of DeckOfCards called deck has been created
			Postcondition: Checks how many Nodes are in deck, and returns false if there
			are more than zero, and true if there aren't */
			bool empty();
			
			/* Precondition: An instance of DeckOfCards called deck has been created
			Postcondition: The index of _data in the LinkedList deck is returned, if it is
			not present, -1 is returned instead */
			int position(const Card& _data);
			
			
			//Mutator member functions 
			
			/* Precondition: An instance of DeckOfCards called deck has been created
			Postcondition: deck is searched for a Node with data of _data. If it
			is found, the Node is deleted, and the 2 nodes either side are connected, and true
			is returned. Else, nothing is deleted, andfalse is returned */ 
			bool remove(const Card& _data);
			
			/* Precondition: An instance of DeckOfCards called deck has been created, rand has been seeded
			Postcondition: All Nodes in deck are randomised according to the Yates algorithm */
			void shuffle();
			
			/* Precondition: An instance of DeckOfCards called deck has been created
			Postcondition: the head of deck is set to current, and a temporary Card is created that
			copies the data of the head. The head is then removed from deck, and the temporary Card is returned */
			Card pop();
			
			/* Precondition: An instance of DeckOfCards called deck has been created
			Postcondition: A Node with data _card is inserted at the head of deck */
			void push(Card& _card);
			
			
			//Overloaded operators
			
			/* Precondition: An instance of DeckOfCards has been created, <iostream>
			has been included
			Postcondition: value() is called on _deck, and the result is returned */
			friend ostream& operator<<(ostream& out, DeckOfCards& _deck);
	};
}
#endif