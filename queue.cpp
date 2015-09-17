//Aaron Lincoln
//
//
//The queue is implemented with a circular linked
//list with a rear pointer. Enqueue adds the data 
//from the card class on the end of the CLL. Dequeue
//removes the node that rear is pointing and links up
//with the new first node. All data can be displayed
//for testing purposes.

#include "queue.h"

//Constructor
queue::queue(void)
{
    rear = NULL;
}

//Deconstructor
queue::~queue(void)
{
    q_node * t_head;
    q_node * temp;

    if(!rear)
        return;
    if( rear -> next == rear)
    {
        delete rear;
        return;
    }
    t_head = rear -> next;
    rear -> next = NULL;

    while( t_head -> next)
    {
        temp = t_head -> next;
        delete t_head;
        t_head = temp;
    }
    delete t_head;
    t_head = NULL;
}

//Takes the argument of a class and makes
//a deep copy of the data into the new node.
//Adds the node at the rear of the CLL.
int queue::enqueue( const card & to_add)
{
    q_node * temp;

    if(!rear)
    {
        rear = new q_node;
        rear -> data.copy(to_add);
        rear -> next = rear;
        return 1;
    }
    else
    {
        temp = new q_node;
        temp -> data.copy(to_add);
        temp -> next = rear -> next;
        rear -> next = temp;
        rear = temp;
        return 1;
    }
    return 0; //failure
}

//Deletes the first node in the CLL
//and points the rear to the new 
//first node. Copies the data that was
//removed into the argument. Returns
//0 if nothing to remove.
int queue::dequeue(card & at_top)
{
    q_node * temp;

    if(!rear)
        return 0;
    if(rear -> next == rear)
    {
        at_top.copy(rear -> data);
        rear = NULL;
        return 1;
    }
    if(rear -> next -> next != rear)
    {
        
        at_top.copy(rear -> next -> data);
        temp = rear -> next -> next;
        delete rear -> next;
        rear -> next = temp;
        return 1;
    }
    at_top.copy(rear -> next -> data);
    delete rear -> next;
    rear -> next = rear;
    return 1;
}

//Displays all the data in the CLL. 
int queue::display(void)
{
    if(!rear)
        return 0;
    
    q_node * temp = rear -> next;
    
    do
    {
        temp -> data.display_all();
        temp = temp -> next;
    }while( temp != rear -> next);
    return 1;
}

