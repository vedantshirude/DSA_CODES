/*Headers*/
#include<stdio.h>
#include<stdlib.h>

/*Symbolic constants*/
#define SUCCESS 1

/*Information Structure Layout*/
struct vector
{
    int *p_arr;
    size_t size;
};
/*Interface function declaration*/
struct vector* create_vector(void);
int push_back(struct vector*p_vec,int new_element);
void destroy_vector(struct vector* p_vec);

/*Auxillary function declaration*/
void* xmalloc(size_t size_per_mem);

int main()
{
    struct vector*p_vec=create_vector();
    for(int i=0;i<10;i++)
    {
        int ret=push_back(p_vec,i*10);
        if(ret!=SUCCESS){
            fprintf(stderr,"unexpected error/n");
            exit(EXIT_FAILURE);
        }
    }
    for(int i=0;i<p_vec->size;i++)
        printf("p_vec->p_arr[%d] : %d\n",i,p_vec->p_arr[i]);

    destroy_vector(p_vec);
    p_vec=NULL;
    return 0;
}
/*Interface function definition*/
struct vector*create_vector(void)
{
    struct vector*p_vec=NULL;
    p_vec=xmalloc(sizeof(struct vector));
    p_vec->p_arr=NULL;
    p_vec->size=0;
    return(p_vec);
}
int push_back(struct vector*p_vec,int new_element)
{
    p_vec->size=p_vec->size+1;
    p_vec->p_arr=realloc(p_vec->p_arr,p_vec->size*sizeof(int));
    p_vec->p_arr[p_vec->size-1]=new_element;
    return(SUCCESS);
}
void destroy_vector(struct vector*p_vec)
{
    free(p_vec->p_arr);
    free(p_vec);
}
/*Auxillary function definition*/
void*xmalloc(size_t size_per_mem)
{
    void*p=NULL;
    p=(struct vector*)malloc(sizeof(size_per_mem));
    if(p==NULL)
    {
        fprintf(stderr,"out of memory\n");
        exit(EXIT_FAILURE);
    }
    return p;
}