CC = g++
CXXFLAGS = -Wall --std=c++11

SOURCES =
SOURCES += main.cpp
SOURCES += item.cpp
SOURCES += player.cpp

OBJECTS := $(SOURCES:.o:.cpp)

EXEC = game

TESTSRC := testmain.cpp
TESTSRC += item.cpp
TESTSRC += itemtest.cpp
TESTSRC += player.cpp
TESTSRC += playertest.cpp

TESTOBJ := $(TESTSRC:.o:.cpp)

TESTLIB = -lcppunit

TEST = test

$(EXEC): $(SOURCES)
	$(CC) $(CXXFLAGS) -o $(EXEC) $(SOURCES)

$(TEST): $(TESTSRC)
	$(CC) $(CXXFLAGS) -o $(TEST) $(TESTSRC) $(TESTLIB)

run: $(TEST)
	./$(TEST)

.PHONY: clean
clean:
	@rm -f *.o *.d
	@rm -f $(EXEC).d
	@rm -f $(EXEC)
	@rm -f $(TEST).d
	@rm -f $(TEST)

.PHONY: depend
depend:
	$(CC) -E $(SOURCES) -o $(EXEC).d
	$(CC) -E $(SOURCES) $(TESTSRC) -o $(TEST).d

