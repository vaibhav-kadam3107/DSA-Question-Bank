//Write a Program to create a Binary Search Tree and display it levelwise.
//Also perform deletion of a node from it.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node * left;
    struct node * right;
};

struct node * new_node(int data){
    struct node * new = (struct node*)malloc(sizeof(struct node));
    new->data = data;
    new->left = new->right = NULL;
    return new;
}

struct node * insert(struct node * root, int val){
    if(root == NULL)
        root = new_node(val);
    if(val < root->data)
        root->left = insert(root->left, val);
    else if (val >root->data)
    {
        root->right = insert(root->right, val);
    }
    return root;
    
}

struct node * inOrder_pre(struct node * root){
    root = root->left;
    while(root->right != NULL)
        root = root->right;
    return root;
}

struct node* delete(struct node * root , int val){
    if(root == NULL) return NULL;

    struct node * iPri;

    if(root->left == NULL && root->right == NULL){
        free(root);
        return NULL;
    }
    if(val < root->data)
        root->left = delete(root->left, val);
    else if (val > root->data)
    {
        root->right = delete(root->right, val);
    }
    else{
        iPri = inOrder_pre(root);
        root->data = iPri->data;
        root->left = delete(root->left, iPri->data);
    }
    
}


void level_wise_display(struct node * root , int level){
    if(root == NULL)return;

    if(level == 1)
        printf("%d " , root->data);
    else{
        level_wise_display(root->left , level-1);
        level_wise_display(root->right , level-1);
    }
}

int getHeight(struct node* root){
    if(root == NULL)return 0;
    else{
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        return (leftHeight > rightHeight) ? leftHeight+1 : rightHeight+1;
    }
}

void get_level(struct node * root){
    int height = getHeight(root);
    for (int i = 1; i <= height; i++)
    {
        printf("\nLevel %d : " , i);
        level_wise_display(root , i);
    }
    
}

void in_order(struct node *root){
    if(root==NULL)return;

    in_order(root->left);
    printf("%d ", root->data);
    in_order(root->right);
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

    // Print the original tree
    printf("Original binary tree:\n");
    printf("     %d\n", root->data);
    printf("   /   \\\n");
    printf("  %d     %d\n", root->left->data, root->right->data);
    printf(" /  \\ \n");
    printf("%d    %d\n", root->left->left->data, root->left->right->data);

    printf("\nIn order of the BST : ");
    in_order(root);

    delete(root , 30);
    printf("\nIn order of the BST after deletion : ");
    in_order(root);

    printf("\nLevel wise display : \n");
    get_level(root);


    return 0;
}