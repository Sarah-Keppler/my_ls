/*
** EPITECH PROJECT, 2019
** linked_list
** File description:
** Functions for linked list.
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

void reverse_list(elem_l_t **list)
{
    elem_l_t *prev = NULL;
    elem_l_t *current = *list;
    elem_l_t *next = NULL;

    while (NULL != current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *list = prev;
}

void push_node(elem_l_t **list, elem_l_t *node)
{
    elem_l_t *fst = *list;
    elem_l_t *tmp = *list;

    if (NULL == tmp)
        fst = node;
    else {
        fst = node;
        fst->next = tmp;
    }
    *list = fst;
}
