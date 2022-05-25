//
//  WordGrid.cpp
//  Super_Word_Search
//
//  Created by Brett Cornick on 5/21/20.
//  Submitted for evaluation by Karagozian & Case as part of interview Challenge #1.
//

#include <iostream>
#include <vector>
#include "GridHeaders.hpp"

//create letter grid
SuperSearch::SuperSearch(int maxRowCount, int maxColCount, std::vector<std::string> gridVector)
{
    letters = new Letter**[maxRowCount]; //2nd dimension

    for (int y = 0; y < maxRowCount; y++)
    {
        letters[y] = new Letter*[maxColCount]; //1st dimension
    }
    for (int y = 0; y < maxRowCount; y++)
    {
        for (int x = 0; x < maxColCount; x++)
        {
            letters[y][x] = new Letter(gridVector[y][x]);
            letters[y][x]->yCoord = y; //uses reference to class Letter to set coord values of letter at (x,y)
            letters[y][x]->xCoord = x;
        }
    }
    
    this->maxRowCount = maxRowCount; //used because local variable name is same as member variable name
    this->maxColCount = maxColCount;
}

//search for words
void SuperSearch::searchWord(std::string word) {
    int initY = 0;
    int initX = 0;
    int endY = 0;
    int endX = 0;
    
    bool wordFound = false;

    for (int y = 0; y < maxRowCount && !wordFound; y++)
        for (int x = 0; x < maxColCount && !wordFound; x++)
        {
            //found first letter
            if (toupper(word[0]) == letters[y][x]->value)
            {
                initX = y;
                initY = x;

                //search adjacent letters
                for (int i = 0; i < 8 && !wordFound; i++)
                {
                    bool foundNext = true;
                    int index = 1;
                    Letter *currentLetter = letters[y][x]->adjLetters[i];

                    while (index < word.length() && foundNext && !wordFound && currentLetter->value != '0' && currentLetter->isSpent != true)
                    {
                        if (toupper(word[index]) != currentLetter->value)
                        {
                            foundNext = false;
                            //reset isSpent flag on letter
                            for (int yy = 0; yy < maxRowCount; yy++)
                                for (int xx = 0; xx < maxColCount; xx++)
                                    letters[yy][xx]->isSpent = false;
                            letters[y][x]->isSpent = true;
                        }
                        else if (index == word.length() - 1 && toupper(word[index]) == currentLetter->value)
                        {
                            wordFound = true;
                            endX = currentLetter->yCoord;
                            endY = currentLetter->xCoord;
                        }
                        else
                        {
                            index++;
                            currentLetter->isSpent = true;
                            currentLetter = currentLetter->adjLetters[i];
                        }
                    }
                } //end search

            } //end if first letter is found
            
        }

    if (wordFound)
    {
        std::cout << "(" << initX << "," << initY << ")(" << endX << "," << endY << ")\n";
    }
    else
    {
        std::cout << "NOT FOUND\n";
    }
}


//set up adjacent letters
void SuperSearch::setAdjacent(bool wrap)
{
    for (int y = 0; y < maxRowCount; y++)
    {
        for (int x = 0; x < maxColCount; x++)
        {
            createAdjacent(y, x, wrap);
        }
    }
}

void SuperSearch::createAdjacent(int y, int x, bool wrap) {
    int maxRow = maxRowCount - 1;
    int maxCol = maxColCount - 1;

    bool upperEdge = (y == 0);
    bool lowerEdge = (y == maxRow);
    bool leftEdge = (x == 0);
    bool rightEdge = (x == maxCol);

    //up direction
    if (!upperEdge)
        letters[y][x]->adjLetters[1] = letters[y - 1][x];
    else if (!wrap)
        letters[y][x]->adjLetters[1] = new Letter('0');
    else if (upperEdge)
        letters[y][x]->adjLetters[1] = letters[maxRow][x];
    
    //right direction
    if (!rightEdge)
        letters[y][x]->adjLetters[3] = letters[y][x + 1];
    else if (!wrap)
        letters[y][x]->adjLetters[3] = new Letter('0');
    else if (rightEdge)
        letters[y][x]->adjLetters[3] = letters[y][0];
    
    //left direction
    if (!leftEdge)
        letters[y][x]->adjLetters[7] = letters[y][x - 1];
    else if (!wrap)
        letters[y][x]->adjLetters[7] = new Letter('0');
    else if (leftEdge)
        letters[y][x]->adjLetters[7] = letters[y][maxCol];
    
    //down direction
    if (!lowerEdge)
        letters[y][x]->adjLetters[5] = letters[y + 1][x];
    else if (!wrap)
        letters[y][x]->adjLetters[5] = new Letter('0');
    else if (lowerEdge)
        letters[y][x]->adjLetters[5] = letters[0][x];
    
    //up and left diagonal direction
    if (!upperEdge && !leftEdge)
        letters[y][x]->adjLetters[0] = letters[y - 1][x - 1];
    else if (!wrap)
        letters[y][x]->adjLetters[0] = new Letter('0');
    else if (upperEdge && leftEdge)
        letters[y][x]->adjLetters[0] = letters[maxRow][maxCol];
    else if (upperEdge)
        letters[y][x]->adjLetters[0] = letters[maxRow][x - 1];
    else if (leftEdge)
        letters[y][x]->adjLetters[0] = letters[y - 1][maxCol];

    //up and right diagonal direction
    if (!upperEdge && !rightEdge)
        letters[y][x]->adjLetters[2] = letters[y - 1][x + 1];
    else if (!wrap)
        letters[y][x]->adjLetters[2] = new Letter('0');
    else if (upperEdge && rightEdge)
        letters[y][x]->adjLetters[2] = letters[maxRow][0];
    else if (upperEdge)
        letters[y][x]->adjLetters[2] = letters[maxRow][x + 1];
    else if (rightEdge)
        letters[y][x]->adjLetters[2] = letters[y - 1][0];

    //down and right diagonal directino
    if (!lowerEdge && !rightEdge)
        letters[y][x]->adjLetters[4] = letters[y + 1][x + 1];
    else if (!wrap)
        letters[y][x]->adjLetters[4] = new Letter('0');
    else if (lowerEdge && rightEdge)
        letters[y][x]->adjLetters[4] = letters[0][0];
    else if (lowerEdge)
        letters[y][x]->adjLetters[4] = letters[0][x + 1];
    else if (rightEdge)
        letters[y][x]->adjLetters[4] = letters[y + 1][0];

    //down and left diagonal direction
    if (!lowerEdge && !leftEdge)
        letters[y][x]->adjLetters[6] = letters[y + 1][x - 1];
    else if (!wrap)
        letters[y][x]->adjLetters[6] = new Letter('0');
    else if (leftEdge && lowerEdge)
        letters[y][x]->adjLetters[6] = letters[0][maxCol];
    else if (leftEdge)
        letters[y][x]->adjLetters[6] = letters[y + 1][maxCol];
    else if (lowerEdge)
        letters[y][x]->adjLetters[6] = letters[0][x - 1];
    
}
