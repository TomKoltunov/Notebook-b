#include "doctest.h"
#include "Notebook.hpp"
#include "Direction.hpp"
using ariel::Direction;

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;
using namespace ariel; // The declaration of this namespace appears in the header file "Notebook.hpp" which I have created

const int ROWLENGTH = 100;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}

TEST_CASE("Good input")
{

    Notebook notebook;

    string str;
    for (int i = 0; i < 100; i++)
    {
        str += "$";
    }

    CHECK_NOTHROW(notebook.write(50000, 50000, 0, Direction::Horizontal, str));

    string toWrite = "a";
    string check = nospaces(toWrite);
    int toRead = toWrite.length();
    int page = 0, row = 0, column = 0;
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "a");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~");

    column = 1;
    toWrite = "A";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "A");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~");

    column = 2;
    toWrite = "aaaaa";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "aaaaa");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~~~~~");

    column = 7;
    toWrite = "AAAAA";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "AAAAA");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~~~~~");

    column = 12;
    toWrite = "AaAaA";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "AaAaA");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~~~~~");

    column = 17;
    toWrite = "aAaA";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "aAaA");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~~~~");

    column = 95;
    toWrite = "zZzZz";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "zZzZz");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~~~~~");

    column = 91;
    toWrite = "ZzZz";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "ZzZz");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~~~~");

    column = 86;
    toWrite = "ZZZZZ";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "ZZZZZ");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~~~~~");

    column = 81;
    toWrite = "zzzzz";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "zzzzz");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~~~~~");

    column = 80;
    toWrite = "Z";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "Z");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~");

    column = 79;
    toWrite = "z";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "z");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~");

    ////////////////////////////////////////////////////////////////////////////////

    toWrite = "a";
    check = nospaces(toWrite);
    toRead = toWrite.length(); 
    row = 500, column = 0;

    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "a");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~");

    column = 1;
    toWrite = "A";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "A");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~");

    column = 2;
    toWrite = "aaaaa";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "aaaaa");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~~~~~");

    column = 7;
    toWrite = "AAAAA";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "AAAAA");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~~~~~");

    column = 12;
    toWrite = "AaAaA";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "AaAaA");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~~~~~");

    column = 17;
    toWrite = "aAaA";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "aAaA");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~~~~");

    column = 95;
    toWrite = "zZzZz";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "zZzZz");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~~~~~");

    column = 91;
    toWrite = "ZzZz";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "ZzZz");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~~~~");

    column = 86;
    toWrite = "ZZZZZ";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "ZZZZZ");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~~~~~");

    column = 81;
    toWrite = "zzzzz";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "zzzzz");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~~~~~");

    column = 80;
    toWrite = "Z";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "Z");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~");

    column = 79;
    toWrite = "z";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "z");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~");

    ////////////////////////////////////////////////////////////////////////////////

    toWrite = "a";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    row = 1000, column = 0;

    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "a");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~");

    column = 1;
    toWrite = "A";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "A");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~");

    column = 2;
    toWrite = "aaaaa";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "aaaaa");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~~~~~");

    column = 7;
    toWrite = "AAAAA";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "AAAAA");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~~~~~");

    column = 12;
    toWrite = "AaAaA";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "AaAaA");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~~~~~");

    column = 17;
    toWrite = "aAaA";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "aAaA");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~~~~");

    column = 95;
    toWrite = "zZzZz";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "zZzZz");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~~~~~");

    column = 91;
    toWrite = "ZzZz";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "ZzZz");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~~~~");

    column = 86;
    toWrite = "ZZZZZ";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "ZZZZZ");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~~~~~");

    column = 81;
    toWrite = "zzzzz";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "zzzzz");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~~~~~");

    column = 80;
    toWrite = "Z";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "Z");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~");

    column = 79;
    toWrite = "z";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "z");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~");

    ///////////////////////////////////////////////////////////////////////////////

    toWrite = "a";
    check = nospaces(toWrite);
    toRead = toWrite.length(); 
    row = 1500, column = 0;

    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "a");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~");

    column = 1;
    toWrite = "A";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "A");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~");

    column = 2;
    toWrite = "aaaaa";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "aaaaa");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~~~~~");

    column = 7;
    toWrite = "AAAAA";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "AAAAA");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~~~~~");

    column = 12;
    toWrite = "AaAaA";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "AaAaA");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~~~~~");

    column = 17;
    toWrite = "aAaA";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "aAaA");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~~~~");

    column = 95;
    toWrite = "zZzZz";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "zZzZz");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~~~~~");

    column = 91;
    toWrite = "ZzZz";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "ZzZz");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~~~~");

    column = 86;
    toWrite = "ZZZZZ";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "ZZZZZ");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~~~~~");

    column = 81;
    toWrite = "zzzzz";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "zzzzz");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~~~~~");

    column = 80;
    toWrite = "Z";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "Z");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~");

    column = 79;
    toWrite = "z";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "z");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~");

    ////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////
    ////////////////////////////////////////////////////////////////////////////////

    toWrite = "a";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    page = 2000, row = 0, column = 0;

    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "a");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~");

    column = 1;
    toWrite = "A";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "A");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~");

    column = 2;
    toWrite = "aaaaa";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "aaaaa");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~~~~~");

    column = 7;
    toWrite = "AAAAA";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "AAAAA");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~~~~~");

    column = 12;
    toWrite = "AaAaA";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "AaAaA");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~~~~~");

    column = 17;
    toWrite = "aAaA";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "aAaA");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~~~~");

    column = 95;
    toWrite = "zZzZz";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "zZzZz");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~~~~~");

    column = 91;
    toWrite = "ZzZz";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "ZzZz");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~~~~");

    column = 86;
    toWrite = "ZZZZZ";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "ZZZZZ");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~~~~~");

    column = 81;
    toWrite = "zzzzz";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "zzzzz");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~~~~~");

    column = 80;
    toWrite = "Z";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "Z");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~");

    column = 79;
    toWrite = "z";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "z");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~");

    ////////////////////////////////////////////////////////////////////////////////

    toWrite = "a";
    check = nospaces(toWrite);
    toRead = toWrite.length(); 
    row = 500, column = 0;

    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "a");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~");

    column = 1;
    toWrite = "A";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "A");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~");

    column = 2;
    toWrite = "aaaaa";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "aaaaa");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~~~~~");

    column = 7;
    toWrite = "AAAAA";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "AAAAA");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~~~~~");

    column = 12;
    toWrite = "AaAaA";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "AaAaA");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~~~~~");

    column = 17;
    toWrite = "aAaA";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "aAaA");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~~~~");

    column = 95;
    toWrite = "zZzZz";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "zZzZz");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~~~~~");

    column = 91;
    toWrite = "ZzZz";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "ZzZz");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~~~~");

    column = 86;
    toWrite = "ZZZZZ";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "ZZZZZ");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~~~~~");

    column = 81;
    toWrite = "zzzzz";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "zzzzz");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~~~~~");

    column = 80;
    toWrite = "Z";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "Z");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~");

    column = 79;
    toWrite = "z";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "z");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~");

    ////////////////////////////////////////////////////////////////////////////////

    toWrite = "a";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    row = 1000, column = 0;

    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "a");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~");

    column = 1;
    toWrite = "A";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "A");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~");

    column = 2;
    toWrite = "aaaaa";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "aaaaa");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~~~~~");

    column = 7;
    toWrite = "AAAAA";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "AAAAA");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~~~~~");

    column = 12;
    toWrite = "AaAaA";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "AaAaA");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~~~~~");

    column = 17;
    toWrite = "aAaA";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "aAaA");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~~~~");

    column = 95;
    toWrite = "zZzZz";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "zZzZz");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~~~~~");

    column = 91;
    toWrite = "ZzZz";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "ZzZz");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~~~~");

    column = 86;
    toWrite = "ZZZZZ";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "ZZZZZ");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~~~~~");

    column = 81;
    toWrite = "zzzzz";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "zzzzz");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~~~~~");

    column = 80;
    toWrite = "Z";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "Z");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~");

    column = 79;
    toWrite = "z";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "z");
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == "~");

    ///////////////////////////////////////////////////////////////////////////////

    toWrite = "a";
    check = nospaces(toWrite);
    toRead = toWrite.length(); 
    row = 1500, column = 0;

    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "a");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~");

    column = 1;
    toWrite = "A";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "A");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~");

    column = 2;
    toWrite = "aaaaa";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "aaaaa");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~~~~~");

    column = 7;
    toWrite = "AAAAA";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "AAAAA");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~~~~~");

    column = 12;
    toWrite = "AaAaA";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "AaAaA");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~~~~~");

    column = 17;
    toWrite = "aAaA";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "aAaA");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~~~~");

    column = 95;
    toWrite = "zZzZz";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "zZzZz");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~~~~~");

    column = 91;
    toWrite = "ZzZz";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "ZzZz");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~~~~");

    column = 86;
    toWrite = "ZZZZZ";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "ZZZZZ");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~~~~~");

    column = 81;
    toWrite = "zzzzz";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "zzzzz");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~~~~~");

    column = 80;
    toWrite = "Z";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "Z");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~");

    column = 79;
    toWrite = "z";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK(notebook.read(page, row, column, Direction::Vertical, toRead) == check);
    CHECK_NOTHROW(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "z");
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
    CHECK(notebook.read(page, row, column, Direction::Horizontal, toRead) == "~");
    
}

