all:
	g++ 10360_rat_attack.cpp
	./a.out < input.txt
clear:
	rm a.out input.txt
