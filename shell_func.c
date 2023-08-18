#include "simple_shell.h"
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
	char **tokens = NULL;
	int T_count = 0;
	/*tokenize com*/
	token = strtok(com, " \n");
	if (token == NULL)
		return;
	while (token != NULL)
	{
		/*allocate mem for tokens in aray and chekc if fai*/
		tokens = realloc(tokens, sizeof(char *) *(T_count + 1));
		if (tokens == NULL)
		{
			perror("realloc");
			return;
		} /*end if*/
		tokens[T_count] = token;
		T_count++;
		token = strtok(NULL, " \n");
		tokens[T_count] = NULL;
	} /*end while*/
	child = fork(); /*child process birth */
	if (child == -1)
	{
		perror("fork");
		return;
	}
	if (child == 0)
	{
		execve(tokens[0], tokens, env); /* Execute the com */
		perror("error: "); /* if execve fails */
		exit(EXIT_FAILURE); /* Exit child with failure status */
	}
	else
	{
		wait(NULL);	  /* Parent process waits for the child process to complete */
		free(tokens); /* Free allocated memory */
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
}
