#include <stdio.h>
#include <unistd.h>

int main(void)
{
    pid_t pid = getpid();   // Récupère le PID du processus actuel
    pid_t ppid = getppid(); // Récupère le PPID du processus actuel

    printf("Mon PID est : %d\n", pid);
    printf("Le PID de mon parent est : %d\n", ppid);

    return 0;
}
