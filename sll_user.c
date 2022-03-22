#include<stdio.h>
#include<stdlib.h>

#include "sll_client.h"

int main()
{
    list_t*p_list=create_list();
    insert_end(p_list,105);
    insert_end(p_list,101);
    insert_end(p_list,1120);
    insert_end(p_list,104);
    insert_end(p_list,102);
    insert_end(p_list,110);
    remove_start(p_list);
    remove_end(p_list);
    show(p_list,"MY SINGLY LINKED LSIT:-");
    return 0;
}