#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "bst_client.h"

/*INTERFACE*/
bst_t *create_bst(void)
{
    bst_t *p_bst = NULL;
    p_bst = (bst_t*)xmalloc(sizeof(bst_t));
    p_bst->p_root_node = NULL;
    p_bst->nr_elements = 0;
    return (p_bst);
}
status_t insert_bst(bst_t *p_bst, data_t new_data)
{
    bst_node_t *p_new_node = NULL;
    bst_node_t *p_run = NULL;

    p_new_node = get_bst_node(new_data);
    p_run = p_bst->p_root_node;

    if (p_run == NULL)
    {
        p_bst->p_root_node = p_new_node;
        p_bst->nr_elements++;
        return (SUCCESS);
    }
    while (TRUE)
    {
        if (new_data <= p_run->data)
        {
            if (p_run->left == NULL)
            {
                p_run->left = p_new_node;
                p_new_node->parent = p_run;
                p_bst->nr_elements++;
                return (SUCCESS);
            }
            else
            {
                p_run = p_run->left;
                continue;
            }
        }
        else
        {
            if(p_run->right==NULL)
            {
                p_run->right=p_new_node;
                p_new_node->parent=p_run;
                p_bst->nr_elements++;
                return(SUCCESS);
            }
            else
            {
                p_run=p_run->right;
                continue;
            }
        }
    }
}
Bool search_bst(bst_t *p_bst, data_t search_data)
{
    if(search_bst_node(p_bst->p_root_node,search_data)==NULL)
        return(FALSE);
    return(TRUE);
}
void inorder_r(bst_t *p_bst)
{
    __inorder_r(p_bst->p_root_node);
}
void preorder_r(bst_t *p_bst)
{
    __preorder_r(p_bst->p_root_node);
}
void postorder_r(bst_t *p_bst)
{
    __postorder_r(p_bst->p_root_node);
}
status_t maximum_bst(bst_t *p_bst, data_t *p_max_data)
{
    bst_node_t*p_run=p_bst->p_root_node;
    if(p_bst->p_root_node==NULL)
        return(BST_EMPTY);
    while(p_run->right!=NULL)
    {
        p_run=p_run->right;
    }
    *p_max_data=p_run->data;
    return(SUCCESS);
}
status_t minimum_bst(bst_t *p_bst, data_t *p_min_data)
{
    bst_node_t*p_run=p_bst->p_root_node;
    if(p_bst->p_root_node==NULL)
        return(BST_EMPTY);
    while(p_run->left!=NULL)
    {
        p_run=p_run->left;
    }
    *p_min_data=p_run->data;
    return(SUCCESS);
}
status_t inorder_successor(bst_t *p_bst, data_t e_data, data_t *p_succ_data)
{
    bst_node_t*p_node=NULL;
    bst_node_t*p_succ_node=NULL;
    p_node=search_bst_node(p_bst->p_root_node,e_data);
    if(p_node==NULL)
        return(BST_EMPTY);
    p_succ_node=inorder_successor_node(p_node);
    if(p_succ_node==NULL)
        return(BST_N0_SUCCESSOR);
    *p_succ_data=p_succ_node->data;
    return(SUCCESS);
    
}
status_t inorder_predecessor(bst_t *p_bst, data_t e_data, data_t *p_pred_data)
{
    bst_node_t*p_node=NULL;
    bst_node_t*p_pred_node=NULL;
    p_node=search_bst_node(p_bst->p_root_node,e_data);
    if(p_node==NULL)
        return(BST_EMPTY);
    p_pred_node=inorder_predecessor_node(p_node);
    if(p_pred_node==NULL)
        return(BST_N0_SUCCESSOR);
    *p_pred_data=p_pred_node->data;
    return(SUCCESS);
}
status_t bst_remove(bst_t*p_bst,data_t r_data)
{
    bst_node_t *p_remove_node=NULL;
    bst_node_t* z=NULL;
    bst_node_t* y=NULL;

    p_remove_node=search_bst_node(p_bst->p_root_node,r_data);
    if(p_remove_node==NULL)
        return(BST_DATA_NOT_FOUND);
    z=p_remove_node;

    //-------------*CASE-1*----------------/
    /*  z->left==NULL  and  z->right may (or) may not be NULL*/
    if(z->left==NULL)
    {
        if(z->parent==NULL)  //if remove element is root node itself
            p_bst->p_root_node=z->right;
        else if(z==z->parent->left)
            z->parent->left=z->right;
        else
            z->parent->right=z->right;
        if(z->right)                   //this condition if z->right is not null
            z->right->parent=z->parent;
    }
    //------------*CASE-2*------------------/
    /*  z->right==NULL  and  z->left may (or) may not be NULL*/
    else if(z->right==NULL)
    {
        if(z->parent==NULL)
            p_bst->p_root_node=z->left;
        else if(z==z->parent->left)
            z->parent->left=z->left;
        else
            z->parent->right=z->left;
        if(z->left)
            z->left->parent=z->parent;
    }
    else
    {
        y=z->right;
        while(y->left!=NULL)
            y=y->left;
        if(y!=z->right)
        {
            y->parent->left=y->right;
            if(y->right)
                y->right->parent=y->parent;

            y->right=z->right;
            y->right->parent=y;
        }
        if(z->parent==NULL)
            p_bst->p_root_node=y;
        else if(z==z->parent->left)
            z->parent->left=y;
        else 
            z->parent->right=y;
        
        y->parent=z->parent;

        y->left=z->left;
        y->left->parent=y;
    }
    free(z);
    z=NULL;

    return(SUCCESS);

}

