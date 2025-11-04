/*
 * Program: Linked List Implementation in C
 * Author: Wasim Khan
 * Description:
 *   A menu-driven program that performs all major operations
 *   on a singly linked list — insertion, deletion, searching, and display.
 *   The program dynamically allocates memory using malloc().
 *
 * Features:
 *   - Insert node at beginning
 *   - Insert node at end
 *   - Insert node at a specific position
 *   - Delete node (beginning, end, or specific position)
 *   - Search for a node
 *   - Display all nodes
 *
 * Language: C
 * Date: November 2025
 */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *start = NULL;

// Function declarations
void insert_beginning(int value);
void insert_random(int value, int position);
void insert_last(int value);
void delete_beginning();
void delete_random(int position);
void delete_last();
void search(int value);
void display();

int main() {
    int choice, value, position;

    while (1) {
        printf("\nLinked List Operations:\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at Random Position\n");
        printf("3. Insert at End\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from Random Position\n");
        printf("6. Delete from End\n");
        printf("7. Search\n");
        printf("8. Display\n");
        printf("9. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert_beginning(value);
                break;

            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position to insert (starting from 1): ");
                scanf("%d", &position);
                insert_random(value, position);
                break;

            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insert_last(value);
                break;

            case 4:
                delete_beginning();
                break;

            case 5:
                printf("Enter position to delete (starting from 1): ");
                scanf("%d", &position);
                delete_random(position);
                break;

            case 6:
                delete_last();
                break;

            case 7:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(value);
                break;

            case 8:
                display();
                break;

            case 9:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

// Function definitions

void insert_beginning(int value) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL) {
        printf("Memory Overflow\n");
        return;
    }
    ptr->data = value;
    ptr->next = start;
    start = ptr;
    printf("Node inserted at beginning.\n");
}

void insert_last(int value) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL) {
        printf("Memory Overflow\n");
        return;
    }
    ptr->data = value;
    ptr->next = NULL;

    if (start == NULL) {
        start = ptr;
    } else {
        struct Node *temp = start;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = ptr;
    }
    printf("Node inserted at end.\n");
}

void insert_random(int value, int position) {
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    if (ptr == NULL) {
        printf("Memory Overflow\n");
        return;
    }
    ptr->data = value;

    if (position == 1) {
        ptr->next = start;
        start = ptr;
        printf("Node inserted at position %d.\n", position);
        return;
    }

    struct Node *temp = start;
    for (int i = 1; i < position - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position.\n");
        free(ptr);
        return;
    }

    ptr->next = temp->next;
    temp->next = ptr;
    printf("Node inserted at position %d.\n", position);
}

void delete_beginning() {
    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node *ptr = start;
    start = start->next;
    free(ptr);
    printf("Node deleted from beginning.\n");
}

void delete_last() {
    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (start->next == NULL) {
        free(start);
        start = NULL;
        printf("Only node deleted.\n");
        return;
    }

    struct Node *ptr = start;
    struct Node *ptr1 = NULL;
    while (ptr->next != NULL) {
        ptr1 = ptr;
        ptr = ptr->next;
    }
    ptr1->next = NULL;
    free(ptr);
    printf("Node deleted from end.\n");
}

void delete_random(int position) {
    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (position == 1) {
        delete_beginning();
        return;
    }

    struct Node *ptr = start;
    struct Node *ptr1 = NULL;

    for (int i = 1; i < position && ptr != NULL; i++) {
        ptr1 = ptr;
        ptr = ptr->next;
    }

    if (ptr == NULL) {
        printf("Invalid position.\n");
        return;
    }

    ptr1->next = ptr->next;
    free(ptr);
    printf("Node deleted from position %d.\n", position);
}

void search(int value) {
    struct Node *temp = start;
    int pos = 1;
    int found = 0;

    while (temp != NULL) {
        if (temp->data == value) {
            printf("Value %d found at position %d.\n", value, pos);
            found = 1;
            break;
        }
        temp = temp->next;
        pos++;
    }

    if (!found)
        printf("Value %d not found in the list.\n", value);
}

void display() {
    if (start == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = start;
    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
