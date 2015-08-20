CC = g++
CXXFLAGS = -Wall --std=c++11

SOURCES =
SOURCES += gamemain.cpp
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

include $(EXEC).d
include $(TEST).d

$(EXEC): $(SOURCES) $(EXEC).d
	$(CC) $(CXXFLAGS) -o $(EXEC) $(SOURCES)

$(TEST): $(TESTSRC) $(TEST).d
	$(CC) $(CXXFLAGS) -o $(TEST) $(TESTSRC) $(TESTLIB)

run: $(TEST)
	./$(TEST)

.PHONY: clean
clean:
	@rm -f *.o *.d
	@rm -f $(EXEC)
	@rm -f $(TEST)

.PHONY: depend
depend:
	$(CC) -MM -E $(SOURCES) -o $(EXEC).d
	$(CC) -MM -E $(TESTSRC) -o $(TEST).d

$(EXEC).d : $(SOURCES)
	$(CC) -MM -E $@ -o $<

$(TEST).d : $(TESTSRC)
	$(CC) -MM -E $@ -o $<


