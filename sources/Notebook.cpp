#include "Direction.hpp"
using ariel::Direction;

#include <string>
#include <iostream>
#include <vector>
#include <stdexcept>
#include <unordered_map>
#include "Notebook.hpp"
using namespace std;
const int ROWLENGTH = 100;
const int FIRST = 0;
const int STAND = 5;
const char LINE = '_';
const char ERASED = '~';
const char SPACE = ' ';
const int SMALL = 33;
const int BIG = 127;
const int divisor = 10;
const int THEANSWERTOLIFESPACEANDALLELSE = 42;

bool isValidParameter(int page, int row, int column, const string &text, int length)
{
    bool answer = true;
    if (page < 0 || row < 0 || column < 0 ||column >= ROWLENGTH || length < 0)
    {
        answer = false;
    }
    for(unsigned i = 0; i < text.length(); i++)
    {
        if (i == 0)
        {
            if(text.at(i) < SMALL || text.at(i) >= BIG || text.at(i) == ERASED)
            {
                answer = false;
                break;
            }
        }
        else
        {
            if((text.at(i)<SMALL || text.at(i)>=BIG || text.at(i)==ERASED) && text.at(i)!=SPACE)
            {
                answer = false;
                break;
            }
        }
    }
    return answer;
}

bool isPossibleHorizontaly(int column, int textLength)
{
    bool answer = true;
    if (column + textLength - 1 >= ROWLENGTH) 
    {
        answer = false;
    }
    return answer;
}

namespace ariel{

    Notebook::Notebook()
    {
        this->notebook[0].assign(ROWLENGTH,vector<char>(ROWLENGTH,LINE));
    }
    
    /*
    The function "write" receives an integers called "page", "row" and "column" which represent the page number, row number
    and exact spot (respectively) where to start the writing. It also receives the direction of the writing that can only be 
    "Horizontal" or "Vertical", the direction type is 'Direction' and its declaration is in the header file "Direction.hpp".
    And the function receives a string called "toWrite" which represents the text we want to write in the notebook. 
    */
    void Notebook::write(int page,int row,int column, Direction dir,const string &toWrite){
         
        if(!isValidParameter(page,row,column,toWrite,0)) // Check the validity of the input parameters
        {
            throw invalid_argument{"Invalid input"};
        }
        if(dir==Direction::Horizontal)
        {
            if(!isPossibleHorizontaly(column, toWrite.length()))
            {
                 throw invalid_argument{"Invalid input"};
            }
        }
        bool ans=false; // check if the page exist in the map, if not we add a new one.
        for(auto const &x:notebook)
        {
            if(x.first==page)
            {
                ans=true;
                break;
            }
        }
        if(!ans)
        {
            notebook[page].assign((unsigned)row+toWrite.length(),vector<char>(ROWLENGTH,LINE)); // Add 'page' to 'notebook'
        }
        /**
         * @brief 
         * checking if we can write in this place.
         */
        for(unsigned i=0;i<toWrite.length();i++)
        {
            if(dir==Direction::Horizontal)
            {
                if(notebook[page].size()<=(unsigned)row)
                {
                    notebook[page].resize((unsigned)row+1);
                }
                if(notebook[page][(unsigned)row].size()<=(unsigned)column+i)
                {
                    notebook[page][(unsigned)row].resize((unsigned)column+i+1);
                }
                 if(notebook[page][(unsigned)row][(unsigned)column+i]!=LINE &&notebook[page][(unsigned)row][(unsigned)column+i]!=0 )
                {
                    throw invalid_argument{"can't write in this place!"};
                }
            }
            else{
                if(notebook[page].size()<=(unsigned)row+i)
                {
                    notebook[page].resize((unsigned)row+i+1);
                }
                if( notebook[page][(unsigned)row+i].size()<=(unsigned)column)
                {
                    notebook[page][(unsigned)row+i].resize((unsigned)column+i+1);
                }
                if(notebook[page].size()==toWrite.length())
                {
                    notebook[page].resize(toWrite.length()+1);
                }
                if(notebook[page].size()<=(unsigned)row+i)
                {
                    notebook[page].resize((unsigned)row+i+1);
                }
                if(notebook[page][(unsigned)row+i][(unsigned)column]!=LINE && notebook[page][(unsigned)row+i][(unsigned)column]!=0)
                {
                    throw invalid_argument{"can't write in this place!"};
                }
            }
        }
        /**
         * @brief 
         * writing in the note book.
         */
        for(unsigned i=0;i<toWrite.length();i++){
            if(dir==Direction::Horizontal)
            {
                if(notebook[page].size()<=(unsigned)row)
                {
                    notebook[page].resize((unsigned)row+1);
                }
                if(notebook[page][(unsigned)row].size()<=(unsigned)column+i)
                {
                    notebook[page][(unsigned)row].resize((unsigned)column+i+1);
                }
                notebook[page][(unsigned)row][(unsigned)column+i]=toWrite[i];
                
            }
            else
            {
                if(notebook[page].size()<=(unsigned)row+i)
                {
                    notebook[page].resize((unsigned)row+i+1);
                }
                if( notebook[page][(unsigned)row+i].size()<=(unsigned)column)
                {
                    notebook[page][(unsigned)row+i].resize((unsigned)column+i+1);
                }
                if(notebook[page].size()==toWrite.length())
                {
                    notebook[page].resize(toWrite.length()+1);
                }
                if(notebook[page].size()<=(unsigned)row+i)
                {
                    notebook[page].resize((unsigned)row+i+1);
                }
                
                notebook[page][(unsigned)row+i][(unsigned)column]=toWrite[i];
                

            }
        }
    }

