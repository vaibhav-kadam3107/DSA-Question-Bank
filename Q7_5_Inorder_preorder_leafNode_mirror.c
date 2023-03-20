// Write a Program to create a Binary Tree and perform following
// Non recursive operations on it. a. In order Traversal b. Preorder Traversal
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

void push(struct stack *s, int data)
{
    if (Full(s))
        printf("\nStack is full");
    else
    {
        s->top++;
        s->arr[s->top] = data;
    }
}

int pop(struct stack *s)
{
    if (Empty(s))
        printf("\nStack is empty");
    else
    {
        int val = s->arr[s->top];
        s->top--;
        return val;
    }
}

struct node *create_node(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void in_order(struct node *root)
{
    if (root == NULL)
        return;

    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->top = -1;
    s->size = 100;
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

void pre_order(struct node *root)
{
    if (root == NULL)
        return;

    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->top = -1;
    s->size = 400;
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
    free(s->arr);
    free(s);
}

void leafNode(struct node *root)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        printf("%d ", root->data);
    }
    else
    {
        leafNode(root->left);
        leafNode(root->right);
    }
}

void swap(struct node *root)
{
    struct node *temp = root->left;
    root->left = root->right;
    root->right = temp;
}

void mirror_image(struct node *root)
{
    if (root == NULL)
        return;

    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 500;
    s->top = -1;
    s->arr = (int *)malloc(sizeof(int) * s->size);

    push(s, (int)root);
    while (!Empty(s))
    {
        root = (struct node *)pop(s);
        swap(root);
        if (root->left != NULL)
        {
            push(s, (int)root->left);
        }
        if (root->right != NULL)
        {
            push(s, (int)root->right);
        }
    }
}

int main()
{
    struct node *root = create_node(5);
    struct node *p1 = create_node(4);
    struct node *p2 = create_node(6);
    struct node *p3 = create_node(2);
    struct node *p4 = create_node(1);
    root->left = p1;
    root->right = p2;
    root->left->left = p3;
    root->left->right = p4;
    /*
        5
       / \
      4   6
     / \
    2   1

    */
    printf("\nIn order before mirror image: ");
    in_order(root);

    printf("\npre order before mirror image: ");
    pre_order(root);

    printf("\nLeaf nodes are : ");
    leafNode(root);

    // Print the original tree
    printf("\nOriginal binary tree:\n");
    printf("     %d\n", root->data);
    printf("   /   \\\n");
    printf("  %d     %d\n", root->left->data, root->right->data);
    printf(" /  \\ \n");
    printf("%d    %d\n", p3->data, p4->data);
    mirror_image(root);
    printf("\nIn order after non recursive mirror image: \n");
    in_order(root);
    return 0;
}