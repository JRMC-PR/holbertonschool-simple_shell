#ifndef simple_shell_h
#define simple_shell_h
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>
#include <sys/stat.h>
/*function signatures*/
int main(int ac, char **av, char **env);
void exec_com(char **com, char **env);
void _free(char **Tokens, int size);
void free_tokens(char **Tokens);
char **Tok(char **tokI, char *com);
char **get_path(char **env);
char *trim(char *str);
#endif
