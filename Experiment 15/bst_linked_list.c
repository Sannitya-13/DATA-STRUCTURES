#include<stdio.h>
#include <stdlib.h>
struct Node{
    struct Node* left_child;
    struct Node* right_child;
    int data;
 };
struct Node* search(struct Node*,int);
struct Node* insert(struct Node*,int);
struct Node* delete(struct Node*,int);
void inorder(struct Node*);
void preorder(struct Node*);
void postorder(struct Node*);
struct Node* find_min(struct Node*);
struct Node* new_node(int);
int main(){
    int choice,want_continue,x,data,temp,key;
    printf("enter choice 1.search 2.insert 3.delete 4.inorder 5.preorder 6.postorder \n");
    struct Node *root=NULL,*r;
    do
      {
           printf("enter choice\n");
           scanf("%d",&choice);
           switch(choice){
                 case 1:
                        printf("enter the key \n");
                        scanf("%d",&key);
                        r=search(root,key);
                        if(r!=NULL)
                            printf("Successfull\n");
                        else
                            printf("not found\n");
                        break;
                 case 2:
                        printf("enter the value\n");
                        scanf("%d",&data);
                        root=insert(root,data);
                        break;

                 case 3:printf("enter the value to delete\n");
                        scanf("%d",&data);
                        root=delete(root,data);
                        break;                       
                 case 4:inorder(root);
                        break;
                 case 5:preorder(root);
                        break;
                 case 6:postorder(root);
         }
         printf("want to continue,enter 1 \n");
         scanf("%d",&want_continue);
       }
        while(want_continue==1);
        return 0;

 }
struct Node* search(struct Node* root,int x){
     if(root==NULL||root->data==x)
         return root;
     else if(x<root->data)
         return search(root->left_child,x); 
     else 
         return search(root->right_child,x); 
}

struct Node* insert(struct Node* root,int x){ 
     if(root==NULL)
         return new_node(x);
     else if(x>(root->data))
         root->right_child=insert(root->right_child,x);
     else 
         root->left_child=insert(root->left_child,x);
     return root;
 }
  
struct Node* new_node(int x){
    struct Node *p;
    p=malloc(sizeof(struct Node));
    p->data=x;
    p->left_child=NULL;
    p->right_child=NULL;
    return p;
 }


struct Node* delete(struct Node* root, int x){
    if(root==NULL)
        return NULL;
    if(x>root->data)
        root->right_child=delete(root->right_child,x);
    else if(x<root->data)
        root->left_child=delete(root->left_child,x);
    else{
        if(root->left_child==NULL&&root->right_child==NULL){
            free(root);
            return NULL;
          }
        else if(root->left_child==NULL||root->right_child==NULL){
            struct Node *temp;
            if(root->left_child==NULL)
                temp=root->right_child;
            else
                temp=root->left_child;
            free(root);
            return temp;
       }
        else{
            struct Node *temp = find_min(root->right_child);
            root->data=temp->data;
            root->right_child=delete(root->right_child,temp->data);
          }
     }
            return root;
}
struct Node* find_min(struct Node* root){
    if(root==NULL)
        return NULL;
    else if(root->left_child!= NULL) 
         return find_min(root->left_child);
    return root; 
}

void inorder(struct Node* root){
    if(root==NULL)
        return;
    inorder(root->left_child);
    printf("%d ",root->data);
    inorder(root->right_child);
    
}

void preorder(struct Node* root){
    if(root==NULL)
        return;
    printf("%d ",root->data);
    preorder(root->left_child);       
    preorder(root->right_child);

}

void postorder(struct Node* root){
    if(root==NULL)
        return;       
    postorder(root->left_child);       
    postorder(root->right_child);
    printf("%d ",root->data);
       
}

