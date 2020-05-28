/*
** EPITECH PROJECT, 2019
** elem.h
** File description:
** Linked list for -l flag.
*/

#ifndef ELEM_H_
#define ELEM_H_

#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "flagl.h"

typedef struct element_l {
    fl_t *elem;
    struct element_l *next;
} elem_l_t;

typedef struct list {
    int nb;
    struct list *next;
} list_t;

#endif /* ELEM_H_ */



