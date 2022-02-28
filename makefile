caso: main.o
	g++ main.o -o caso.exe

main.o: main.cpp
	g++ -c main.cpp -o main.o