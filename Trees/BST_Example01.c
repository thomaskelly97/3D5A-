#include <stdio.h> 
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>
struct Tree_Node {
    char data; 
    struct Tree_Node *left, *right;     
};

//Function that returns a new node, with input data and null pointers 

void tree_insert (struct Tree_Node **root, char data){ 
    int break1 = 0; 
    if(*root == NULL){ //First node in tree 
        struct Tree_Node * node = (struct Tree_Node *) malloc(sizeof(struct Tree_Node));
        node->left = node->right = NULL; 
        node->data = data;
        *root = node;  
        break1 = 1; 
    } else if(data <= (*root)->data && break1 == 0){
        tree_insert(&(*root)->left, data);
    } else if(data > (*root)->data && break1 == 0){
        tree_insert(&(*root)->right, data);
    }
}

void tree_delete (struct Tree_Node* root){
    if(root != NULL){
        tree_delete(root->left);
        printf("%c,",root->data);
        free(root);
        tree_delete(root->right);
    }
}

struct Tree_Node * tree_search(struct Tree_Node * root, char data){
    if(root == NULL || root->data == data){
        return root; 
    } 
    else if (root->data >= data){ 
        return tree_search(root->left, data);
    } else if(root->data < data){
        return tree_search(root->right,data);
    }
}

void tree_print_sorted(struct Tree_Node* root){
   // while(root != NULL){
   // }
   if(root != NULL){
       tree_print_sorted(root->left);
       printf("%c-", root->data);
       tree_print_sorted(root->right);
   }
}

int main(){
    struct Tree_Node * root_ = NULL; 
    struct Tree_Node * head_root; 
    time_t t; 
    char input_data[29] = {'F','L','O','C','C','I','N','A','U','C','I','N','I','H','I','L','I','P','I','L','I','F','I','C','A','T','I','O','N'};
    char chars[26] = {'A','B', 'C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    char answ;
    char searchChar; 
    struct Tree_Node* found; 
    for(int i=0;i<29;i++){
        tree_insert(&root_, input_data[i]);
        if(i == 0)
            head_root = root_; 
    }

     printf("\nUnsorted Tree:\n"); 
    for(int j =0;j<29;j++){
        printf("%c-",input_data[j]);
    } 
    printf("\nSorted Tree:\n");
    tree_print_sorted(root_);

    //Generate a random number between 1 and 26 
    int rand_ind;
    srand((unsigned) time(&t));
    for(int j = 0; j<2; j++){
        rand_ind = rand() % 26;
        searchChar = chars[rand_ind];
        printf("\nSearching for character %c:\n", searchChar);
        found = tree_search(head_root,searchChar);
        if (found != NULL){
        printf("The charcter %c has been found.\n\n", found->data);
        } else {
            printf("The character %c was not found.\n\n", searchChar);
        }     
    }

    
     
    
    printf("Tree will now be deleted.\n\n");
    printf("Deleting Nodes:\n");
    tree_delete(root_);
    printf("\n\n");
}
