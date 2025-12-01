#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Pre-order Traversal (Root → Left → Right)
void preorder(struct Node* root) {
    if (root == NULL)
        return;
    
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}

// In-order Traversal (Left → Root → Right)
void inorder(struct Node* root) {
    if (root == NULL)
        return;

    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

// Post-order Traversal (Left → Right → Root)
void postorder(struct Node* root) {
    if (root == NULL)
        return;

    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}


int main() {
  
    
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);

    printf("Pre-order Traversal: ");
    preorder(root);

    printf("\nIn-order Traversal: ");
    inorder(root);

    printf("\nPost-order Traversal: ");
    postorder(root);

    return 0;
}
