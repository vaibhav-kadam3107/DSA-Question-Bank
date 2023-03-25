// Write a Program to create a Binary Search Tree and perform following
// non recursive operations on it. a. Preorder Traversal b. In order Traversal
// c. Display Number of Leaf Nodes d. Mirror Image

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
    int top;
    int size;
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

void push(struct stack *s, int data)
{
    if (Full(s))
        printf("\nStack is full\n");
    else
    {
        s->top++;
        s->arr[s->top] = data;
    }
}

int pop(struct stack *s)
{
    if (Empty(s))
        printf("\nStack is empty\n");
    else
    {
        int val = s->arr[s->top];
        s->top--;
        return val;
    }
}

struct node *new_node(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}


struct node* Insert(struct node* root, int val)
{
    if (root == NULL)
        return new_node(val);
    
    if (val < root->data)
        root->left = Insert(root->left, val);
    else if (val > root->data)
        root->right = Insert(root->right, val);

    return root;
}


void pre_order(struct node *root)
{
    if (root == NULL)
        return;

    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 100;
    s->top = -1;
    s->arr = (int *)malloc(sizeof(int) * s->size);

    while (root != NULL)
    {
        printf("%d ", root->data);
        push(s, (int)root);
        root = root->left;
    }

    while (!Empty(s))
    {
        root = (struct node *)pop(s);
        root = root->right;
        while (root != NULL)
        {
            printf("%d ", root->data);
            push(s, (int)root);
            root = root->left;
        }
    }
}

void in_order(struct node *root)
{
    if (root == NULL)
        return;

    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 100;
    s->top = -1;
    s->arr = (int *)malloc(sizeof(int) * s->size);

    while (root != NULL)
    {
        push(s, (int)root);
        root = root->left;
    }

    while (!Empty(s))
    {
        root = (struct node *)pop(s);
        printf("%d ", root->data);
        root = root->right;
        while (root != NULL)
        {
            push(s, (int)root);
            root = root->left;
        }
    }
}

void swap(struct node *root)
{
    struct node *temp = root->left;
    root->left = root->right;
    root->right = temp;
}

void mirror(struct node *root)
{
    if (root == NULL)
        return;

    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->top = -1;
    s->size = 100;
    s->arr = (int *)malloc(sizeof(int) * s->size);

    push(s, (int)root);

    while (!Empty(s))
    {
        root = (struct node *)pop(s);
        swap(root);
        if (root->left != NULL)
            push(s, (int)root->left);
        if (root->right != NULL)
            push(s, (int)root->right);
    }
}

void leaf_node(struct node *root) {
    if (root == NULL)
        return;

    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->top = -1;
    s->size = 100;
    s->arr = (int *)malloc(sizeof(int) * s->size);

    push(s, (int)root);

    while (!Empty(s)) {
        root = (struct node *)pop(s);

        if (root->left == NULL && root->right == NULL) {
            printf("%d ", root->data);
        } else {
            if (root->left != NULL)
                push(s, (int)root->left);

            if (root->right != NULL)
                push(s, (int)root->right);
        }
    }
    free(s->arr);
    free(s);
}


int main()
{
    struct node *root = NULL;
    root = Insert(root, 50);
    root = Insert(root, 20);
    root = Insert(root, 30);
    root = Insert(root, 80);
    root = Insert(root, 10);
    /*
        50
       / \
      20   80
     / \
    10  30

    */
    printf("\nIn order : ");
    in_order(root);

    printf("\npre order : ");
    pre_order(root);

    /*
        50
       / \
      80   20
          / \
        30  10

    */

    mirror(root);
    printf("\nIn order after non recursive mirror image: ");
    in_order(root);

    printf("\nLeaf nodes: ");
    leaf_node(root);
    return 0;
}