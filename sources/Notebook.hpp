#include "Direction.hpp"
using ariel::Direction;

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

namespace ariel {

    class Notebook { // declaration of a class named "Notebook"

        unordered_map<int, vector<vector<char>>> notebook; // declaration of unordered map (Works similrarely as Hash map):
        // notebook's keys are integers each represents a page number, and notebook's values are vectors of vectors (matrixes)
        // each represents a page. the notebook's creation is private because each class attributes should be private.

        public: // From now on all things declared will be public

            Notebook(); // Class constructor receiving no parametes
            
            /*
            The function "write" receives an integers called "page", "row" and "column" which represent the page number, row number
            and exact spot (respectively) where to start the writing. It also receives the direction of the writing that can only be 
            "Horizontal" or "Vertical", the direction type is 'Direction' and its declaration is in the header file "Direction.hpp".
            And the function receives a string called "toWrite" which represents the text we want to write in the notebook. 
            */
            void write(int page, int row, int column, Direction direction, const string &toWrite);

            /*
            The function "read" receives an integers called "page", "row" and "column" which represent the page number, row number
            and exact spot (respectively) where to start the reading, and an integer called "toRead" which is the number of characters
            we want to read. It also receives the direction of the reading that can only be "Horizontal" or "Vertical", the direction type 
            is 'Direction' and its declaration is in the header file "Direction.hpp". 
            Eventually "read" will return the text it read if succeeded.
            */
            string read(int page, int row, int column, Direction direction, int toRead);

            /*
            The function "erase" receives an integers called "page", "row" and "column" which represent the page number, row number
            and exact spot (respectively) where to start the erasing, and an integer called "toErase" which is the number of characters
            we want to erase. It also receives the direction of the reading that can only be "Horizontal" or "Vertical", the direction type 
            is 'Direction' and its declaration is in the header file "Direction.hpp". 
            Erasing of a character id carried out by replacing it by the char '~'.
            */
            void erase(int page, int row, int column, Direction direction, int toErase);

            /*
            The function "show" receives an integer named "page" which represents the notebook's page it has to show on the screen.
            */
            void show(int page);
    };
}