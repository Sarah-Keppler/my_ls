/*
** EPITECH PROJECT, 2019
** ls
** File description:
** Show content.
*/

#include <dirent.h>
#include <errno.h>
#include <grp.h>
#include <pwd.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>
#include "../include/my.h"
#include "../include/proto.h"

char print_severals_files(char **files, char *flags)
{
    char *name = NULL;

    for (int i = 0; files[i]; ++i) {
        name = malloc(sizeof(char) * (my_strlen(files[i]) + 1));
        if (NULL == name)
            return ('1');
        my_strcpy(name, files[i]);
        name[my_strlen(files[i]) - 1] = '\0';
        my_putstr(name);
        my_putstr(":\n");
        if ('1' == show_content(files[i], flags))
            return ('1');
        if (NULL != files[i + 1])
            my_putchar('\n');
        free(name);
    }
    return ('0');
}

char my_ls_recursive(char **files, char *flags)
{
    my_putstr(files[0]);
    my_putstr(":\n");
    if ('1' == show_content(files[0], flags))
        return ('1');
    if ('1' == seek_directories(files[0], flags))
        return ('1');
    return ('0');
}

char my_ls(char **files, char *flags)
{
    int nb = 0;

    for (int i = 0; files[i]; ++i)
        ++nb;
    if (1 == nb) {
        if ('1' == show_content(files[0], flags))
            return ('1');
    } else {
        if ('1' == print_severals_files(files, flags))
            return ('1');
    }
    return ('0');
}

char start_my_ls(int ac, char **av)
{
    char **files = recup_files(ac, av);
    char *flags = get_all_flags(ac, av);
    char rtn = '0';

    if (NULL == flags || NULL == files || '1' == check_flags(flags))
        return ('1');
    for (int i = 0; flags[i]; ++i)
        if ('R' == flags[i]) {
            rtn = my_ls_recursive(files, flags);
            my_free_args(files, flags);
            return (rtn);
        }
    rtn = my_ls(files, flags);
    my_free_args(files, flags);
    return (rtn);
}

int main(int ac, char **av)
{
    if ('1' == start_my_ls(ac, av))
        return (84);
    return (0);
}
