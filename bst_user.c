#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#include "bst_client.h"

int main(void)
{
    bst_t*p_bst=create_bst();
    srand(time(0));
    for(int i=0;i<10;i++)
    {
        insert_bst(p_bst,i*10);
    }
    inorder_r(p_bst);
    int inorder_succ;
    inorder_successor(p_bst,10,&inorder_succ);
    printf("\nInoder successor of 10 is = %d",inorder_succ);
    int inorder_pred;
    inorder_predecessor(p_bst,50,&inorder_pred);
    printf("\nInoder predeccessor of 50 is = %d\n",inorder_pred);
    bst_remove(p_bst,50);
    inorder_r(p_bst);

    return 0;
}