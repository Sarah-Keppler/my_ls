/*
** EPITECH PROJECT, 2019
** my_free
** File description:
** Free.
*/

#include <stdlib.h>
#include "../include/my.h"
#include "../include/proto.h"

void my_free_args(char **files, char *flags)
{
    for (int i = 0; files[i]; ++i)
        free(files[i]);
    free(files);
    free(flags);
}
