/*Name: Kyle Vincent
Course: SENG1120
Student no.: 3166360*/

#ifndef KYLE_LINKEDLIST_H_
#define KYLE_LINKEDLIST_H_
#include "Node.h"

using namespace std;
using namespace kyle_assignment_2;

namespace kyle_assignment_2
{
	template <typename Item>
	class LinkedList
	{
		public:
			//Constructor
			
			//Precondition:
			//Postcondition: An instance of LinkedList is created head_ptr is set to a new Node
			//object, tail_ptr is set to head_ptr, listCount is set to zero, and current is set to head_ptr
			LinkedList();
			
			//Destructor
			
			//Precondition: An instance of LinkedList has been created
			//Postcondition: Each Node in the LinkedList instance has been deleted
			~LinkedList();
			
			//Accessor member functions
			
			//Precondition: An instance of LinkedList has been created
			//Postcondition: listCount is returned
			int list_length() const;
			
			//Precondition: An instance of LinkedList has been created
			//Postcondition: Function searches the LinkedList's data for input
			//and returns the index of the input data, or -1 if not found
			int list_search(const Item& input);
			
			//Precondition: An instance of LinkedList has been created
			//Postcondition: Returns data from the current Node
			Item list_node_get_data() const;
			
			//Mutator member functions
			
			//Precondition: An instance of LinkedList has been created
			//Postcondition: A new Node is created, and its next is set to head_ptr,
			//its prev is set to NULL, and head_ptr's prev is set to the new node,
			//then it becomes head_ptr. listCount is increased by 1
			void list_head_insert(const Item& added_data);
			
			//Precondition: An instance of LinkedList has been created
			//Postcondition: A new Node is created, and its next is set to current,
			//its prev is set to current->get_prev(), and current->get_prev()'s next is set to the
			//new node. currents's prev is set to the new node, and listCount is increased by 1
			void list_insert(const Item& added_data);
			
			//Precondition: An instance of LinkedList has been created
			//Postcondition: A new Node is created, and its prev is set to tail_ptr,
			//its next is set to NULL, and tail_ptr's next is set to the new node,
			//then it becomes tail_ptr. listCount is increased by 1
			void list_append(const Item& added_data);
			
			//Precondition: An instance of LinkedList has been created
			//Postcondition: current->get_prev()'s next is set to current->get_next()
			//and vice versa. current is deleted and listCount is reduced by 1
			void list_remove_node();
			
			//Precondition: An instance of LinkedList has been created
			//Postcondition: head_ptr->get_next()'s prev is set to NULL, head_ptr is deleted,
			//the aofrementioned node is set to head_ptr, and listCount is reduced by 1
			void list_remove_head();
			
			//Precondition: An instance of LinkedList has been created
			//Postcondition: tail_ptr->get_prev()'s next is set to NULL, tail_ptr is deleted,
			//the aofrementioned node is set to tail_ptr, and listCount is reduced by 1
			void list_remove_tail();
			
			//Precondition: An instance of LinkedList has been created
			//Postcondition: sets current to the Node in the position'th index
			void list_set_current(int position);
			
			//Precondition: An instance of LinkedList has been created
			//Postcondition: the data in the current node is set to _data
			void list_node_set_data(const Item& _data);
			
			
		private:
			Node<Item>* head_ptr;
			Node<Item>* tail_ptr;
			Node<Item>* current;
			int listCount;
	};
}
#include "LinkedList.template"
#endif