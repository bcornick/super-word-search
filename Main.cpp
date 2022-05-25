//
//  Main.cpp
//  Super_Word_Search
//
//  Created by Brett Cornick on 5/21/20.
//  Credit to github user maxim-kht for structure inspiration.
//  Submitted for evaluation by Karagozian & Case as part of interview Challenge #1.
//
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "GridHeaders.hpp"


int main()
{
    //read file variables
    std::ifstream inputFile;
    std::string fileName;
    int fileCheck = 1;
    std::vector<std::string> allLines;
    
    //get dimensions variables
    std::string dimString;
    std::string n;
    std::string m;
    int rows;
    int columns;
    
    //wrapChoice variables
    std::string wrapChoice;
    
    //numWords variables
    std::string p;
    int numWords;
    
    //input grid variables
    std::vector<std::string> gridVector;
    
    //1. Read the input file
    while (fileCheck == 1)
    {
        std::cout << "Enter the file name (with extension): ";
        std::cin >> fileName;
    
        inputFile.open(fileName);
        if (inputFile)
        {
            std::string line;
            while (getline(inputFile, line))
            {
                allLines.push_back(line);
            }
            inputFile.close();
            fileCheck = 0;
        }
        else
        {
            std::cout << "Error opening the file.\n";
        }
    }
    
    //2. get grid dimensions
    dimString = allLines[0];
    n = dimString[0];
    m = dimString[2];
    rows = std::stoi(n);
    columns = std::stoi(m);
    
    //3. determine wrap choice
    wrapChoice = allLines[rows+1];
    
    //4. determine number of words to find
    p = allLines[rows+2];
    numWords = std::stoi(p);
    
    //5. grid initializing
    gridVector = std::vector<std::string>(allLines.begin() + 1, allLines.end() - numWords - 2);

    //6. determine wrap mode
    bool wrap = (wrapChoice == "WRAP") ? true : false;

    //7. read words to look for
    std::string *words = new std::string[numWords];
    for (int i = 0; i < numWords; i++)
    {
        words[i] = allLines[rows+i+3];
    }

    //8. create grid, search, output the result, and reset grid (to reset spent letters)
    for (int i = 0; i < numWords; i++)
    {
        SuperSearch *grid = new SuperSearch(rows, columns, gridVector);
        grid->setAdjacent(wrap);
        grid->searchWord(words[i]);
        delete grid;
    }
    delete[] words;

    return 0;
}
