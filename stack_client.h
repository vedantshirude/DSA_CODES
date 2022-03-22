#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <assert.h>

#define SUCCESS 1
#define FAILURE 0
#define TRUE 1
#define FALSE 0
#define List_Data_Not_Found 2
#define List_Empty 3

typedef int data_t;
typedef int status_t;
typedef int bool;
typedef struct node node_t;
typedef node_t list_t;
typedef int len_t;
typedef list_t stack_t;


struct node
{
    data_t data;
    node_t *prev;
    node_t *next;
};
//----------------------------------------------------/*LIST ROUTINES*/----------------------------------------------------------------------
/*interface routines-declaration*/
list_t *create_list(void);
len_t get_length(list_t *p_list);
bool is_list_empty(list_t *p_list);
bool contains(list_t *p_list, data_t search_data);
void show_list(list_t *p_list, const char *msg);
int get_repeat_count(list_t *p_list, data_t search_data);
status_t get_beg(list_t *p_list, data_t *p_data);
list_t *get_reversed_list(list_t *p_list);
list_t *concat_list(list_t *p_list1, list_t *p_list2);
status_t remove_data(list_t *p_list, data_t r_data);
status_t insert_before(list_t *p_list, data_t e_data, data_t new_data);
status_t insert_after(list_t *p_list, data_t e_data, data_t new_data);
status_t pop_end(list_t *p_list, data_t *p_data);
status_t pop_beg(list_t *p_list, data_t *p_data);
status_t delete_end(list_t *p_list);
status_t delete_beg(list_t *p_list);
status_t insert_end(list_t *p_list, data_t new_data);
status_t insert_beg(list_t *p_list, data_t new_data);
status_t append_list(list_t *p_list1, list_t *p_list2);
status_t get_last(list_t *p_list, data_t *p_data);
list_t *array_to_list(data_t *p_array, size_t size);

/*list auxillary routines-declaration*/
node_t *get_list_node(data_t new_data);
node_t *locate_node(list_t *p_list, data_t search_data);
void generic_insert(node_t *p_beg, node_t *p_mid, node_t *p_end);
void generic_delete(node_t *p_delete_node);

/*memory allocation routines -declaration*/
void *xmalloc(size_t size_in_bytes);


//----------------------------------------------------/*STACK ROUTINES*/--------------------------------------------//
stack_t*create_stack(void);
status_t push(stack_t*p_stack,data_t p_data);
status_t pop(stack_t*p_stack,data_t*p_data);
status_t peek(stack_t*p_stack,data_t*p_data);
bool is_stack_empty(stack_t*p_stack);
len_t total_stack_element(stack_t*p_stack);
void show_stack(stack_t*p_stack,char*msg);
