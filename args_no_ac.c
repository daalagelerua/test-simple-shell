#include <stdio.h>

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
