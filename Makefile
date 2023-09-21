all: main.o Sorting.o ../Arraylist/Arraylist.o 
	g++ main.o Sorting.o ../Arraylist/Arraylist.o -o Sorting
main.o: main.cpp
	g++ -c main.cpp -o main.o
Sorting.o: Sorting.cpp
	g++ -c Sorting.cpp -o Sorting.o
../Arraylist/Arraylist.o: ../Arraylist/Arraylist.cpp
	g++ -c ../Arraylist/Arraylist.cpp -o ../Arraylist/Arraylist.o
clean:
	rm -f *.o ../Arraylist/Arraylist.o Sorting