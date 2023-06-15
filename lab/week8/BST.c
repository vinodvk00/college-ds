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
//functions without recursion
struct node *inorder_nonRecursive(struct node *temp);
struct node *preorder_nonRecursive(struct node *temp);
struct node *postorder_nonRecursive(struct node *temp);
struct node *search_nonRecursive(struct node *root, int key);
struct node *deletenode_nonRecursive(struct node *root, int key);

int key;

int main(){
    int ch;
    struct node *res;
    printf("1.create 2.inorder 3.search 4.delete 5.preorder_nonR 6.postorder_nonR 7.search_nonR 8.delete_nonR\n");

    do{
        printf("\nEnter your choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1: create(); break;
            case 2: inorder(root); break;
            case 3: 
                printf("Enter key to search : ");
                scanf("%d",&key);
                res = search(root,key);
                if(res == NULL){
                    printf("Element not found\n");
                }else{
                    printf("Element found\n");
                }
                break;
            case 4:
                printf("Enter key to delete : ");
                scanf("%d",&key);
                res = deletenode(root,key);
                inorder(root);
                break;
            case 5: preorder_nonRecursive(root); break;
            case 6: postorder_nonRecursive(root); break;
            case 7: 
                printf("Enter key : ");
                scanf("%d",&key);
                res = search_nonRecursive(root,key);
                if(res == NULL){
                    printf("Element not found\n");
                }else{
                    printf("Element found\n");
                }
                break;
            case 8:
                printf("Enter key : ");
                scanf("%d",&key);
                res = deletenode_nonRecursive(root,key);
                inorder_nonRecursive(root);
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
    if(key < root->data){
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

// inorder traversal without using recursion
struct node *inorder_nonRecursive(struct node *temp){
    struct node *stack[100];
    int top = -1;
    while(1){
        while(temp!=NULL){
            stack[++top] = temp;
            temp = temp->left;
        }
        if(top>=0){
            temp = stack[top--];
            printf("%d\t",temp->data);
            temp = temp->right;
        }else{
            break;
        }
    }
}

// preorder traversal without using recursion
struct node *preorder_nonRecursive(struct node *temp){
    struct node *stack[100];
    int top = -1;
    while(1){
        while(temp!=NULL){
            printf("%d\t",temp->data);
            stack[++top] = temp;
            temp = temp->left;
        }
        if(top>=0){
            temp = stack[top--];
            temp = temp->right;
        }else{
            break;
        }
    }
}

// postorder traversal without using recursion
struct node *postorder_nonRecursive(struct node *temp){
    struct node *stack[100];
    int top = -1;
    struct node *prev = NULL;
    do{
        while(temp!=NULL){
            stack[++top] = temp;
            temp = temp->left;
        }
        while(temp == NULL && top>=0){
            temp = stack[top];
            if(temp->right == NULL || temp->right == prev){
                printf("%d\t",temp->data);
                top--;
                prev = temp;
                temp = NULL;
            }else{
                temp = temp->right;
            }
        }
    }while(top>=0);
}

// search without using recursion
struct node *search_nonRecursive(struct node *root, int key){
    while(root!=NULL){
        if(key == root->data){
            return root;
        }else if(key < root->data){
            root = root->left;
        }else{
            root = root->right;
        }
    }
    return NULL;
}

// delete without using recursion
struct node *deletenode_nonRecursive(struct node *root, int key){
    struct node *parent = NULL;
    struct node *current = root;
    while(current!=NULL){
        if(key == current->data){
            break;
        }else if(key < current->data){
            parent = current;
            current = current->left;
        }else{
            parent = current;
            current = current->right;
        }
    }
    if(current == NULL){
        return root;
    }
    if(current->left == NULL && current->right == NULL){
        if(current != root){
            if(parent->left == current){
                parent->left = NULL;
            }else{
                parent->right = NULL;
            }
        }else{
            root = NULL;
        }
        free(current);
    }else if(current->left == NULL){
        if(current != root){
            if(parent->left == current){
                parent->left = current->right;
            }else{
                parent->right = current->right;
            }
        }else{
            root = current->right;
        }
        free(current);
    }else if(current->right == NULL){
        if(current != root){
            if(parent->left == current){
                parent->left = current->left;
            }else{
                parent->right = current->left;
            }
        }else{
            root = current->left;
        }
        free(current);
    }else{
        struct node *successor = current->right;
        while(successor->left != NULL){
            successor = successor->left;
        }
        int val = successor->data;
        deletenode_nonRecursive(root,successor->data);
        current->data = val;
    }
    return root;
}
