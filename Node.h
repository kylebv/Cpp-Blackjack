/*Name: Kyle Vincent
Course: SENG1120
Student no.: 3166360*/

#ifndef KYLE_NODE_H_
#define KYLE_NODE_H_
#include <string>

using namespace std;

namespace kyle_assignment_2
{
	template <typename Item>
	class Node
	{
		public:
			//Constructors
			
			//Precondition:
			//Postcondition: a new instance of Node is created , next and prev
			//are set to NULL and data is set to ""
			Node();
			
			//Precondition:
			//Postcondition: a new instance of Node is created , next and prev
			//are set to next_node and prev_node respectively, and data is set to init_data
			Node(const Item& init_data,  Node*  next_node = NULL, Node* prev_node = NULL);
			
			//Destructor
			
			//Precondition: An instance of Node has been created
			//Postcondition: next and prev are set to NULL
			~Node();
			
			//Mutator member functions
			
			//Precondition: Instance of Node has been constructed
			//Postcondition: Sets the next of Node to next_link
			void set_next(Node* const next_link);
			
			//Precondition: Instance of Node has been constructed
			//Postcondition: Sets the prev of Node to prev_link
			void set_prev(Node* const prev_link);
			
			//Precondition: Instance of Node has been constructed
			//Postcondition: Sets the data of Node to _data
			void set_data(const Item& _data);
			
			//Accessor member functions
			
			//Precondition: Instance of Node has been constructed
			//Postcondition: Returns next 
			Node* get_next() const;
			
			//Precondition: Instance of Node has been constructed
			//Postcondition: Returns prev 
			Node* get_prev() const;
			
			//Precondition: Instance of Node has been constructed
			//Postcondition: Returns data 
			Item get_data() const;
		
		private:
			Item data;
			Node* next;
			Node* prev;
	};
}
#include "Node.template"
#endif