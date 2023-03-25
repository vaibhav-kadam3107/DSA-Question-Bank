// You have to maintain information for a shop owner. For each of the
// products sold in his/hers shop the following information is kept: a
// unique code, a name, a price, amount in stock, date received, expiration
// date. For keeping track of its stock, the clerk would use a computer
// program based on a search tree data structure. Write a program to help
// this person, by implementing the following operations: • Insert an item
// with all its associated data. • Find an item by its code, and support
// updating of the item found. • List valid items in lexicographic order of
// their names.

#include <stdio.h>
#include <stdlib.h>

struct product
{
    int code;
    char name[50];
    float price;
    int stock;
    int expiration_data;
    int date_received;
};

struct node
{
    struct product *product;
    struct node *left;
    struct node *right;
};

struct node *new_node(struct product *product)
{
    struct node *node = malloc(sizeof(struct node));
    node->product = product;
    node->left = node->right = NULL;
    return node;
}

struct node *Insert(struct node *root, struct product *product)
{
    if (root == NULL)
    {
        root = new_node(product);
    }
    else if (product->code < root->product->code)
    {
        root->left = Insert(root->left, product);
    }
    else if (product->code > root->product->code)
    {
        root->right = Insert(root->right, product);
    }
    else
    {
        printf("\nProduct with %d this code already exists\n", product->code);
    }
    return root;
}

struct product *Find(struct node *root, int code)
{
    if (root == NULL)
        return NULL;

    if (code == root->product->code)
    {
        return root->product;
    }
    else if (code < root->product->code)
    {
        return Find(root->left, code);
    }
    else
    {
        return Find(root->right, code);
    }
}

void List_valid_items(struct node *root)
{
    if (root != NULL)
    {
        List_valid_items(root->left);
        printf("\n------------\n");
        if (root->product->expiration_data >= root->product->date_received)
        {
            printf("Code: %d \nName: %s \nPrice: %.2f \nStock: %d \nDate Received: %d \nExpiration Date: %d\n",
                   root->product->code, root->product->name, root->product->price, root->product->stock,
                   root->product->date_received, root->product->expiration_data);
        }
        printf("\n------------\n");
        List_valid_items(root->right);
    }
}

int main()
{
    struct node *root = NULL;
    while (1)
    {
        struct product *product = (struct product *)malloc(sizeof(struct product));
        int ch;
        printf("\n1. Insert new product. \n2. Find the item. \n3. List valid items in lexicographic order. \n4. Exit");
        printf("\nEnter the choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            printf("\nEnter the product code: ");
            scanf("%d", &product->code);
            printf("Enter the product name: ");
            scanf("%s", product->name);
            printf("Enter the product price: ");
            scanf("%f", &product->price);
            printf("Enter the product stock: ");
            scanf("%d", &product->stock);
            printf("Enter the product expiration date: ");
            scanf("%d", &product->expiration_data);
            printf("Enter the product date received: ");
            scanf("%d", &product->date_received);
            root = Insert(root, product);
            break;
        }

        case 2:
        {
            int ch2;
            printf("\nEnter the product code you want to find: ");
            scanf("%d", &ch2);

            struct product *found_product = Find(root, ch2);
            if (found_product == NULL)
                printf("\nProduct not found with code %d", ch2);
            else
            {
                printf("\nFound products with code %d", ch2);
                printf("\nProduct name: %s", found_product->name);
                printf("\nProduct price : %f", found_product->price);
                printf("\nProduct expiration_data : %d", found_product->expiration_data);
                printf("\nProduct stock : %d", found_product->stock);
                printf("\nProduct date_received : %d", found_product->date_received);
            }
            int a;
            printf("\nDo you want to update this product 1/0 : ");
            scanf("%d", &a);

            if (a == 1)
            {
                printf("\nEnter updated product name: ");
                scanf("%s", &found_product->name);
                printf("Enter updated product price: ");
                scanf("%f", &found_product->price);
                printf("Enter updated product stock: ");
                scanf("%d", &found_product->stock);
                printf("Enter updated product expiration_data: ");
                scanf("%d", &found_product->expiration_data);
                printf("Enter updated product date_received: ");
                scanf("%d", &found_product->date_received);

                printf("\nProduct details updated\n");
            }

            break;
        }

        case 3:
            printf("\nValid items in lexicographic order of their names:\n");
            List_valid_items(root);
            break;

        case 4:
            printf("Exiting program.\n");
            return 0;

        default:
            printf("Unknown choice");
            break;
        }
    }

    return 0;
}