#include <stdio.h>

extern char **environ; /*declaration de la variable globale environ*/

int main(int argc, char *argv[], char *env[])
{
    /*affiche l'adresse de env (le troisieme parametre de main)*/
    printf("Address env: %p\n", (void *)env);

    /*affiche l'adresse de environ (la variable globale)*/
    printf("Address environ: %p\n", (void *)environ);
	/*le cast (void *) garantit la compatibilite avec le format %p*/
    return 0;
}
