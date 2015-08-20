// testmain.cpp

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
	bool success runner.run( "" );

	// Return error code 1 if any tests failed.
	return success ? 0 : 1;
}

