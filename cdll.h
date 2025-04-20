#ifndef CDLL_H_INCLUDED
#define CDLL_H_INCLUDED
#include <stdlib.h>
#include <stdio.h>

// ��� ��������� ������
typedef int element_t;

// ����
typedef struct node
{
    struct node *next;
    struct node *prev;
    element_t data;
} node;

// ������
typedef struct
{
    node *current;
} cdll;

// �������� ������� ������
cdll * cdll_create ();

// ������� � ���������� ��������
void cdll_move_next (cdll *l);

// ������� � ����������� ��������
void cdll_move_prev (cdll *l);

// ������� �������� ����� �������� (������� ������� �� ����������)
int cdll_push_next (cdll *l, element_t data);

// ������� �������� ����� �������
int cdll_push_prev (cdll *l, element_t data);

// �������� �������� ��������
element_t cdll_pop (cdll *l);

// ��������� �������� ��������
element_t cdll_get_current (const cdll *l);

// �������� ������
void cdll_destroy(cdll* l);

// �������� ����� ������
cdll * cdll_clone (const cdll *l);

#endif // CDLL_H_INCLUDED
