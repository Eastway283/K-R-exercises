#include <stdio.h>
#include <limits.h>
#include <stdint.h>

/* Эта программа содержит все битовые упражнения  */
/* из главы 2 учебника по C K&R. Дата: 2026-02-16 */

unsigned getbits(unsigned x, int p, int n); /* извлекает n бит, начиная с p-й позиции */

unsigned setbits(unsigned x, int p, int n, unsigned y); /* изменяет n бит c p-й позиции числа x, делая их равными n крайним правым битам числа y */

unsigned invert(unsigned x, int p, int n); /* инвертирует n бит, начина с p-й позиции */

unsigned rightrot(unsigned x, int n); /* вращает x вправо на n двоичных разрядов */

unsigned toogle(unsigned x, int p); /* Переключает бит на позиции p */

unsigned getHalf(unsigned x, int n); /* извлекает n-ю половину бита, n принимает 1 или 2, в противном случае, возвращает x */

int bitcount(unsigned x); /* подсчитывает количество единиц в бите */

void print_binary_padded(unsigned int n, int bits) {
    for (int i = bits - 1; i >= 0; i--) {
        putchar((n >> i) & 1 ? '1' : '0');
    }
}

int main(void)
{

    uint8_t x = 0b10101100;
    int bits = sizeof(x) * CHAR_BIT;

    print_binary_padded(x, bits);
    putchar('\n');
    printf("Toogle bits in value: %d\n", bitcount(x));

    x = invert(x, 6, 3);
    printf("After invert, p == 6, n == 3:\n");
    print_binary_padded(x, bits);
    putchar('\n');

    x = toogle(x, 7);
    printf("After toogle, n == 7:\n");
    print_binary_padded(x, bits);
    putchar('\n');

    x = getHalf(x, 2);
    printf("After getHalf, n == 2:\n");
    print_binary_padded(x, bits);
    putchar('\n');

    return 0;
}

unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p + 1 - n)) & ~(~0 << n);
}

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    unsigned target_y = y & ~(~0 << n);
    unsigned shifted = target_y << (p + 1 - n);
    unsigned mask = ~(~0 << n) << (p + 1 - n);
    return (x & ~mask) | shifted;
}

unsigned invert(unsigned x, int p, int n)
{
    unsigned mask = ((1 << n) - 1) << (p + 1 - n);
    return x ^ mask;
}

unsigned rightrot(unsigned x, int n)
{
    int bits = sizeof(x) * CHAR_BIT;

    if (n == 0)
        return x;

    n %= bits;

    return (x >> n) | (x << (bits - n));
}

unsigned toogle(unsigned x, int p)
{
    return x ^ (1 << p);
}

unsigned getHalf(unsigned x, int n)
{
    if (n == 1)
        return (x & 0x0F);
    if (n == 2)
        return (x >> 4);
    return x;
}

int bitcount(unsigned x)
{
    int b = 0;
    while (x != 0)
    {
        x &= (x - 1);
        ++b;
    }
    return b;
}
