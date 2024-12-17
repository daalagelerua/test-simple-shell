#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main(void)
{
    pid_t pid;
    int status;

    pid = fork(); // Cree un processus enfant

    if (pid == -1)
    {
        perror("fork");
        return (1);
    }
    else if (pid == 0) // Code execute par l'enfant
    {
        printf("Je suis l'enfant, mon PID est %d\n", getpid());
        sleep(2); // Simulation d'une tache longue
        printf("L'enfant se termine\n");
    }
    else // Code execute par le parent
    {
        printf("Je suis le parent, mon PID est %d. J'attends l'enfant...\n", getpid());
        wait(&status); // Le parent attend que l'enfant se termine
        printf("L'enfant a termine avec le statut %d\n", status);
    }

    return (0);
}
