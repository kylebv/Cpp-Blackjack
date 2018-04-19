/*Name: Kyle Vincent
Course: SENG1120
Student no.: 3166360*/

#include <iostream> // for cout and endl
#include <cstdlib>  // for srand, rand and atoi
#include <ctime>    // for time
#include "DeckOfCards.h"
#include "HandOfCards.h"

using namespace std;
using namespace kyle_assignment_2;

int main(int argc, char* argv[]) 
{
    /* The following if-else code was taken from the demo file provided on 
	blackboard, it seeds the rand generator */
    if (argc >= 2) 
	{
        int seed = atoi(argv[1]);
        srand(seed);
    }
    else 
	{
        int seed = time(NULL);
        srand(seed);
    }
	
	cout << "Welcome to Blackjack!" << endl << endl;
	
	//the deck and players are established
	DeckOfCards* gamedeck = new DeckOfCards();
	HandOfCards* dealer = new HandOfCards();
	HandOfCards* player1 = new HandOfCards();
	
	cout << "Let's Play." << endl << endl;
	
	//first turn of the game, each player is given a card, then another card, with the dealer's 2nd facing down
	cout << "Player 1 is dealt 1 card, face up." << endl << endl;
	player1->add(gamedeck->pop(), true);
	cout << "Dealer is dealt 1 card, face up." << endl << endl;
	dealer->add(gamedeck->pop(), true);
	cout << "Player 1 is dealt 1 card, face up." << endl << endl;
	player1->add(gamedeck->pop(), true);
	cout << "Dealer is dealt 1 card, face down." << endl << endl << endl;
	dealer->add(gamedeck->pop(), false);
	
	//input int in is initialised as zero
	int in = 0;
	
	//while the player hasn't chosen to Stand, the following loop will execute
	while(in!=2)
	{
		//if player chose to Hit, he is dealt 1 card
		if(in==1)
		{
			cout << "Player 1 is dealt 1 card, face up." << endl << endl;
			player1->add(gamedeck->pop(), true);
		}
		
		//the hand and points of each player is displayed
		cout << "Player 1: " << *player1 << "(" << player1->count() <<" points)" << endl;
		cout << "Dealer: " << *dealer << "(" << dealer->count() <<" points)" << endl << endl << endl;
		
		//if both player and dealer hit blackjack, reveal both hands, announce a tie and exit
		if(player1->count()==21 && dealer->countAll()==21)
		{
			dealer->faceUp();
			cout << "Both players have Blackjack!" << endl;
			cout << "Player 1: " << *player1 << "(" << player1->count() <<" points)" << endl;
			cout << "Dealer: " << *dealer << "(" << dealer->count() <<" points)" << endl << endl << endl;
			cout << "Tie! There are no winners.";
			return 0;
		}
		//if player has blackjack but dealer has not, announce player won and exit
		else if(player1->count()==21)
		{
			cout << "The player is the winner!";
			return 0;
		}
		//if dealer has blackjack but player has not, announce dealer won and exit
		else if(dealer->countAll()==21)
		{
			dealer->faceUp();
			cout << "The dealer has Blackjack!" << endl;
			cout << "Player 1: " << *player1 << "(" << player1->count() <<" points)" << endl;
			cout << "Dealer: " << *dealer << "(" << dealer->count() <<" points)" << endl << endl << endl;
			cout << "The dealer is the winner!";
			return 0;
		}
		//if dealer has busted (double aces - it can happen) but the player has not, announce player wins and exit
		else if(player1->count()<=21 && dealer->countAll()>21)
		{
			cout << "The player is the winner!";
			return 0;
		}
		//if both players bust (an infinitestimal chance), announce a tie and exit
		else if(player1->count()>21 && dealer->countAll()>21)
		{
			dealer->faceUp();
			cout << "Both players bust!" << endl;
			cout << "Player 1: " << *player1 << "(" << player1->count() <<" points)" << endl;
			cout << "Dealer: " << *dealer << "(" << dealer->count() <<" points)" << endl << endl << endl;
			cout << "Tie! There are no winners.";
			return 0;
		}
		//if player busts and dealer does not, announce dealer won and exit
		else if(player1->count()>21)
		{
			cout << "The dealer is the winner!";
			return 0;
		}
		
		//else, ask player whether they want to Hit or Stand
		cout << "Do you want to Hit(1) or Stand(2)?" << endl;
		
		//if cin fails...
		try 
		{
			cin >> in;
			if(cin.fail()){throw 0;}
		}
			
		//..kill the program
		catch(int i)
		{
			cout << "Exception: Invalid input. The program will now close." << endl;
			return -1;
		}
		
		//double spacing for readability
		cout << endl << endl;
	}
	
	//after the player has chosen to Stand, the dealer's pseudo-AI will execute
	if(dealer->countAll()<=16)
	{
		//if the dealer's hand does not equal greater than 16, it will keep
		//drawing cards until its hand does
		while(dealer->countAll()<=16)
		{
			cout << "Dealer is dealt 1 card, face up." << endl << endl << endl;
			dealer->add(gamedeck->pop(), true);
		}
	}
	
	//then all of the dealer's cards are turned face up
	dealer->faceUp();
	//and each player's hands are revealed
	cout << "Player 1: " << *player1 << "(" << player1->count() <<" points)" << endl;
	cout << "Dealer: " << *dealer << "(" << dealer->count() <<" points)" << endl << endl << endl;
	
	//if both the player and dealer have the same amount of points, announce a tie and exit
	if(player1->count()==dealer->count())
	{
		cout << "Tie! There are no winners.";
		return 0;
	}
	//if the dealer's points are higher than the player's and the dealer hasn't busted, announce the dealer wins and exit
	else if(player1->count()<dealer->count() && dealer->count()<=21)
	{
		cout << "The dealer is the winner!";
		return 0;
	}
	//if the player's points are higher than the dealer's, or if the dealer has busted, announce the player wins and exit
	else
	{
		cout << "The player is the winner!";
		return 0;
	}
}