#include "simple_shell.h"
/**
 *non_inter - executes command from arv
 *@av: argument pointer array
 *@env: points the the enviroment variable
 */
void non_inter(char *com, char **env)
{
	/*declarations*/
	pid_t child;
	char *token = NULL;
	char **Tokens = NULL;
	int T_count = 0;
	/*make up for options*/
	token = strtok(com, " ");
	if (token == NULL)
		return;
	while (token != NULL)
	{
		/*allocate mem for tokens in aray and chekc if fai*/
		Tokens = realloc(Tokens, sizeof(char *) * (T_count + 1));
		if (Tokens == NULL)
		{
			perror("realloc fail");
			return;
		} /*end if*/
		Tokens[T_count] = token;
		T_count++;
		token = strtok(NULL, "\n");
		Tokens[T_count] = NULL;
	} /*end while*/
	child = fork(); /*child birth*/
	/*check if forck sucess*/
	if (child == 0)
	{
		execve(Tokens[0], Tokens , env); /* Execute the com */
		perror("error: "); /* if execve fails */
		exit(EXIT_FAILURE); /* Exit child with failure status */
	}
	else
	{
		wait(NULL);	  /* Parent process waits for the child process to complete */
	}
} /*end function*/
/**
 *exec_com - incarge of analizing and executing the comnand
 *@com: holds the command to be executed
 *@env: enviroment variables of the system
 */
void exec_com(char *com, char **env)
{
	/*declarations*/
	pid_t child;
	char *token = NULL;
	char **Tokens = NULL;
	int T_count = 0;
	/*tokenize com*/
	token = strtok(com, " ");
	if (token == NULL)
		return;
	while (token != NULL)
	{
		/*allocate mem for tokens in aray and chekc if fai*/
		Tokens = realloc(Tokens, sizeof(char *) * (T_count + 1));
		if (Tokens == NULL)
		{
			perror("realloc fail");
			return;
		} /*end if*/
		Tokens[T_count] = token;
		T_count++;
		token = strtok(NULL, " \n");
		Tokens[T_count] = NULL;
	} /*end while*/
	child = fork(); /*child process birth */
	if (child == -1)
	{
		perror("fork");
		return;
	}
	if (child == 0)
	{
		execve(Tokens[0], Tokens, env); /* Execute the com */
		perror("error: "); /* if execve fails */
		exit(EXIT_FAILURE); /* Exit child with failure status */
	}
	else
	{
		wait(NULL);	  /* Parent process waits for the child process to complete */
		free(Tokens); /* Free allocated memory */
	}
} /*end exec*/

/**
 * get_paths - Extracts paths from the PATH environment variable
 * Return: A pointer to an array of strings containing the paths
 *         NULL on failure or if PATH is not found
 */
char **get_paths(void)
{
	/* Get the value of the PATH environment variable */
	char *path_env = NULL;
	char *token = NULL;
	int num_paths = 0;
	char **paths = NULL;

	path_env = getenv("PATH");
	/* Check if PATH environment variable exists */
	if (path_env == NULL)
	{
		perror("error: ");
		return (NULL);
	}
	token = strtok(path_env, ":");
	while (token != NULL)
	{
		/* Allocate memory for the new path in the array */
		paths = realloc(paths, sizeof(char *) * (num_paths + 1));
		if (paths == NULL)
		{
			perror("error: ");
			return (NULL);
		}
		paths[num_paths] = token; /* Store the current path in the array */
		num_paths++;			  /* You increment the num_paths counter.*/
		token = strtok(NULL, ":"); /* Move to the next token */
	}
	/* Add a NULL pointer at the end to terminate the array */
	paths = realloc(paths, sizeof(char *) * (num_paths + 1));
	paths[num_paths] = NULL;
	return (paths);
} /*end fucntion*/
