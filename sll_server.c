#include<stdio.h>
#include<stdlib.h>

#include "sll_client.h"

list_t*create_list(void)
{
    node_t *p_new_node=NULL;
    p_new_node=(list_t*)xmalloc(sizeof(list_t));
    p_new_node->data=-1;
    p_new_node->next=NULL;

    return(p_new_node);
}

/*supportive functions   or    interface routines*/
static void get_node_and_prev(list_t*p_list,data_t s_data,node_t**pp_node,node_t **pp_prev_node)
{
    node_t*p_run=NULL;
    node_t*p_run_prev=NULL;

    p_run=p_list->next;
    p_run_prev=p_list;

    while(p_run!=NULL)
    {
        if(p_run->data==s_data)
        {
            *pp_node=p_run;
            *pp_prev_node=p_run_prev;
            break;
        }
        p_run_prev=p_run;
        p_run=p_run->next;
    }
}
static void get_last_node(list_t*p_list,node_t**pp_last_node)
{
    node_t*p_run=NULL;
    p_run=p_list;
    while(p_run->next!=NULL)
        p_run=p_run->next;
    *pp_last_node=p_run;

}
static void get_last_node_and_prev(list_t*p_list,node_t**pp_node,node_t**pp_prev_node)
{
    node_t*p_run=NULL;
    node_t*p_run_prev=NULL;

    p_run=p_list->next;
    p_run_prev=p_list;

    while(p_run->next!=NULL)
    {
        p_run_prev=p_run;
        p_run=p_run->next;
    }
    *pp_node=p_run;
    *pp_prev_node=p_run_prev;
}
static node_t*get_node(data_t new_data)
{
    node_t*p_new_node=NULL;
    p_new_node=(node_t*)xmalloc(sizeof(node_t));
    p_new_node->data=new_data;
    p_new_node->next=NULL;
    return(p_new_node);
}
void *xmalloc(size_t size_in_bytes)
{
    void*p=NULL;
    p=malloc(size_in_bytes);
    if(p==NULL)
    {
        fprintf(stderr,"out of memory \n");
        EXIT_FAILURE;
    }
    return(p);
}
static node_t*search_node(list_t*p_list,data_t s_data)
{
    node_t*p_run=NULL;
    p_run=p_list->next;
    while(p_run!=NULL)
    {
        if(p_run->data==s_data)
        {
            return(p_run);
        }
        p_run=p_run->next;
    }
}

/*auxillary routines*/
lent_t get_lenght(list_t*p_list)
{
    node_t* p_run=NULL;
    p_run=p_list->next;
    lent_t count=0;
    while(p_run!=NULL)
    {
        count++;
        p_run=p_run->next;
    }
    return (count);
}
Bool is_empty(list_t *p_list)
{
    return(p_list->next==NULL);
}
Bool is_member(list_t*p_list,data_t s_data)
{
    node_t*p_node=NULL;
    p_node=search_node(p_list,s_data);
    if(p_node==NULL)
        return(FALSE);
    return(TRUE);
}
void show(list_t*p_list,const char*msg)
{
    node_t*p_run=NULL;
    if(msg)
        puts(msg);
    printf("[START]->");
    p_run=p_list->next;
    while(p_run!=NULL)
    {
        printf("[%d]->",p_run->data);
        p_run=p_run->next;
    }
    puts("[END]");
}

status_t insert_start(list_t*p_list,data_t new_data)
{
    node_t*p_new_node=get_node(new_data);
    p_new_node->next=p_list->next;
    p_list->next=p_new_node;
    return(SUCCESS);
}
status_t insert_end(list_t*p_list,data_t new_data)
{
    node_t*p_new_node=get_node(new_data);
    node_t*p_last_node=NULL;
    get_last_node(p_list,&p_last_node);
    p_last_node->next=p_new_node;
    return(SUCCESS);
}
status_t insert_after(list_t*p_list,data_t e_data,data_t new_data)
{
    node_t*p_existing_node=NULL;
    p_existing_node=search_node(p_list,e_data);
    if(p_existing_node==NULL)
        return(LIST_DATA_NOT_FOUND);
    node_t*p_new_node=get_node(new_data);
    p_new_node->next=p_existing_node->next;
    p_existing_node->next=p_new_node;
    return(SUCCESS);
}
status_t insert_before(list_t*p_list,data_t e_data,data_t new_data)
{
    node_t*p_existing_node=NULL;
    node_t*p_prev_node=NULL;
    get_last_node_and_prev(p_list,&p_existing_node,&p_prev_node);
    if(p_existing_node==NULL)
        return(LIST_DATA_NOT_FOUND);
    node_t*p_new_node=get_node(new_data);
    p_new_node->next=p_existing_node;
    p_prev_node->next=p_new_node;
    return(SUCCESS);
}

status_t get_start(list_t*p_list,data_t*p_start_data)
{
    if(is_empty(p_list))
        return LIST_EMPTY;
    *p_start_data=p_list->next->data;
    return(SUCCESS);
}
status_t get_end(list_t*p_list,data_t*p_end_data)
{
    if(is_empty(p_list))
        return LIST_EMPTY;
    node_t*last_node=NULL;
    get_last_node(p_list,&last_node);
    *p_end_data=last_node->data;
    return(SUCCESS);
}
status_t pop_start(list_t*p_list,data_t*p_start_data)
{
    if(is_empty(p_list))
        return(LIST_EMPTY);
    *p_start_data=p_list->next->data;
    node_t*start_node=p_list->next;
    p_list->next=p_list->next->next;
    free(start_node);
    return(SUCCESS);
}
status_t pop_end(list_t*p_list,data_t*p_end_data)
{
    if(is_empty(p_list))
        return(LIST_EMPTY);
    node_t*last_node=NULL;
    node_t*last_node_prev=NULL;
    get_last_node_and_prev(p_list,&last_node,&last_node_prev);
    last_node_prev->next=NULL;
    free(last_node);
    return(SUCCESS);
}
status_t remove_start(list_t*p_list)
{
    if(is_empty(p_list))
        return(LIST_EMPTY);
    node_t*start_node=p_list->next;
    p_list->next=p_list->next->next;
    free(start_node);
    return(SUCCESS);
}
status_t remove_end(list_t*p_list)
{
    if(is_empty(p_list))
        return(LIST_EMPTY);
    node_t* last_node=NULL;
    node_t*last_node_prev=NULL;
    get_last_node_and_prev(p_list,&last_node,&last_node_prev);
    last_node_prev->next=NULL;
    free(last_node);
    return(SUCCESS);
}
status_t remove_data(list_t*p_list,data_t remove_data)
{
    node_t*p_data_node=NULL;
    node_t*p_prev_node=NULL;
    if(is_empty(p_list))
        return(LIST_EMPTY);
    get_node_and_prev(p_list,remove_data,&p_data_node,&p_prev_node);
    p_prev_node->next=p_data_node->next;
    free(p_data_node);
    return(SUCCESS);
}