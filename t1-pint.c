#include "monty.h"

void push(stack_t **stack, int value)
{
    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack != NULL)
        (*stack)->prev = new_node;

    *stack = new_node;
}

void pall(stack_t **stack)
{
    stack_t *current = *stack;
    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

void pint(stack_t **stack)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "L<line_number>: can't pint, stack empty\n");
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*stack)->n);
}

int main(void)
{
    stack_t *stack = NULL;

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    pall(&stack);

    pint(&stack);

    return 0;
}
