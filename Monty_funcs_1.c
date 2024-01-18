#include "monty.h"

void pushToStack(stack_t **stack, unsigned int lineNum);
void printStackValues(stack_t **stack, unsigned int lineNum);
void printTopValue(stack_t **stack, unsigned int lineNum);
void popFromStack(stack_t **stack, unsigned int lineNum);
void swapTopTwoValues(stack_t **stack, unsigned int lineNum);

/**
 * pushToStack - Pushes a value to a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @lineNum: The current working line number of a Monty bytecodes file.
 */
void pushToStack(stack_t **stack, unsigned int lineNum)
{
    stack_t *tmp, *newNode;
    int i;

    newNode = malloc(sizeof(stack_t));
    if (newNode == NULL)
    {
        set_op_tok_error(malloc_error());
        return;
    }

    if (op_toks[1] == NULL)
    {
        set_op_tok_error(no_int_error(lineNum));
        return;
    }

    for (i = 0; op_toks[1][i]; i++)
    {
        if (op_toks[1][i] == '-' && i == 0)
            continue;
        if (op_toks[1][i] < '0' || op_toks[1][i] > '9')
        {
            set_op_tok_error(no_int_error(lineNum));
            return;
        }
    }
    newNode->n = atoi(op_toks[1]);

    if (check_mode(*stack) == STACK)
    {
        tmp = (*stack)->next;
        newNode->prev = *stack;
        newNode->next = tmp;
        if (tmp)
            tmp->prev = newNode;
        (*stack)->next = newNode;
    }
    else
    {
        tmp = *stack;
        while (tmp->next)
            tmp = tmp->next;
        newNode->prev = tmp;
        newNode->next = NULL;
        tmp->next = newNode;
    }
}

/**
 * printStackValues - Prints the values of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @lineNum: The current working line number of a Monty bytecodes file.
 */
void printStackValues(stack_t **stack, unsigned int lineNum)
{
    stack_t *tmp = (*stack)->next;

    while (tmp)
    {
        printf("%d\n", tmp->n);
        tmp = tmp->next;
    }
    (void)lineNum;
}

/**
 * printTopValue - Prints the top value of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @lineNum: The current working line number of a Monty bytecodes file.
 */
void printTopValue(stack_t **stack, unsigned int lineNum)
{
    if ((*stack)->next == NULL)
    {
        set_op_tok_error(pint_error(lineNum));
        return;
    }
    printf("%d\n", (*stack)->next->n);
}

/**
 * popFromStack - Removes the top value element of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @lineNum: The current working line number of a Monty bytecodes file.
 */
void popFromStack(stack_t **stack, unsigned int lineNum)
{
    stack_t *next = NULL;

    if ((*stack)->next == NULL)
    {
        set_op_tok_error(pop_error(lineNum));
        return;
    }

    next = (*stack)->next->next;
    free((*stack)->next);
    if (next)
        next->prev = *stack;
    (*stack)->next = next;
}

/**
 * swapTopTwoValues - Swaps the top two value elements of a stack_t linked list.
 * @stack: A pointer to the top mode node of a stack_t linked list.
 * @lineNum: The current working line number of a Monty bytecodes file.
 */
void swapTopTwoValues(stack_t **stack, unsigned int lineNum)
{
    stack_t *tmp;

    if ((*stack)->next == NULL || (*stack)->next->next == NULL)
    {
        set_op_tok_error(short_stack_error(lineNum, "swap"));
        return;
    }

    tmp = (*stack)->next->next;
    (*stack)->next->next = tmp->next;
    (*stack)->next->prev = tmp;
    if (tmp->next)
        tmp->next->prev = (*stack)->next;
    tmp->next = (*stack)->next;
    tmp->prev = *stack;
    (*stack)->next = tmp;
}
