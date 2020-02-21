CXX=clang++
# CXX=g++

# We have -Wno-unused-parameter so that the compiler
# doesn't complain too much about our stubs.

CXXFLAGS = -std=c++11 -Wall -Wextra -Wno-unused-parameter -Wno-unused-private-field

# Change to this before final submission:

#CXXFLAGS = -std=c++11 -Wall -Wextra -Werror

BINARIES= prog1

all: ${BINARIES}

prog1: prog1.o MinHeap.o Hash.o Quash.o
	${CXX} $^ -o $@

tests: ${BINARIES}
	./prog1

clean:
	/bin/rm -f ${BINARIES} *.o