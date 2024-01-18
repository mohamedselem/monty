#include "monty.h"

/**
 * nop - do nothing
 * @stack: Pointer to a pointer pointing top node of stack.
 * @line_number: Interger represente the line number of opcode.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}


/**
 * swap_nodes - func to Swap the top elements of the stack.
 * @stack: Pointer to a pointer pointing to top node .
 * @line_number: Interger represente the line number of opcode.
 */
void swap_nodes(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "swap");
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	if (temp->next != NULL)
		temp->next->prev = *stack;
	temp->next = *stack;
	(*stack)->prev = temp;
	temp->prev = NULL;
	*stack = temp;
}

/**
 * add_nodes - func Adds the top elements of the stack.
 * @stack: Pointer to a pointer pointing to top node .
 * @line_number: Interger representing line number of the opcode.
 */
void add_nodes(stack_t **stack, unsigned int line_number)
{
	int summ;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "add");

	(*stack) = (*stack)->next;
	summ = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = summ;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * sub_nodes - func to Add the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger represente the line number of the opcode.
 */
void sub_nodes(stack_t **stack, unsigned int line_number)
{
	int summ;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_err(8, line_number, "sub");


	(*stack) = (*stack)->next;
	summ = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = summ;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * div_nodes - func to Add the top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node of the stack.
 * @line_number: Interger representing the line number of the opcode.
 */
void div_nodes(stack_t **stack, unsigned int line_number)
{
	int summ;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "div");

	if ((*stack)->n == 0)
		more_err(9, line_number);
	(*stack) = (*stack)->next;
	summ = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = summ;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
