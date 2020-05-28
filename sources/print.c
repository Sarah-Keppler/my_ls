/*
** EPITECH PROJECT, 2019
** print
** File description:
** Print what nned to be print.
*/

#include <errno.h>
#include <grp.h>
#include <pwd.h>
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <time.h>
#include "../include/my.h"
#include "../include/elem.h"
#include "../include/flagl.h"
#include "../include/ls.h"
#include "../include/proto.h"

void disp_elem(fl_t *ll)
{
    get_type(ll);
    my_put_nbr(ll->link);
    my_putchar(' ');
    my_putstr(ll->pwd->pw_name);
    my_putchar(' ');
    my_putstr(ll->gr->gr_name);
    my_putchar(' ');
    my_put_nbr(ll->size);
    my_putchar(' ');
    my_putstr(get_date(ctime(&(ll->sb.st_mtime))));
    my_putchar(' ');
    my_putstr(ll->name);
}

void print_name(elem_l_t *list, int a)
{
    while (list) {
        if ('.' != list->elem->name[0] && 0 == a) {
            my_putstr(list->elem->name);
            my_putchar('\n');
        } else if (a) {
            my_putstr(list->elem->name);
            my_putchar('\n');
        }
        list = list->next;
    }
}

void print_list(elem_l_t *list, int a, ls_t *ls)
{
    my_putstr("total ");
    my_put_nbr((int)(ls->total / 2));
    my_putchar('\n');
    while (list) {
        if ('.' != list->elem->name[0] && 0 == a) {
            disp_elem(list->elem);
            my_putchar('\n');
        } else if (a) {
            disp_elem(list->elem);
            my_putchar('\n');
        }
        list = list->next;
    }
}

void print_files(elem_l_t *list, char *flags, ls_t *ls)
{
    int a = 0;

    for (int i = 0; flags[i]; ++i)
        if ('a' == flags[i])
            a = 1;
    for (int i = 0; flags[i]; ++i)
        if ('l' == flags[i]) {
            print_list(list, a, ls);
            return;
        }
    print_name(list, a);
}

char show_content(char *path, char *flags)
{
    ls_t *ls = init_ls(path, flags);
    elem_l_t *list = NULL;

    if (NULL == ls || '1' == get_informations_per_file(ls, &list))
        return ('1');
    for (int i = 0; flags[i]; ++i) {
        if ('r' == flags[i])
            reverse_list(&list);
        if ('t' == flags[i])
            my_sort_list(&list);
    }
    print_files(list, flags, ls);
    closedir(ls->dir);
    free(ls->path);
    free(ls->name);
    free(ls);
    return ('0');
}
