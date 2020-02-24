CXX=clang++
CXXFLAGS = -std=c++11 -Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field
BINARIES= prog1.out

all: ${BINARIES}

prog1.out: prog1.o MinHeap.o Hash.o Quash.o
	${CXX} $^ -o $@

tests: ${BINARIES}
	./prog1.out

clean:
	/bin/rm -f ${BINARIES} *.o

