#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * main - Mimics the `which` command
 * @argc: Number of arguments
 * @argv: Array of arguments
 *
 * Return: 0 on success, 1 on error
 */
int main(int argc, char **argv)
{
    char *path, *dir, *full_path;
    struct stat st;
    int i;

    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s filename ...\n", argv[0]);
        return (1);
    }

    /* Get the PATH environment variable */
    path = getenv("PATH");
    if (!path)
    {
        perror("getenv");
        return (1);
    }

    /* Duplicate PATH to avoid modifying the original */
    path = strdup(path);
    if (!path)
    {
        perror("strdup");
        return (1);
    }

    /* Loop through each filename provided as an argument */
    for (i = 1; i < argc; i++)
    {
        char *file = argv[i];
        int found = 0;

        /* Split PATH into directories */
        dir = strtok(path, ":");
        while (dir != NULL)
        {
            /* Build the full path to the file */
            full_path = malloc(strlen(dir) + strlen(file) + 2);
            if (!full_path)
            {
                perror("malloc");
                free(path);
                return (1);
            }
            sprintf(full_path, "%s/%s", dir, file);

            /* Check if the file exists and is executable */
            if (stat(full_path, &st) == 0 && access(full_path, X_OK) == 0)
            {
                printf("%s\n", full_path);
                found = 1;
                free(full_path);
                break;
            }

            free(full_path);
            dir = strtok(NULL, ":");
        }

        /* Reset path for the next file */
        free(path);
        path = strdup(getenv("PATH"));

        if (!found)
        {
            printf("%s: not found\n", file);
        }
    }

    free(path);
    return (0);
}
