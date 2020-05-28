/*
** EPITECH PROJECT, 2019
** my_sort
** File description:
** Sort.
*/

#include "../include/my.h"
#include "../include/proto.h"

void swap_first(elem_l_t **list)
{
    elem_l_t *fst = *list;
    elem_l_t *scd = fst->next;
    elem_l_t *thd = fst->next->next;

    scd->next = fst;
    fst->next = thd;
    *list = scd;
}

void swap_last(elem_l_t **list)
{
    elem_l_t *tmp = *list;
    elem_l_t *last = NULL;
    elem_l_t *before_last = NULL;

    while (NULL != tmp->next->next->next)
        tmp = tmp->next;
    last = tmp->next;
    before_last = last->next;
    tmp->next = before_last;
    before_last->next = last;
    last->next = NULL;
}

void swap_between(elem_l_t **list, elem_l_t *node1, elem_l_t *node2)
{
    elem_l_t *before = *list;
    elem_l_t *after = *list;
    elem_l_t *tmp = NULL;

    while (node1 != before->next)
        before = before->next;
    while (node2 != after)
        after = after->next;
    after = after->next;
    tmp = before->next;
    before->next = tmp->next;
    before->next->next = tmp;
    tmp->next = after;
}

void my_sort_list(elem_l_t **list)
{
    elem_l_t *tmp = *list;

    if (NULL == *list || NULL == tmp->next)
        return;
    while (NULL != tmp->next) {
        if (tmp->elem->last_modif < tmp->next->elem->last_modif) {
            if (NULL == tmp->next->next)
                swap_last(list);
            else if (*list == tmp)
                swap_first(list);
            else
                swap_between(list, tmp, tmp->next);
            tmp = *list;
        } else
            tmp = tmp->next;
    }
}

/*
void swap_first(test_t **list)
{
    test_t *fst = *list;
    test_t *scd = fst->next;
    test_t *thd = fst->next->next;

    scd->next = fst;
    fst->next = thd;
    *list = scd;
}

void swap_last(test_t **list)
{
    test_t *tmp = *list;
    test_t *last = NULL;
    test_t *before_last = NULL;

    while (NULL != tmp->next->next->next)
        tmp = tmp->next;
    last = tmp->next;
    before_last = last->next;
    tmp->next = before_last;
    before_last->next = last;
    last->next = NULL;
}

void swap_between(test_t **list, test_t *test1, test_t *test2)
{
    test_t *before = *list;
    test_t *after = *list;
    test_t *tmp = NULL;

    while (test1 != before->next)
        before = before->next;
    while (test2 != after)
        after = after->next;
    after = after->next;
    tmp = before->next;
    before->next = tmp->next;
    before->next->next = tmp;
    tmp->next = after;
}

void my_sort_list(test_t **list)
{
    test_t *tmp = *list;

    if (NULL == *list || NULL == tmp->next)
        return;
    while (NULL != tmp->next) {
        if (tmp->nb > tmp->next->nb) {
            if (NULL == tmp->next->next)
                swap_last(list);
            else if (*list == tmp)
                swap_first(list);
            else
                swap_between(list, tmp, tmp->next);
            tmp = *list;
        } else
            tmp = tmp->next;
    }
}
*/
/*
test_t *list = NULL;
    test_t *elem1 = malloc(sizeof(test_t));
    test_t *elem2 = malloc(sizeof(test_t));
    test_t *elem3 = malloc(sizeof(test_t));
    test_t *elem4 = malloc(sizeof(test_t));
    elem1->nb = -52;
    elem2->nb = 42;
    elem3->nb = 84;
    elem4->nb = 21;
    push_test(&list, elem1);
    push_test(&list, elem2);
    push_test(&list, elem3);
    push_test(&list, elem4);
    print_test(list);
    my_putchar('\n');
    my_sort_list(&list);
    print_test(list);
 */
