# CppUnit Example

This is a simple example project showing how to use CppUnit to build unit
tests for a small project.

It was derived from the following example:

<http://c2.com/cgi/wiki?DirtSimpleCppUnitExample>

## Building the Project and Running the Tests

1.  Install CppUnit libraries

```sh
sudo apt-get install libcppunit-dev libcppunit-doc
```

2.  Compile and Run

```sh
mkdir build && cd build
cmake ..
make
./game
./test
```

