/*
** EPITECH PROJECT, 2019
** ls_recursive.c
** File description:
** Display the content of underfiles.
*/

#include <dirent.h>
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include "../include/my.h"
#include "../include/proto.h"

char check_correct_directory(char *name, char a)
{
    int pos = 0;

    for (int i = 0; name[i]; ++i)
        if ('/' == name[i])
            pos = i;
    if (0 == my_strcmp(name + pos + 1, ".") ||
        0 == my_strcmp(name + pos + 1, ".."))
        return ('1');
    if ('.' == name[pos + 1] && '1' == a)
        return ('0');
    else if ('.' == name[pos + 1] && '0' == a)
        return ('1');
    return ('0');
}

char display_content(char *file_name, char *flags)
{
    char *underfile_name = NULL;

    if (NULL == (underfile_name = malloc(sizeof(char) * (256 + 1))))
        return ('1');
    my_putstr(file_name);
    my_putstr(":\n");
    my_strcpy(underfile_name, file_name);
    my_strcat(underfile_name, "/");
    if ('1' == show_content(underfile_name, flags)) {
        free(underfile_name);
        return ('1');
    }
    seek_directories(underfile_name, flags);
    free(underfile_name);
    return ('0');
}

char check_if_directory(char *dir_name, char *file_name, char *flags, char a)
{
    struct stat sb;
    char rtn = '0';

    if (0 == stat(file_name, &sb)) {
        rtn = check_correct_directory(file_name, a);
        if (1 == S_ISDIR(sb.st_mode) && '0' == rtn) {
            my_putchar('\n');
            if ('1' == display_content(file_name, flags))
                return ('1');
        }
    } else
        return ('1');
    return ('0');
}

char print_each_directory_content(char *file, char *flags, char *rd_name)
{
    char *underfile_name = NULL;
    char a = '0';

    for (int i = 0; flags[i]; ++i)
        if ('a' == flags[i])
            a = '1';
    if (NULL == (underfile_name = malloc(sizeof(char) * (256 + 1))))
        return ('1');
    my_strcpy(underfile_name, file);
    my_strcat(underfile_name, rd_name);
    if ('1' == check_if_directory(file, underfile_name, flags, a))
        return ('1');
    free(underfile_name);
    return ('0');
}

char seek_directories(char *file, char *flags)
{
    DIR *dir;
    struct dirent *rd_file;

    if (NULL == (dir = opendir(file))) {
        perror("");
        return ('1');
    }
    while (NULL != (rd_file = readdir(dir))) {
        if ('1' == print_each_directory_content(file, flags, rd_file->d_name))
            return ('1');
    }
    closedir(dir);
    return ('0');
}
