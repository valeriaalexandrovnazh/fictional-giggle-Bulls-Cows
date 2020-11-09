CXX=gcc

CFLAGS = -c -Wall  -std=c99

FLAGS = -Wall  -std=c99

OBJECTS = build/src/main.o build/src/BullsLib.o 

TEST_OBJECTS = build/test/main.o build/test/tests.o build/src/BullsLib.o

.PHONY: clean all bin build run

all: prog test

prog: bin build bin/key

test: bin build bin/key_test
	bin/key_test

bin/key_test: $(TEST_OBJECTS)
	$(CXX) $(FLAGS) $(TEST_OBJECTS) -o bin/key_test

build/test/main.o: test/main.c
	$(CXX) $(CFLAGS) test/main.c -I thirdparty/ -I src/ -o build/test/main.o

build/test/tests.o: test/tests.c
	$(CXX) $(CFLAGS) test/tests.c -I thirdparty/ -I src/ -o build/test/tests.o

bin/key: $(OBJECTS)
	$(CXX) $(FLAGS) $(OBJECTS) -o bin/key

build/src/main.o: src/main.c
	$(CXX) $(CFLAGS) src/main.c -o build/src/main.o 

build/src/BullsLib.o: src/BullsLib.c 
	$(CXX) $(CFLAGS) src/BullsLib.c -o build/src/BullsLib.o

build:
	mkdir -p build/src
	mkdir -p build/test

bin:
	mkdir -p bin 

clean:
	-rm -rf build bin

run:
	./bin/key
