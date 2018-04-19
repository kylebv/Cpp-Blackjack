/*Name: Kyle Vincent
Course: SENG1120
Student no.: 3166360*/

#include <iostream>
#include "HandOfCards.h"

using namespace std;
using namespace kyle_assignment_2;

namespace kyle_assignment_2
{
	HandOfCards::HandOfCards()
	{
		hand = new LinkedList<Card>();
	}

	HandOfCards::~HandOfCards()
	{
		delete hand;
	}
	
	string HandOfCards::value() const
	{
		//a blank string is initialised
		string card_sequence = "";
		for(int counter=0;counter<hand->list_length();counter++)
		{
			//starting at the first index, current is set to said index
			hand->list_set_current(counter);
			//and the data is appended onto the end of card_sequence if Card is face up
			if((hand->list_node_get_data()).getFaceUp())
			{
				card_sequence.append((hand->list_node_get_data()).getFace()+" ");
			}
			//else, "?-?" is appended instead
			else
			{
				card_sequence.append("?-? ");
			}
		}
		return card_sequence;
	}
	
	int HandOfCards::count() const
	{
		int count = 0;
		for(int counter=0;counter<hand->list_length();counter++)
		{
			//starting at the first index, current is set to said index
			hand->list_set_current(counter);
			//and the data is added to count
			if((hand->list_node_get_data()).getFaceUp())
			{
				count += (hand->list_node_get_data()).getValue();
			}
		}
		return count;
	}
	
	int HandOfCards::countAll() const
	{
		int count = 0;
		for(int counter=0;counter<hand->list_length();counter++)
		{
			//starting at the first index, current is set to said index
			hand->list_set_current(counter);
			//and the data is added to count
			count += (hand->list_node_get_data()).getValue();
		}
		return count;
	}

	void HandOfCards::faceUp()
	{
		for(int counter=0;counter<hand->list_length();counter++)
		{
			//starting at the first index, current is set to said index
			hand->list_set_current(counter);
			//and the data is modified
			Card temp = hand->list_node_get_data();
			temp.setFaceUp(true);
			hand->list_node_set_data(temp);
		}
	}
	
	void HandOfCards::add(Card _card, bool _faceUp)
	{
		_card.setFaceUp(_faceUp);
		hand->list_append(_card);
	}
	
	ostream& operator<<(ostream& out, const HandOfCards& _hand)
	{
		out << _hand.value();
		return out;
	}
}