#include "shell.h"

/**
 * _sighandler - Handles the SIGINT signal (Ctrl+C) & displays the shell prompt
 * @sig_n: The signal number.
 */
void _sighandler(int sig_n)
{
	if (sig_n == SIGINT)
	{
		_puts("\n#shellaway$ ");
	}

}

/**
 * E_O_F - Handles the end of file (EOF) condition.
 * @length: The length of the input line.
 * @buffer: The input buffer.
 */
void E_O_F(int length, char *buffer)
{
	(void)buffer;
	if (length == -1)
	{
		if (isatty(STDIN_FILENO))
		{
			_puts("\n");
			free(buffer);
		}
		exit(0);
	}
}

/**
 * is_atty - Checks if STDIN is a terminal and displays the shell prompt.
 */
void is_atty(void)
{
	if (isatty(STDIN_FILENO))
		_puts("#shellaway$ ");
}

/**
 * main - The main function of the shell program.
 * Return: Always 0.
 */
int main(void)
{
	ssize_t length = 0;
	char *buffer = NULL, *val, *path_name, **ar;
	size_t sze = 0;
	handle_path *headd = '\0';
	void (*j)(char **);

	signal(SIGINT, _sighandler);
	while (length != EOF)
	{
		is_atty();
		length = getline(&buffer, &sze, stdin);
		E_O_F(length, buffer);
		ar = str_split(buffer, " \n");
		if (!ar || !ar[0])
			exec(ar);
		else
		{
			val = handle_env("PATH");
			headd = pathlink(val);
			path_name = find_path(ar[0], headd);
			j = handlebuild(ar);
			if (j)
			{
				free(buffer);
				j(ar);
			}
			else if (!path_name)
				exec(ar);
			else if (path_name)
			{
				free(ar[0]);
				ar[0] = path_name;
				exec(ar);
			}
		}
	}
	_freelist(headd);
	free_arv(ar);
	free(buffer);
	return (0);
}
