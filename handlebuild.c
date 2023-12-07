#include "shell.h"

/**
 * handlebuild - Finds and returns a function pointer based on a command.
 * @ar: An array of command arguments.
 *
 * Return: A function pointer corresponding to the command,
 * or NULL if not found.
 */
void(*handlebuild(char **ar))(char **ar)
{
	int m, n;
	_mybuild K[] = {
		{"exit", shell_exit},
		{"env", envir},
		{"setenv", envset},
		{"unsetenv", env_unset},
		{NULL, NULL}
	};

	for (m = 0; K[m].nme; m++)
	{
		n = 0;
		if (K[m].nme[n] == ar[0][n])
		{
			for (n = 0; ar[0][n]; n++)
			{
				if (K[m].nme[n] != ar[0][n])
					break;
			}
			if (!ar[0][n])
				return (K[m].funct);
		}
	}
	return (0);
}
