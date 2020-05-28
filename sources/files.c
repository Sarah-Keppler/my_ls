/*
** EPITECH PROJECT, 2019
** files
** File description:
** Recup the files.
*/

#include <errno.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "../include/my.h"
#include "../include/proto.h"

int get_nb_files(int ac, char **av)
{
    int nb = 0;

    for (int i = 1; ac > i; ++i) {
        if ('-' != av[i][0])
            ++nb;
    }
    return (nb);
}

char **no_files_case(void)
{
    char **files = malloc(sizeof(char *) * 2);

    if (NULL == files)
        return (NULL);
    files[0] = malloc(sizeof(char) * 3);
    if (NULL == files[0])
        return (NULL);
    my_strcpy(files[0], "./");
    files[1] = NULL;
    return (files);
}

void check_end_of_file(char **files)
{
    int len = 0;

    for (int i = 0; files[i]; ++i) {
        len = my_strlen(files[i]);
        if ('/' != files[i][len - 1]) {
            files[i][len] = '/';
            files[i][len + 1] = '\0';
        }
    }
}

char **copy_each_file(int ac, char **av, int nb_files)
{
    char **files = malloc(sizeof(char *) * (nb_files + 1));
    int y = 0;

    if (NULL == files)
        return (NULL);
    for (int i = 1; ac > i; ++i) {
        if ('-' != av[i][0]) {
            files[y] = malloc(sizeof(char) * (my_strlen(av[i]) + 2));
            if (NULL == files[y])
                return (NULL);
            my_strcpy(files[y], av[i]);
            ++y;
        }
    }
    files[nb_files] = NULL;
    check_end_of_file(files);
    return (files);
}

char **recup_files(int ac, char **av)
{
    int nb_files = get_nb_files(ac, av);
    char **files = NULL;

    if (0 == nb_files) {
        files = no_files_case();
        return (files);
    }
    files = copy_each_file(ac, av, nb_files);
    if (NULL == files)
        return (NULL);
    return (files);
}
