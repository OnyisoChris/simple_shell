#include "shell.h"
#include <unistd.h>

/**
 * shell_exit - Exits the shell with or without a return status.
 * @a: Array of arguments.
 */
void shell_exit(char **a)
{
	int j, k;

	if (a[1])
	{
		k = ato_i(a[1]);
		if (k <= -1)
			k = 2;
		free_arv(a);
		exit(k);
	}
	for (j = 0; a[j]; j++)
		free(a[j]);
	free(a);
	exit(0);
}

/**
 * ato_i - Converts a string to an integer.
 * @string: The input string.
 * Return: The converted integer.
 */
int ato_i(char *string)
{
	int k, l, m = 1;

	k = 0;
	l = 0;
	while (!((string[k] >= '0') && (string[k] <= '9')) && (string[k] != '\0'))
	{
		if (string[k] == '-')
		{
			m = m * (-1);
		}
		k++;
	}
	while ((string[k] >= '0') && (string[k] <= '9'))
	{
		l = (l * 10) + (m * (string[k] - '0'));
		k++;
	}
	return (l);
}

/**
 * envir - Prints the current environment variables.
 * @ar: Array of arguments (unused).
 */
void envir(char **ar __attribute__ ((unused)))
{
	int k;

	for (k = 0; environ[k]; k++)
	{
		_puts(environ[k]);
		_puts("\n");
	}
}

/**
 * envset - Initializes or modifies an environment variable.
 * @a: Array of entered words.
 */
void envset(char **a)
{
	int k, l, m;

	if (!a[1] || !a[2])
	{
		perror(handle_env("_"));
		return;
	}

	for (k = 0; environ[k]; k++)
	{
		l = 0;
		if (a[1][l] == environ[k][l])
		{
			while (a[1][l])
			{
				if (a[1][l] != environ[k][l])
					break;

				l++;
			}
			if (a[1][l] == '\0')
			{
				m = 0;
				while (a[2][m])
				{
					environ[k][l + 1 + m] = a[2][m];
					m++;
				}
				environ[k][l + 1 + m] = '\0';
				return;
			}
		}
	}
	if (!environ[k])
	{
		environ[k] = handle_concat(a[1], "=", a[2]);
		environ[k + 1] = '\0';
	}
}

/**
 * env_unset - Removes an environment variable.
 * @a: Array of entered words.
 */
void env_unset(char **a)
{
	int k, l;

	if (!a[1])
	{
		perror(handle_env("_"));
		return;
	}
	for (k = 0; environ[k]; k++)
	{
		l = 0;
		if (a[1][l] == environ[k][l])
		{
			while (a[1][l])
			{
				if (a[1][l] != environ[k][l])
					break;
				l++;
			}
			if (a[1][l] == '\0')
			{
				free(environ[k]);
				environ[k] = environ[k + 1];
				while (environ[k])
				{
					environ[k] = environ[k + 1];
					k++;
				}
				return;
			}
		}
	}
}
