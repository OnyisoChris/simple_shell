#include "shell.h"

/**
 * handle_env - Retrieve the value of an environment variable by name.
 * @nme: The name of the environment variable to retrieve.
 *
 * Return: The value of the environment variable or NULL if not found.
 */
char *handle_env(const char *nme)
{
	int k, l;
	char *val;

	if (!nme)
		return (NULL);
	for (k = 0; environ[k]; k++)
	{
		l = 0;
		if (nme[l] == environ[k][l])
		{
			while (nme[l])
			{
				if (nme[l] != environ[k][l])
					break;
				l++;
			}
			if (nme[l] == '\0')
			{
				val = (environ[k] + l + 1);
				return (val);
			}
		}
	}
	return (0);
}

/**
 * node_end_plus - Append a node to the end of a linked list of directories.
 * @headd: Pointer to the head of the linked list.
 * @string: The directory path to be added to the linked list.
 *
 * Return: Pointer to the updated head of the linked list.
 */
handle_path *node_end_plus(handle_path **headd, char *string)
{
	handle_path *temp;
	handle_path *n_new;

	n_new = malloc(sizeof(handle_path));

	if (!n_new || !string)
	{
		return (NULL);
	}

	n_new->dirr = string;

	n_new->m = '\0';
	if (!*headd)
	{
		*headd = n_new;
	}
	else
	{
		temp = *headd;

		while (temp->m)
		{
			temp = temp->m;
		}

		temp->m = n_new;
	}

	return (*headd);
}

/**
 * pathlink - Create a linked list of directory paths.
 * @_path: The colon-separated string of directory paths.
 *
 * Return: Pointer to the head of the linked list.
 */
handle_path *pathlink(char *_path)
{
	handle_path *headd = '\0';
	char *tokn;
	char *c_path = str_dup(_path);

	tokn = strtok(c_path, ":");
	while (tokn)
	{
		headd = node_end_plus(&headd, tokn);
		tokn = strtok(NULL, ":");
	}

	return (headd);
}

/**
 * find_path - Search for a file in a list of directories.
 * @f_name: The name of the file to search for.
 * @headd: Pointer to the head of the linked list of directories.
 *
 * Return: The full path to the file if found, or NULL if not found.
 */
char *find_path(char *f_name, handle_path *headd)
{
	struct stat sts;
	char *str;

	handle_path *temp = headd;

	while (temp)
	{
		str = handle_concat(temp->dirr, "/", f_name);
		if (stat(str, &sts) == 0)
		{
			return (str);
		}
		free(str);
		temp = temp->m;
	}

	return (NULL);
}

/**
 * _freelist - Free the memory allocated for a linked list of directories.
 * @headd: Pointer to the head of the linked list.
 */
void _freelist(handle_path *headd)
{
	handle_path *storage;

	while (headd)
	{
		storage = headd->m;
		free(headd->dirr);
		free(headd);
		headd = storage;
	}
}