/*BST AUXILLARY*/
bst_node_t *search_bst_node(bst_node_t *p_root_node, data_t search_data)
{
    bst_node_t*p_run=NULL;
    p_run=p_root_node;
    while(p_run!=NULL)
    {
        if(p_run->data==search_data)
            return(p_run);
        else if(p_run->data<search_data)
            p_run=p_run->right;
        else
            p_run=p_run->left;
    }
    return(p_run);
}
bst_node_t *get_bst_node(data_t new_data)
{
    bst_node_t *p_new_node = NULL;
    p_new_node = (bst_node_t *)xmalloc(sizeof(bst_node_t));
    p_new_node->data = new_data;
    p_new_node->left = NULL;
    p_new_node->right = NULL;
    p_new_node->parent = NULL;
    return (p_new_node);
}
bst_node_t *inorder_successor_node(bst_node_t *p_bst_node)
{
    bst_node_t*x=NULL;
    bst_node_t*y=NULL;
    bst_node_t*p_run=NULL;

    x=p_bst_node;
    y=p_bst_node->parent;    //i.e y=x->parent;

    /*case 1:-*/
    if(x->right!=NULL)
    {
        p_run=x->right;
        while(p_run->left!=NULL)
            p_run=p_run->left;
        return(p_run);
    }
    /*case 2:-*/
    while(y!=NULL && x==y->right)
    {
        x=y;
        y=x->parent;
    }
    return(y);

}
bst_node_t *inorder_predecessor_node(bst_node_t *p_bst_node)
{
    bst_node_t*x=NULL;
    bst_node_t*y=NULL;
    bst_node_t*p_run=NULL;

    x=p_bst_node;
    y=x->parent;
    /*case 1:-*/
    if(x->left!=NULL)
    {
        p_run=x->left;
        while(p_run->right!=NULL)
            p_run=p_run->right;
        return(p_run);
    }
    /*case 2:*/
    while(y!=NULL && x==y->left)
    {
        x=y;
        y=x->parent;
    }
    return(y);
}
void __inorder_r(bst_node_t *p_root_node)
{
    if(p_root_node!=NULL)
    {
        __inorder_r(p_root_node->left);
        printf("[%d] ",p_root_node->data);
        __inorder_r(p_root_node->right);
    }
}
void __preorder_r(bst_node_t *p_root_node)
{
    if(p_root_node!=NULL)
    {
        printf("[%d] ",p_root_node->data);
        __preorder_r(p_root_node->left);
        __preorder_r(p_root_node->right);
    }
}
void __postorder_r(bst_node_t *p_root_node)
{
    if(p_root_node!=NULL)
    {
        __postorder_r(p_root_node->left);
        __postorder_r(p_root_node->right);
        printf("[%d] ",p_root_node->data);
    }
}

/*GENERAL AUXILLARY ROUTINES*/
void *xmalloc(size_t nr_size)
{
    void *p = NULL;
    p = malloc(nr_size);
    if (p == NULL)
    {
        fprintf(stderr, "Out of memory\n");
        EXIT_FAILURE;
    }
    return (p);
}
