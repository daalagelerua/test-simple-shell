#include <stdio.h>
#include <stdlib.h>

/**
* stdin (entree standard) lieu ou on lit l'entree utilisateur (le clavier)
*/

int main(void)
{
    char input[1024]; // Buffer pour stocker la commande de l'utilisateur

    while (1) // Boucle infinie pour continuer à afficher le prompt
    {
        printf("$ "); // Afficher le prompt
        if (fgets(input, sizeof(input), stdin) == NULL) // Lire l'entree utilisateur comme scanf mais plus secure
        {
            printf("\n");
            break; // Si l'entrée est vide (Ctrl+D), quitter la boucle
        }

        // Afficher la commande saisie
        printf("You entered: %s", input);
    }

    return 0;
}