    /*
    The function "read" receives an integers called "page", "row" and "column" which represent the page number, row number
    and exact spot (respectively) where to start the reading, and an integer called "toRead" which is the number of characters
    we want to read. It also receives the direction of the reading that can only be "Horizontal" or "Vertical", the direction type 
    is 'Direction' and its declaration is in the header file "Direction.hpp". 
    Eventually "read" will return the text it read if succeeded.
    */
     string Notebook::read(int page,int row,int column, Direction dir,int toRead){
        if(!isValidParameter(page,row,column,"abcd",toRead)) // Check the validity of the input parameters
        {
            throw invalid_argument{"Invalid input"};
        }
        if(dir==Direction::Horizontal)
        {
            if(!isPossibleHorizontaly(column, toRead))
            {
                 throw invalid_argument{"Invalid input"};
            }
        }
        bool isExist=false; // This condition means 'page' doesn't exist
        for(auto const &x:notebook)
        {
            if(x.first==page)
            {
                isExist=true;
                break;
            }
        }
        if(!isExist) // This condition means 'page' doesn't exist
        {
            notebook[page].assign((unsigned)row+(unsigned)toRead,vector<char>(ROWLENGTH,LINE)); // Add 'page' to 'notebook'
        }
        string total;
        for(unsigned i=0;i<(unsigned)toRead;i++)
        {
            if(dir==Direction::Horizontal)
            {
                if(notebook[page].size()<=(unsigned)row)
                {
                    notebook[page].resize((unsigned)row+1);
                }
                if(notebook[page][(unsigned)row].size()<=(unsigned)column+i)
                {
                    notebook[page][(unsigned)row].resize((unsigned)column+i+1);
                }

                total+=notebook[page][(unsigned)row][(unsigned)column+i];
            }
            else{
                if(notebook[page].size()<=(unsigned)row+i)
                {
                    notebook[page].resize((unsigned)row+i+1);
                }
                if( notebook[page][(unsigned)row+i].size()<=(unsigned)column)
                {
                    notebook[page][(unsigned)row+i].resize((unsigned)column+i+1);
                }
                if(notebook[page][(unsigned)row+i][(unsigned)column]==0)
                {
                    total+=LINE;
                }
                else{
                total+=notebook[page][(unsigned)row+i][(unsigned)column];
                }
            }
        }
        return total;
    }


    /*
    The function "erase" receives an integers called "page", "row" and "column" which represent the page number, row number
    and exact spot (respectively) where to start the erasing, and an integer called "toErase" which is the number of characters
    we want to erase. It also receives the direction of the reading that can only be "Horizontal" or "Vertical", the direction type 
    is 'Direction' and its declaration is in the header file "Direction.hpp". 
    Erasing of a character id carried out by replacing it by the char '~'.
    */
    void Notebook::erase(int page,int row,int column, Direction dir,int toErase){
        if(!isValidParameter(page,row,column,"Tom",toErase)) // Check the validity of the input parameters
        {
            throw invalid_argument{"Invalid input"};
        }
        if(dir==Direction::Horizontal)
        {
            if(!isPossibleHorizontaly(column, toErase))
            {
                 throw invalid_argument{"Invalid input"};
            }
        }
        bool isExist=false; // check if the page exist in the map, if not we add a new one.
        for(auto const &x:notebook)
        {
            if(x.first==page)
            {
                isExist=true;
                break;
            }
        }
        if(!isExist) // This condition means 'page' doesn't exist
        {
            notebook[page].assign((unsigned)row+(unsigned)toErase,vector<char>(ROWLENGTH,LINE)); // Add 'page' to 'notebook'
        }

        for(unsigned i=0;i<(unsigned)toErase;i++)
        {
            if(dir==Direction::Horizontal)
            {
                 if(notebook[page].size()<=(unsigned)row)
                {
                    notebook[page].resize((unsigned)row+1);
                }
                 if(notebook[page][(unsigned)row].size()<=(unsigned)column+i)
                {
                    notebook[page][(unsigned)row].resize((unsigned)column+i+1);
                }
                
                notebook[page][(unsigned)row][(unsigned)column+i]=ERASED;
                
            }
            else{
                if(notebook[page].size()<=(unsigned)row+i)
                {
                    notebook[page].resize((unsigned)row+i+1);
                }
                 if( notebook[page][(unsigned)row+i].size()<=(unsigned)column)
                {
                    notebook[page][(unsigned)row+i].resize((unsigned)column+i+1);
                }
                
                notebook[page][(unsigned)row+i][(unsigned)column]=ERASED;
            }
        }
       
    }

    /*
    The function "show" receives an integer named "page" which represents the notebook's page it has to show on the screen.
    */
    void Notebook::show(int page) 
    {
        if (isValidParameter(page, 0, 0, "Tom", 0)) // Check the validity of the input parameter 'page'
        {
            bool isExist = false;
            for (auto const &x:notebook) // This loop checks if 'page' exists
            {
                if (x.first == page)
                {
                    isExist = true;
                    break;
                }
            }
            if (!isExist) // This condition means 'page' doesn't exist
            {
                notebook[page].assign(ROWLENGTH, vector<char>(ROWLENGTH, '_')); // Add 'page' to 'notebook'
            }
            for (unsigned i = 0; i <= THEANSWERTOLIFESPACEANDALLELSE; i++)
            {
                for (unsigned j = 0; j < ROWLENGTH; j++)
                {
                    cout << notebook[page][i][j];
                }
                cout << endl;
            }
        }
        else 
        {
            throw invalid_argument{"The parameter 'page' is invalid"};
        }
    }
};