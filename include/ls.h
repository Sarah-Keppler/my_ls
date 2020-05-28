/*
** EPITECH PROJECT, 2019
** ls.h
** File description:
** Struct of my_ls.
*/

#ifndef LS_H_
#define LS_H_

#include <dirent.h>

typedef struct my_ls {
    DIR *dir;
    struct dirent *rd_file;
    char *flags;
    char *path;
    char *name;
    int total;
} ls_t;

#endif /* LS_H_ */



