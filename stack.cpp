//Aaron Lincoln
//
//
//Abstract data type that takes data in
//from the card class.Stored in first in last
//out structure. Data is held in a 
//linear linked list and each nodes data member
//is an array of length 5. Data is pushed on the 
//stack staring with the first node and the first
//element of the array then added to the next 
//element until the array is full. When the array
//is full a new node is inserted before head and process
//repeats. Elements can be poped off the top of the 
//stack. Peek allows us to see the top of the stack
//without altering it. Can display all data in the stack
//for testing purposes.

#include "stack.h"

//Constructor
stack::stack(void)
{
    head = NULL;
    top_index = 0;
}

//Destructor
stack::~stack(void)
{
    node * temp;
    if(!head)
        return;
    while(head)
    {
        temp = head -> next;
        delete [] head -> data;
        delete head;
        head = temp;
    }
}

//Takes the arguments data and makes 
//a deep copy of the data into the linear
//linked list of arrays.Data is added to
//the first element of the head nodes data
//array then the second until the array is 
//full. When the array is full a new node 
//is inserted before head and becomes the 
//new head. The top_index is then reset to 
//zero and data is added to that element.
int stack::push( const card & to_add )
{
    node * current;
    
    if(!head)
    {
        head = new node;
        //Array of data of size MAX
        head -> data = new card[MAX];
        head -> data[top_index++].copy(to_add);
        head -> next = NULL;
        return 1;
    }
    if(top_index == MAX)
    {
        top_index = 0;
        current = new node;
        current -> data = new card[MAX];
        current -> next = head;
        head = current;
        head -> data[top_index++].copy(to_add);
        return 1;
    }
    if(top_index < MAX)
    {
        head -> data[top_index++].copy(to_add);
        return 1;
    }
    return 0; //Failed
}

//Decrements the index by 1 so that the
//data contained in the array will not be
//displayed and will instead be written over
//the next time an item is pushed. If index
//is less than 1 the array and head are
//deallocated and the next node is the new
//head, the index is then reset to the MAX
//constant.
int stack::pop(void)
{
    node * temp;
    
    if(!head)
        return 0;
    if(top_index < 1) 
    {
        temp = head -> next;
        delete [] head -> data;
        delete head;
        head = temp;
        top_index = MAX;
    }
    else
        --top_index;
 	return 1;
}
//Returns 0 if no data. Returns data 
//found at the top to
int stack::peek( card & at_top)
{
    int temp_index = top_index;

    if(top_index == 0 || !head)
        return 0;
    at_top.copy( head -> data[--temp_index]);
    return 1;
}

//Displays all data in stack starting
//with the last pushed item.
int stack::display(void)
{
    int temp_index = top_index; //temp index so
                            //top_index is not altered.
    node * current = head;

    if(!head)
        return 0;
    if(!current -> next && temp_index == 0)
        return 0;
    while(current)
    {
        --temp_index;
        if(temp_index < 1)
        {
            current -> data[temp_index].display_all();
            current = current -> next;
            temp_index = MAX;
        }
        if(temp_index >= 1 && current)
            current -> data[temp_index].display_all();
    }
    return 1;
}
