#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    pid_t pid;
    int i;
    char *argv[] = {"/bin/ls", "-l", "/tmp", NULL}; // Arguments pour execve

    for (i = 0; i < 5; i++) // Boucle pour creer 5 enfants
    {
        pid = fork(); // Cree un processus enfant

        if (pid == -1) // Gestion d'erreur de fork
        {
            perror("fork");
            return (1);
        }
        else if (pid == 0) // Code execute par l'enfant
        {
            printf("Child %d: Executing ls -l /tmp\n", i + 1);
            if (execve(argv[0], argv, NULL) == -1) // Execution de la commande
            {
                perror("execve");
                return (1);
            }
        }
        else // Code execute par le parent
        {
            wait(NULL); // Attend que l'enfant se termine
            printf("Parent: Child %d finished execution\n", i + 1);
        }
    }

    printf("All children have finished.\n");
    return (0);
}
