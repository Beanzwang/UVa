all:
	g++ main.cpp
	./a.out < input.txt > output.txt
clear:
	rm a.out input.txt output.txt
