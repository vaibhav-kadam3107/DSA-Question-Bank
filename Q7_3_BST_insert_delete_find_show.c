//Write a program to illustrate operations on a BST holding numeric keys.
//The menu must include: • Insert • Delete • Find • Show
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* create_node(int data){
    struct node * temp = (struct node* )malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct node * insert(struct node* root , int data){
    if(root == NULL)
        root = create_node(data);
    else if (data <= root->data)
    {
        root->left = insert(root->left , data);
    }
    else{
        root->right = insert(root->right , data);
    }
    return root;
}

void in_order(struct node *root){
    if(root==NULL)return;

    in_order(root->left);
    printf("%d ", root->data);
    in_order(root->right);
}

struct node* inOrderPre(struct node* root){
    //root chya left cha rightmost part
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

struct node* delete(struct node *root , int val){
    if(root == NULL)return NULL;
    if(root->left == NULL && root->right == NULL){
        free(root);
        return NULL;
    }
    struct node* iPri;
    //find the element
    if(val < root->data)
        root->left = delete(root->left , val);
    else if (val > root->data)
    {
        root->right = delete(root->right , val);
    }
    else{
        iPri = inOrderPre(root);
        root->data = iPri->data;
        root->left = delete(root->left , iPri->data);
    }
    return root;
}

int find(struct node* root , int val){
    if(root == NULL)return 0;

    if(val == root->data){
        //printf("\nfound : %d" , root->data);
        return 1;
    }
    

    if (val < root->data)
    {
        find(root->left , val);
    }
    else{
        find(root->right , val);
    }
    
    
}

int main(){

    struct node* root = NULL;
    root = insert(root , 50);
    root = insert(root , 20);
    root = insert(root , 30);
    root = insert(root , 80);
    root = insert(root , 10);
    printf("\nIn order of the BST : ");
    in_order(root);

    delete(root , 30);
    printf("\nIn order of the BST after deletion : ");
    in_order(root);

    printf("\nelement found : %d" , find(root , 30));
   

    return 0;
}