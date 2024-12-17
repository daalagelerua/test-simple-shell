#include <stdio.h>
#include <unistd.h>


int main(void)
{
    pid_t pid;

    printf("Avant le fork\n");

    pid = fork(); // Creation du processus enfant

    if (pid == -1) // Gestion de l'erreur
    {
        perror("Erreur avec fork");
        return (1);
    }
    else if (pid == 0) // Code execute par le processus enfant
    {
        printf("Je suis l'enfant, mon PID est : %d\n", getpid());
    }
    else // Code execute par le processus parent
    {
        printf("Je suis le parent, mon PID est : %d, l'enfant a pour PID : %d\n", getpid(), pid);
    }

    printf("Apres le fork\n");

    return (0);
}
