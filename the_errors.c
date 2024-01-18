#include "monty.h"

/**
 * err - func do Prints error messages determined by error code.
 * @error_code: error codes are the following:
 * (case no 1) => user not given any file or more than afile to the program.
 * (case no 2) => The file provided is not a file that can be opened or read.
 * (case no 3) => The file provided contains an invalid instruction.
 * (case no 4) => When the program is unable to malloc more memory.
 * (case no 5) => parameter passed to the instruction is not an int.
 * (case no 6) => the stack it empty for pint.
 * (case no 7) => the stack it empty for pop.
 * (case no 8) => stack is too short for operation.
 */
void err(int error_code, ...)
{
	va_list ag;
	char *ope;
	int num1;

	va_start(ag, error_code);
	switch (error_code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(ag, char *));
			break;
		case 3:
			num1 = va_arg(ag, int);
			ope = va_arg(ag, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", num1, ope);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(ag, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * more_err - handles errors.
 * @error_code: The error codes are the following:
 * (case no 6) => When the stack it empty for pint.
 * (case no 7) => When the stack it empty for pop.
 * (case no 8) => When stack is too short for operation.
 * (case no 9) => Division by zero.
 */
void more_err(int error_code, ...)
{
	va_list ag;
	char *ope;
	int num1;

	va_start(ag, error_code);
	switch (error_code)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(ag, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(ag, int));
			break;
		case 8:
			num1 = va_arg(ag, unsigned int);
			ope = va_arg(ag, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", num1, ope);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(ag, unsigned int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * string_err - func to handles errors.
 * @error_code: error codes are the following:
 * (case no 10) => The number inside a node is outside ASCII bounds.
 * (case no 11) => The stack is empty.
 */
void string_err(int error_code, ...)
{
	va_list ag;
	int num1;

	va_start(ag, error_code);
	num1 = va_arg(ag, int);
	switch (error_code)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", num1);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", num1);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
