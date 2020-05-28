/*
** EPITECH PROJECT, 2019
** my.c
** File description:
** Functions from my.h
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

char *my_strcat_malloc(char *src2, char const *src)
{
    int di = my_strlen(src2);
    char *str = malloc(sizeof(char) * (my_strlen(src2) + my_strlen(src) + 1));

    if (NULL == str)
        return (NULL);
    for (int i = 0; src2[i]; ++i)
        str[i] = src2[i];
    for (int i = 0; src[i]; ++i) {
        str[di] = src[i];
        ++di;
    }
    str[di] = '\0';
    free(src2);
    return (str);
}
