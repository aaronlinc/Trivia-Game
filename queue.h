//Aaron Lincoln
//
//
//The queue is an abstract data type (ADT) which stores the
//data circularly. Data is added at the bottom and
//taken off of the top. It is a first in, first out 
//data type. Enqueue adds data to the bottom. 
//Dequeue removes data from the top and also copies
//it into the argument passed. Display prints out all
//the data in the ADT starting at the top.

#include "card.h"

struct q_node
{
    card data;
    q_node * next;
};


class queue
{
    public:
        queue(void);
        ~queue(void);
        int enqueue( const card & to_add);
        int dequeue(card & at_top);
        int display(void);

    private:
        q_node * rear;
};
