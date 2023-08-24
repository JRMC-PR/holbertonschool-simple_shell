#include "simple_shell.h"
/**
 *main -execute main shell function
 *@ac: argument count
 *@av: array of pointers
 *@env: enviroments variables
 *Return: 0 on success
 */
int main(int ac, char **av, char **env)
{
	int isa = isatty(STDIN_FILENO) == 0;
	char *input = NULL, *com = NULL;
	size_t size = 0;
	ssize_t read;

	(void)ac;
	/*check for arguents to activate non interACTIVE MODE*/
	if (isa)
	{
		/*read the user imput next verify if failed*/
		read = getline(&input, &size, stdin);
		if (read == -1)
			return (0);
		com = strtok(input, "\n");
		non_inter(com, env);
		free(input);
		return (0);
	}
	else
	{/*end non_inter verification */
		do {
			/*ignore unused attributes*/
			(void)av;
			/*prompt the shell*/
			printf("$ ");
			/*read the user imput next verify if failed*/
			read = getline(&input, &size, stdin);
			if (read == -1)
				break; /*exit loop*/
			if (input[0] == '\n') /*check if there is something from the user*/
				continue; /*continue to next itertion*/
			if (strncmp(input, "exit", 4) == 0)
			{
				free(input);
				return (0); /*exit loop*/
			}
			if (isspace((unsigned char)input[0]))
				continue; /*continue to next iteraration*/
			exec_com(input, env);
		} while (1);
	}
	free(input);
	return (0);
} /*end main*/


