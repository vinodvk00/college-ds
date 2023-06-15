//BST operations using c 

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *n,*temp,*root = NULL;

void create();
void inorder(struct node *temp);
struct node *search(struct node *root, int key);
struct node *deletenode(struct node *root,int key);
struct node *minvaluenode(struct node *node);

int key;

int main(){
    int ch;
    struct node *res;
    printf("1.create 2.inorder 3.search 4.delete\n");

    do{
        printf("\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1: create(); break;
            case 2: inorder(root); break;
            case 3: 
                printf("Enter key : ");
                scanf("%d",&key);
                res = search(root,key);
                if(res == NULL){
                    printf("Element not found\n");
                }else{
                    printf("Element found\n");
                }
                break;
            case 4:
                printf("Enter key : ");
                scanf("%d",&key);
                res = deletenode(root,key);
                inorder(root);
                break;
        }
    }while(ch!=0);

    return 0;
}

void create(){
    n = (struct node *)malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d",&n->data);
    n->left = NULL;
    n->right = NULL;
    if(root == NULL){
        root = n;
    }else{
        temp = root;
        while(temp!=NULL){
            if(n->data < temp->data){
                if(temp->left == NULL){
                    temp->left = n;
                    break;
                }else{
                    temp = temp->left;
                }
            }else{
                if(temp->right == NULL){
                    temp->right = n;
                    break;
                }else{
                    temp = temp->right;
                }
            }
        }
    }
}

void inorder(struct node *temp){
    if(temp != NULL){
        inorder(temp->left);
        printf("%d\t",temp->data);
        inorder(temp->right);
    }
}

struct node *search(struct node *root, int key){
    if(root == NULL || root->data == key){
        return root;
    }

    if(key > root->data){
        return search(root->right,key);
    }

    return search(root->left,key);
}

struct node *deletenode(struct node *root, int key){
    if(root == NULL){
        return root;
    }
    if(key<root->data){
        root->left = deletenode(root->left,key);
    }else if(key > root->data){
        root->right = deletenode(root->right, key);
    }else{
        if(root->left == NULL && root->right == NULL){
            return NULL;
        }else if(root->left == NULL){
            struct node *temp = root->right;
            free(root);
            return temp;
        }else if(root->right == NULL){
            struct node *temp = root->left;
            free(root);
            return temp;
        }
        struct node *temp = minvaluenode(root->right);
        root->data = temp->data;
        root->right = deletenode(root->right,temp->data);
    }
    return root;
}

struct node *minvaluenode(struct node *node){
    struct node *current = node;
    while(current && current->left!= NULL){
        current = current->left;
    }
    return current;
}
