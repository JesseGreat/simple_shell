#include "shell.h"



ssize_t prompt()
{
	int i;
	
	char *piece;

	char *cmd = {NULL};

	char * argv[] = {NULL};

	char **s = environ;

	char *prompt = "CJ@User$ ";

	char *lineptr;

	size_t len = 0;

	ssize_t char_read;

	pid_t pid;

	while(1)

	{
		printf("%s", prompt);

		char_read = getline(&lineptr, &len, stdin);

		lineptr[strlen(lineptr) - 1] = '\0';

		if(char_read == -1)
		{
			printf("\n");
			exit (0);
		}
		else if(strcmp(lineptr, "exit") == 0)
		{
			printf("CJ WEB TERMINAL CLOSING.....\n");
			exit (0);
		}
		piece = strtok(lineptr, " ");
		for (i = 0; piece != NULL; i++)
		{
			argv[i] = piece;
			piece = strtok(NULL, " ");
		}
		cmd = argv[0];
		cmd = find / -name cmd
		argv[i] = NULL;

		pid = fork();
		if (pid == -1)
		{
			return (-1);
		}

		if (pid == 0)
		{
			if (execve(cmd, argv, s) == -1)
			{	
				perror("Could not execute execve");
			}
			printf("Oops something went wrong\n");
		}
		else
		{
			wait(NULL);
		}
	}
	 return (0);
}
