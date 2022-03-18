#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

#define TRUE 1
#define FALSE 0

typedef int status_t;

status_t binary_search(int *pa,int search_element,int start_index,int end_index);

int main(int argc,char*argv[])
{
    int pa[]={1,2,3,4,5,6,7,8,9};
    assert(argc==4);
    int search_element=atoi(argv[1]);
    int si=atoi(argv[2]);
    int ei=atoi(argv[3]);
    int status=binary_search(pa,search_element,si,ei);
    if(status)
        printf("Element Successfully Found");
    else
        printf("Element Not Found");
    return 0;
}
status_t binary_search(int *pa,int search_element,int start_index,int end_index)
{
    int mid_index;

    if(start_index<=end_index)
    {
        mid_index=(start_index+end_index)/2;
        if(search_element==pa[mid_index])
            return(TRUE);

        else if(search_element<pa[mid_index])
            return binary_search(pa,search_element,start_index,mid_index-1);

        else if(search_element>pa[mid_index])
            return binary_search(pa,search_element,mid_index+1,end_index);
    }
    return (FALSE);
}