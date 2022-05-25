# super-word-search
Created a word searhc game using C++ in response to the challenge described in the README.

This program was created by Brett Cornick.
___________________________________________________________________________________________

BUILD AND RUN INSTRUCTIONS:

Mac/Linux:
An application with the name "SuperSearch" can be created on a Mac/Linux OS that has g++
installed using the Makefile provided. This was tested on MacOS Catalina and on a Vagrant VM 
running Ubuntu. To build and run the program, simply enter the following commands in the 
terminal from the main directory:

$ make
$ ./SuperSearch

The program will ask for the name of the input file. Ensure that input file is in same
directory as SuperSearch. A sample input file called "SWS_test_input.txt" has already
been included. When finished, running the following command will restore the directory 
to state prior to build:

$ make clean

If g++ is not installed on the machine, run the following command prior to building:

$ sudo apt-get install g++


Windows:
The application can be compiled and run using Virtual Studio. Make sure compiler is using 
C++11. This was not tested since I do not have access to a machine with a Windows license.
___________________________________________________________________________________________

REASONING FOR USING SELECTED LANGUAGE:

C++ is commonly used for game development due to its speed and performance. The word search 
falls into this category. The ability to use pointers and pointers to pointers within a 
multidimensional array stood out as an obvious advantage in an application like the 
word search where an element's location and value both had to be evaluated.

___________________________________________________________________________________________

CHALLENGE:

In a typical word search puzzle (http://en.wikipedia.org/wiki/Word_search), you are given an NxM grid of seemingly random letters and a list of P words that are in the grid. The words can be found going in any of the 8 directions in a two-dimensional grid:
 
• top to bottom 
• bottom to top 
• left to right
• right to left
• bottom left to top right 
• bottom right to top left
• top left to bottom right 
• top right to bottom left

You're a college professor (for English and Topology, of all things), and your students have become very good at traditional Word Search. Since you want them to continue spending time on academic games, you created a variant of Word Search (inventively) called Super Word Search.

As with the standard word search, you get an NxM grid of letters, and P words that are to be found in the grid. You also get a "mode" flag with one of the following values: WRAP, NO_WRAP. The flag value indicates whether words can wrap-around after they hit a boundary of the grid.
Row numbers start at 0 (top row) and go to N-1 (bottom row). Column numbers start at 0 (leftmost column) and go to M-1 (rightmost column). Grid coordinates are specified as (row_num, column_num).

Here is an example to illustrate the difference between WRAP and NO_WRAP: 012
--- 
0|ABC 
1|DEF 
2|GHI

"FED" is a word that starts at (1,2) and ends at (1,0).
If we are in WRAP mode:
• "CAB" is a word that starts at (0,2) and ends at (0,1). 
• "GAD" is a word that starts at (2,0) and ends at (1,0). 
• "BID" is a word that starts at (0,1) and ends at (1,0).
 
If we are in NO_WRAP mode:
Input Format
• "FED" is a word that starts at (1,2) and ends at (1,0).
• "CAB" is not a word since it requires wrapping in the horizontal direction.
• "GAD" is not a word since it requires wrapping in the vertical direction.
• "BID" is not a word since it requires wrapping in the horizontal and vertical directions.

A letter in the grid is not allowed to be in a word more than once. So, while technically "HIGH" can be found in the above grid in WRAP mode, we will not allow it because it uses the H at (2,1) twice.

Input format:
NM
N rows of M letters
"WRAP" or "NO_WRAP"
P
P words with 1 word per lines

Output format:
Your program should accept the name of an input file which will contain data in the above format.
For each of the P words, you are to output the start and end coordinates of that word in the format "(row_start, column_start) (row_end, column_end)". If the word cannot be found in the grid, output "NOT FOUND".
You are guaranteed that each word will occur at most once in the grid, so a word's start and end coordinates will always be unique (if the word is in the grid), and will never be ambiguous.
