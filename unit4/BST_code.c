#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left,*right;
};

struct node *root = NULL, *n, *temp;

void insert();
void inorder_traversal(struct node *temp);
void preorder_traversal(struct node *temp);
void postorder_traversal(struct node *temp);

int main(){
    int ch;
    printf("0.exit 1.insert 2.inorder traversal 3.preorder traversal 4.postorder traversal\n");
    do{
        printf("choice : ");
        scanf("%d",&ch);
        switch(ch){
            case 1 : insert(); break;
            case 2 : inorder_traversal(root); break;
            case 3 : preorder_traversal(root); break;
            case 4 : postorder_traversal(root); break;
        }
    }while(ch!=0);

    return 0;
}

void insert(){
    n = (struct node*)malloc(sizeof(struct node));
    printf("Enter data : ");
    scanf("%d",&n->data);
    n->left = n->right = NULL;

    if(root == NULL){
        root = n;
    }else{
        temp = root;

        while(temp!=NULL){
            // int LorR;
            // printf("left-1 or right-0 : ");
            // scanf("%d",&LorR);

            // if(LorR == 1){
            //     if(temp->left!=NULL){
            //         temp = temp->left;
            //     }else{
            //         temp->left = n;
            //         break;
            //     }
            // }else if(LorR == 0 ){
            //     if(temp->right!=NULL){
            //         temp=temp->right;
            //     }else{
            //         temp->right = n;
            //         break;
            //     }
            // }
            if(n->data < temp->data){
                if(!temp->left){
                    temp->left = n;
                    return;
                }else{
                    temp = temp->left;
                }
            }else{
                if(!temp->right){
                    temp->right = n;
                    return;
                }else{
                    temp = temp->right;
                }
            }
        }
    }

}

void inorder_traversal(struct node *temp){
    if(temp!=NULL){
        inorder_traversal(temp->left);
        printf("%d ",temp->data);
        inorder_traversal(temp->right);
        
    }
}

void preorder_traversal(struct node *temp){
    if(temp!=NULL){
        printf("%d ",temp->data);
        preorder_traversal(temp->left);
        preorder_traversal(temp->right);
        
    }
}

void postorder_traversal(struct node *temp){
    if(temp!=NULL){
        postorder_traversal(temp->left);
        postorder_traversal(temp->right);
        printf("%d ",temp->data);
    }
}
