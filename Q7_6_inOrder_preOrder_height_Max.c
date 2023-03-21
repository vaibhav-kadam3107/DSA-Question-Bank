// Write a Program to create a Binary Tree and perform following
// Non recursive operations on it. a. In order Traversal b. Pre order Traversal
// c. Display Height of a tree d. Find Maximum

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
        printf("\nStack is empty");
    else
    {
        int temp = s->arr[s->top];
        s->top--;
        return temp;
    }
}

struct node *create_node(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->right = temp->left = NULL;
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
    s->size = 100;
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

int height(struct node *root)
{
    if (root == NULL)
        return 0;
    else
    {
        int l_height = height(root->left);
        int r_height = height(root->right);
        return (l_height > r_height) ? l_height+1 : r_height+1;
    }
}

int max(struct node *root)
{
    int max = -1;
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 100;
    s->top = -1;
    s->arr = (int *)malloc(sizeof(int) * s->size);

    while (1)
    {
        while (root != NULL)
        {
            push(s, (int)root);
            root = root->left;
        }
        if (s->top == -1)
            break;

        root = (struct node *)pop(s);

        if (root->data > max)
        {
            max = root->data;
        }
        root = root->right;
    }
    return max;
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

    printf("\nIn order : ");
    in_order(root);

    printf("\npre order : ");
    pre_order(root);

    printf("\nMax node : %d" , max(root));
    

    printf("\nHeight : %d", height(root));
    
    return 0;
}