#ifndef PLAYER_TEST_H
#define PLAYER_TEST_H

#include <cppunit/TestCase.h>

class PlayerTest : public CppUnit::TestCase
{
public:
	static CppUnit::Test *suite();
	void setUp();
	void tearDown();

	void testConstructor();
	void testStrength();
	void testHealth();
};

#endif // PLAYER_TEST_H

