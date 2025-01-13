# buster

A tiny, single file, header only assertion library library for C++23

## Usage

The general idea of this library is to give you a way to write tests in any way you see fit, so it's
not really doing anything but giving you assertion functions.

One way to use buster, which is how I like to do tests these days:
- Make a tests directory, add the [src/buster.hpp](src/buster.hpp) and start adding your tests
- Create a new .cpp file for every test case
- Write a script that builds all of them and then executes them

Example for one test case:

```cpp
#include "buster.hpp"

// the function we're going to test
int adder(int a, int b) {
    return a + b;
}

int main() {
    expect_equals(4, adder(2, 2));
    expect_true(adder(2, 3) == 5);

    return 0;
}
```

## License

BSD 0-Clause
