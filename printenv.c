#include <stdio.h>
#include <unistd.h>

extern char **environ; /*declaration variable globale environ*/

int main(void)
{
char **env = environ; /*initialisation d'un pointeur pour parcourir environ*/

while (*env) /*parcours les variables d'environnement*/
	{
	printf("%s\n", *env); /*affiche chaque variable*/
	env++; 
	}
return (0);
}
