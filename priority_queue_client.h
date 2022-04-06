
typedef struct node node_t;
typedef node_t list_t;
typedef node_t priority_queue_t;
typedef int status_t;
typedef int data_t;
typedef int Bool;

#define SUCCESS 1
#define FAILURE -1
#define LIST_IS_EMPTY  2
#define PRIOR_QUEUE_EMPTY 3


struct node
{
    data_t data;
    struct node*prev;
    struct node*next;
};

priority_queue_t*create_prior_queue(void);
status_t prior_enqueue(priority_queue_t*p_queue,data_t data);
status_t prior_dequeue_min(priority_queue_t*p_queue,data_t*min_data);
Bool is_prior_queue_empty(priority_queue_t*p_queue);
status_t destroy_prior_queue(priority_queue_t*p_queue);
void show_priority_queue(priority_queue_t*p_queue,const char*msg);

list_t*create_list(void);

status_t insert_beg(list_t*p_list,data_t data);
status_t insert_end(list_t*p_list,data_t data);
status_t remove_beg(list_t*p_list,data_t*data);
status_t remove_end(list_t*p_list,data_t*data);
Bool is_list_empty(list_t*p_list);
status_t destroy_list(list_t*p_list);
void show_list(list_t*p_list,const char*msg);


void generic_insert(node_t*p_beg,node_t*p_mid,node_t*p_end);
void generic_delete(node_t*p_delete_node);
node_t*get_list_node(data_t data);
void*xmalloc(size_t size_nr_bytes);

