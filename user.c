#include<stdio.h>
#include<stdlib.h>

#include "client.h"

int main()
{
    stack_t*p_stack=create_stack();
    for(int i=0;i<10;i++)
    {
        push(p_stack,i*10);
    }
    show_stack(p_stack,"my first stack:");
    int peek1;
    peek(p_stack,&peek1);
    printf("peek :- %d",peek1);
    push(p_stack,100);
    show_stack(p_stack,"stack1:");
    int pop1;
    pop(p_stack,&pop1);
    pop(p_stack,&pop1);
    pop(p_stack,&pop1);
    pop(p_stack,&pop1);
    pop(p_stack,&pop1);
    pop(p_stack,&pop1);
    pop(p_stack,&pop1);
    pop(p_stack,&pop1);
    pop(p_stack,&pop1);
    pop(p_stack,&pop1);
    pop(p_stack,&pop1);
    int status=pop(p_stack,&pop1);
    if(status==List_Empty)
    {
        printf("\n");
        printf("stack empty");
    }
    else{
    show_stack(p_stack,"stack2:");
    }
    return 0;
}