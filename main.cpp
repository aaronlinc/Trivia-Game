//Aaron Lincoln
//
//
//Trivial Pursuit type card game.
//Loads all question and answer data into a queue
//which is called the deck. User answers questions from
//the deck or discard pile. If answered correctly question
//is placed at bottom of deck (queue). Incorrect answers go on the 
//top of the discard pile (stack). When score of 5 points is 
//reached the game is over.

#include <fstream>
#include "queue.h"
#include "stack.h"
using namespace std;

//Prototypes
int load_cards(card & new_card, queue & to_add );
int lower_answer( char * answer);

int main()
{
    card new_card, found;
    queue deck;
    stack discard;
    char * u_answer = new char [50];
    char response;
    int score = 0;
    char * question = new char[300];
    
    
    //Load deck of cards from external file.
    load_cards( new_card, deck);
    cout << "Score 5 points and you win!!!!\nAnswer the following:\n";    
    do
    {
        //Checks for card in discard pile displays that
        //questino if available.
        if(!discard.peek(found))
        {
            cout << "\nThere are no cards in the discard pile.\n";
            response = 'd';
        }
        if(discard.peek(found))
        {
            cout << "Question on discard pile: ";
            found.display();
            cout << "\nChoose question from discard pile or deck (p,d): ";
            cin >> response; cin.ignore(100, '\n');
        }
        
        //Checks user response and loads card from
        //discard pile or deck.
        if( tolower(response) == 'd')
        {    
            if(!deck.dequeue(found)) //If deck is empty reponse get the value 'p'
            {
                cout <<"\nSorry the deck is empty!\nHere is the discarded question:\n";
                response = 'p';
            }
        
        }
        if(tolower(response) == 'p')
        {
            discard.peek(found);
            discard.pop();
        }
        
        //Displays question and determines correct or wrong 
        //answer.
        found.display();
        cout << "\tA: ";
        cin.get(u_answer, 50, '\n');
        cin.ignore(100, '\n');
        lower_answer(u_answer);
        if(found.match(u_answer))
        {
            ++score;
            cout << "correct!\t" << "Score: " << score << endl;
            deck.enqueue(found);
        }
        else
        {
            cout << "incorrect\n";
            discard.push(found);
        }
    }while(score < 5);   

   
    return 0 ;
}
// Loads cards from external file "trivial.txt" 
// into the queue.
int load_cards(card & new_card, queue & to_add )
{
    ifstream fin;
    char * question = new char[300];
    char * answer = new char[100];

    fin.open("trivial.txt");
    if(fin)
    {
	fin.get(question,300, '?');
	while(!fin.eof())
	{
	    fin.ignore(300,'?');
            fin.get(answer, 100, '\n');
            fin.ignore(100,'\n');
            new_card.add_card( question, answer);
            to_add.enqueue(new_card);
            question = new char[300];
            answer = new char[100];
            fin.get(question,300, '?');
	} 
    }fin.close();
    return 1;
}

//Takes a character array and makes all letter lower case.
int lower_answer(char * answer)
{
    int len = strlen(answer);

    for( int i = 0; i < len; ++i)
    {
        answer[i] = tolower(answer[i]);
    }
    return 1;
}
