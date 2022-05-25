//
//  WordGrid.hpp
//  Super_Word_Search
//
//  Created by Brett Cornick on 5/21/20.
//  Submitted for evaluation by Karagozian & Case as part of interview Challenge #1.
//

#ifndef WORDGRID_HPP
#define WORDGRID_HPP

#include <string>
#include <vector>

//create class for word search grid
class SuperSearch
{
private:
    int maxRowCount; //N from input file
    int maxColCount; //M from input file
    std::vector<std::string> gridVector; //vector of grid values read from input file
    
    //create structure within SuperSearch for Letters
    struct Letter
    {
        Letter(char value):value(value) {};
        char value;
        Letter *adjLetters[8]; //represents the 8 possible directions for movement
        int yCoord;
        int xCoord;
        bool isSpent; //flag to mark if a letter has already been used
    };

    Letter ***letters; //use triple pointer to set Letter as specific location in letters


public:
    SuperSearch(int, int, std::vector<std::string>);
    void searchWord(std::string); //searches for a word
    void setAdjacent(bool); //initializes nearby letters
    void createAdjacent(int, int, bool); //determines values of adjacent letters

};

#endif
