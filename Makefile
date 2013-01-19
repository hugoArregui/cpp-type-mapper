LIBRARY_PATH = /usr/local/lib
INCLUDE_PATH = /usr/local/include

#########Compilation Flags#######################################

CXXFLAGS+=-Wall -Wextra -std=c++0x -I. 

CXX = g++

all: install

.PHONY: cleanall cleanobj install

clean: cleanall

cleanall : cleanobj 

cleanobj :
	rm -f *.o */*.o */*/*.o */*/*/*.o

install:
	cp -r tm_pp $(INCLUDE_PATH)
	ldconfig

# Find all sources with available tests
TEST_SRCS := $(patsubst ./%, %, $(shell find|egrep "_test\.cpp$$") )
TEST_BINS := $(patsubst %.cpp, %, $(TEST_SRCS))

test:
	@# Run all tests
	for TEST in $(TEST_BINS); do \
		make "$$TEST"_run; \
	done

%_test: %_test.cpp
	@# Compile the source and link with the real .o
	g++ $(CXXFLAGS) $(LDFLAGS) \
		-lgtest_main -lpthread -o $@ \
			$(OBJECTS) $@.cpp 

%_test_run: %_test
	@# Zomg magic magic - this will make the test and then run it
	./$<
