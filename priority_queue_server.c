#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "priority_queue_client.h"

priority_queue_t *create_prior_queue(void)
{
    return(create_list());
}
status_t prior_enqueue(priority_queue_t *p_queue, data_t data)
{
    insert_end(p_queue,data);
    return(SUCCESS);
}
status_t prior_dequeue_min(priority_queue_t *p_queue, data_t *min_data)
{
    int current_min_data;
    node_t*p_run=NULL;
    node_t*p_min_data_node=NULL;

    if(is_prior_queue_empty(p_queue))
        return PRIOR_QUEUE_EMPTY;
    
    current_min_data=p_queue->next->data;
    p_min_data_node=p_queue->next;
    
    for(p_run=p_queue->next;p_run!=p_queue;p_run=p_run->next)
    {
        if(p_run->data<current_min_data)
        {
            p_min_data_node=p_run;
            current_min_data=p_run->data;
        }
    }
    generic_delete(p_min_data_node);
    *min_data=current_min_data;
    return(SUCCESS);
}
Bool is_prior_queue_empty(priority_queue_t *p_queue)
{
    return(is_list_empty(p_queue));
}
void show_priority_queue(priority_queue_t*p_queue,const char*msg)
{
    show_list(p_queue,msg);
}
status_t destroy_prior_queue(priority_queue_t *p_queue);

list_t *create_list(void)
{
    node_t *p_list = NULL;
    p_list = (node_t *)xmalloc(sizeof(node_t));
    p_list->data = -1;
    p_list->next = p_list;
    p_list->prev = p_list;
    return (p_list);
}

status_t insert_beg(list_t *p_list, data_t data)
{
    generic_insert(p_list,get_list_node(data),p_list->next);
    return(SUCCESS);
}
status_t insert_end(list_t *p_list, data_t data)
{
    generic_insert(p_list->prev,get_list_node(data),p_list);
    return(SUCCESS);
}
status_t remove_beg(list_t *p_list, data_t *data)
{
    if(is_list_empty(p_list))
        return LIST_IS_EMPTY;
    *data=p_list->next->data;
    generic_delete(p_list->next);
    return(SUCCESS);
}
status_t remove_end(list_t *p_list, data_t *data)
{
    if(is_list_empty(p_list))
        return LIST_IS_EMPTY;
    *data=p_list->prev->data;
    generic_delete(p_list->prev);
    return(SUCCESS);
}
Bool is_list_empty(list_t *p_list)
{
    return(p_list->next == p_list && p_list->prev == p_list);
}
void show_list(list_t*p_list,const char*msg)
{
    node_t*p_run=NULL;
    if(msg)
        puts(msg);
    p_run=p_list->next;
    printf("[START]->");
    while(p_run!=p_list)
    {
        printf("[%d]->",p_run->data);
        p_run=p_run->next;
    }
    puts("[END]");
}
status_t destroy_list(list_t *p_list)
{
    node_t*p_run=NULL;
    node_t*p_run_next=NULL;
    if(is_list_empty(p_list))
        return LIST_IS_EMPTY;
    p_run=p_list->next;
    while(p_run!=p_list)
    {
        p_run_next=p_run->next;
        free(p_run);
        p_run=p_run_next;
    }
    free(p_list);
    p_run=NULL;
    p_run_next=NULL;
    return(SUCCESS);
}

void generic_insert(node_t *p_beg, node_t *p_mid, node_t *p_end)
{
    p_mid->next=p_end;
    p_mid->prev=p_beg;
    p_beg->next=p_mid;
    p_end->prev=p_mid;
}
void generic_delete(node_t *p_delete_node)
{
    p_delete_node->prev->next=p_delete_node->next;
    p_delete_node->next->prev=p_delete_node->prev;
    free(p_delete_node);
}
node_t *get_list_node(data_t data)
{
    node_t *p_new_node = NULL;
    p_new_node = (node_t *)xmalloc(sizeof(node_t));
    p_new_node->data = data;
    p_new_node->next = NULL;
    p_new_node->prev = NULL;
    return (p_new_node);
}
void *xmalloc(size_t size_nr_bytes)
{
    void *p = NULL;
    p = malloc(size_nr_bytes);
    if (p == NULL)
    {
        fprintf(stderr, "out of memory \n");
        exit(EXIT_FAILURE);
    }
    return p;
}
