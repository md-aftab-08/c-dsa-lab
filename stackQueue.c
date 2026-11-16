#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Global variables for Stack
int stack[MAX];
int top = -1;

// Global variables for Queue
int queue[MAX];
int front = -1;
int rear = -1;

/* ================= STACK OPERATIONS ================= */

void pushStack(int val) {
    if (top == MAX - 1) {
        printf("Stack Overflow! Cannot push %d\n", val);
    } 
    else {
        top++;
        stack[top] = val;
        printf("Pushed %d onto the stack.\n", val);
    }
}

void popStack() {
    if (top == -1) {
        printf("Stack Underflow! Stack is empty.\n");
    } 
    else {
        printf("Popped %d from the stack.\n", stack[top]);
        top--;
    }
}

void peekStack() {
    if (top == -1) {
        printf("Stack is empty!\n");
    } 
    else {
        printf("Top element is %d\n", stack[top]);
    }
}

void displayStack() {
    if (top == -1) {
        printf("Stack is empty!\n");
    } 
    else {
        printf("Stack elements (top to bottom): ");
        int i = top;
        while (i >= 0) {
            printf("%d ", stack[i]);
            i--;
        }
        printf("\n");
    }
}

/* ================= QUEUE OPERATIONS ================= */

void enqueueQueue(int val) {
    if (rear == MAX - 1) {
        printf("Queue Overflow! Cannot enqueue %d\n", val);
    } 
    else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = val;
        printf("Enqueued %d into the queue.\n", val);
    }
}

void dequeueQueue() {
    if (front == -1 || front > rear) {
        printf("Queue Underflow! Queue is empty.\n");
    } 
    else {
        printf("Dequeued %d from the queue.\n", queue[front]);
        front++;
        if (front > rear) {
            // Reset queue when it becomes empty
            front = -1;
            rear = -1;
        }
    }
}

void peekQueue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
    } 
    else {
        printf("Front element is %d\n", queue[front]);
    }
}

void displayQueue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
    } 
    else {
        printf("Queue elements (front to rear): ");
        int i = front;
        while (i <= rear) {
            printf("%d ", queue[i]);
            i++;
        }
        printf("\n");
    }
}

/* ================= MAIN PROGRAM ================= */

int main() {
    int choice, val;

    while (1) {
        printf("\n--- Stack and Queue Menu ---\n");
        printf("--- Stack Operations ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("--- Queue Operations ---\n");
        printf("5. Enqueue\n");
        printf("6. Dequeue\n");
        printf("7. Peek\n");
        printf("8. Display\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Exiting.\n");
            break;
        }

        if (choice == 1) {
            printf("Enter value to push: ");
            scanf("%d", &val);
            pushStack(val);
        } 
        else if (choice == 2) {
            popStack();
        } 
        else if (choice == 3) {
            peekStack();
        } 
        else if (choice == 4) {
            displayStack();
        } 
        else if (choice == 5) {
            printf("Enter value to enqueue: ");
            scanf("%d", &val);
            enqueueQueue(val);
        } 
        else if (choice == 6) {
            dequeueQueue();
        } 
        else if (choice == 7) {
            peekQueue();
        } 
        else if (choice == 8) {
            displayQueue();
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