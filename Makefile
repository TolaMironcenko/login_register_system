build:
	g++ -o main main.cpp

run:
	./main

buildgcc:
	g++ -o main *.cpp

buildclang:
	clang++ -o main *.cpp

startgcc:
	g++ -o main main.cpp
	./main

startclang:
	clang++ -o main *.cpp
	./main
