#include<stdio.h>
#include<string.h>
#include <stdbool.h>
#define maxsize 50

char S[maxsize] = {0};
int Top = -1;

bool isEmpty();
bool isFull();
void push(char);
char pop();
char peek();
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

void push(char data){
    if(Top==maxsize-1)
        printf("\nStack is Full\n");
        else{
            Top++;
            S[Top] = data;
        }
}

char pop(){
    char data;
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

char peek(){
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

int cal(char data){

if(data=='+'||data=='-')return 1;
else if (data=='*'||data=='/')return 2;
else if (data=='^')return 3;
else return 0;
}
int main(){
    char A[99];
    printf("Enter infix expression: ");
    gets(A);
    printf("Postfix: ");
    for(int i=0;i<strlen(A);i++){
        if(A[i] == '('){
            push(A[i]);
        }
        else if(A[i] == '+' || A[i] == '-' || A[i] == '*' || A[i] == '/' || A[i] == '^'){
            if(isEmpty()){
                    push(A[i]);
            }

            else if (cal(A[i])>cal(S[Top])){
                    push(A[i]);
            }

            else if (cal(A[i])<=cal(S[Top])){
                printf("%c",pop());
                push(A[i]);
            }
        }
        else if(A[i]==')'){
            while(S[Top]!='('){
                char g = pop();
                printf("%c",g);
            }
            Top--;
        }
        else{
            printf("%c",A[i]);
        }


     }
     while(!isEmpty()){
        char g = pop();
        printf("%c",g);
     }

}
