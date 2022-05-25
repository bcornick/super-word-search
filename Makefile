output: Main.o GridFunctions.o
	g++ -std=c++11 Main.o GridFunctions.o -o SuperSearch
    
Main.o: Main.cpp
	g++ -std=c++11 -c Main.cpp
    
GridFunctions.o: GridFunctions.cpp GridHeaders.hpp
	g++ -std=c++11 -c GridFunctions.cpp
    
clean:
	rm *.o SuperSearch