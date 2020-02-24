CXX=clang++
CXXFLAGS = -std=c++11 -Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field
BINARIES= prog1.out

all: ${BINARIES}

prog1.out: prog1.cpp
	clang++ -o prog1.out prog1.cpp MinHeap.cpp Hash.cpp Quash.cpp

clean:
	/bin/rm -f ${BINARIES} *.o

