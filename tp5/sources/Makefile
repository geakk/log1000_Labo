
article: Emission.o main.o
	g++ -o Emission main.o Emission.o 

Emission.o: Emission.cpp Emission.h
	g++ -o Emission.o -c Emission.cpp

main.o: main.cpp Emission.h
	g++ -o main.o -c main.cpp
 
clean: 
	rm *.o
	rm Emission
