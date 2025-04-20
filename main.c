/* Реализовать циклический двусвязный список целых чисел. Обеспечить наличие возможностей
   (a) перехода к следующему и предыдущему элементу;
   (b) вставка элемента после и перед текущим;
   (c) удаление текущего элемента;
   (d) создания копии списка;
   (e) вывода всех элементов списка на экран.
   Снабдить модуль пользовательским интерфейсом доступа к указанным возможностям посредством выбора пунктов меню.

 * (C) Ev. M. Votyakov, 24.Б22-мм
 */

#include <stdio.h>
#include <stdlib.h>
#include "cdll.h"
#include "ui.h"

#define MAX_LISTS 10

int main()
{
    int choice;
    cdll *lists[MAX_LISTS] = {NULL};
    int current_list = 0;
    int list_count = 0;

    do
    {
        cdll_commands();
        scanf("%d", &choice);
        while (getchar() != '\n');
        printf("\n");

        switch (choice)
        {
            case 1:
                if (list_count < MAX_LISTS)
                {
                    lists[list_count] = cdll_create();
                    if (lists[list_count])
                    {
                        current_list = list_count;
                        list_count++;
                        printf("Created list #%d\n", current_list);
                    }
                }
                else
                {
                    printf("Maximum number of lists reached (%d)\n", MAX_LISTS);
                }
                break;

            case 2:
                if (list_count < MAX_LISTS && lists[current_list])
                {
                    lists[list_count] = cdll_clone(lists[current_list]);
                    if (lists[list_count])
                    {
                        current_list = list_count;
                        list_count++;
                        printf("Created copy as list #%d\n", current_list);
                    }
                }
                else if (list_count >= MAX_LISTS)
                {
                    printf("Maximum number of lists reached (%d)\n", MAX_LISTS);
                }
                else
                {
                    printf("No list to copy\n");
                }
                break;

            case 3:
                if (lists[current_list])
                {
                    element_t data;
                    printf("Enter data:\n");
                    scanf("%d", &data);
                    cdll_push_next(lists[current_list], data);
                }
                else
                {
                    printf("No active list\n");
                }
                break;

            case 4:
                if (lists[current_list])
                {
                    element_t data;
                    printf("Enter data:\n");
                    scanf("%d", &data);
                    cdll_push_prev(lists[current_list], data);
                }
                else
                {
                    printf("No active list\n");
                }
                break;

            case 5:
                if (lists[current_list])
                {
                    cdll_pop(lists[current_list]);
                }
                else
                {
                    printf("No active list\n");
                }
                break;

            case 6:
                if (lists[current_list])
                {
                    cdll_move_next(lists[current_list]);
                }
                else
                {
                    printf("No active list\n");
                }
                break;

            case 7:
                if (lists[current_list])
                {
                    cdll_move_prev(lists[current_list]);
                }
                else
                {
                    printf("No active list\n");
                }
                break;

            case 8:
                if (lists[current_list])
                {
                    printf("Current list: #%d\n", current_list);
                    cdll_print(lists[current_list]);
                }
                else
                {
                    printf("No active list\n");
                }
                break;

            case 9:
                if (lists[current_list])
                {
                    cdll_destroy(lists[current_list]);
                    lists[current_list] = NULL;

                    for (int i = current_list; i < list_count - 1; i++)
                    {
                        lists[i] = lists[i + 1];
                    }
                    lists[list_count - 1] = NULL;
                    list_count--;

                    if (list_count == 0)
                    {
                        current_list = 0;
                    }
                    else if (current_list >= list_count)
                    {
                        current_list = list_count - 1;
                    }
                }
                else
                {
                    printf("No active list\n");
                }
                break;

            case 10:
                printf("Available lists: ");
                for (int i = 0; i < list_count; i++)
                {
                    if (lists[i]) printf("%d ", i);
                }
                printf("\nSelect list number: ");

                int new_list;
                scanf("%d", &new_list);
                if (new_list >= 0 && new_list < list_count && lists[new_list])
                {
                    current_list = new_list;
                    printf("Switched to list #%d\n", current_list);
                }
                else
                {
                    printf("Invalid list number\n");
                }
                break;

            default:
                break;
        }
    }
    while (choice != 0);

    for (int i = 0; i < list_count; i++)
    {
        if (lists[i]) cdll_destroy(lists[i]);
    }

    return 0;
}
