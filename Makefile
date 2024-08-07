#Author: Anuj Prabhu
#Date: 2 December 2023
#Description: Makefile
#Usage: -make || make clean; file compiles all object files into a single executable

exe : hw5_prabhu_anuj.o
	g++ -g -Wall hw5_prabhu_anuj.o -o exe
hw5_prabhu_anuj.o : linkedlist_prabhu.hpp
	g++ -g -Wall -c hw5_prabhu_anuj.cpp
clean :
	rm *.o exe -v
