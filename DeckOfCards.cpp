/*Name: Kyle Vincent
Course: SENG1120
Student no.: 3166360*/

#include <iostream>
#include <cstdlib>
#include "DeckOfCards.h"

using namespace std;
using namespace kyle_assignment_2;

namespace kyle_assignment_2
{
	DeckOfCards::DeckOfCards()
	{
		deck = new LinkedList<Card>();
		//the data is set for the first Node
		Card S2 = Card(std::string("2-S"), 2);
		deck->list_node_set_data(S2);
		//and each Node is sequentially added onto the end of the list one at a time to make a deck
		//of 52 cards. The deck is then shuffled
		Card S3 = Card(std::string("3-S"), 3);
		push(S3);
		Card S4 = Card(std::string("4-S"), 4);
		push(S4);
		Card S5 = Card(std::string("5-S"), 5);
		push(S5);
		Card S6 = Card(std::string("6-S"), 6);
		push(S6);
		Card S7 = Card(std::string("7-S"), 7);
		push(S7);
		Card S8 = Card(std::string("8-S"), 8);
		push(S8);
		Card S9 = Card(std::string("9-S"), 9);
		push(S9);
		Card S10 = Card(std::string("10-S"), 10);
		push(S10);
		Card SJ = Card(std::string("J-S"), 10);
		push(SJ);
		Card SQ = Card(std::string("Q-S"), 10);
		push(SQ);
		Card SK = Card(std::string("K-S"), 10);
		push(SK);
		Card SA = Card(std::string("A-S"), 11);
		push(SA);
		Card H2 = Card(std::string("2-H"), 2);
		push(H2);
		Card H3 = Card(std::string("3-H"), 3);
		push(H3);
		Card H4 = Card(std::string("4-H"), 4);
		push(H4);
		Card H5 = Card(std::string("5-H"), 5);
		push(H5);
		Card H6 = Card(std::string("6-H"), 6);
		push(H6);
		Card H7 = Card(std::string("7-H"), 7);
		push(H7);
		Card H8 = Card(std::string("8-H"), 8);
		push(H8);
		Card H9 = Card(std::string("9-H"), 9);
		push(H9);
		Card H10 = Card(std::string("10-H"), 10);
		push(H10);
		Card HJ = Card(std::string("J-H"), 10);
		push(HJ);
		Card HQ = Card(std::string("Q-H"), 10);
		push(HQ);
		Card HK = Card(std::string("K-H"), 10);
		push(HK);
		Card HA = Card(std::string("A-H"), 11);
		push(HA);
		Card C2 = Card(std::string("2-C"), 2);
		push(C2);
		Card C3 = Card(std::string("3-C"), 3);
		push(C3);
		Card C4 = Card(std::string("4-C"), 4);
		push(C4);
		Card C5 = Card(std::string("5-C"), 5);
		push(C5);
		Card C6 = Card(std::string("6-C"), 6);
		push(C6);
		Card C7 = Card(std::string("7-C"), 7);
		push(C7);
		Card C8 = Card(std::string("8-C"), 8);
		push(C8);
		Card C9 = Card(std::string("9-C"), 9);
		push(C9);
		Card C10 = Card(std::string("10-C"), 10);
		push(C10);
		Card CJ = Card(std::string("J-C"), 10);
		push(CJ);
		Card CQ = Card(std::string("Q-C"), 10);
		push(CQ);
		Card CK = Card(std::string("K-C"), 10);
		push(CK);
		Card CA = Card(std::string("A-C"), 11);
		push(CA);
		Card D2 = Card(std::string("2-C"), 2);
		push(D2);
		Card D3 = Card(std::string("3-D"), 3);
		push(D3);
		Card D4 = Card(std::string("4-D"), 4);
		push(D4);
		Card D5 = Card(std::string("5-D"), 5);
		push(D5);
		Card D6 = Card(std::string("6-D"), 6);
		push(D6);
		Card D7 = Card(std::string("7-D"), 7);
		push(D7);
		Card D8 = Card(std::string("8-D"), 8);
		push(D8);
		Card D9 = Card(std::string("9-D"), 9);
		push(D9);
		Card D10 = Card(std::string("10-D"), 10);
		push(D10);
		Card DJ = Card(std::string("J-D"), 10);
		push(DJ);
		Card DQ = Card(std::string("Q-D"), 10);
		push(DQ);
		Card DK = Card(std::string("K-D"), 10);
		push(DK);
		Card DA = Card(std::string("A-D"), 11);
		push(DA);
		shuffle();
	}
	
	DeckOfCards::~DeckOfCards()
	{
		delete deck;
	}
	
	void DeckOfCards::push(Card& _card)
	{
		deck->list_head_insert(_card);
	}
	
	Card DeckOfCards::pop()
	{
		//current is set to the head node
		deck->list_set_current(0);
		//a temporary Card is created form the head node
		Card temp = deck->list_node_get_data();
		//the head node is removed, and its data returned
		deck->list_remove_head();
		return temp;
	}
	
	void DeckOfCards::shuffle()
	{
		int i,j;
		//for every index in the DeckOfCards, starting at j and decreasing
		for(j = deck->list_length();j>0;j--)
		{
			//j is the highest indice in the linked list on the first loop, and the
			//maximum indice on each sequential loop
			//j+1 indicates that the random number 'i' will be generated between 1 and j-1
			i=rand() % (j+1);
			//the current node is set to the jth node
			deck->list_set_current(j);
			//and its data is retrieved and stored as data_j
			Card data_j = deck->list_node_get_data();
			//the current node is set to the ith node
			deck->list_set_current(i);
			//its data is retrieved and stored as data_i
			Card data_i = deck->list_node_get_data();
			//the data in the ith node is set to data_j
			deck->list_node_set_data(data_j);
			//the current node is set back to the jth node
			deck->list_set_current(j);
			//the data in the jth node is set to data_i
			deck->list_node_set_data(data_i);
		}
	}
	
	int DeckOfCards::length()
	{
		//1 is added as the return result would give the highest index number
		return deck->list_length()+1;
	}
	
	bool DeckOfCards::empty()
	{
		if (deck->list_length()==0){return true;}
		else{return false;}
	}
	
	int DeckOfCards::position(const Card& _data)
	{
		int _position = deck->list_search(_data);
		return _position;
	}
	
	string DeckOfCards::value()
	{
		//a blank string is initialised
		string card_sequence = "";
		for(int counter=0;counter<=deck->list_length();counter++)
		{
			//starting at the first index, current is set to said index
			deck->list_set_current(counter);
			//and the data is appended onto the end of card_sequence
			card_sequence.append((deck->list_node_get_data()).getFace()+" ");
		}
		return card_sequence;
	}
	
	ostream& operator<<(ostream& out, DeckOfCards& _deck)
	{
		out << _deck.DeckOfCards::value();
		return out;
	}
	
	bool DeckOfCards::remove(const Card& _data)
	{
		//the deck is searched for _data, and its index is returned, or if
		//not found, -1 is returned
		int _position = deck->list_search(_data);
		if (_position==-1){return false;}
		else
		{
			//if a real index was returned, current is set to said index
			deck->list_set_current(_position);
			//if that index is the head, the head is removed
			if(_position==0){deck->list_remove_head();}
			//if that index is the tail, the tail is removed
			else if(_position==deck->list_length()){deck->list_remove_tail();}
			//if it is another index, that Node is removed
			else{deck->list_remove_node();}
			return true;
		}
	}
}