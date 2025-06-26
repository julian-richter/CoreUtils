# CoreUtils Library

A simple C library with C++ example application.

## Project Structure

```
├── CMakeLists.txt           # Main build configuration
├── include/                 # Public header files
│   └── coreutils/          # Library headers
│       └── library.h       # Main library header
├── src/                    # Library source files
│   └── library.c           # Library implementation
└── examples/               # Example applications
    └── example.cxx         # C++ example application
```

## Building the Library

```bash
mkdir build
cd build
cmake ..
make
```

## Running the Example

```bash
./example
```

## Using the Library in Other Projects

When using this library in other CMake projects:

```cmake
find_package(coreUtils REQUIRED)
target_link_libraries(your_target PRIVATE coreUtils::coreUtils)
```

And include the headers in your code:

```cpp
#include "coreutils/library.h"
```
