#include "shell.h"


/**
 * str_split - Splits a string into array of substrings based on delimiter.
 * @string: The string to be split.
 * @deli: The delimiter used for splitting.
 *
 * Return: An array of substrings or NULL on failure.
 */
char **str_split(char *string, const char *deli)
{
	int k, w;
	char **arr;
	char *tokn;
	char *cp;

	cp = malloc(str_len(string) + 1);
	if (cp == NULL)
	{
		perror(handle_env("_"));
		return (NULL);
	}
	k = 0;
	while (string[k])
	{
		cp[k] = string[k];
		k++;
	}
	cp[k] = '\0';

	tokn = strtok(cp, deli);
	arr = malloc((sizeof(char *) * 2));
	arr[0] = str_dup(tokn);

	k = 1;
	w = 3;
	while (tokn)
	{
		tokn = strtok(NULL, deli);
		arr = re_alloc(arr, (sizeof(char *) * (w - 1)), (sizeof(char *) * w));
		arr[k] = str_dup(tokn);
		k++;
		w++;
	}
	free(cp);
	return (arr);
}

/**
 * exec - Execute a program with the given arguments.
 * @argv: An array of strings containing the program name and arguments.
 */
void exec(char **argv)
{
	int j, stat;

	if (!argv || !argv[0])
		return;
	j = fork();
	if (j == -1)
	{
		perror(handle_env("_"));
	}
	if (j == 0)
	{
		execve(argv[0], argv, environ);
		perror(argv[0]);
		exit(EXIT_FAILURE);
	}
	wait(&stat);
}

/**
 * re_alloc - Reallocate memory for a given pointer to a specified size.
 * @ptrr: Pointer to be reallocated.
 * @prev_size: Previous size of the memory block.
 * @now_size: New size of the memory block.
 *
 * Return: A pointer to the reallocated memory or NULL on failure.
 */
void *re_alloc(void *ptrr, unsigned int prev_size, unsigned int now_size)
{
	char *n_new;
	char *o_old;

	unsigned int k;

	if (ptrr == NULL)
		return (malloc(now_size));

	if (now_size == prev_size)
		return (ptrr);

	if (now_size == 0 && ptrr != NULL)
	{
		free(ptrr);
		return (NULL);
	}

	n_new = malloc(now_size);
	o_old = ptrr;

	if (n_new == NULL)
		return (NULL);

	if (now_size > prev_size)
	{
		for (k = 0; k < prev_size; k++)
			n_new[k] = o_old[k];
		free(ptrr);
		for (k = prev_size; k < now_size; k++)
			n_new[k] = '\0';
	}
	if (now_size < prev_size)
	{
		for (k = 0; k < now_size; k++)
			n_new[k] = o_old[k];
		free(ptrr);
	}
	return (n_new);
}

/**
 * free_arv - Free memory allocated for an array of strings.
 * @arvv: The array of strings to be freed.
 */
void free_arv(char **arvv)
{
	int k;

	for (k = 0; arvv[k]; k++)
		free(arvv[k]);
	free(arvv);
}
