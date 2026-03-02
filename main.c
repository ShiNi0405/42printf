#include <stdio.h>    // Allowed here for comparison
#include "ft_printf.h"
#include <limits.h>
int main(void)
{
    int mine;
    int real;

    printf("--- 1. BASIC CHARACTERS & PERCENT ---\n");
    mine = ft_printf("Mine: %c %c %%\n", 'A', '0');
    real = printf("Real: %c %c %%\n", 'A', '0');
    printf("Return -> Mine: %d | Real: %d\n\n", mine, real);

    printf("--- 2. STRINGS ---\n");
    mine = ft_printf("Mine: [%s] [%s]\n", "42 Is Great", "");
    real = printf("Real: [%s] [%s]\n", "42 Is Great", "");
    printf("Return -> Mine: %d | Real: %d\n\n", mine, real);

    printf("--- 3. NULL STRING (Edge Case) ---\n");
    mine = ft_printf("Mine: %s\n", (char *)NULL);
    real = printf("Real: %s\n", (char *)NULL);
    printf("Return -> Mine: %d | Real: %d\n\n", mine, real);

    printf("--- 4. SIGNED INTEGERS (%%d, %%i) ---\n");
    mine = ft_printf("Mine: %d | %i | %d | %i\n", 0, -42, INT_MAX, INT_MIN);
    real = printf("Real: %d | %i | %d | %i\n", 0, -42, INT_MAX, INT_MIN);
    printf("Return -> Mine: %d | Real: %d\n\n", mine, real);

    printf("--- 5. UNSIGNED INTEGERS (%%u) ---\n");
    mine = ft_printf("Mine: %u | %u\n", 0, UINT_MAX);
    real = printf("Real: %u | %u\n", 0, UINT_MAX);
    printf("Return -> Mine: %d | Real: %d\n\n", mine, real);

    printf("--- 6. HEXADECIMAL (%%x, %%X) ---\n");
    mine = ft_printf("Mine: %x | %X | %x\n", 0, 255, -1);
    real = printf("Real: %x | %X | %x\n", 0, 255, -1);
    printf("Return -> Mine: %d | Real: %d\n\n", mine, real);

    printf("--- 7. POINTERS (%%p) ---\n");
    int x = 42;
    mine = ft_printf("Mine: %p | %p\n", &x, (void *)NULL);
    real = printf("Real: %p | %p\n", &x, (void *)NULL);
    printf("Return -> Mine: %d | Real: %d\n\n", mine, real);

    printf("--- 8. MIXED ARGUMENTS ---\n");
    mine = ft_printf("Mine: %s has %d points and hex %x\n", "John", 42, 42);
    real = printf("Real: %s has %d points and hex %x\n", "John", 42, 42);
    printf("Return -> Mine: %d | Real: %d\n\n", mine, real);

    return (0);
}
