#pragma once

#define SUCCESS 1
#define TRUE 1
#define FALSE 0
#define LIST_DATA_NOT_FOUND 2
#define LIST_EMPTY 3

typedef int data_t;
typedef int status_t;
typedef int lent_t;
typedef int Bool;
typedef struct node node_t;
typedef node_t list_t;

struct node
{
    data_t data;
    struct node*next;
};
list_t*create_list(void);

/*supportive functions   or    interface routines*/
static void get_node_and_prev(list_t*p_list,data_t s_data,node_t**pp_node,node_t **pp_prev_node);
static void get_last_node(list_t*p_list,node_t**pp_last_node);
static void get_last_node_and_prev(list_t*p_list,node_t**pp_node,node_t**pp_prev_node);
static node_t*get_node(data_t new_data);
void *xmalloc(size_t size_in_bytes);
static node_t*search_node(list_t*p_list,data_t s_data);

/*auxillary routines*/
lent_t get_lenght(list_t*p_list);
Bool is_empty(list_t *p_list);
Bool is_member(list_t*p_list,data_t s_data);
void show(list_t*p_list,const char*msg);

status_t insert_start(list_t*p_list,data_t new_data);
status_t insert_end(list_t*p_list,data_t new_data);
status_t insert_after(list_t*p_list,data_t e_data,data_t new_data);
status_t insert_before(list_t*p_list,data_t e_data,data_t new_data);

status_t get_start(list_t*p_list,data_t*p_start_data);
status_t get_end(list_t*p_list,data_t*p_end_data);
status_t pop_start(list_t*p_list,data_t*p_start_data);
status_t pop_end(list_t*p_list,data_t*p_end_data);

status_t remove_start(list_t*p_list);
status_t remove_end(list_t*p_list);
status_t remove_data(list_t*p_list,data_t remove_data);

