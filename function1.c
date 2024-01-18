#include "monty.h"


/**
 * add_to_stack - Func to adds a node to the stack.
 * @node1: Pointer to new node.
 * @lnte: Interger represent the line number of opcode.
 */
void add_to_stack(stack_t **node1, __attribute__((unused))unsigned int lnte)
{
	stack_t *temp;

	if (node1 == NULL || *node1 == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *node1;
		return;
	}
	temp = head;
	head = *node1;
	head->next = temp;
	temp->prev = head;
}


/**
 * print_stack - Adds a node to the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: line number of  the opcode.
 */
void print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void) line_number;
	if (stack == NULL)
		exit(EXIT_FAILURE);
	temp = *stack;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}

/**
 * pop_top - func Add a node to the stack.
 * @stack: the Pointer to a pointer pointing to top node
 * @line_number: Interger represent the line number of of the opcode.
 */
void pop_top(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
		more_err(7, line_number);

	temp = *stack;
	*stack = temp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}

/**
 * print_top - func to Print the top node of the stack
 * @stack: Pointer to a pointer pointing to top node
 * @line_number: Interger represente the line number of the opcode
 */
void print_top(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
		more_err(6, line_number);
	printf("%d\n", (*stack)->n);
}
