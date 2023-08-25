#include "simple_shell.h"
/**
 *exec_com - incarge of analizing and executing the comnand
 *@com: holds the command to be executed
 *@env: enviroment variables of the system
 */
void exec_com(char **com, char **env){
	pid_t child;
	char *Path = "/bin/";
	char *comP = malloc(512);
	int status;
	struct stat st;
	/*recive tokens*/

		strcat(Path, com[0]);
		if (stat(Path, &st) == 0) {
			com[0] =strdup(Path);
			free(comP);
		}
	child = fork(); /*child process birth */
	if (child == -1){
		perror("fork");
		return;
	}
	if (child == 0){
		execve(com[0], com, env); /* Execute the com */
		free(com[0]);
		free(com);
		perror("error: "); /* if execve fails */
		exit(EXIT_FAILURE); /* Exit child with failure status */
	}
	else{
		waitpid(child, &status, 0); /* Parent process waits for the child process to complete */
		free(com[0]);
	}
} /*end exec*/


/**
 ***Tok - tokenize something
 *@com: points to the command recived
 *delm: points to the delimiter
 *Return: The Tokens pointer
 */
char **Tok(char **tokI, char *com)
{
	/*Declarations*/
	char *token = NULL;
	int T_count = 0;
	/*verify allocation*/
	if (tokI == NULL)
	{
		perror("malloc fail");
		exit(EXIT_FAILURE);
	} /*verify malloc*/
	/*
	 * " ": Space character
	 *"\t": Tab character
	 *"\r": Carriage return character
	 *"\n": Newline character
	 *"\a": Bell character (audible alert)
	 *":" : Chech for colons
	 */
	token = strtok(com, "\t\r\n\a:");
	while (token != NULL)
	{
		tokI[T_count] = token;
		T_count++;
		token = strtok(NULL, "\t\r\n\a:");
	}
	tokI[T_count] = NULL;
	return (tokI);
} /*end function*/


