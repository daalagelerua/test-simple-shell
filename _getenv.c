#include <stdio.h>
#include <string.h>

extern char **environ;

char *_getenv(cont char *name)
{
int i = 0;
size_t len = strlen(name); /*get the length of environnement variable name*/

while (environ[i] != NULL) /*loop through environnement variable*/
	{
	/*compare the beginning of each environnement variable with the name parameter*/
	if (strncmp(environ[i], name, len) == 0 && environ[i][len] == '=')
		{
		return (environ[i] + len + 1; /*return the value after the = sign*/
		}
	i++;
	}
return NULL; /*NULL if environnement variable is not found*/
}
