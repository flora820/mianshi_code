#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct link
{
    int data;
    struct link *next;
}Link, *Linklist;

/*有头节点*/
Linklist initlink(int a[],int size)
{
    int i;
    Linklist head = (Linklist)malloc(sizeof(Link));
    Linklist temp = NULL;
    
    head->next = NULL;
    temp = head;

    for(i = 0; i < size; i++)
    {
        Linklist p = (Linklist)malloc(sizeof(Link));
        p->data = a[i];
        p->next = NULL;
        temp->next = p;
        temp = temp->next;
    }
    printf("init linkend\r\n");
    
    return head;
}

void printlist(Linklist head)
{
    Linklist temp = head;
    temp = temp->next;

    while(temp != NULL)
    {
        printf("%d,",temp->data);
        temp = temp->next; 
    }

}



int main()
{
    int a[10] = {10,2,1,4,5,8,21,7,8,6};
    Linklist head = NULL;
    head = initlink(a, 10);
    printlist(head);


    
    return 0;
}
