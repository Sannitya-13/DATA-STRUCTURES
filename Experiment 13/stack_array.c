#include <stdio.h>
#include <stdlib.h>
# define max_size 10
void push(int item);
int pop();
int Isfull();
int Isempty();
int stack[max_size];
int top = -1;
int main(){
    int choice,value,want_continue;
    printf("Enter choice: 1.Push 2.Pop\n");
    do{
       printf("enter choice\n");
       scanf("%d",&choice);
       switch(choice){
              case 1:printf("enter value to be pushed:");
                     scanf("%d",&value);
                     push(value);
                     break;
              case 2:value = pop();
                     printf("%d\n",value);
                     break;
      }
      printf("want to continue,enter 1:");
      scanf("%d",&want_continue);
      }
      while(want_continue == 1);
      return 0;
}
int Isempty(){
    return top == -1;
}
int Isfull(){
    return top == max_size -1;
}
void push(int item){
     if(Isfull() == 1){
       printf("Overflow\n");
       return ;
    }
    top += 1;
    stack[top] = item;
}
int pop(){
    if(Isempty() == 1){
         printf("Underflow\n");
         exit(0);
    }
    return stack[top--];
}
    
       
