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
void non_inter(char *com, char **env);
void exec_com(char *com, char **env);
char **Tok(char *com, const char *delm);
char **get_path(char **env);
#endif
