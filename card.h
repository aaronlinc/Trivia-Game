//Aaron Lincoln
//
//
//Class for adding a question and answer to 
//a "card"

#include <iostream>
#include <cctype>
#include <cstring>
#include <fstream>


#ifndef CARDS
#define CARDS
class card
{
	public:
		card(void);
		~card(void);
                //Adds two arrays to the private data membors
                //question and answer.
                int add_card(char * question, char * answer);
		int copy(const card & new_card); //Deep copy of arguments data 
                                                //to class data members.
		int display(void); //Displays question
	        int display_all(void); //Displays question & answer
                int match( char * u_answer); //Checks if user answer passed
                                             //in is a match to answer
	
        private:
		char * question;
		char * answer;
};
#endif
