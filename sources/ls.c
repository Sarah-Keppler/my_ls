/*
** EPITECH PROJECT, 2019
** ls
** File description:
** Init and do ls.
*/

#include <errno.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include "../include/my.h"
#include "../include/flagl.h"
#include "../include/ls.h"
#include "../include/proto.h"

char get_informations_per_file(ls_t *ls, elem_l_t **list)
{
    elem_l_t *node = NULL;

    while (NULL != (ls->rd_file = readdir(ls->dir))) {
        node = init_node(ls);
        if (NULL == node)
            return ('1');
        push_node(list, node);
    }
    return ('0');
}

elem_l_t *init_node(ls_t *ls)
{
    elem_l_t *node = malloc(sizeof(elem_l_t));

    if (NULL == node)
        return (NULL);
    node->elem = init_info_l(ls);
    if (NULL == node->elem)
        return (NULL);
    node->next = NULL;
    return (node);
}

char init_struct_stat(ls_t *ls, fl_t *ll, char *path)
{
    char check_a = '0';

    for (int i = 0; ls->flags[i]; ++i)
        if ('a' == ls->flags[i])
            check_a = '1';
    if (0 == stat(path, &(ll->sb))) {
        ll->name = ls->rd_file->d_name;
        if ('.' != ll->name[0] && '0' == check_a)
            ls->total += ll->sb.st_blocks;
        else if ('1' == check_a)
            ls->total += ll->sb.st_blocks;
        ll->link = (long)ll->sb.st_nlink;
        get_uid_gid(ll);
        ll->size = (long long)ll->sb.st_size;
        ll->last_modif = ll->sb.st_mtime;
    } else
        return ('1');
    return ('0');
}

fl_t *init_info_l(ls_t *ls)
{
    fl_t *ll = malloc(sizeof(fl_t));
    char *whole_path = malloc(sizeof(char) * (my_strlen(ls->path) + 1));

    if (NULL == ll || NULL == whole_path)
        return (NULL);
    ll->name = malloc(sizeof(char) * 257);
    if (NULL == ll->name)
        return (NULL);
    whole_path = my_strcpy(whole_path, ls->path);
    whole_path = my_strcat_malloc(whole_path, ls->rd_file->d_name);
    if ('1' == init_struct_stat(ls, ll, whole_path))
        return (NULL);
    free(whole_path);
    return (ll);
}

ls_t *init_ls(char *file, char *flags)
{
    ls_t *ls = malloc(sizeof(ls_t));

    if (NULL == ls)
        return (NULL);
    ls->dir = opendir(file);
    if (NULL == ls->dir) {
        perror("");
        return (NULL);
    }
    ls->name = malloc(sizeof(char) * (256 + 1));
    ls->path = malloc(sizeof(char) * (256 + 1));
    ls->flags = flags;
    if (NULL == ls->name || NULL == ls->path)
        return (NULL);
    ls->path = my_strcpy(ls->path, file);
    return (ls);
}