TEST_CASE("Bad input")
{
    Notebook notebook;
    string str;
    for (int i = 0; i <= 100; i++)
    {
        str += "$";
    }

    CHECK_THROWS(notebook.write(50000, 50000, 0, Direction::Horizontal, str));

    string toWrite = "a ";
    int toRead = toWrite.length();
    int page = 0, row = 0, column = 0;
    CHECK_THROWS(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK_THROWS(notebook.read(page, row, column, Direction::Vertical, toRead));
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());

    column = -1;
    toWrite = "A";
    string check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK_THROWS(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK_THROWS(notebook.read(page, row, column, Direction::Vertical, toRead));
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());

    toWrite = "a ";
    toRead = toWrite.length();
    page = 1;
    column = 0;
    CHECK_THROWS(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK_THROWS(notebook.read(page, row, column, Direction::Horizontal, toRead));
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());

    column = -1;
    toWrite = "A";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK_THROWS(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK_THROWS(notebook.read(page, row, column, Direction::Horizontal, toRead));
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());

    toWrite = "a\n";
    page = 2;
    toRead = toWrite.length();
    CHECK_THROWS(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK_THROWS(notebook.read(page, row, column, Direction::Vertical, toRead));
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());

    column = -1;
    toWrite = "A";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK_THROWS(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK_THROWS(notebook.read(page, row, column, Direction::Vertical, toRead));
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());

    toWrite = "a\n";
    page = 3;
    toRead = toWrite.length();
    CHECK_THROWS(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK_THROWS(notebook.read(page, row, column, Direction::Horizontal, toRead));
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());

    column = -1;
    toWrite = "A";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK_THROWS(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK_THROWS(notebook.read(page, row, column, Direction::Horizontal, toRead));
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());

    toWrite = "a\t";
    page = 4;
    toRead = toWrite.length();
    CHECK_THROWS(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK_THROWS(notebook.read(page, row, column, Direction::Vertical, toRead));
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());

    column = 100;
    toWrite = "A";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK_THROWS(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK_THROWS(notebook.read(page, row, column, Direction::Vertical, toRead));
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());

    toWrite = "a\t";
    page = 5;
    toRead = toWrite.length();
    CHECK_THROWS(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK_THROWS(notebook.read(page, row, column, Direction::Horizontal, toRead));
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());

    
    column = 100;
    toWrite = "A";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK_THROWS(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK_THROWS(notebook.read(page, row, column, Direction::Horizontal, toRead));
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());

    toWrite = "a\r";
    page = 6;
    toRead = toWrite.length();
    CHECK_THROWS(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK_THROWS(notebook.read(page, row, column, Direction::Vertical, toRead));
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());

    column = 100;
    toWrite = "A";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK_THROWS(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK_THROWS(notebook.read(page, row, column, Direction::Vertical, toRead));
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());

    toWrite = "a\r";
    page = 7;
    toRead = toWrite.length();
    CHECK_THROWS(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK_THROWS(notebook.read(page, row, column, Direction::Horizontal, toRead));
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());

    
    column = 100;
    toWrite = "A";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK_THROWS(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK_THROWS(notebook.read(page, row, column, Direction::Horizontal, toRead));
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());

    ///////////////////////////////////////////////////////////////////////////////

    toWrite = "a a a a a";
    toRead = toWrite.length();
    page = 50;
    row = 50;
    column = 50;
    CHECK_THROWS(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK_THROWS(notebook.read(page, row, column, Direction::Vertical, toRead));
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());

    column = -1;
    toWrite = "AAAAA";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK_THROWS(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK_THROWS(notebook.read(page, row, column, Direction::Vertical, toRead));
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());

    toWrite = "a a a a a";
    toRead = toWrite.length();
    page = 1;
    column = 0;
    CHECK_THROWS(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK_THROWS(notebook.read(page, row, column, Direction::Horizontal, toRead));
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());

    column = -1;
    toWrite = "AAAAA";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK_THROWS(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK_THROWS(notebook.read(page, row, column, Direction::Horizontal, toRead));
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());

    toWrite = "a\na\na\na\na";
    page = 2;
    toRead = toWrite.length();
    CHECK_THROWS(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK_THROWS(notebook.read(page, row, column, Direction::Vertical, toRead));
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());

    column = -1;
    toWrite = "AAAAA";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK_THROWS(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK_THROWS(notebook.read(page, row, column, Direction::Vertical, toRead));
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());

    toWrite = "a\na\na\na\na";
    page = 3;
    toRead = toWrite.length();
    CHECK_THROWS(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK_THROWS(notebook.read(page, row, column, Direction::Horizontal, toRead));
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());

    column = -1;
    toWrite = "AAAAA";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK_THROWS(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK_THROWS(notebook.read(page, row, column, Direction::Horizontal, toRead));
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());

    toWrite = "a\ta\ta\ta\ta";
    page = 4;
    toRead = toWrite.length();
    CHECK_THROWS(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK_THROWS(notebook.read(page, row, column, Direction::Vertical, toRead));
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());

    column = 100;
    toWrite = "AAAAA";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK_THROWS(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK_THROWS(notebook.read(page, row, column, Direction::Vertical, toRead));
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());

    toWrite = "a\ta\ta\ta\ta";
    page = 5;
    toRead = toWrite.length();
    CHECK_THROWS(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK_THROWS(notebook.read(page, row, column, Direction::Horizontal, toRead));
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());

    
    column = 100;
    toWrite = "AAAAA";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK_THROWS(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK_THROWS(notebook.read(page, row, column, Direction::Horizontal, toRead));
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());

    toWrite = "a\ra\ra\ra\ra";
    page = 6;
    toRead = toWrite.length();
    CHECK_THROWS(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK_THROWS(notebook.read(page, row, column, Direction::Vertical, toRead));
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());

    column = 100;
    toWrite = "AAAAA";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK_THROWS(notebook.write(page, row, column, Direction::Vertical, toWrite));
    CHECK_THROWS(notebook.read(page, row, column, Direction::Vertical, toRead));
    notebook.erase(page, row, column, Direction::Vertical, toWrite.length());

    toWrite = "a\ra\ra\ra\ra";
    page = 7;
    toRead = toWrite.length();
    CHECK_THROWS(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK_THROWS(notebook.read(page, row, column, Direction::Horizontal, toRead));
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());

    
    column = 100;
    toWrite = "AAAAA";
    check = nospaces(toWrite);
    toRead = toWrite.length();
    CHECK_THROWS(notebook.write(page, row, column, Direction::Horizontal, toWrite));
    CHECK_THROWS(notebook.read(page, row, column, Direction::Horizontal, toRead));
    notebook.erase(page, row, column, Direction::Horizontal, toWrite.length());
}