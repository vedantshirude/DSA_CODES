
#define SUCCESS  1
#define TRUE     1
#define FALSE    0
#define BST_EMPTY  10
#define BST_DATA_NOT_FOUND 2
#define BST_N0_SUCCESSOR      3
#define BST_NO_PREDECESSOR    4
#define LIST_EMPTY            6

struct bst_node;
struct bst;

typedef struct bst_node bst_node_t;
typedef struct bst bst_t;

typedef int data_t;
typedef int status_t;
typedef int Bool;

struct bst
{
    bst_node_t*p_root_node;
    int nr_elements;
};
struct bst_node
{
    data_t data;
    struct bst_node*left;
    struct bst_node*right;
    struct bst_node*parent;
};
/*INTERFACE*/
bst_t *create_bst(void);
status_t insert_bst(bst_t*p_bst,data_t new_data);
Bool search_bst(bst_t *p_bst,data_t search_data);
void inorder_r(bst_t *p_bst);
void preorder_r(bst_t *p_bst);
void postorder_r(bst_t *p_bst);
status_t maximum_bst(bst_t*p_bst,data_t*p_max_data);
status_t minimum_bst(bst_t*p_bst,data_t*p_min_data);
status_t inorder_successor(bst_t*p_bst,data_t e_data,data_t*p_succ_data);
status_t inorder_predecessor(bst_t*p_bst,data_t e_data,data_t*p_pred_data);
status_t bst_remove(bst_t*p_bst,data_t r_data);

/*BST AUXILLARY*/
bst_node_t*search_bst_node(bst_node_t*p_root_node,data_t search_data);
bst_node_t*get_bst_node(data_t new_data);
bst_node_t*inorder_successor_node(bst_node_t*p_bst_node);
bst_node_t*inorder_predecessor_node(bst_node_t*p_bst_node);
void __inorder_r(bst_node_t*p_root_node);
void __preorder_r(bst_node_t*p_root_node);
void __postorder_r(bst_node_t*p_root_node);

/*GENERAL AUXILLARY ROUTINES*/
void*xmalloc(size_t nr_size);