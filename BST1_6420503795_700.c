#include <stdio.h>
#include <stdlib.h>

struct Treenode{
    int data;
    struct Treenode *leftChild;
    struct Treenode *rightChild;
};

struct Treenode *Root;

struct Treenode* createNode(int data){
    struct Treenode *new_node;
    new_node = (struct Treenode*)malloc(sizeof(struct Treenode));
    new_node->data = data;
    new_node->leftChild = NULL;
    new_node->rightChild = NULL;
    return new_node;

    if(Root = NULL){
        Root = new_node;
    }
}

void InOrder(struct Treenode* r){
    if(r != NULL){
        InOrder(r->leftChild);
        printf("%d ",r->data);
        InOrder(r->rightChild);
    }
    return r;
}

void Tree_Insert(int data){
    struct Treenode *y = NULL;
    struct Treenode *t = Root;
    struct Treenode *x = createNode(data);

    while(t != NULL){
        y = t;
        if(data < t->data){
            t = t->leftChild;
        }
        else{
            t = t->rightChild;
        }
        if(y = NULL){
            Root = x;
        }
        else{
            if(x->data < y->data){
                y->leftChild = x;
            }
            else{
                y->rightChild = x;
            }
        }
    }
}

int main(){
    int i,n=20;
    srand((unsigned) time(NULL)); //Initializes random number generator

    int num[n];
    printf("Number before sorting\n");

    for(i=0;i<n;i++){
        num[i]=rand(); //random number between 0-32767
        printf("%d ",num[i]);
        Tree_Insert(num[i]);
    }

    printf("\nNumber after sorting\n");
    InOrder(Root);

// Fill your code here for sorting number using Tree-sort
}
