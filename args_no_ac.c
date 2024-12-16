#include <stdio.h>

/**
* av est un double pointeur car:
* chaque argument est une chaine de caractere, ces chaines sont stockees dans un tableau de pointeurs
* chaque element du tableau est un pointeur vers un char (une chaine)
* si on utilisait un simple pointeur la ligne de commande serait vu commme une seule chaine de caractere
*/

int main(int argc, char **av)
{
    (void)argc; // On ignore argc pour ne pas recevoir de warning

    char **arg = av; // Pointeur pour parcourir les arguments
    while (*arg != NULL)
    {
        printf("%s\n", *arg);
        arg++;
    }

    return 0;
}
