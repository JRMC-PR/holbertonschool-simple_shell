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
	/*int isa = isatty(STDIN_FILENO) == 0;*/
	char *input = NULL;
	char **comd = NULL;
	char **tokI = malloc(sizeof(char *) * 64);
	size_t size = 0;
	ssize_t read;

	/*if (isa)
	{
		printf("$ ");
	}*/
	/*check for arguents to activate non interACTIVE MODE*/
	do {
		/*ignore unused attributes*/
		(void)ac;
		(void)av;
		/*prompt the shell*/
		printf("$ ");
		/*read the user imput next verify if failed*/
		read = getline(&input, &size, stdin);
		if (read == -1 || input == NULL)
			break; /*exit loop*/
		input = trim(input);
		if (input[0] == '\n') /*check if there is something from the user*/
			continue; /*continue to next itertion*/
		if (strncmp(input, "exit", 4) == 0)
		{
			free(input);
			return (0);
		}
		if (isspace((unsigned char)input[0]))
			continue; /*continue to next iteraration*/
		comd = Tok(tokI, input);
		exec_com(comd, env);
		free_tokens(comd);
		free_tokens(tokI);
	} while (1);
	return (0);
} /*end main*/

/**
 **trim - trim input;
 *@str: points to a str
 *Return: str
 */
char *trim(char *str)
{
	char *end = NULL;
	/* Trim leading spaces*/
	while (isspace((unsigned char)(*str))) {
		str++;
	}
	if (*str == '\0') {
		return str; /*All spaces, return*/
	}
	/*Trim trailing spaces*/
	end = str + strlen(str) - 1;
	while (end > str && isspace((unsigned char)(*end))) {
		end--;
	}
	/*Null-terminate the trimmed string*/
	*(end + 1) = '\0';
	return str;
} /*end fucntion*/
/**
 *free_tokens - free memmory used
 *@Tokens: points to an array of
 */

void free_tokens(char **Tokens) {
	int i= 0;

	for (; Tokens[i] != NULL; i++) {
		free(Tokens[i]);
	}
	free(Tokens);
} /*end function*/


