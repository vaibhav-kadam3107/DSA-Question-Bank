//Write a Program to create a Binary Tree and perform following
//non recursive operations on it. a. Preorder Traversal b. Postorder
//Traversal c. Count total no. of nodes d. Display height of a tree
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct stack
{
    int size;
    int top;
    int *arr;
};

int Empty(struct stack *s)
{
    if (s->top == -1)
        return 1;
    return 0;
}

int Full(struct stack *s)
{
    if (s->top == s->size - 1)
        return 1;
    return 0;
}

void Push(struct stack *s, int data)
{
    if (Full(s))
        printf("stack is full");
    else
    {
        s->top++;
        s->arr[s->top] = data;
    }
}
int Pop(struct stack *s)
{
    if (Empty(s))
        return -1;
    else
    {
        int val = s->arr[s->top];
        s->top--;
        return val;
    }
}

struct node *create_node(int data)
{
    struct node *s = (struct node *)malloc(sizeof(struct node));
    s->data = data;
    s->right = NULL;
    s->left = NULL;
    return s;
}

void preOrder(struct node *root)
{
    if (root == NULL)
        return;

    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->top = -1;
    s->size = 100;
    s->arr = (int *)malloc(s->size * sizeof(int));

    while (root != NULL)
    {
        printf("%d ", root->data);
        Push(s, (int)root);
        root = root->left;
    }
    while (!Empty(s))
    {
        root = (struct node *)Pop(s);
        root = root->right;
        while (root != NULL)
        {
            printf("%d ", root->data);
            Push(s, (int)root);
            root = root->left;
        }
    }
    free(s->arr);
    free(s);
}

void post_order(struct node * root){
    if(root == NULL)return;

    struct stack* s = (struct stack*)malloc(sizeof(struct stack));
    s->size = 100;
    s->top = -1;
    s->arr = (int*)malloc(sizeof(int) * s->size);
    struct node* prev = NULL;
    
    do
    {
        while(root != NULL){
        Push(s , (int)root);
        root = root->left;
    }
    while(root == NULL && !Empty(s)){
        root = (struct node*) s->arr[s->top];
        if(root->right == NULL || root->right == prev){
            printf("%d " , root->data);
            Pop(s);
            prev = root;
            root = NULL;
        }
        else{
            root = root->right;
        }
    }
    } while (!Empty(s));
    
}

int countNodes(struct node* root) {
    int count = 0;
    struct node* current = root;
    while (current != NULL) {
        if (current->left == NULL) {
            count++;
            current = current->right;
        }
        else {
            struct node* predecessor = current->left;
            while (predecessor->right != NULL && predecessor->right != current) {
                predecessor = predecessor->right;
            }
            if (predecessor->right == NULL) {
                predecessor->right = current;
                current = current->left;
            }
            else {
                predecessor->right = NULL;
                count++;
                current = current->right;
            }
        }
    }
    return count;
}


void In_order(struct node *root){
    if (root == NULL)return ;

    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 100;
    s->top = -1;
    s->arr = (int*)malloc(sizeof(int) * s->size);

    while(root != NULL){
        Push(s , (int)root);
        root = root->left;
    }
    while(!Empty(s)){
        root = (struct node*)Pop(s);
        printf("%d ", root->data);
        root = root->right;

        while(root != NULL){
            Push(s , (int)root);
            root = root->left;
        }
    }
}

int max(int a, int b) {
    return a > b ? a : b;
}

int height(struct node* root) {
    if (root == NULL) {
        return -1;
    }
    else {
        return max(height(root->left), height(root->right)) + 1;
    }
}

int main()
{

    /*
        5
       / \
      3   7
     / \
    2   4

    */

    struct node *root = create_node(5);
    struct node *p1 = create_node(3);
    struct node *p2 = create_node(7);
    struct node *p3 = create_node(2);
    struct node *p4 = create_node(4);

    root->left = p1;
    root->right = p2;
    root->left->left = p3;
    root->left->right = p4;

    printf("\npreorder is : ");
    preOrder(root);

    printf("\npost order is : ");
    post_order(root);

    printf("\nIn_order is : ");
    In_order(root);

    printf("\nTotal count of nodes: %d", countNodes(root));
    printf("\nHeight of the binary tree: %d", height(root));
    return 0;
}