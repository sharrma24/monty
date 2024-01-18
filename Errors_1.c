#include "monty.h"

int custom_usage_error(void);
int custom_malloc_error(void);
int custom_f_open_error(char *filename);
int custom_unknown_op_error(char *opcode, unsigned int line_number);
int custom_no_int_error(unsigned int line_number);

/**
 * custom_usage_error - Prints custom usage error messages.
 *
 * Return: (EXIT_FAILURE) always.
 */
int custom_usage_error(void)
{
    fprintf(stderr, "Error: Please provide the correct usage - monty <filename>\n");
    return (EXIT_FAILURE);
}

/**
 * custom_malloc_error - Prints custom malloc error messages.
 *
 * Return: (EXIT_FAILURE) always.
 */
int custom_malloc_error(void)
{
    fprintf(stderr, "Error: Memory allocation failed\n");
    return (EXIT_FAILURE);
}

/**
 * custom_f_open_error - Prints custom file opening error messages w/ file name.
 * @filename: Name of file failed to open
 *
 * Return: (EXIT_FAILURE) always.
 */
int custom_f_open_error(char *filename)
{
    fprintf(stderr, "Error: Unable to open the file '%s'\n", filename);
    return (EXIT_FAILURE);
}

/**
 * custom_unknown_op_error - Prints custom unknown operation error messages w/ opcode.
 * @opcode: Opcode where error occurred.
 * @line_number: Line number of the error in the Monty file.
 *
 * Return: (EXIT_FAILURE) always.
 */
int custom_unknown_op_error(char *opcode, unsigned int line_number)
{
    fprintf(stderr, "Error at line %u: Unknown instruction - '%s'\n", line_number, opcode);
    return (EXIT_FAILURE);
}

/**
 * custom_no_int_error - Prints custom no integer argument error messages.
 * @line_number: Line number of the error in the Monty file.
 *
 * Return: (EXIT_FAILURE) always.
 */
int custom_no_int_error(unsigned int line_number)
{
    fprintf(stderr, "Error at line %u: Missing integer argument - Usage: push integer\n", line_number);
    return (EXIT_FAILURE);
}
