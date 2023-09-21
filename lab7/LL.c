#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    Node *link;
} Node;

Node *start = NULL;
void createList()
{
    if (start == NULL)
    {
        int n;
        printf("Enter number of nodes: ");
        scanf("%d", &n);
        if (n != 0)
        {
            int data;
            Node *newNode;
            Node *current;
            newNode = malloc(sizeof(Node));
            start = newNode;
            current = start;
            printf("Enter start data: ");
            scanf("%d", &data);
            start->data = data;
            for (int i = 2; i <= n; i++)
            {
                newNode = malloc(sizeof(Node));
                current->link = newNode;
                printf("Enter data: ");
                scanf("%d", &data);
                newNode->data = data;
                current = current->link;
            }
            current->link = NULL;
            printf("List is created\n");
        }
    }
    else
        printf("List already created\n");
}

void traverse()
{
    Node *current;
    if (start == NULL)
        printf("Empty list");
    else
    {
        printf("Displaying list: \n");
        current = start;
        while (current != NULL)
        {
            printf("Data: %d\n", current->data);
            current = current->link;
        }
    }
}

void insertBefore() // inserts element before specified element
{
    int data, val, found = 0;
    Node *temp;
    Node *current;
    Node *nextNode;
    temp = malloc(sizeof(Node));
    current = malloc(sizeof(Node));
    printf("Enter data to insert before of in linked list: ");
    scanf("%d", &val);

    current = start;
    nextNode = current->link;
    while (current != NULL)
    {
        if (nextNode->data == val)
        {
            current->link = temp;
            temp->link = nextNode;
            printf("Enter data to be inserted: ");
            scanf("%d", &data);
            temp->data = data;
            printf("Insert node before another node containing data %d completed\n", val);
            found = 1;
            return;
        }
        current = current->link;
        nextNode = current->link;
    }
    if (found == 0)
        printf("Data not found\n");
}

void insertAfter()
{
    int data, val, found = 0;
    Node *temp;
    Node *current;
    Node *nextNode;
    temp = malloc(sizeof(Node));
    current = malloc(sizeof(Node));
    printf("Enter data to insert after of in linked list: ");
    scanf("%d", &val);

    current = start;
    nextNode = current->link;
    while (current != NULL)
    {
        if (current->data == val)
        {
            current->link = temp;
            temp->link = nextNode;
            printf("Enter data to be inserted: ");
            scanf("%d", &data);
            temp->data = data;
            printf("Insert node after another node containing data %d completed\n", val);
            found = 1;
            return;
        }
        current = current->link;
        nextNode = current->link;
    }
    if (found == 0)
        printf("Data not found\n");
}

void delete()
{
    int del, found = 0;
    Node *previous;
    Node *current;
    current = malloc(sizeof(Node));
    previous = NULL;
    printf("Enter element to be deleted: ");
    scanf("%d", &del);

    current = start;
    while (current != NULL)
    {
        if (current->data == del)
        {
            previous->link = current->link;
            printf("Element %d deleted\n", del);
            found = 1;
            return;
        }
        previous = current;
        current = current->link;
    }
    if (found == 0)
        printf("Element not found");
}

int main()
{
    createList();
    delete ();
    traverse();
}