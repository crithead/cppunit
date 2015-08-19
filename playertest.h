#ifndef TEST_PLAYER_H
#define TEST_PLAYER_H

#include <cppunit/TestCase.h>

class PlayerTest : public CppUnit::TestCase
{
	CPPUNIT_TEST_SUITE( PlayerTest );
	CPPUNIT_TEST( testConstructor );
	CPPUNIT_TEST( testStrength );
	CPPUNIT_TEST( testHealth );
	CPPUNIT_TEST_SUITE_END();

	void testConstructor();
	void testStrength();
	void testHealth();

public:
	void setUp();
	void tearDown();
};

#endif // TEST_PLAYER_H
