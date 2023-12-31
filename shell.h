#ifndef _SHELL_H_
#define _SHELL_H_
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <stdio.h>

#define END_OF_FILE -2
#define EXIT -3

/* Globl environemnt */
extern char **environ;
/* Globl program name */
char *name;
/* Globl history counter */
int histry;

/**
 * struct list_s - A new struct type defining a linked list.
 * @dir: A directory path.
 * @next: A pointer to another struct list_s.
 */
typedef struct list_s
{
	char *dir;
	struct list_s *next;
} list_t;

/**
 * struct builtin_s - A new struct type defining builtin commands.
 * @name: The name of the builtin command.
 * @f: A function pointer to the builtin command's function.
 */
typedef struct builtin_s
{
	char *name;
	int (*f)(char **argv, char **front);
} builtin_t;

/**
 * struct alias_s - A new struct defining aliases.
 * @name: The name of the alias.
 * @value: The value of the alias.
 * @next: A pointer to another struct alias_s.
 */
typedef struct alias_s
{
	char *name;
	char *value;
	struct alias_s *next;
} alias_t;

/* Global aliases linked list */
alias_t *aliases;

/* All Main Helpers */
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_strtok(char *line, char *delim);
char *get_loca(char *command);
list_t *gett_path_dir(char *path);
int execute(char **args, char **front);
void free_list(list_t *head);
char *_itoa(int num);

/* All Input Helpers */
void handle_line(char **line, ssize_t read);
void variable_replacement(char **args, int *exe_ret);
char *get_args(char *line, int *exe_ret);
int call_args(char **args, char **front, int *exe_ret);
int run_args(char **args, char **front, int *exe_ret);
int handle_args(int *exe_ret);
int check_args(char **args);
void free_args(char **args, char **front);
char **replace_aliases(char **args);

/* All String functions */
int _strlen(const char *s);
char *_strcat(char *dest, const char *src);
char *_strncat(char *dest, const char *src, size_t n);
char *_strcpy(char *dest, const char *src);
char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);

/* All Builtins */
int (*g_builtin(char *command))(char **args, char **front);
int sh_exit(char **args, char **front);
int sh_env(char **args, char __attribute__((__unused__)) **front);
int sh_setenv(char **args, char __attribute__((__unused__)) **front);
int sh_unsetenv(char **args, char __attribute__((__unused__)) **front);
int sh_cd(char **args, char __attribute__((__unused__)) **front);
int sh_alias(char **args, char __attribute__((__unused__)) **front);
int sh_help(char **args, char __attribute__((__unused__)) **front);

/* All Builtin Helpers */
char **_cpenv(void);
void free_env(void);
char **_getenv(const char *var);

/* All Error Handling */
int create_err(char **args, int err);
char *err_env(char **args);
char *err_1(char **args);
char *err_2_exit(char **args);
char *err_2_cd(char **args);
char *err_2_syntax(char **args);
char *err_126(char **args);
char *err_127(char **args);

/* The Linkedlist Helpers */
alias_t *add_alias_end(alias_t **head, char *name, char *value);
void free_aliases_list(alias_t *head);
list_t *add_end_node(list_t **head, char *dir);
void free_list(list_t *head);

void help_all(void);
void help_alias(void);
void help_cd(void);
void help_exit(void);
void help_help(void);
void help_env(void);
void help_setenv(void);
void help_unsetenv(void);
void help_history(void);

int proc_file_commands(char *file_path, int *exe_ret);
#endif /* _SHELL_H_ */
