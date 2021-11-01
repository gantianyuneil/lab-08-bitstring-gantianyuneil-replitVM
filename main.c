#include <stdio.h>
#include <stdint.h>
#include <string.h>

void bitstring(int32_t in, char *out);

/* This structure forms a test input and expected output; the input is
 * an int32_t, and the result is exactly the string expected to be
 * returned by bitstring().  The list of such structures tests[] is
 * terminated by a structure with an expected result of NULL. */
const struct {
    const int32_t val;
    const char *result;
} tests[] = {
    { 0x00000001, "00000000000000000000000000000001" },
    { 0x55555555, "01010101010101010101010101010101" },
    { 0x80000000, "10000000000000000000000000000000" },
    { 0x12345678, "00010010001101000101011001111000" },
    { 0xABCDEF01, "10101011110011011110111100000001" },
    { 0x0, NULL }
};

int main(int argc, char *argv[])
{
    for (int i = 0; tests[i].result != NULL; i++) {
        char output[8 * sizeof(int32_t) + 1] = { '\0' };
        bitstring(tests[i].val, output);

        printf("Checking 0x%08x: ", tests[i].val);
        if (!strncmp(tests[i].result, output, sizeof(output))) {
            puts("passed");
        } else {
            puts("failed");
        }
    }

    return 0;
}
