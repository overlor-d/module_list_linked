#include "stack_linked.h"

list_linked *push_stack_linked(list_linked *list, int elt)
{
	return add_elt_list_linked(list, elt, 1);
}

list_linked *pop_stack_linked(list_linked *list)
{
	return del_elt_list_linked(list, 1);
}

int length_stack_linked(list_linked *list)
{
	return length_list_linked(list);
}

int is_empty_stack_linked(list_linked *list)
{
	return is_empty_list_linked(list);
}

void print_stack_linked(list_linked *list)
{
	print_list_linked(list);
}

int get_head_stack_linked(list_linked *list)
{
	return get_elt_list_linked(list, 1);
}

int clear_stack_linked(list_linked *list)
{
	return clear_list_linked(list);
}