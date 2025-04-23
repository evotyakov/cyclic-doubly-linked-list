#include "cdll.h"

cdll * cdll_create ()
{
    cdll *new_list = malloc(sizeof(cdll));
    if (!new_list) return NULL;

    new_list->current = NULL;
    return new_list;
}

void cdll_move_next (cdll *l)
{
    if (l == NULL || l->current == NULL) return;

    l->current = l->current->next;
}

void cdll_move_prev (cdll *l)
{
    if (l == NULL || l->current == NULL) return;

    l->current = l->current->prev;
}

int cdll_push_next (cdll *l, element_t data)
{
    if (l == NULL) return -1;

    node *new_node = malloc(sizeof(node));
    if (!new_node) return -1;

    new_node->data = data;

    if (l->current == NULL)
    {
        new_node->next = new_node;
        new_node->prev = new_node;
        l->current = new_node;
    }
    else
    {
        new_node->prev = l->current;
        new_node->next = l->current->next;
        l->current->next->prev = new_node;
        l->current->next = new_node;
    }
    return 0;
}

int cdll_push_prev (cdll *l, element_t data)
{
    if (l == NULL) return -1;

    node *new_node = malloc(sizeof(node));
    if (!new_node) return -1;

    new_node->data = data;

    if (l->current == NULL)
    {
        new_node->next = new_node;
        new_node->prev = new_node;
        l->current = new_node;
    }
    else
    {
        new_node->prev = l->current->prev;
        new_node->next = l->current;
        l->current->prev->next = new_node;
        l->current->prev = new_node;
    }
    return 0;
}

element_t cdll_pop (cdll *l)
{
    if (l == NULL || l->current == NULL)
    {
        fprintf(stderr, "Error: cdll_pop() called on NULL or empty list\n");
        return (element_t){0};
    }

    node *pop_node = l->current;
    element_t data = pop_node->data;

    if (pop_node == pop_node->next)
    {
        l->current = NULL;
    }
    else
    {
        pop_node->prev->next = pop_node->next;
        pop_node->next->prev = pop_node->prev;
        l->current = pop_node->next;
    }
    free(pop_node);
    return data;
}

element_t cdll_get_current (const cdll *l)
{
    if (l == NULL || l->current == NULL)
    {
        fprintf(stderr, "Error: cdll_get_current() called on NULL or empty list\n");
        return (element_t){0};
    }
    return l->current->data;
}

void cdll_destroy(cdll* l)
{
    if (l == NULL) return;

    while (l->current != NULL)
    {
        node* to_remove = l->current;
        l->current = to_remove->next;

        if (to_remove->next == to_remove)
        {
            l->current = NULL;
        }
        else
        {
            to_remove->prev->next = to_remove->next;
            to_remove->next->prev = to_remove->prev;
        }
        free(to_remove);
    }
    free(l);
}

cdll *cdll_clone(const cdll *src)
{
    if (src == NULL) return NULL;

    cdll *new_list = cdll_create();
    if (new_list == NULL) return NULL;

    if (src->current == NULL) return new_list;

    const node *original_current = src->current;
    const node *current_node = src->current;

    do
    {
        if (cdll_push_next(new_list, current_node->data) != 0)
        {
            cdll_destroy(new_list);
            return NULL;
        }
        current_node = current_node->prev;
    }
    while (current_node != original_current);

    return new_list;
}


