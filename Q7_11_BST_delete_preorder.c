//Write a Program to create a Binary Search Tree and perform deletion of
//a node from it. Also display the tree in non recursive postorder way.

#include <stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * left;
    struct node * right;
};

struct stack
{
    int top;
    int size;
    int *arr;
};

int Empty(struct stack *s ){
    if(s->top == -1)
        return 1;
    return 0;
}

int Full(struct stack *s ){
    if(s->top == s->size -1)
        return 1;
    return 0;
}

void push(struct stack * s , int val){
    if(Full(s))
        printf("\nstack is full\n");
    else{
        s->top++;
        s->arr[s->top] = val;
    }
}

int pop(struct stack *s){
    if(Empty(s))
        printf("\nstack is empty");
    else{
        int val = s->arr[s->top];
        s->top--;
        return val;
    }
}

struct node * new_node(int data){
    struct node * temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

struct node * insert(struct node * root , int val){
    if(root == NULL)
        root = new_node(val);
    
    if(val < root->data)
        root->left = insert(root->left, val);
    else if (val > root->data)
    {
        root->right = insert(root->right, val);
    }
    return root;
}

struct node * inOrder_pre(struct node * root){
    // root chya left cha right most node
    root = root->left;
    while(root->right != NULL)
        root = root->right;
    return root;
}

struct node * delete(struct node * root , int val){
    if(root == NULL)return NULL;

    struct node * iPri;
    
    // if the deleting element is a leaf node
    if(root->left == NULL && root->right == NULL){
        free(root);
        return NULL;
    }

    //now find the element for deleting
    if(val < root->data)
        root->left = delete(root->left , val);
    else if (val > root->data)
    {
        root->right = delete(root->right , val);
    }
    else{
        iPri = inOrder_pre(root);
        root->data = iPri->data;
        root->left = delete(root->left , iPri->data);
    }
    return root;
    
}

void post_order(struct node *root){
    if(root == NULL)return;

    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 100;
    s->top = -1;
    s->arr = (int *)malloc(sizeof(int) * s->size);
    struct node * prev = NULL;

    do
    {
        
        while(root != NULL){
            push(s , (int)root);
            root =root->left;
        }

        while(root == NULL && !Empty(s)){
            root = (struct node *)s->arr[s->top];
            if (root->right == NULL || root->right == prev)
            {
                printf("%d ", root->data);
                pop(s);
                prev = root;
                root = NULL;
            }
            else{
                root = root->right;
            }
        }


    } while (!Empty(s));
    
}

int main(){
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
    /*
    if(delete(root , 20) == NULL)
        printf("\nElement not fount");
    else{
        printf("\ndeleted element : %d" , delete(root , 20));
    } */

    printf("\nPost order of the BST : ");
    post_order(root);


    delete(root , 50);

    printf("\ndeleted element : 50");
    //printf("\ndeleted element : %d" , delete(root , 20));

    printf("\nPost order after of the BST : ");
    post_order(root);

    return 0;
}