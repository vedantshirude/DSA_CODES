
#include<stdio.h>
#include<stdlib.h>
#include "queue_client.h"

/*memory allocation routines -definition*/
void *xmalloc(size_t size_in_bytes) // take size_t i.e unsigned long long
{
    void *p = NULL;
    p = malloc(size_in_bytes);
    assert(p);
    return p;
}
/*list auxillary routines-defintion*/
node_t *get_list_node(data_t new_data)
{
    node_t *p_new_node = NULL;
    p_new_node = (node_t *)xmalloc(sizeof(node_t));
    p_new_node->data = new_data;
    p_new_node->next = NULL;
    p_new_node->prev = NULL;
    return (p_new_node);
}
node_t *locate_node(list_t *p_list, data_t search_data)
{
    node_t *p_run = NULL;
    p_run = p_list->next;
    while (p_run != p_list)
    {
        if (p_run->data == search_data)
        {
            return p_run;
        }
        p_run = p_run->next;
    }
    p_run = NULL;
    return (p_run);
}
/*interface routines-definition*/
list_t *create_list(void)
{
    list_t *p_list = NULL;
    p_list = get_list_node(-1);
    p_list->prev = p_list;
    p_list->next = p_list;
    return (p_list);
}
len_t get_length(list_t *p_list)
{
    node_t *p_run = NULL;
    if (is_list_empty(p_list))
        return (List_Empty);
    len_t length = 0;
    p_run = p_list->next;
    while (p_run != p_list)
    {
        length++;
        p_run = p_run->next;
    }
    return (length);
}
bool is_list_empty(list_t *p_list)
{
    return (p_list->next == p_list && p_list->prev == p_list);
}
bool contains(list_t *p_list, data_t search_data)
{
    return (locate_node(p_list, search_data) != NULL);
}
void show_list(list_t *p_list, const char *msg)
{
    node_t *p_run;
    if (msg)
        puts(msg);
    printf("[BEG]<->");
    p_run = p_list->next;
    while (p_run != p_list)
    {
        printf("[%d]<->", p_run->data);
        p_run = p_run->next;
    }
    printf("[END]\n");
}
int get_repeat_count(list_t *p_list, data_t search_data)
{
    int count = 0;
    node_t *p_run = NULL;
    p_run = p_list->next;
    while (p_run != p_list)
    {
        if (p_run->data == search_data)
        {
            count++;
        }
        p_run = p_run->next;
    }
    return count;
}
status_t get_beg(list_t *p_list, data_t *p_data)
{
    if (is_list_empty(p_list))
        return (List_Empty);
    *p_data = p_list->next->data;
    return (SUCCESS);
}
status_t get_last(list_t *p_list, data_t *p_data)
{
    if (is_list_empty(p_list))
        return (List_Empty);
    *p_data = p_list->prev->data;
    return (SUCCESS);
}
status_t append_list(list_t *p_list1, list_t *p_list2)
{
    p_list1->prev->next = p_list2->next;
    p_list2->next->prev = p_list1->prev;
    p_list1->prev = p_list2->prev;
    p_list2->prev->next = p_list1;
    free(p_list2);
    return (SUCCESS);
}
status_t insert_beg(list_t *p_list, data_t new_data)
{
    node_t *p_new_node = NULL;
    p_new_node = get_list_node(new_data);
    p_new_node->next = p_list->next;
    p_new_node->prev = p_list;
    p_list->next->prev = p_new_node;
    p_list->next = p_new_node;
    return (SUCCESS);
}
status_t insert_end(list_t *p_list, data_t new_data)
{
    node_t *p_new_node = NULL;
    p_new_node = get_list_node(new_data);
    p_new_node->next = p_list;
    p_new_node->prev = p_list->prev;
    p_list->prev->next = p_new_node;
    p_list->prev = p_new_node;
    return (SUCCESS);
}
status_t delete_beg(list_t *p_list)
{
    node_t *p_node = p_list->next;
    if (is_list_empty(p_list))
        return (List_Empty);
    p_list->next->next->prev = p_list;
    p_list->next = p_list->next->next;
    free(p_node);
    return (SUCCESS);
}
status_t delete_end(list_t *p_list)
{
    node_t *p_node = p_list->prev;
    if (is_list_empty(p_list))
        return (List_Empty);
    p_list->prev->prev->next = p_list;
    p_list->prev = p_list->prev->prev;
    free(p_node);
    return (SUCCESS);
}
status_t pop_beg(list_t *p_list, data_t *p_data)
{
    if (is_list_empty(p_list))
        return (List_Empty);
    *p_data = p_list->next->data;
    delete_beg(p_list);
    return (SUCCESS);
}
status_t pop_end(list_t *p_list, data_t *p_data)
{
    if (is_list_empty(p_list))
        return (List_Empty);
    *p_data = p_list->prev->data;
    delete_end(p_list);
    return (SUCCESS);
}
status_t insert_after(list_t *p_list, data_t e_data, data_t new_data)
{
    node_t *p_node_before = locate_node(p_list, e_data);
    if (p_node_before == NULL)
        return (List_Data_Not_Found);
    node_t *p_new_node = get_list_node(new_data);
    p_new_node->prev = p_node_before;
    p_new_node->next = p_node_before->next;
    p_node_before->next->prev = p_new_node;
    p_node_before->next = p_new_node;
    return (SUCCESS);
}
status_t insert_before(list_t *p_list, data_t e_data, data_t new_data)
{
    node_t *p_node_after = locate_node(p_list, e_data);
    if (p_node_after == NULL)
        return (List_Data_Not_Found);
    node_t *p_new_node = get_list_node(new_data);
    p_new_node->next = p_node_after;
    p_new_node->prev = p_node_after->prev;
    p_node_after->prev->next = p_new_node;
    p_node_after->prev = p_new_node;
    return (SUCCESS);
}
status_t remove_data(list_t *p_list, data_t r_data)
{
    node_t *p_node = locate_node(p_list, r_data);
    if (p_node == NULL)
        return (List_Data_Not_Found);
    p_node->prev->next == p_node->next;
    p_node->next->prev = p_node->prev;
    free(p_node);
    return (SUCCESS);
}
list_t *get_reversed_list(list_t *p_list)
{
    list_t *p_reversed_list = create_list();
    if (is_list_empty(p_list))
        return NULL;
    node_t *p_run = p_list->next;
    while (p_run != p_list)
    {
        insert_beg(p_reversed_list, p_run->data);
        p_run = p_run->next;
    }
    return (p_reversed_list);
}
list_t *concat_list(list_t *p_list1, list_t *p_list2)
{
    list_t *p_concated_list = create_list();
    node_t *p_run1 = p_list1->next;
    node_t *p_run2 = p_list2->next;
    while (p_run1 != p_list1)
    {
        insert_end(p_concated_list, p_run1->data);
        p_run1 = p_run1->next;
    }
    while (p_run2 != p_list2)
    {
        insert_end(p_concated_list, p_run2->data);
        p_run2 = p_run2->next;
    }
    return (p_concated_list);
}
list_t *array_to_list(data_t *p_array, size_t size)
{
    list_t *p_new_list = create_list();
    for(int i=0;i<size;i++)
    {
        insert_end(p_new_list,p_array[i]);
    }
    return(p_new_list);
}
/***************************************************** queue routines********************************************************/
queue_t* create_queue()
{
    return(create_list());
}
status_t enqueue(queue_t*p_queue,data_t new_data)
{
    status_t status=insert_end(p_queue,new_data);
    return(status);
}
status_t dequeue(queue_t*p_queue,data_t* new_data)
{
    status_t status=pop_beg(p_queue,new_data);
    return(status);
}
bool is_queue_empty(queue_t*p_queue)
{
    return(is_list_empty(p_queue));
}
status_t peek(queue_t* p_queue,data_t*p_data)
{
    status_t status=get_beg(p_queue,p_data);
    return status;
}
len_t length(queue_t*p_queue)
{
    return(get_length(p_queue));
}
void show_queue(queue_t*p_queue,char*msg)
{
    show_list(p_queue,msg);
}