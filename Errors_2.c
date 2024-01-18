#include "monty.h"

int handleShortStackError(unsigned int lineNum, char *operation);
int handleDivisionError(unsigned int lineNum);
int handlePopError(unsigned int lineNum);
int handlePintError(unsigned int lineNum);
int handlePcharError(unsigned int lineNum, char *errorMsg);

/**
 * handlePopError - Prints pop error messages for empty stacks.
 * @lineNum: Line number in script where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int handlePopError(unsigned int lineNum)
{
    fprintf(stderr, "L%u: can't pop an empty stack\n", lineNum);
    return (EXIT_FAILURE);
}

/**
 * handlePintError - Prints pint error messages for empty stacks.
 * @lineNum: Line number in Monty bytecodes file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int handlePintError(unsigned int lineNum)
{
    fprintf(stderr, "L%d: can't pint, stack empty\n", lineNum);
    return (EXIT_FAILURE);
}

/**
 * handleShortStackError - Prints monty math function error messages
 *                         for stacks/queues smaller than two nodes.
 * @lineNum: Line number in Monty bytecodes file where error occurred.
 * @operation: Operation where the error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int handleShortStackError(unsigned int lineNum, char *operation)
{
    fprintf(stderr, "L%u: can't %s, stack too short\n", lineNum, operation);
    return (EXIT_FAILURE);
}

/**
 * handleDivisionError - Prints division error messages for division by 0.
 * @lineNum: Line number in Monty bytecodes file where error occurred.
 *
 * Return: (EXIT_FAILURE) always.
 */
int handleDivisionError(unsigned int lineNum)
{
    fprintf(stderr, "L%u: division by zero\n", lineNum);
    return (EXIT_FAILURE);
}

/**
 * handlePcharError - Prints pchar error messages for empty stacks
 *                   and non-character values.
 * @lineNum: Line number in Monty bytecodes file where error occurred.
 * @errorMsg: The corresponding error message to print.
 *
 * Return: (EXIT_FAILURE) always.
 */
int handlePcharError(unsigned int lineNum, char *errorMsg)
{
    fprintf(stderr, "L%u: can't pchar, %s\n", lineNum, errorMsg);
    return (EXIT_FAILURE);
}
