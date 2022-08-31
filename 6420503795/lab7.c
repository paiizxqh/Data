#include <stdio.h>
#include <stdbool.h>
#include<string.h>
#define maxsize 50

char S[maxsize] = {0};
int Top = -1;

bool isEmpty();
bool isFull();
void push(char);
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

void push(char data){
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
    int check = 0;
    char A[99];
    printf("Enter letter: ");
    gets(A);

    for(int i=0;i<strlen(A);i++){
        if(A[i] == '{' || A[i] == '(' || A[i] == '['){
            push(A[i]);
            check++;
           }

           else if(A[i] == '}' || A[i] == ')' || A[i] == ']'){
            if(A[i] == '}'){
                if(S[Top]=='{'){
                    pop();
                    check--;
                }
                else{
                    printf("-1");
                    return 0;
                }
            }
            else if (A[i] == ')'){
                if(S[Top]=='('){
                    pop();
                    check--;
                }
                else{
                    printf("-1");
                    return 0;
                }
            }
            else if (A[i] == ']'){
                if(S[Top]=='['){
                    pop();
                    check--;
                }
                else{
                    printf("-1");
                    return 0;
                }

           }
        }

        //printf("%d",check);

    }
    printf("\nresult : ");
    printf("%d",check);

}
