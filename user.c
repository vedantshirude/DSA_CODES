#include "client.h"
int main(void)
{
    list_t *p_list = create_list();
    for (int i = 0; i < 10; i++)
    {
        insert_end(p_list, i * 10);
    }
    show_list(p_list, "My linked list:");
    list_t *p_reversed = get_reversed_list(p_list);
    show_list(p_reversed, "My reversed linked list:");
    delete_beg(p_reversed);
    delete_end(p_reversed);
    insert_beg(p_reversed, 1000);
    insert_end(p_reversed, 9000);
    insert_after(p_reversed, 30, 4444);
    insert_before(p_reversed, 30, 444);
    show_list(p_reversed, "My updated linked list:");
    int length = get_length(p_reversed);
    printf("Length of my updated list:- %d", length);
    list_t *p_listt = concat_list(p_list, p_reversed);
    show_list(p_listt, "Two concated lists :");
    return 0;
}