#include <stdlib.h>

char *convertIntToString(int num);
unsigned int absoluteValue(int);
int calculateNumBaseLength(unsigned int num, unsigned int base);
void fillNumBaseBuffer(unsigned int num, unsigned int base,
                       char *buffer, int bufferSize);

/**
 * convertIntToString - Converts an integer to a string.
 * @num: Number to convert.
 *
 * Return: Pointer to the newly created string. NULL if malloc fails.
 */
char *convertIntToString(int num)
{
    unsigned int absoluteNum;
    int length = 0;
    long numLong = 0;
    char *result;

    absoluteNum = absoluteValue(num);
    length = calculateNumBaseLength(absoluteNum, 10);

    if (num < 0 || numLong < 0)
        length++; /* for negative sign */
    result = malloc(length + 1); /* create a new string */
    if (!result)
        return (NULL);

    fillNumBaseBuffer(absoluteNum, 10, result, length);
    if (num < 0 || numLong < 0)
        result[0] = '-';

    return result;
}

/**
 * absoluteValue - Gets the absolute value of an integer.
 * @i: Integer to get the absolute value of.
 *
 * Return: Unsigned integer representing the absolute value of i.
 */
unsigned int absoluteValue(int i)
{
    if (i < 0)
        return (-(unsigned int)i);
    return (unsigned int)i;
}

/**
 * calculateNumBaseLength - Gets the length of a buffer needed for an unsigned int.
 * @num: Number to get the length needed for.
 * @base: Base of the number representation used by the buffer.
 *
 * Return: Integer containing the length of the buffer needed (doesn't contain null byte).
 */
int calculateNumBaseLength(unsigned int num, unsigned int base)
{
    int length = 1; /* all numbers contain at least one digit */

    while (num > base - 1)
    {
        length++;
        num /= base;
    }
    return length;
}

/**
 * fillNumBaseBuffer - Fills a buffer with correct numbers up to base 36.
 * @num: Number to convert to a string given a base.
 * @base: Base of the number used in conversion (works up to base 36).
 * @buffer: Buffer to fill with the result of the conversion.
 * @bufferSize: Size of the buffer in bytes.
 *
 * Return: Always void.
 */
void fillNumBaseBuffer(unsigned int num, unsigned int base,
                       char *buffer, int bufferSize)
{
    int remainder, i = bufferSize - 1;

    buffer[bufferSize] = '\0';
    while (i >= 0)
    {
        remainder = num % base;
        if (remainder > 9) /* return lowercase ASCII value representation */
            buffer[i] = remainder + 87; /* 10 will be a, 11 = b, ... */
        else
            buffer[i] = remainder + '0';
        num /= base;
        i--;
    }
}
