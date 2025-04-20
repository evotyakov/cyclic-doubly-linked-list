#ifndef CDLL_H_INCLUDED
#define CDLL_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>

// Тип элементов списка
typedef int element_t;

// Узел
typedef struct node
{
    struct node *next;
    struct node *prev;
    element_t data;
} node;

// Список
typedef struct
{
    node *current;
} cdll;

// Создание пустого списка
cdll * cdll_create ();

// Переход к следующему элементу
void cdll_move_next (cdll *l);

// Переход к предыдущему элементу
void cdll_move_prev (cdll *l);

// Вставка элемента после текущего (текущий элемент не изменяется)
int cdll_push_next (cdll *l, element_t data);

// Вставка элемента перед текущим
int cdll_push_prev (cdll *l, element_t data);

// Удаление текущего элемента
element_t cdll_pop (cdll *l);

// Получение текущего элемента
element_t cdll_get_current (const cdll *l);

// Удаление списка
void cdll_destroy(cdll* l);

// Создание копии списка
cdll * cdll_clone (const cdll *l);

#endif // CDLL_H_INCLUDED
