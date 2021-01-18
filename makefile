a.out: nQueens.o
	g++ nQueens.o -o a.out

nQueens.o: nQueens.cpp
	g++ -c nQueens.cpp -o nQueens.o

