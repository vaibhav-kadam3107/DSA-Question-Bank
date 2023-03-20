// Write a program to illustrate operations on a BST holding numeric keys.
// The menu must include: • Insert • Mirror Image • Find • Post order (non recursive)

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
    if (s->top = s->size - 1)
        return 1;
    return 0;
}

void push(struct stack *s, int data)
{
    if (Full(s))
        printf("\nstack is full");
    else
    {
        s->top++;
        s->arr[s->top] = data;
    }
}

int pop(struct stack *s)
{
    if (Empty(s))
        printf("\nstack is empty");
    else
    {
        int val = s->arr[s->top];
        s->top--;
        return val;
    }
}

struct node *create_node(struct node *root, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

struct node *insert(struct node *root, int val)
{
    if (root == NULL)
    {
        root = create_node(root, val);
    }
    else if (val < root->data)
    {
        root->left = insert(root->left, val);
    }
    else
    {
        root->right = insert(root->right, val);
    }
    return root;
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
    {
        return;
    }

    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 800;
    s->top = -1;
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

int find(struct node *root, int val)
{
    if (root == NULL)
        return 0;

    if (root->data == val)
        return 1;
    else if (val < root->data)
    {
        find(root->left, val);
    }
    else
    {
        find(root->right, val);
    }
}

void post_order(struct node *root)
{
    if (root == NULL)
        return;

    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 800;
    s->top = -1;
    s->arr = (int *)malloc(sizeof(int) * s->size);
    struct node *prev = NULL;
    do
    {
        while (root != NULL)
        {
            push(s, (int)root);
            root = root->left;
        }
        while (root == NULL && !Empty(s))
        {
            root = (struct node *)s->arr[s->top];
            if (root->right == NULL || root->right == prev)
            {
                printf("%d ", root->data);
                pop(s);
                prev = root;
                root = NULL;
            }
            else
            {
                root = root->right;
            }
        }
    } while (!Empty(s));
}

void in_order(struct node *root)
{
    if (root == NULL)
        return;

    in_order(root->left);
    printf("%d ", root->data);
    in_order(root->right);
}

int main()
{
    struct node *root = NULL;
    root = insert(root, 50);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 80);
    root = insert(root, 10);
    /*
        50
       / \
      20   80
     / \
    10  30

    */
    printf("\nIn order of the BST : ");
    in_order(root);
    printf("\nElement 30 found : %d", find(root, 30));
    printf("\npost order : ");
    post_order(root);
    return 0;
}