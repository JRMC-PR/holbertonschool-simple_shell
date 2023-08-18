#include "simple_shell.h"
/**
 *main -execute main shell function
 *@ac: argument count
 *@av: array of pointers
 *env: enviroments variables
 *Return: 0 on success
 */
int main(int ac, char **av, char** env)
{
	/*Declarations*/
	char *input = NULL;
	size_t size = 0;
	ssize_t read;
	
	/*the do will prompt "$" untill exit*/
	do
	{
		/*ignore unused attributes*/
		(void)ac;
		(void)av;
	/*prompt the shell*/
		printf("$ ");
		/*read the user imput next verify if failed*/
		read = getline(&input, &size, stdin);
		if (read == -1)
			break; /*exit loop*/
		if (input[0] == '\n') /*check if there is something from the user*/
			continue; /*continue to next itertion*/
		/*check for exit ir spaces entred*/
		if (strcmp(input, "exit") == 0)
			break; /*exit loop*/
		if (isspace((unsigned char)input[0]))
			continue; /*continue to next iteraration*/
		/*execute commant entered*/
		exec_com(input, env);
	} while (1);
	/*free pointer and exit*/
	free(input);
	return (0);
} /*end main*/
