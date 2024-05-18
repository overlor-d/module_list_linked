#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>

#include "list_linked.h"

list_linked *add_elt_list_linked(list_linked *list, int elt, int pos)
{
    if (pos <= 0 || (pos > 1 && is_empty_list_linked(list)))
	{
        return NULL;
    }

	list_linked *maillon = malloc(sizeof(list_linked));
	if (maillon == NULL)
	{
		return NULL;
	}

	maillon->elt = elt;
	if (pos == 1)
	{
		maillon->next = list;
		return maillon;
	}

	list_linked *tmp = list;
	for (int k = 2; k < pos; k++)
	{
        if (tmp->next == NULL)
        {
            free(maillon);
            return NULL;
        }
		tmp = tmp->next;
	}
	
	maillon->next = tmp->next;
    tmp->next = maillon;
	return list;
}

list_linked *del_elt_list_linked(list_linked *list, int pos)
{
    if (pos <= 0 || (pos > 1 && is_empty_list_linked(list)) || is_empty_list_linked(list))
	{
        return NULL;
    }

    list_linked *tmp = list;
    list_linked *prec = NULL;

    for (int k = 1; k < pos; k++)
	{
        prec = tmp;
        tmp = tmp->next;
    }

    if (prec == NULL)
	{
        list_linked *new_head = tmp->next;
        free(tmp);
        return new_head;
    }
	else
	{
        prec->next = tmp->next;
        free(tmp);
        return list;
    }
}

int length_list_linked(list_linked *list)
{
	if (is_empty_list_linked(list))
	{
		return 0;
	}
	int cpt = 0;
	while (list != NULL)
	{
		cpt++;
		list = list->next;
	}
	return cpt;
}

int is_empty_list_linked(list_linked *list)
{
	if (list == NULL)
	{
		return 1;	
	}
	return 0;
}

void print_list_linked(list_linked *list)
{
	if (is_empty_list_linked(list))
	{
		return;
	}
	while (list->next != NULL)
	{
		printf("%d\n", list->elt);
		list = list->next;
	}
}

int search_elt_list_linked(list_linked *list, int elt)
{
	if (is_empty_list_linked(list))
	{
		return -1;
	}
	int cpt =0;
	while (list != NULL)
	{
		cpt++;
		if (list->elt == elt)
		{
			return cpt;
		}
		list = list->next;
	}
	return -2;
}

int get_elt_list_linked(list_linked *list,int pos)
{
	if (is_empty_list_linked(list))
	{
		return -1;
	}
	if ( pos > length_list_linked(list) || pos < 1)
	{
		return -2;
	}

	for (int k = 1; k < pos; k++)
	{
		list = list->next;
	}
	return list->elt;
}

int clear_list_linked(list_linked *list)
{
	if (is_empty_list_linked(list))
	{
		return 0;
	}
	int cpt = 0;

	while (list != NULL)
	{
		cpt++;
		list_linked *tmp = list->next;
		free(list);
		list = tmp;
	}
	return cpt;
}