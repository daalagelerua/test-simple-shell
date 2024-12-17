#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_CMD_LENGTH 1024

extern char **environ; // declaration de l'environnement

int main(void)
{
    char cmd[MAX_CMD_LENGTH];  // Buffer pour la commande entree
    pid_t pid;
    int status;

    while (1)
    {
        // Afficher le prompt
        printf("$ ");
        // Lire la commande entree par l'utilisateur
        if (fgets(cmd, MAX_CMD_LENGTH, stdin) == NULL)
        {
            perror("fgets");
            exit(1);
        }

        // Supprimer le retour a la ligne a la fin de la commande
        cmd[strcspn(cmd, "\n")] = 0;

        // Si l'utilisateur entre "exit", quitter le shell
        if (strcmp(cmd, "exit") == 0)
        {
            break;
        }

        // Creer un processus enfant
        pid = fork();
        if (pid == -1)
        {
            perror("fork");
            exit(1);
        }

        if (pid == 0)  // Dans le processus enfant
        {
		 // Creer un tableau argv avec la commande a executer
            char *argv[] = {cmd, NULL};  // Le premier argument est la commande elle-meme

		 // Executer la commande
            if (execve(cmd, argv, environ) == -1)
            {
                perror("execve");
                exit(1);
            }
        }
        else  // Dans le processus parent
        {
            // Attendre que le processus enfant termine
            wait(&status);
        }
    }

    return 0;
}
