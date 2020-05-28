/*
** EPITECH PROJECT, 2019
** get_flags
** File description:
** Find the flags.
*/

#include <errno.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "../include/my.h"
#include "../include/elem.h"
#include "../include/flagl.h"
#include "../include/ls.h"
#include "../include/proto.h"

int get_flaglen(int ac, char **av)
{
    int len = 0;

    for (int i = 1; ac > i; ++i)
        if ('-' == av[i][0])
            len += my_strlen(av[i]);
    return (len);
}

char check_already_in(char *flag, char c)
{
    int nb = 0;

    for (int i = 0; flag[i]; ++i)
        if (c == flag[i])
            ++nb;
    if (nb != 0)
        return ('1');
    return ('0');
}

void get_flag(char *flag, char *src)
{
    static int y = 0;

    for (int i = 1; src[i]; ++i) {
        if ('0' == check_already_in(flag, src[i])) {
            flag[y] = src[i];
            ++y;
            flag[y] = '\0';
        }
    }
}

char *get_all_flags(int ac, char **av)
{
    int len = get_flaglen(ac, av);
    char *flag = NULL;

    flag = malloc(sizeof(char) * (len + 1));
    if (NULL == flag)
        return (NULL);
    flag[0] = '\0';
    for (int i = 1; ac > i; ++i) {
        if ('-' == av[i][0])
            get_flag(flag, av[i]);
    }
    return (flag);
}

char check_flags(char *flags)
{
    char *valided_flag = "arlRt";
    int nb = 0;

    for (int i = 0; flags[i]; ++i) {
        for (int y = 0; valided_flag[y]; ++y)
            if (flags[i] != valided_flag[y])
                ++nb;
        if (my_strlen(valided_flag) == nb)
        {
            my_putstr("my_ls: invalid option -- ");
            my_putchar(flags[i]);
            my_putchar('\n');
            return ('1');
        }
        nb = 0;
    }
    return ('0');
}
