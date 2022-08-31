#include <stdio.h>
#include <stdbool.h>
#define maxsize 50

int S[maxsize] = {0};
int Top = -1;

bool isEmpty();
bool isFull();
void push(int);
int pop();
int peek();
void display();

bool isEmpty(){
    if(Top == -1)
        return true;
    return false;
}

bool isFull(){
    if(Top == maxsize-1)
        return true;
    return false;
}

void push(int data){
    if(Top==maxsize-1)
        printf("\nStack is Full\n");
        else{
            Top++;
            S[Top] = data;
        }
}

int pop(){
    int data;
    if(Top == -1){
        printf("\nStack is Empty\n");
        return -1;
        }
        else{
            data = S[Top];
            Top--;
            return data;
        }
}

int peek(){
    if(Top == -1){
        printf("\nStack is Empty\n");
        return -1;
        }
        else{
            return S[Top];
        }
}

void display(){
    int i;
    if(Top == -1)
        printf("\nStack is Empty\n");
    else
        for(i=Top;i>=0;i--)
            printf("\n%d",S[i]);
    }

int main(){
    int item, option;
    do{
        printf("\n ***** MAIN MENU *****");
        printf("\n1.PUSH\n2.POP\n3.PEEK\n4.DISPLAY");
        printf("\n5.EXIT");
        printf("\nEnter your option: ");
        scanf("%d",&option);

        switch(option){
        case 1:
            printf("\nEnter the number to be used on stack: ");
            scanf("%d",&item);
            push(item);
            break;

        case 2:
            item = pop();
            if(item!= 1)
                printf("\nThe value deleted from stack is: %d",item);
                break;

        case 3:
            item = peek();
            if(item!=-1)
                printf("\nThe value stored at top of stack is: %d",item);
                break;

        case 4: display();
                break;

        case 5:
                printf("Unknown option\n");
                break;
            }
    }while(option!=5);
    return 0;
}
