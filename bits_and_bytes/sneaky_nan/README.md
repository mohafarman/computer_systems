# sneaky_nan
Hiding a message inside a floating point. Project exercise from [csprimer](https://csprimer.com/watch/sneaky-nan/). This is my implementation.

References used includes articles from wikipedia about [floating-point arithmetics](https://en.wikipedia.org/wiki/Floating-point_arithmetic#IEEE_754:_floating_point_in_modern_computers) and [NaN](https://en.wikipedia.org/wiki/NaN) as well as [zetcode](https://www.zetcode.com/clang/float-type/) for binary representation on floating-point types. I could not have figured it out without this stackoverflow [article](https://stackoverflow.com/questions/8680220/how-to-get-the-value-of-individual-bytes-of-a-variable#8680360) on getting the value of individual bytes of a variable.

# Run
To run with gcc and enabled debugging information on a Linux-based system.
``` shell
gcc main.c -ggdb -o sneaky_nan && ./sneaky_nan
```
