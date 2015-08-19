// playertest.cpp
#include <cstring>
#include <stdexcept>

#include <cppunit/extensions/HelperMacros.h>

#include "player.h"
#include "playertest.h"

CppUnit::Test *PlayerTest::suite()
{
	CppUnit::TestSuite *testSuite = new CppUnit::TestSuite( "PlayerTest" );

	testSuite->addTest( new CppUnit::TestCaller<PlayerTest>(
			"testConstructor", &PlayerTest::testConstructor ) );
	testSuite->addTest( new CppUnit::TestCaller<PlayerTest>(
			"testStrength", &PlayerTest::testStrength ) );
	testSuite->addTest( new CppUnit::TestCaller<PlayerTest>(
			"testHealth", &PlayerTest::testHealth ) );

	return testSuite;
}

void PlayerTest::setUp()
{
}

void PlayerTest::tearDown()
{
}

#define NAME "Alice Barbaros"

void PlayerTest::testConstructor()
{
	Player player( NAME );
	CPPUNIT_ASSERT( strcmp( player.Name(), NAME ) == 0 );
	CPPUNIT_ASSERT( player.Strength() == 0 );
	CPPUNIT_ASSERT( player.Level() == 0 );
	CPPUNIT_ASSERT( player.Health() == Player::BASE_HEALTH );
}

void PlayerTest::testStrength()
{
	Player player( NAME );
	CPPUNIT_ASSERT( player.Strength() == 0 );
	player.SetStrength( 10 );
	CPPUNIT_ASSERT( player.Strength() == 10 );
	player.SetStrength( 99 );
	CPPUNIT_ASSERT( player.Strength() == 99 );

	CPPUNIT_ASSERT_THROW( player.SetStrength( -10 ), std::invalid_argument );
}

void PlayerTest::testHealth()
{
	Player player( NAME );
	CPPUNIT_ASSERT( player.Health() == Player::BASE_HEALTH );
	player.SetLevel( 3 );
	CPPUNIT_ASSERT( player.Health() == 50 );
}

#if 0
	CPPUNIT_ASSERT( condition );
	CPPUNIT_ASSERT_MESSAGE( message, condition );
	CPPUNIT_FAIL( message );
	CPPUNIT_ASSERT_EQUAL( expected, actual );
	CPPUNIT_ASSERT_EQUAL_MESSAGE( message, expected, actual );
	CPPUNIT_ASSERT_DOUBLES_EQUAL( expected, actual, delta );

	CPPUNIT_ASSERT_THROW( expression, exception-type );
	CPPUNIT_ASSERT_THROW_MESSAGE( message, expression, exception-type );
	CPPUNIT_ASSERT_NO_THROW( expression );
	CPPUNIT_ASSERT_NO_THROW_MESSAGE( message, expression );
#endif

