#include "shell.h"

/**
 * str_dup - Duplicate a string.
 * @string: The string to be duplicated.
 *
 * Return: A new duplicated string or NULL on failure.
 */
char *str_dup(const char *string)
{
	int m, n;
	char *n_new;

	if (!string)
	{
		return (NULL);
	}
	for (n = 0; string[n] != '\0';)
	{
		n++;
	}
	
	n_new = malloc(sizeof(char) * n + 1);

	if (!n_new)
	{
		return (NULL);
	}

	for (m = 0; m <= n; m++)
	{
		n_new[m] = string[m];
	}
	n_new[n] = string[n];
	return (n_new);
}

/**
 * handle_concat - Concatenate three strings.
 * @nme: The first string.
 * @sec_str: The second string to be inserted in the middle.
 * @val: The third string.
 *
 * Return: A new string resulting from the concatenation or NULL on failure.
 */
char *handle_concat(char *nme, char *sec_str, char *val)
{
	char *solution;
	int i1, i2, i3, m, n;

	i1 = str_len(nme);
	i2 = str_len(sec_str);
	i3 = str_len(val);

	solution = malloc(i1 + i2 + i3 + 1);
	if (!solution)
		return (NULL);

	for (m = 0; nme[m]; m++)
		solution[m] = nme[m];
	n = m;

	for (m = 0; sec_str[m]; m++)
		solution[n + m] = sec_str[m];
	n = n + m;

	for (m = 0; val[m]; m++)
		solution[n + m] = val[m];
	n = n + m;

	solution[n] = '\0';

	return (solution);
}

/**
 * str_len - Calculate the length of a string.
 * @str: The input string.
 *
 * Return: The length of the string.
 */
int str_len(char *str)
{
	int k = 0;

	while (*(str + k) != '\0')
	{
		k++;
	}
	return (k);
}

/**
 * _putchar - Write a character to standard output.
 * @ch: The character to be written.
 *
 * Return: The number of characters written (1).
 */
int _putchar(char ch)
{
	return (write(1, &ch, 1));
}

/**
 * _puts - Write a string to standard output.
 * @string: The string to be written.
 */
void _puts(char *string)
{
	int k = 0;

	while (string[k])
	{
		_putchar(string[k]);
		k++;
	}
}
