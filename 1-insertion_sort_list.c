#include "sort.h"
/**
 * swap_nodes - Swaps two adjacent nodes in a doubly linked list
 * @list: Double pointer to the head of the list
 * @a: Pointer to the first node
 * @b: Pointer to the second node
 *
 * Return: Nothing
 */
void swap_nodes(listint_t **list, listint_t *a, listint_t *b)
{
if (a->prev)
a->prev->next = b;
else
*list = b;
if (b->next)
b->next->prev = a;
a->next = b->next;
b->prev = a->prev;
a->prev = b;
b->next = a;
}
/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       in ascending order using the Insertion sort algorithm
 * @list: Double pointer to the head of the doubly linked list
 *
 * Return: Nothing
 */
void insertion_sort_list(listint_t **list)
{
listint_t *current, *tmp;
if (!list || !*list || !(*list)->next)
return;
current = (*list)->next;
while (current)
{
tmp = current;
while (tmp->prev && tmp->n < tmp->prev->n)
{
swap_nodes(list, tmp->prev, tmp);
print_list(*list);
}
current = current->next;
}
}
