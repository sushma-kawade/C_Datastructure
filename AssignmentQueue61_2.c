#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *next;
};
struct node *First;

void EnQueue(int No)
{
    struct node *newn = (struct node*)malloc(sizeof(struct node));


    newn->data = No;
    newn->next = NULL;

    if(First == NULL)
    {
        First = newn;
    } 
    else
    {
        struct node *temp;
        temp = First;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
    }
    printf("%d gets enqueue the elemts of a queue\n",newn->data);
}

int DeQueue()
{
    struct node *temp;
    if(First == NULL)
    {
        return -1;
    }
    else
    {
        First = First->next;
        free(temp);
    }
    return First->data;
}

void Display()
{
    struct node *temp;
    temp = First;
    if(First == NULL)
    {
        printf("Queue is empty\n");
    }
    else
    {
        printf("The elemts of queue are:\n");
        while(temp != NULL)
        {
            printf("| %d |->",temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }

}
int main()
{
    int iRet = 0;
    EnQueue(1);
    EnQueue(2);
    EnQueue(3);
    EnQueue(4);
    EnQueue(5);

    Display();

    iRet = DeQueue();
    printf("The remove element of queue is: %d\n",iRet);
    Display();

    iRet = DeQueue();
    printf("The remove element of queue is: %d\n",iRet);
    Display();

    return 0;
}