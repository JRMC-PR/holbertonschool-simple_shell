#include "simple_shell.h"
/**
 *non_inter - executes command from arv
 *@com: argument pointer array
 *@env: points the the enviroment variable
 */
void non_inter(char *com, char **env)
{
	/*declarations*/
	pid_t child;
	char **Tokens = NULL;
	/*Recive tokens*/
	Tokens = Tok(com, " ");
	child = fork(); /*child birth*/
	/*check if forck sucess*/
	if (child == 0)
	{
		execve(Tokens[0], Tokens, env); /* Execute the com */
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
	char **Tokens = NULL;
	char **Path = NULL;
	int i = 0;
	struct stat st;
	/*recive tokens*/
	Tokens = Tok(com, "\n");
	Path = get_path(env);
	while (Path[i] != NULL)
	{
		strcat(Path[i],"/");
		strcat(Path[i], Tokens[0]);
		if (stat(Path[i], &st) == 0)
		{
			Tokens[0] = Path[i];
			break;
		}
		i++;
	}
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
 * get_path - Extracts paths from the PATH environment variable
 * @env: points to the env variable
 * Return: A pointer to an array of strings containing the paths
 *         NULL on failure or if PATH is not found
 */
char **get_path(char **env)
{
	/* Get the value of the PATH environment variable */
	char *path_env = NULL;
	char **Tokens = NULL;
	int i = 0;
	/*search for the PATH*/
	for ( ; env[i] != NULL; i++)
	{
		if (strncmp(env[i], "PATH=", 5) == 0)
		{
			path_env = env[i] + 5;
			break;
		} /*end if*/
	} /*end for*/
	/*verify is we have the PATH*/
	if (path_env != NULL)
	{
		Tokens = Tok(path_env, ":");
		return (Tokens);
	}
	else
		perror("error: ");
	return (NULL);
} /*end fucntion*/

/**
 ***Tok - tokenize something
 *@com: points to the command recived
 *delm: points to the delimiter
 *Return: The Tokens pointer
 */
char **Tok( char *com, const char *delm)
{
	char *token = NULL;
	char **Tokens = NULL;
	int T_count = 0;
	/*tokenize com*/
	token = strtok(com, delm);
	if (token == NULL)
		return(NULL);
	/*allocate mem for tokens in aray and chekc if fai*/
	Tokens = realloc(Tokens, sizeof(char *) * (T_count + 1));
	if (Tokens == NULL){
		perror("realloc fail");
		return (NULL);
	} /*end if*/
	while (token != NULL){ /*popullate Tokens*/
		Tokens[T_count] = token;
		T_count++;
		token = strtok(NULL, ":");
	} /*end while*/
	Tokens[T_count] = NULL;
	return (Tokens);
} /*end function*/


