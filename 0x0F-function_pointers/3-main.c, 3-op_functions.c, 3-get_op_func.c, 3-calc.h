#ifndef CALC_H
#define CALC_H

/**
 * struct op - Struct op
 *
 * @op: operator
 * @f: function
 */
typedef struct op
{
	char *op;
	int (*f)(int a, int b);
}
op_t;

int op_add(int a, int b);
int op_sub(int a, int b);
int op_mul(int a, int b);
int op_div(int a, int b);
int op_mod(int a, int b);
int (*get_op_func(char *s))(int, int);

#endif

#include "3-calc.h"
#include <stdlib.h>

/**
 * get_op_func - select the correct operation function asked by user
 * @s: operator argument
 * Return: function pointer corresponding to operator given
 */
int (*get_op_func(char *s))(int, int)
{
	op_t ops[] = {
		{"+", op_add},
		{"-", op_sub},
		{"*", op_mul},
		{"/", op_div},
		{"%", op_mod},
		{NULL, NULL}
	};
	int i = 0;

	while (ops[i].op != NULL && *(ops[i].op) != *s)
		i++;
	return (ops[i].f);
}

#include "3-calc.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * main - Prints the result of simple operations.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: Always 0.
 */

int main(int argc, char *argv[])
{
	int num1, num2;
	char *op;

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}
	num1 = atoi(argv[1]);
	op = argv[2];
	num2 = atoi(argv[3]);

	if (get_op_func(op) == NULL || op[1] != '\0')
	{
		printf("Error\n");
		exit(99);
	}
	if ((*op == '/' && num2 == 0) ||
			(*op == '%' && num2 == 0))
	{
		printf("Error\n");
		exit(100);
	}
	printf("%d\n", get_op_func(op)(num1, num2));
	return (0);
}

#include "3-calc.h"

/**
 * op_add - addition operator
 * @a: first int
 * @b: second int
 * Return: sum of 2 numbers
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - subtraction operator
 * @a: first in
 * @b: second int
 *Return: difference of 2 numbers
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - product of 2 numbers
 * @a: first int
 *  @b: second int
 *  Return: product of the numbers
 */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 *  op_div - division of 2 numbers
 *   @a: first int
 *    @b: second int
 *    Return: result of the division of the numbers
 */
int op_div(int a, int b)
{
	return (a / b);
}

/**
 * op_mod - get remainder of the division of 2 numbers
 * @a: first int
 *  @b: second int
 *  Return: remainder of division of the numbers
 */

int op_mod(int a, int b)
{
	return (a % b);
}
