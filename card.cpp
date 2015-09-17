//Aaron Lincoln
//
//
//Adds question and answer to the card class
//can display question, display question and
//answer, and check for a matching answer.

#include "card.h"
using namespace std;

//Constructor
card::card(void)
{
    question = new char[500];
    answer = new char[200];
}

//Destructor
card::~card(void)
{
    delete [] question;
    delete [] answer;
}

//Add question and answer arguments to the data 
//members in the class card.
int card::add_card( char * question, char * answer)
{
    card to_copy; //card class to copy data from
    
    to_copy.question = question;
    to_copy.answer = answer;
    copy( to_copy); //copies to_copy's data members
                    //to class data members.
    return 1;
}

//Deep copy of the arguments data members to 
//the class data members.
int card::copy(const card & new_card)
{
    if(!new_card.question || !new_card.answer)
        return 0;
    if(question)
        delete [] question;
    question = new char[strlen(new_card.question) + 1];
    strcpy(question, new_card.question);
    if(answer)
        delete [] answer;
    answer = new char[strlen(new_card.answer) + 1];
    strcpy(answer, new_card.answer);
    return 1;

}

//Displays the question data member.
int card::display(void)
{
    cout << "Q: " << question << "?\n";
    return 1;
}

//Displays the question and answer
//data member
int card::display_all(void)
{

    cout << "Q: " << question << "?\n"
         << "\tA: " << answer << endl;
    return 1;
}


//Returns 1 if answer matches the answer provided
//by the card question. Returns 0 otherwise.
int card::match( char * u_answer)
{
    if( strcmp(u_answer, answer) == 0)
        return 1;
    else
        return 0;
}


