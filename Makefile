FLAGS = -Wall

all: Driver.o Tree.o 
	g++ $(FLAGS) Driver.o Tree.o -o output.out

Tree.o: Tree.cpp
	g++ $(FLAGS) Tree.cpp -c

Driver.o: Driver.cpp
	g++ $(FLAGS) Driver.cpp -c

run:
	./output.out

clean:
	rm -rf *.o
	rm -f *.out
	rm -f *~ *.h.gch *#
