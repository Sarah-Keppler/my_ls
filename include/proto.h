/*
** EPITECH PROJECT, 2019
** proto.h
** File description:
** Proto of all functions.
*/

#ifndef PROTO_H_
#define PROTO_H_

#include "elem.h"
#include "flagl.h"
#include "ls.h"

//get_flags.c
char *get_all_flags(int, char **);
int get_len(int, char **);
void get_flag(char *, char *);
char check_already_in(char *, char);
char check_flags(char *);

//get_info_l.c
void get_uid_gid(fl_t *);
char *get_date(char *);
void get_type(fl_t *);

//files.c
char **recup_files(int, char **);
int get_nb_files(int, char **);
char **copy_each_file(int, char **, int);
char **no_files_case(void);

//linked_list.c
void push_node(elem_l_t **, elem_l_t *);
void reverse_list(elem_l_t **);

//ls.c
ls_t *init_ls(char *, char *);
fl_t *init_info_l(ls_t *);
char init_struct_stat(ls_t *, fl_t *, char *);
elem_l_t *init_node(ls_t *);
char get_informations_per_file(ls_t *, elem_l_t **);

//ls_recursive.c
char seek_directories(char *, char *);
char print_each_directory_content(char *, char *, char *);
char check_if_directory(char *, char *, char *, char);
char check_correct_directory(char *, char);
char display_content(char *, char *);

//my.c
char *my_strcat_malloc(char *, char const *);

//my_free.c
void my_free_args(char **, char *);

//my_sort.c
void my_sort_list(elem_l_t **);
void swap_first(elem_l_t **);
void swap_last(elem_l_t **);
void swap_between(elem_l_t **, elem_l_t *, elem_l_t *);

//print.c
char show_content(char *, char *);
void print_files(elem_l_t *, char *, ls_t *);
void print_list(elem_l_t *, int, ls_t *);
void print_name(elem_l_t *, int);
void disp_elem(fl_t *);

#endif /* PROTO_H_ */
