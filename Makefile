FLAGS = -Wall

all: Driver.o Tree.o 
	g++ $(FLAGS) Driver.o Tree.o -o output.out

Tree.o: Tree.cpp
	g++ $(FLAGS) Tree.cpp -c

Driver.o: Driver.cpp
	g++ $(FLAGS) Driver.cpp -c

DriverSkeleton.o: DriverSkeleton.cpp
	g++ $(FLAGS) DriverSkeleton.cpp -c

simple:
	g++ $(FLAGS) DriverSkeleton.cpp Tree.o -o simple.out

run:
	./output.out

valgrind:
	valgrind --tool=massif --stacks=yes ./simple.out

clean:
	rm -rf *.o
	rm -f *.out
	rm -f *~ *.h.gch *#
