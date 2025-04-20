#ifndef UI_H_INCLUDED
#define UI_H_INCLUDED
#include "cdll.h"
#include <stdio.h>

// Вывод всех элементов списка на экран (с пометкой текущего элемента)
void cdll_print (const cdll *l);

// Вывод доступных команд
void cdll_commands ();

#endif // UI_H_INCLUDED
