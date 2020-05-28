/*
** EPITECH PROJECT, 2019
** flagl.h
** File description:
** Struct of ls -l.
*/

#ifndef FLAGL_H_
#define FLAGL_H_

#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

typedef struct flagl {
    struct stat sb;
    char *name;
    long link;
    struct passwd *pwd;
    struct group *gr;
    long long size;
    char *date;
    int last_modif;
} fl_t;

#endif /* FLAGL_H_ */



