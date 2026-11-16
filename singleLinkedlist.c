#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node
struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

// 1. Insert at the Beginning
void insertAtBeginning(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = head;
    head = newNode;
    printf("Inserted %d at the beginning.\n", val);
}

// 2. Insert at the End
void insertAtEnd(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } 
    else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    printf("Inserted %d at the end.\n", val);
}

// 3. Insert at a Specific Position
void insertAtPosition(int val, int pos) {
    if (pos < 1) {
        printf("Invalid position!\n");
    } 
    else if (pos == 1) {
        insertAtBeginning(val);
    } 
    else {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = val;

        struct Node* temp = head;
        int i = 1;
        while (i < pos - 1 && temp != NULL) {
            temp = temp->next;
            i++;
        }

        if (temp == NULL) {
            printf("Position out of range!\n");
            free(newNode);
        } 
        else {
            newNode->next = temp->next;
            temp->next = newNode;
            printf("Inserted %d at position %d.\n", val, pos);
        }
    }
}

// 4. Delete from the Beginning
void deleteFromBeginning() {
    if (head == NULL) {
        printf("List is empty! Nothing to delete.\n");
    } 
    else {
        struct Node* temp = head;
        head = head->next;
        printf("Deleted %d from the beginning.\n", temp->data);
        free(temp);
    }
}

// 5. Delete from the End
void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty! Nothing to delete.\n");
    } 
    else if (head->next == NULL) {
        printf("Deleted %d from the end.\n", head->data);
        free(head);
        head = NULL;
    } 
    else {
        struct Node* temp = head;
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        printf("Deleted %d from the end.\n", temp->next->data);
        free(temp->next);
        temp->next = NULL;
    }
}

// 6. Delete from a Specific Position
void deleteFromPosition(int pos) {
    if (head == NULL) {
        printf("List is empty!\n");
    } 
    else if (pos < 1) {
        printf("Invalid position!\n");
    } 
    else if (pos == 1) {
        deleteFromBeginning();
    } 
    else {
        struct Node* temp = head;
        int i = 1;
        while (i < pos - 1 && temp != NULL) {
            temp = temp->next;
            i++;
        }

        if (temp == NULL || temp->next == NULL) {
            printf("Position out of range!\n");
        } 
        else {
            struct Node* nextNode = temp->next;
            temp->next = nextNode->next;
            printf("Deleted %d from position %d.\n", nextNode->data, pos);
            free(nextNode);
        }
    }
}

// 7. Display the Linked List
void display() {
    if (head == NULL) {
        printf("List is empty!\n");
    } 
    else {
        struct Node* temp = head;
        printf("Linked List: ");
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

// 8. Search an Element
void search(int key) {
    if (head == NULL) {
        printf("List is empty!\n");
    } 
    else {
        struct Node* temp = head;
        int pos = 1;
        int found = 0;
        while (temp != NULL) {
            if (temp->data == key) {
                printf("Element %d found at position %d.\n", key, pos);
                found = 1;
                break;
            }
            temp = temp->next;
            pos++;
        }
        if (found == 0) {
            printf("Element %d not found in the list.\n", key);
        }
    }
}

int main() {
    int choice, val, pos;

    while (1) {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Specific Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Specific Position\n");
        printf("7. Display List\n");
        printf("8. Search Element\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Exiting.\n");
            break;
        }

        if (choice == 1) {
            printf("Enter value to insert: ");
            scanf("%d", &val);
            insertAtBeginning(val);
        } 
        else if (choice == 2) {
            printf("Enter value to insert: ");
            scanf("%d", &val);
            insertAtEnd(val);
        } 
        else if (choice == 3) {
            printf("Enter value to insert: ");
            scanf("%d", &val);
            printf("Enter position: ");
            scanf("%d", &pos);
            insertAtPosition(val, pos);
        } 
        else if (choice == 4) {
            deleteFromBeginning();
        } 
        else if (choice == 5) {
            deleteFromEnd();
        } 
        else if (choice == 6) {
            printf("Enter position to delete: ");
            scanf("%d", &pos);
            deleteFromPosition(pos);
        } 
        else if (choice == 7) {
            display();
        } 
        else if (choice == 8) {
            printf("Enter value to search: ");
            scanf("%d", &val);
            search(val);
        } 
        else if (choice == 9) {
            printf("Exiting program...\n");
            break;
        } 
        else {
            printf("Invalid choice! Please choose between 1 and 9.\n");
        }
    }
    return 0;
}