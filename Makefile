CC = g++

#Folders
BIN = bin/
SRC = src/
LIB = lib/
OBJ = obj/

#Files
FILES = data referenceData SIRmodel environment main 

SOURCES=$(patsubst %, ${SRC}%.cpp, ${FILES})
HEADERS=$(patsubst %, ${SRC}%.hpp, ${FILES})
OBJECTS=$(patsubst %, ${OBJ}%.o, ${FILES})

EXECUTABLE=${BIN}pandemicSimulation

#Flags
FLAGS = -lglut -lGLU -lGL -march=native -funroll-loops -Wall -Wextra -std=c++11 -fopenmp

${EXECUTABLE}: ${OBJECTS} ${OBJ}parameters.o
	@/bin/echo -e "${GREEN}${BOLD}----- Creating executable -----${NC}"
	${CC} ${OBJECTS} -o ${EXECUTABLE} ${FLAGS}

${OBJ}%.o: ${SRC}%.cpp
	@/bin/echo -e "${GREEN}Compiling $<${NC}"
	${CC} -c $< -o $@ ${FLAGS}

${OBJ}parameters.o: ${LIB}parameters.cpp
	@/bin/echo -e "${GREEN}Compiling $<${NC}"
	${CC} -c ${LIB}parameters.cpp

clean:
	@/bin/echo -e "${GREEN}${BOLD}----- Cleaning project -----${NC}"
	rm -rf ${OBJ}*.o
	rm -rf ${EXECUTABLE}

run: ${EXECUTABLE} ${SOURCES}
	@/bin/echo -e "${GREEN}${BOLD}----- Running ${EXECUTABLE} -----${NC}"
	./${EXECUTABLE} test

#all: build

#run: build
#	./run

#build: SIR_model.o main.o

#main.o: main.cpp
#	@g++ main.cpp -Wall -o run  $(flags) SIR_model.o

#SIR_model.o: SIR_model.cpp
#	@g++ SIR_model.cpp -c $(flags)

#clean:
#	@rm run *.o
