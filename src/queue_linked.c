#include "queue_linked.h"

list_linked *enqueue_queue_linked(list_linked *list, int elt)
{
	return add_elt_list_linked(list, elt, length_list_linked(list) + 1);
}

list_linked *dequeue_queue_linked(list_linked *list)
{
	return del_elt_list_linked(list, 1);
}

int length_queue_linked(list_linked *list)
{
	return length_list_linked(list);
}

int is_empty_queue_linked(list_linked *list)
{
	return is_empty_list_linked(list);
}

void print_queue_linked(list_linked *list)
{
	print_list_linked(list);
}

int get_head_queue_linked(list_linked *list)
{
	return get_elt_list_linked(list, 1);
}

int clear_queue_linked(list_linked *list)
{
	return clear_list_linked(list);
}
