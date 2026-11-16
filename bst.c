#include <stdio.h>
#include <stdlib.h>

// Define the structure for a BST node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* createNode(int val) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// 1. Insert an element into the BST
struct Node* insert(struct Node* root, int val) {
    if (root == NULL) {
        return createNode(val);
    }
    
    if (val < root->data) {
        root->left = insert(root->left, val);
    } 
    else if (val > root->data) {
        root->right = insert(root->right, val);
    } 
    else {
        printf("Duplicate value %d not allowed in BST.\n", val);
    }
    return root;
}

// 2. Search an element in the BST
struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    
    if (key < root->data) {
        return search(root->left, key);
    } 
    else {
        return search(root->right, key);
    }
}

// 3. Inorder Traversal (Left, Root, Right)
void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// 4. Preorder Traversal (Root, Left, Right)
void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// 5. Postorder Traversal (Left, Right, Root)
void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

// Helper function to find the minimum value node in a subtree
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current != NULL && current->left != NULL) {
        current = current->left;
    }
    return current;
}

// 6. Delete a node from the BST
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->data) {
        root->left = deleteNode(root->left, key);
    } 
    else if (key > root->data) {
        root->right = deleteNode(root->right, key);
    } 
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } 
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct Node* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    struct Node* root = NULL;
    int choice, val;

    while (1) {
        printf("\n--- Binary Search Tree Menu ---\n");
        printf("1. Insert Node\n");
        printf("2. Search Node\n");
        printf("3. Inorder Traversal\n");
        printf("4. Preorder Traversal\n");
        printf("5. Postorder Traversal\n");
        printf("6. Delete Node\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Exiting.\n");
            break;
        }

        if (choice == 1) {
            printf("Enter value to insert: ");
            scanf("%d", &val);
            root = insert(root, val);
            printf("Inserted %d into the BST.\n", val);
        } 
        else if (choice == 2) {
            printf("Enter value to search: ");
            scanf("%d", &val);
            struct Node* result = search(root, val);
            if (result != NULL) {
                printf("Element %d found in the BST!\n", val);
            } 
            else {
                printf("Element %d not found in the BST.\n", val);
            }
        } 
        else if (choice == 3) {
            if (root == NULL) {
                printf("BST is empty!\n");
            } 
            else {
                printf("Inorder Traversal: ");
                inorder(root);
                printf("\n");
            }
        } 
        else if (choice == 4) {
            if (root == NULL) {
                printf("BST is empty!\n");
            } 
            else {
                printf("Preorder Traversal: ");
                preorder(root);
                printf("\n");
            }
        } 
        else if (choice == 5) {
            if (root == NULL) {
                printf("BST is empty!\n");
            } 
            else {
                printf("Postorder Traversal: ");
                postorder(root);
                printf("\n");
            }
        } 
        else if (choice == 6) {
            printf("Enter value to delete: ");
            scanf("%d", &val);
            struct Node* check = search(root, val);
            if (check == NULL) {
                printf("Element %d not found in BST!\n", val);
            } 
            else {
                root = deleteNode(root, val);
                printf("Deleted %d from the BST.\n", val);
            }
        } 
        else if (choice == 7) {
            printf("Exiting program...\n");
            break;
        } 
        else {
            printf("Invalid choice! Please choose between 1 and 7.\n");
        }
    }
    return 0;
}