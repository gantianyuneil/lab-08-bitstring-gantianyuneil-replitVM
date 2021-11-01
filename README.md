Bit Strings
===

In this lab you will convert an integer to an ASCII string of `1` and
`0` characters representing the 32 individual bits of the integer, from
most significant bit to least significant bit.  This will require you to
use bit manipulations and masking, as well as reinforce the structure of
integers.

Requirements
---

You must implement the function `bitstring()` in `bitstring.c`.  This
function accepts an integer and a character pointer, and writes a string
of exactly 32 ASCII `'1'` and `'0'` characters followed by a terminating
NUL byte to the location beginning at the character pointer, containing
the bit representation in the input integer.

```c
void bitstring(int32_t in, char *out);
```

The bits of `in`, from 0 to 31, should be placed into the string `out`,
with bit 31 in out[0] and bit 0 in out[31], followed by a terminating
NUL character, with an ASCII `'1'` character representing a one bit and
an ASCII `'0'` character representing a 0 bit.  Thus, the integer `1`
would produce the string `"00000000000000000000000000000001"`.

Possible Strategies
---

There are two likely strategies for pulling the individual bit values
out of an integer:

 * Shifting a mask one bit at a time, and applying it to the fixed integer
 * Shifting the integer one bit at a time, and applying a fixed mask to it

It is also (because the number of bits in the integer is a fixed
constant) possible to process the integer in either most-significant to
least-significant bit order, or least-significant to most-significant.

Building and Testing
---

As usual, `make` will build your project, and `make test` will run a
simple test suite.

Submission
---

Submit _only_ the file `bitstring.c` to Autograder.

Grading
---

Points will be awarded as follows:

 * 1 pt: The integer `0x1` is properly encoded
 * 1 pt: The integer `0x55555555` is properly encoded
 * 1 pt: The integer `0x80000000` is properly encoded
 * 1 pt: A random positive integer is properly encoded
 * 1 pt: A random negative integer is properly encoded
