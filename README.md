Table of Contents
=================

   * [Table of Contents](#table-of-contents)
   * [NumberRange](#numberrange)
   * [Introduction](#introduction)
   * [License](#license)
   * [Implementation](#implementation)
   * [Build](#build)
   * [Test.](#test)
   * [Usage](#usage)
    + [Basic range](#basic-range)
    + [Reverse range](#reverse-range)
    + [Range start point](#range-start-point)
    + [Reverse range start point](#reverse-range-start-point)
    + [Range with step size](#range-with-step-size)
    + [Reverse range step size](#reverse-range-step-size)
    + [Range with char type](#range-with-char-type)
    + [Reverse range with char type](#reverse-range-with-char-type)
    + [Here be dragons](#here-be-dragons)


# NumberRange

## Introduction
Currently even in modern C++ (up to C++17) looping over a range of numbers is still performed the same way as its done in C, that is with a for loop

```cpp
for(int i = 0; i < 10; ++i)
// use i
```

Python has a range library which provides a much more elegant solution,

```python
for i in range(10)
// use i
```

the python range library supports specifying a start point and step size for each iteration, while those things can be performed with the C for loop, its is clumsy and cannot be used with modern C++ algorithms.

The NumberRange C++ library implements a C++ range class that provides a similar interface as the python range library, which can also be used in modern C++ algorithms.

## License
NumberRange is licensed under the terms of the MIT license, see LICENSE.md for details

## Implementation
The library is implemented in a single header src/NumberRange.hpp and requires a C++17 compliant compiler.

## Build
NumberRange is a single header library and needs to be built with a C++17 compliant compiler for clang and gcc set the -std=c++17 flag compiler flag

## Test.
To build the test go in the test directory and run:

```
mkdir build
cd build
cmake ..
make run_tests
```
The tests require googletest and the make process will download and build the googletest library as part of the test build and run process.

## Usage
All the NumberRange code is inside the NumberRange namespace, NumberRange is a template class with long long as the default template parameter, the library was designed to be used with POD only.

### Basic range

```cpp
NumberRange range{10};

for(auto value: range)
    // use value {0 - 9}
```

### Reverse range

```cpp
NumberRange range{10}

for(auto value : ReverseIterator{range})
    // use value {9 - 0}
```

### Range start point

```cpp
NumberRange range{10,5};

for(auto value : range)
    // use value {5 - 9}
```

### Reverse range start point

```cpp
NumberRange range{10,5};

for(auto value : ReverseIterator{range})
    // use value {9 - 5}
```

### Range with step size

```cpp
NumberRange range{10,0,2};

for(auto value : range)
    // use value {0, 2, 4, 6, 8}
```

### Reverse range step size

```cpp
NumberRange range{10,0,2};

for(auto value : ReverseIterator{range})
    // use value {9, 7, 5, 3, 1}
```

This might seem superising but is consistent C++ indexing rules

### Range with char type

```cpp
NumberRange range{'Z','A'};

for(auto value : range)
    // use value {'A' - 'Z'}
```

### Reverse range with char type

```cpp
NumberRange range{'A','Z'};

for(auto value : NR::ReverseIterator{range})
    // use value {'Z' - 'A'}
```

### Here be dragons
The library does no bounds checking it is the responsibility of the client to make sure 
given values don’t overflow when iterating, this is espically true when the iteration 
steps are greater than one.

Negitive ranges is currently not supported, it is the responsibility of the client 
to make sure range construction values do not flowing into negitive states during iteration
