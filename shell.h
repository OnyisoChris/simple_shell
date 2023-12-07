#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <stddef.h>
#include <string.h>
#include <errno.h>
#include <sys/stat.h>

int _putchar(char ch);
void _puts(char *string);
int str_len(char *str);
char *str_dup(const char *string);
char *handle_concat(char *nme, char *sec_str, char *val);

char **str_split(char *string, const char *deli);
void exec(char **argv);
void *re_alloc(void *ptrr, unsigned int prev_size, unsigned int now_size);

extern char **environ;

/**
 * struct handle_path - Represents a linked list node for managing PATH directories.
 *
 * @dirr: The PATH directory string.
 * @m: A pointer to the next node in the linked list.
 */
typedef struct handle_path
{
	char *dirr;
	struct handle_path *m;
} handle_path;

char *handle_env(const char *nme);
handle_path *node_end_plus(handle_path **headd, char *string);
handle_path *pathlink(char *_path);
char *find_path(char *f_name, handle_path *headd);

/**
 * struct _mybuild - Represents a command and its associated function pointer.
 *
 * @nme: The name of the command.
 * @funct: A function pointer to the command's corresponding function.
 */
typedef struct _mybuild
{
	char *nme;
	void (*funct)(char **);
} _mybuild;

void(*handlebuild(char **ar))(char **ar);
void shell_exit(char **a);
int ato_i(char *string);
void envir(char **ar __attribute__ ((unused)));
void envset(char **a);
void env_unset(char **a);

void free_arv(char **arvv);
void _freelist(handle_path *headd);

#endif
