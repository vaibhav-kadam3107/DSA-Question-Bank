// Write a Program to create a Binary Tree and perform following
// non recursive operations on it. a. Level wise display b. Mirror image c.
// Display height of a tree.

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
        printf("stack is full\n");
    else
    {
        s->top++;
        s->arr[s->top] = data;
    }
}

int pop(struct stack *s)
{
    if (Empty(s))
        printf("stack is empty\n");
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
    temp->left = NULL;
    temp->right = NULL;
    return temp;
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

/*
void mirror_image(struct node *root)
{
    if (root == NULL)
        return;
    else
    {

        mirror_image(root->left);
        mirror_image(root->right);

        struct node *temp = root->left;
        root->left = root->right;
        root->right = temp;
    }
}
*/

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
    s->size = 100;
    s->top = -1;
    s->arr = (int *)malloc(sizeof(int) * s->size);
    struct node * prev = NULL;

    push(s , (int)root);

    while(!Empty(s)){
        root = (struct node*)pop(s);
        swap(root);
        if(root->left != NULL){
            push(s , (int)root->left);
        }
        if(root->right != NULL){
            push(s , (int)root->right);
        }
    }
}

int getHeight(struct node* root) {
    if (root == NULL) {
        return 0;
    } else {
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        return (leftHeight > rightHeight) ? leftHeight+1 : rightHeight+1;
    }
}

void printNodesAtLevel(struct node* root, int level) {
    if (root == NULL) {
        return;
    }
    if (level == 1) {
        printf("%d ", root->data);
    } else if (level > 1) {
        printNodesAtLevel(root->left, level-1);
        printNodesAtLevel(root->right, level-1);
    }
}

// Function to print the nodes of the binary tree level-wise
void printLevelOrder(struct node* root) {
    int height = getHeight(root);
    for (int i = 1; i <= height; i++) {
        printf("\nLevel %d: ", i);
        printNodesAtLevel(root, i);
        printf("\n");
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

    // Print the original tree
    printf("Original binary tree:\n");
    printf("     %d\n", root->data);
    printf("   /   \\\n");
    printf("  %d     %d\n", root->left->data, root->right->data);
    printf(" /  \\ \n");
    printf("%d    %d\n", p3->data, p4->data);


    //mirror_image(root);

    //printf("\nIn order after mirror image: ");
    //in_order(root);
    /*
         5
        / \
       6   4
         / \
        1   2

     */
    mirror(root);
    printf("\nIn order after non recursive mirror image: \n");
    in_order(root);

    printLevelOrder(root);

    // Print the mirrored tree
    return 0;
}