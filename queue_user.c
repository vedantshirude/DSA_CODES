#include<stdio.h>
#include<stdlib.h>

#include "queue_client.h"

int main()
{
    queue_t*p_queue=create_queue();
    enqueue(p_queue,100);
    enqueue(p_queue,200);
    enqueue(p_queue,300);
    enqueue(p_queue,400);
    show_queue(p_queue,"My queue : ");
    int delete1;
    dequeue(p_queue,&delete1);
    printf(" dequeue element :- %d\n",delete1);
    show_queue(p_queue,"My queue : ");
    int peek1;
    peek(p_queue,&peek1);
    printf(" peek :- %d\n",peek1);
    int length1= length(p_queue);
    printf(" lenght :- %d\n",length1);

    return 0;
}