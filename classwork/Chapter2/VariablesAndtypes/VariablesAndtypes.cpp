#include <iostream>

//Entry point
int main()
{
    // cout << E
    // std::end ::= new line
    //output a message -1
    std::cout << "Hello World" << std::endl;

    //Message - 2
    std::cout << "Hello" << " " << "World" << std::endl;

    //Message - 3
    std::cout << "Hello";
    std::cout << " ";
    std::cout << "World";
    std::cout << std::endl;

    //Message - 4
    std::cout << "Hello\tWorld\n";

    std::cout << "Hello \"Bob\"";

    
    std::cout << "C:\\windows\\temp"; 
    //std::cout << R"C:\windows\temp"; 

    //Variables
    // Named memory location to store data
    // Declaration - tell complier a variable exists
    // Scope - lifetime of a variable/identifier: Point of declaration to end of block
    // Expression - can be used anywhere an expression is allowed
    // Styling - Name: nouns, Casing: Camel
    //
    // variable-decl ::= T id [ '=' E ] { ',' id [ '=' E ] }* ';'
    // Scope - lifetime of a variable/identifier: Point of declaration to end of block
    int length;
    length = 0;

    int releaseYear = 1900; 

    std::cout << length;

    
   // Types
    //   Defines what kind of data is stored, range, size
    //   Primitives - understoood by lang
    // | Types | Size | Range |
    // |- | - |  -  |
    // | short | 2 | +-32767 (integral) |
    // | int | 4 | +- 2 billion (default) |
    // | long | 4 | +-2 billion |
    // | unsigned * | * | 0-
    // Floats
    // | float | 4 | E+-38 | precision: 5-7 |
    // | double | 8 | E+-308 | precision: 12-15 (default) |
    // Text
    // | char | 1 | -128 to 127 | character
    // | std::string | * | text |
    // | bool |  1? | true or false |
    short s = 0;
    int i = 0;
    long l = 5l;
    unsigned int ui = 3U;
    double pi = 3.14159;
    double largenumber = 10E100;
    char c = 'A';
    std::string name = "Bob";
    bool isPassing = true;
    //int isOK = 1 ; //Don't do it
    int intSize = sizeof(int);

    //Assignment
    // asn_op ::= V = E
    // Must be type compatible
    // Expression of type Vt
    int shapelength = 10;
    int shapeWidth = 20;
    int shapeArea;

    shapeArea = shapelength;
    shapeWidth = 10;
    //20  = shapeWidth;

    shapeArea = shapelength = shapeWidth = 20;