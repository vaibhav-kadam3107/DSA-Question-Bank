//WAP to implement multiple stack i.e. More than two stacks using array
//and perform following operations on it. A. PUSH, B. POP, C. StackFull
//D. Stack Empty E. Display Stack.

#include<stdio.h>
#define max 100

int arr[max];
int top1 = -1;
int top2 = max;

int Empty(int stack_no){
    if(stack_no == 1 ){
        if(top1 == -1)
            return 1;
        return 0;
    }
    else if (stack_no == 2)
    {
        if(top2 == max)
            return 1;
        return 0;
    }
}

int Full(){
    if(top1 + 1 == top2)
        return 1;
    return 0;
}

void push(int stack_no , int val){
    if(Full()){
        printf("stack is full");
        return;
    }
    if(stack_no == 1){
        top1++;
        arr[top1] = val;
    }
    else if (stack_no == 2)
    {
        top2--;
        arr[top2] = val;
    }
}

int pop(int stack_no){
    int val;
    if(stack_no == 1){
        if(Empty(stack_no)){
            return -1;
        }
        val = arr[top1];
        top1--;
        return val;
    }
    else if (stack_no == 2)
    {
        if(Empty(stack_no))
            return -1;
        val = arr[top2];
        top2--;
        return val;
    }
    
}

void display(int stack_no){
    if(stack_no == 1){
        printf("\nStack 1 is : ");
        for (int i = 0; i <= top1; i++)
        {
            printf("%d " , arr[i]);
        }
        printf("\n");
    }
    else if (stack_no == 2)
    {
        printf("\nStack 2 is : ");
        for (int i = top2; i < max; i++)
        {
            printf("%d " , arr[i]);
        }
        printf("\n");
    }
    
}

int main(){
    int ch,stack_no,val;
    while (1)
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Check if stack is full\n");
        printf("4. Check if stack is empty\n");
        printf("5. Display stack\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("\nEnter stack no: ");
            scanf("%d" , &stack_no);
            printf("Enter value: ");
            scanf("%d" , &val);
            push(stack_no , val);
            break;

        case 2:
            printf("\nEnter stack no: ");
            scanf("%d" , &stack_no);
            printf("Popped value: %d\n", pop(stack_no));
            break;

        case 3: 
            if(Empty(stack_no))
                printf("\nStack is Empty\n");
            else{
                printf("\nStack is not empty\n");
            }
            break;
        
        case 4:
            if(Full())
                printf("\nStack is Full\n");
            else{
                printf("\nstack is not full\n");
            }
            break;

        case 5:
            printf("\nEnter stack no: ");
            scanf("%d" , &stack_no);
            display(stack_no);
            break;
        
        case 6: 
            return 0;
        
        default: printf("\nEnter correct choice");
            break;
        }
    }
    
    return 0;
}

