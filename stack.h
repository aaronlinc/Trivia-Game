//Aaron Lincoln
//
//
//This class implements an abstract data type (ADT)
//called a stack. Data is stored in a first in last out
//method. Push adds to the top of the stack and pop removes
//the last thing pushed. Peek returns 1 if there is data 
//at the top of the stack and 0 otherwise, it also copies
//the data at the top into the argument of peek. Display
//is for displaying all data in the stack starting with
//the last item pushed.

#include "card.h"

struct node
{
    card * data;
    node * next;
};


const int MAX = 5;

class stack
{
    public:
        stack(void);
        ~stack(void);
        int push( const card & to_add);
        int pop();
        int peek(card & at_top);
        int display(void);
    
    private:
        node * head;
        int top_index;
};
