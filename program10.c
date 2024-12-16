#include <stdio.h>
#include <stdlib.h>

// Structure definition for BST node
struct BST {
    int data;
    struct BST *left;
    struct BST *right;
};
typedef struct BST NODE;

// Function to create a new node and insert it in BST
NODE* createtree(NODE *root, int data) {
    if (root == NULL) {
        NODE *temp;
        temp = (NODE*) malloc(sizeof(NODE));
        temp->data = data;
        temp->left = temp->right = NULL;
        return temp;
    }
    if (data < root->data)
        root->left = createtree(root->left, data);
    else if (data > root->data)
        root->right = createtree(root->right, data);
    return root;
}

// Function for inorder traversal (Left->Root->Right)
void inorder(NODE *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d\t", root->data);
        inorder(root->right);
    }
}

// Function for preorder traversal (Root->Left->Right)
void preorder(NODE *root) {
    if (root != NULL) {
        printf("%d\t", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

// Function for postorder traversal (Left->Right->Root)
void postorder(NODE *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d\t", root->data);
    }
}

// Function to search for an element in BST
NODE* search(NODE *root, int data) {
    if (root == NULL) {
        printf("\nElement not found");
        return NULL;
    }
    else if (data < root->data)
        root->left = search(root->left, data);
    else if (data > root->data)
        root->right = search(root->right, data);
    else {
        printf("\nElement found is: %d", root->data);
        return root;
    }
    return root;
}

// Main function
int main() {
    int data, ch, i, n;
    NODE *root = NULL;

    while (1) {
        printf("\n1. Creation of Binary Search Tree");
        printf("\n2. Inorder\n3. Preorder\n4. Postorder\n5. Search\n6. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                printf("\nEnter N value: ");
                scanf("%d", &n);
                printf("\nEnter the values to create BST: ");
                for(i=0; i<n; i++) {
                    scanf("%d", &data);
                    root = createtree(root, data);
                }
                break;

            case 2:
                printf("\nInorder Traversal:\n");
                inorder(root);
                break;
            case 3:
                printf("\nPreorder Traversal:\n");
                preorder(root);
                break;
            case 4:
                printf("\nPostorder Traversal:\n");
                postorder(root);
                break;
            case 5:
                printf("\nEnter the element to Search: ");
                scanf("%d", &data);
                root = search(root, data);
                break;
            case 6:
                exit(0);
            default:
                printf("\nWrong Option");
                break;
        }
    }
    return 0;
}
