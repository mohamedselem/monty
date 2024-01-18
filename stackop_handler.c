#include "monty.h"

/**
 * mul_nodes - func to Add top two elements of the stack.
 * @stack: Pointer to a pointer pointing to top node.
 * @line_number: Interger represente the line number of opcode.
 */
void mul_nodes(stack_t **stack, unsigned int line_number)
{
	int summ;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		more_err(8, line_number, "mul");

	(*stack) = (*stack)->next;
	summ = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = summ;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * mod_nodes - func to Add the top elements of the stack.
 * @stack: Pointer to a pointer pointing to top node.
 * @line_number: Interger represente the line number of opcode.
 */
void mod_nodes(stack_t **stack, unsigned int line_number)
{
	int summ;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

		more_err(8, line_number, "mod");


	if ((*stack)->n == 0)
		more_err(9, line_number);
	(*stack) = (*stack)->next;
	summ = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = summ;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
