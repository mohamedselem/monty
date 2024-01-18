#include "monty.h"

/**
 * print_char - func do Prints Ascii value.
 * @stack: Pointer to a pointer pointing to top node.
 * @line_number: Interger represente the line number of opcode.
 */
void print_char(stack_t **stack, unsigned int line_number)
{
	int asc;

	if (stack == NULL || *stack == NULL)
		string_err(11, line_number);

	asc = (*stack)->n;
	if (asc < 0 || asc > 127)
		string_err(10, line_number);
	printf("%c\n", asc);
}

/**
 * print_str - func do Prints a string.
 * @stack: Pointer to a pointer pointing to top node.
 * @ln: Interger represente the line number of opcode.
 */
void print_str(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	int asc;
	stack_t *temp;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	temp = *stack;
	while (temp != NULL)
	{
		asc = temp->n;
		if (asc <= 0 || asc > 127)
			break;
		printf("%c", asc);
		temp = temp->next;
	}
	printf("\n");
}

/**
 * rotl - func to Rotate the first node to the bottom.
 * @stack: Pointer to a pointer pointing to top node.
 * @ln: Interger represente the line number of opcode.
 */
void rotl(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;
	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;
	(*stack)->prev = temp;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}


/**
 * rotr - func to Rotates the last node to the top.
 * @stack: Pointer to a pointer pointing to top node.
 * @ln: Interger represente the line number of opcode.
 */
void rotr(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return;

	temp = *stack;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *stack;
	temp->prev->next = NULL;
	temp->prev = NULL;
	(*stack)->prev = temp;
	(*stack) = temp;
}
