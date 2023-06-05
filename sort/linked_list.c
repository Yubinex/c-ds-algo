#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct LinkedList {
    Node* head;
} LinkedList;

void initLinkedList(LinkedList* list) { list->head = NULL; }

void insertAtBeginning(LinkedList* list, int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->next = NULL;
    new_node->value = value;

    if (list->head == NULL) {
        list->head = new_node;
    } else {
        new_node->next = list->head;
        list->head = new_node;
    }
}

void insertAtEnd(LinkedList* list, int value) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->next = NULL;
    new_node->value = value;

    if (list->head == NULL) {
        list->head = new_node;
        return;
    }

    Node* curr = list->head;
    while (curr->next != NULL) { curr = curr->next; }

    curr->next = new_node;
}

void removeNode(LinkedList* list, int value) {
    // If the list is empty, immediately return
    if (list->head == NULL) { return; }

    // Check if the head node holds the correct data
    if (list->head->value == value) {
        Node* temp = list->head;
        list->head = list->head->next;
        free(temp);
        return;
    }

    // Traverse the list to find the node to remove
    Node* curr = list->head;
    while (curr->next != NULL) {
        if (curr->value == value) {
            Node* temp = curr->next;
            curr->next = curr->next->next;
            free(temp);
            return;
        }
        curr = curr->next;
    }
}

void printList(LinkedList* list) {
    Node* curr = list->head;
    while (curr != NULL) {
        printf("%d - ", curr->value);
        curr = curr->next;
    }
}

void freeLinkedList(LinkedList* list) {
    Node* curr = list->head;
    while (curr != NULL)
    {
        Node* temp = curr;
        curr = curr->next;
        free(temp);
    }

}

int main() {
    LinkedList list;
    initLinkedList(&list);

    insertAtBeginning(&list, 5);
    insertAtBeginning(&list, 3);
    insertAtBeginning(&list, 1);
    printf("List after inserting at the beginning: ");
    printList(&list);
    printf("\n");

    insertAtEnd(&list, 7);
    insertAtEnd(&list, 9);
    printf("List after inserting at the end: ");
    printList(&list);
    printf("\n");

    removeNode(&list, 3);
    printf("List after removing 3: ");
    printList(&list);
    printf("\n");

    freeLinkedList(&list);

    return 0;
}