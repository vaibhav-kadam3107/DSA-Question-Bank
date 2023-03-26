// Write a Program to create a Binary Search Tree and perform following
// non recursive operations on it. a. Preorder Traversal b. Postorder
// Traversal c. Display total Number of Nodes d. Display Leaf nodes

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
        printf("\nstack Full\n");
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

struct node *new_node(int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

struct node *Insert(struct node *root, int val)
{
    if (root == NULL)
        root = new_node(val);
    else if (val < root->data)
    {
        root->left = Insert(root->left, val);
    }
    else if (val > root->data)
    {
        root->right = Insert(root->right, val);
    }
    else
    {
        printf("\nThis node already exists");
    }
    return root;
}

void pre_order(struct node *root)
{
    if (root == NULL)
        return;

    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->top = -1;
    s->size = 1000;
    s->arr = (int *)malloc(s->size * sizeof(int));

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

void post_order(struct node *root)
{
    if (root == NULL)
        return;
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->top = -1;
    s->size = 1000;
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

int leaf_node(struct node *root)
{
    if (root == NULL)
        return 0;

    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->top = -1;
    s->size = 1000;
    s->arr = (int *)malloc(sizeof(int) * s->size);
    int count = 0; // Initialize count to 0

    push(s, (int)root);

    while (!Empty(s))
    {
        root = (struct node *)pop(s);
        if (root->right == NULL && root->left == NULL)
            count++;
        else
        {
            if (root->right != NULL)
                push(s, (int)root->right);
            if (root->left != NULL)
                push(s, (int)root->left);
        }
    }

    free(s->arr);
    free(s);
    return count;
}

int total_node(struct node *root)
{
    if (root == NULL)
        return 0;

    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->top = -1;
    s->size = 1000;
    s->arr = (int *)malloc(sizeof(int) * s->size);
    int count = 0;

    push(s, (int)root);

    while (!Empty(s))
    {
        root = (struct node *)pop(s);
        count++;

        if (root->right != NULL)
        {
            push(s, (int)root->right);
        }
        if (root->left != NULL)
        {
            push(s, (int)root->left);
        }
    }

    return count;
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
    printf("\npost order : ");
    post_order(root);

    printf("\npre order : ");
    pre_order(root);

    printf("\nTotal leaf nodes are : %d", leaf_node(root));
    printf("\nTotal nodes are : %d", total_node(root));

    return 0;
}