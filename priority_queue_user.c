#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "priority_queue_client.h"

int main()
{
    priority_queue_t*p_queue=create_prior_queue();
    prior_enqueue(p_queue,10);
    prior_enqueue(p_queue,20);
    prior_enqueue(p_queue,30);
    prior_enqueue(p_queue,40);
    prior_enqueue(p_queue,4);
    prior_enqueue(p_queue,50);
    prior_enqueue(p_queue,60);
    int min_data;
    prior_dequeue_min(p_queue,&min_data);
    printf("dequeue element is:%d\n",min_data);
    show_priority_queue(p_queue,"My First Priority Queue:-");
    return 0;
}