/*
** EPITECH PROJECT, 2019
** get_info_l
** File description:
** Get all the informations for l flag.
*/

#include <errno.h>
#include <grp.h>
#include <pwd.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <time.h>
#include "../include/my.h"
#include "../include/flagl.h"
#include "../include/ls.h"
#include "../include/proto.h"

void get_type(fl_t *flag)
{
    switch (flag->sb.st_mode & S_IFMT) {
    case S_IFDIR: my_putstr("d");
        break;
    default : my_putstr("-");
    }
    my_putchar((flag->sb.st_mode & S_IRUSR) ? 'r' : '-');
    my_putchar((flag->sb.st_mode & S_IWUSR) ? 'w' : '-');
    my_putchar((flag->sb.st_mode & S_IXUSR) ? 'x' : '-');
    my_putchar((flag->sb.st_mode & S_IRGRP) ? 'r' : '-');
    my_putchar((flag->sb.st_mode & S_IWGRP) ? 'w' : '-');
    my_putchar((flag->sb.st_mode & S_IXGRP) ? 'x' : '-');
    my_putchar((flag->sb.st_mode & S_IROTH) ? 'r' : '-');
    my_putchar((flag->sb.st_mode & S_IWOTH) ? 'w' : '-');
    my_putchar((flag->sb.st_mode & S_IXOTH) ? 'x' : '-');
    my_putchar(' ');
}

char *get_date(char *src)
{
    char *date = malloc(sizeof(char) * (my_strlen(src) + 1));

    if (NULL == date)
        return (NULL);
    date = my_strcpy(date, src + 4);
    date[my_strlen(date) - 9] = '\0';
    return (date);
}

void get_uid_gid(fl_t *flag)
{
    flag->pwd = getpwuid(flag->sb.st_uid);
    flag->gr = getgrgid(flag->sb.st_gid);
}
