// C program to delete a given key from
// linked list.
#include <stdio.h>
#include <stdlib.h>

/* structure for a node */
struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

/* Function to insert a node at the beginning of
a Circular linked list */
void push(struct Node** head_ref, int data)
{
    // Create a new node and make head as next
    // of it.
    struct Node* ptr1 = (struct Node*)malloc(sizeof(struct Node));
    ptr1->data = data;
    ptr1->next = *head_ref;

    /* If linked list is not NULL then set the
    next of last node */
    if (*head_ref != NULL) {
        // Find the node before head and update
        // next of it.
        struct Node* temp = *head_ref;
        while (temp->next != *head_ref)
            temp = temp->next;
        temp->next = ptr1;
    }
    else
        ptr1->next = ptr1; /*For the first node */

    *head_ref = ptr1;
}

/* Function to print nodes in a given
circular linked list */
void printList(struct Node* head)
{
    struct Node* temp = head;
    if (head != NULL) {
        do {
            printf("%d ", temp->data);
            temp = temp->next;
        } while (temp != head);
    }

    printf("\n");
}

/* Function to delete a given node from the list */
int deleteNode(struct Node* head,struct Node* curr)
{
    if (head == NULL)
        return -1;

    struct Node *prev = curr;

    // Check if node is only node
    if (curr->next == head)
    {
        printf("%d",curr->data);
        head = NULL;
        free(curr);
        return 1;
    }

    // If more than one node, check if
    // it is first node
    if (curr == head)
    {
        prev = head;
        while (prev->next != head)
            prev = prev->next;
        head = curr->next;
        prev->next = head;
        free(curr);
    }

    // check if node is last node
    else if (curr->next == head && curr == head)
    {
        printf("%d",curr->data);
        prev->next = head;
        free(curr);
        return 1;
    }
    else
    {
        prev->next = curr->next;
        free(curr);
    }
    return 0;
}

int remove_step(struct Node* head,int step)
{
    int count = 0;
    struct Node *curr = head;
    while (head != head->next) {
        if (count == step) {
            printf("Sai o %d : ",curr->data);
            deleteNode(head,curr);
            count = 0;
        }
        curr = curr->next;
        count++;
    }
    printf("%d",curr->data);
    return 0;
}

/* Driver code */
int main()
{
    /* Initialize lists as empty */
    struct Node* head = NULL;
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);

    remove_step(head,2);

    return 0;
}