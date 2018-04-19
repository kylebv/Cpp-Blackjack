/*Name: Kyle Vincent
Course: SENG1120
Student no.: 3166360*/

#ifndef KYLE_CARD_H
#define KYLE_CARD_H
#include <string>

using namespace std;

namespace kyle_assignment_2
{
	class Card
	{
		public:
			//Construct/Destruct
			
			/* Pre-condition:
			Post-condition: a new instance of Card is created, face is set to "",
			value is set to 0, and faceUp is set to false */
			Card();
			
			/* Pre-condition:
			Post-condition: a new instance of Card is created, face is set to _face,
			value is set to _value, and faceUp is set to false */
			Card(string _face, int _value);
			
			/* Pre-condition: An instance of Card has been created 
			Post-condition:*/
			~Card();
			
			//Accessors
			
			/* Pre-condition: An instance of Card has been created
			Post-condition: Face is returned  */
			string getFace() const;
			
			/* Pre-condition: An instance of Card has been created
			Post-condition: Value is returned  */
			int getValue() const;
			
			/* Pre-condition: An instance of Card has been created
			Post-condition: FaceUp is returned  */
			bool getFaceUp() const;
			
			//Mutators
			
			/* Pre-condition: An instance of Card has been created
			Post-condition: Face is set to _face  */
			void setFace(string _face);
			
			/* Pre-condition: An instance of Card has been created
			Post-condition: value is set to _value  */
			void setValue(int _value);
			
			/* Pre-condition: An instance of Card has been created
			Post-condition: faceUp is set to _faceUp  */
			void setFaceUp(bool _faceUp);
			
			//Overloaded operators
			
			/* Pre-condition: An instance of Card has been created, <iostream> has been included
			Post-condition:  getFace() is called on _Card, and the result is returned */
			friend ostream& operator <<(ostream& os, const Card& _Card);
			
			/* Pre-condition: An instance of Card has been created, <iostream> has been included
			Post-condition:  getFace() is called on c1 and c2, and the comparison of them is returned */
			friend bool operator ==(const Card& c1, const Card& c2);
		
		private:
			string face;
			int value;
			bool faceUp;
	};
}
#endif