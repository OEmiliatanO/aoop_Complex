CC:=g++

all: main.o complex.o
	$(CC) -o main main.o complex.o
dep: main.cpp src/complex.cpp
	$(CC) -c -W main.cpp
	$(CC) -c -W src/complex.cpp
clean:
	rm *.o