#include <stdio.h>
#include <string.h>

/**
* la fonction strtok sert a divisee une chaine en plusieurs sous-chaine appelees token,
* en fonction d'un ou plusieurs delimiteurs (ex: chaque " ")
* une ligne CSV (comma-separated values) serait une  chaine separee par
* des virgules ou autres delimiteurs (, ; tab espace |)
*/
int main(void) {
    char str[] = "Hello world this is C programming";
    char *token;

    // Le premier appel a strtok, on passe la chaine originale
    token = strtok(str, " ");

    // Tant qu'il y a des tokens√a traiter, on les affiche
    while (token != NULL) {
        printf("Token: %s\n", token);
        // Appel suivant pour obtenir le token suivant
        token = strtok(NULL, " ");
    }

    return 0;
}
