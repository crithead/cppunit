// testmain.cpp
#define USE_VERISON_ONE 0
#define USE_VERISON_TWO 1

#if 0 // USE_VERSION_ONE
//
// http://c2.com/cgi/wiki?DirtSimpleCppUnitExample
//

#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/CompilerOutputter.h>

CppUnit::Test *suite( const char *suiteName )
{
	CppUnit::TestFactoryRegistry &registry =
		CppUnit::TestFactoryRegistry::getRegistry();

	registry.registerFactory(
		&CppUnit::TestFactoryRegistry::getRegistry( suiteName ) );
	return registry.makeTest();
}


int main( int argc, char* argv[] )
{
	// if command line contains "-selftest" then this is the post build check
	// => the output must be in the compiler error format.
	bool selfTest = (argc > 1)  &&
		(std::string("-selftest") == argv[1]);

	CppUnit::TextUi::TestRunner runner;
	// Add the top suite to the test runner
	runner.addTest( suite( "ItemTest" ) );
	runner.addTest( suite( "PlayerTest" ) );

	if ( selfTest ) {
		// Change the default outputter to a compiler error format outputter
		// The test runner owns the new outputter.
		runner.setOutputter( CppUnit::CompilerOutputter::defaultOutputter(
			&runner.result(), std::cerr ) );
	}

	// Run the test.
	bool wasSucessful = runner.run( "" );

	// Return error code 1 if any tests failed.
	return wasSucessful ? 0 : 1;
}

#else // USE_VERSION_TWO
//
// http://cppunit.sourceforge.net/doc/1.8.0/cppunit_cookbook.html
//

#include <cppunit/ui/text/TestRunner.h>
#include <cppunit/CompilerOutputter.h>

#include "itemtest.h"
#include "playertest.h"

int main( int argc, char* argv[] )
{
	// if command line contains "-selftest" then this is the post build check
	// => the output must be in the compiler error format.
	bool selfTest = ( argc > 1 )  &&
			( std::string( "-selftest" ) == argv[ 1 ] );

	CppUnit::TextUi::TestRunner runner;
	runner.addTest( ItemTest::suite() );
	runner.addTest( PlayerTest::suite() );

	if ( selfTest ) {
		// Change the default outputter to a compiler error format outputter
		// The test runner owns the new outputter.
		runner.setOutputter( CppUnit::CompilerOutputter::defaultOutputter(
			&runner.result(), std::cerr ) );
	}

	// Run the test.
	bool wasSucessful = runner.run( "" );

	// Return error code 1 if any tests failed.
	return wasSucessful ? 0 : 1;
}

#endif

