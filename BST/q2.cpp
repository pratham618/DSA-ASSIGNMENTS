#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

// Create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Insert a node in BST
struct Node* insert(struct Node* root, int value) {
    if (root == NULL)
        return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);
   

    return root;
}



// Recursive search in BST
struct Node* searchRecursive(struct Node* root, int key) {
    if (root == NULL || root->data == key)
        return root;

    if (key < root->data)
        return searchRecursive(root->left, key);
    else
        return searchRecursive(root->right, key);
}

// Non-recursive (iterative) search in BST
struct Node* searchIterative(struct Node* root, int key) {
    while (root != NULL) {
        if (key == root->data)
            return root;
        else if (key < root->data)
            root = root->left;
        else
            root = root->right;
    }
    return NULL; 
}

//  (b) MAXIMUM ELEMENT OF BST 

struct Node* findMax(struct Node* root) {
    if (root == NULL)
        return NULL;

    while (root->right != NULL)
        root = root->right;

    return root;
}

//  (c) MINIMUM ELEMENT OF BST 

struct Node* findMin(struct Node* root) {
    if (root == NULL)
        return NULL;

    while (root->left != NULL)
        root = root->left;

    return root;
}

//  (d) IN-ORDER SUCCESSOR OF A GIVEN NODE
  

struct Node* inorderSuccessor(struct Node* root, int key) {
    struct Node* succ = NULL;
    struct Node* current = root;

    while (current != NULL) {
        if (key < current->data) {
            succ = current;             
            current = current->left;
        } else if (key > current->data) {
            current = current->right;
        } else {
            // Node with key found
            if (current->right != NULL) {
                succ = findMin(current->right);
            }
            break;
        }
    }
    return succ;
}

//  (e) IN-ORDER PREDECESSOR OF A GIVEN NODE
  

struct Node* inorderPredecessor(struct Node* root, int key) {
    struct Node* pred = NULL;
    struct Node* current = root;

    while (current != NULL) {
        if (key > current->data) {
            pred = current;             // this could be predecessor
            current = current->right;
        } else if (key < current->data) {
            current = current->left;
        } else {
            // Node with key found
            if (current->left != NULL) {
                pred = findMax(current->left);
            }
            break;
        }
    }
    return pred;
}

// In-order Traversal (just to see the BST)
void inorder(struct Node* root) {
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    struct Node* root = NULL;

    // Create a sample BST
    // Insert: 50, 30, 70, 20, 40, 60, 80
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("In-order Traversal of BST: ");
    inorder(root);
    printf("\n");

    int key = 60;

    // (a) Search
    struct Node* r = searchRecursive(root, key);
    struct Node* i = searchIterative(root, key);
    printf("Recursive search for %d: %s\n", key, (r ? "Found" : "Not Found"));
    printf("Iterative search for %d: %s\n", key, (i ? "Found" : "Not Found"));

    // (b) Max element
    struct Node* maxNode = findMax(root);
    if (maxNode)
        printf("Maximum element in BST: %d\n", maxNode->data);

    // (c) Min element
    struct Node* minNode = findMin(root);
    if (minNode)
        printf("Minimum element in BST: %d\n", minNode->data);

    // (d) In-order successor
    struct Node* succ = inorderSuccessor(root, key);
    if (succ)
        printf("In-order successor of %d is: %d\n", key, succ->data);
    else
        printf("In-order successor of %d does not exist.\n", key);

    // (e) In-order predecessor
    struct Node* pred = inorderPredecessor(root, key);
    if (pred)
        printf("In-order predecessor of %d is: %d\n", key, pred->data);
    else
        printf("In-order predecessor of %d does not exist.\n", key);

    return 0;
}
