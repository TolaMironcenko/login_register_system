build:
	g++ -o main *.cpp

buildgcc:
	g++ -o main *.cpp

buildclang:
	clang++ -o main *.cpp

start:
	g++ -o main main.cpp
	./main
