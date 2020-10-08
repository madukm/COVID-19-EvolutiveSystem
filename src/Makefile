flags = -lglut -lGLU -lGL -march=native -funroll-loops -Wall -Wextra -std=c++11 -fopenmp

all: build

run: build
	./run

build: SIR_model.o main.o

main.o: main.cpp
	@g++ main.cpp -Wall -o run  $(flags) SIR_model.o

SIR_model.o: SIR_model.cpp
	@g++ SIR_model.cpp -c $(flags)

clean:
	@rm run *.o
