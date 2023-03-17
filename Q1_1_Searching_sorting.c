// WAP to implement Bubble sort and Quick Sort on 1D array of Student
// structure (contains student_name, student_roll_no, total_marks), with
// key as student_roll_no. And count the number of swap performed.

#include <stdio.h>

struct student
{
    char std_name[100];
    int std_rollNo;
    int std_marks;
};

void swap(struct student *s1, struct student *s2){
    struct student temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

int partition(struct student s[] , int start , int end , int *swap_count){
    int pivot = s[start].std_rollNo;
    int count = 0;

    //to find the correct position of pivot
    for (int i = start+1; i <= end; i++)
    {
        if (s[i].std_rollNo <= pivot)
        {
            count++;
        } 
    }

    int pivot_index = start + count;
    swap(&s[pivot_index] , &s[start]);
    (*swap_count)++;

    //place all the elements less than pivot to right and greater to left of pivot
    int k = start;
    int l = end;

    while (k < pivot_index && l > pivot_index)
    {
        if (s[k].std_rollNo <= pivot)
        {
            k++;
        }
        if (s[l].std_rollNo > pivot)
        {
            l--;
        }
        if (k < pivot_index && l > pivot_index)
        {
            swap(&s[k++] , &s[l--]);
            (*swap_count)++;
        }
        
        
    }
    
    return pivot_index;
}

void quick_sort(struct student s[] , int start , int end , int *swap_count){
    //base condition
    if(start >= end){
        return ;
    }

    
    int pivot_index = partition(s , start , end , swap_count);

    quick_sort(s, start , pivot_index-1 , swap_count);
    quick_sort(s , pivot_index + 1, end , swap_count);
}


void bubble_sort(struct student s[] , int n, int *swap_count){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if (s[j].std_rollNo > s[j+1].std_rollNo) 
            {
                struct student temp = s[j];
                s[j] = s[j+1];
                s[j+1] = temp;
                (*swap_count)++;
            }
            
        }
        
    }
    
}


int main(){
    int n,swap_count=0, start ,end;
    printf("Enter number of student: ");
    scanf("%d" , &n);

    struct student s[n];

    for (int i = 0; i < n; i++)
    {
        printf("\nenter %d student info: \n\n", i+1);
        printf("Enter student name: ");
        scanf("%s" , &s[i].std_name);

        printf("Enter student roll no: ");
        scanf("%d" , &s[i].std_rollNo);

        printf("Enter student marks: ");
        scanf("%d" , &s[i].std_marks);

    }

    /*
    printf("\n-------Bubble sort--------\n");
    printf("\nbefore sorting\n");
    printf("roll_no\tStudent_Name\t\tMarks\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%s\t\t\t%d\n", s[i].std_rollNo , s[i].std_name , s[i].std_marks);
    }

    bubble_sort(s, n, &swap_count);

    printf("\nAfter sorting\n");
    printf("roll_no\tStudent_Name\t\tMarks\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%s\t\t\t%d\n", s[i].std_rollNo , s[i].std_name , s[i].std_marks);
    }
    printf("\nNumber of swap count = %d" , swap_count);

    */

    //swap_count = 0;
    
    start = 0;
    end = n-1;

    printf("s is : %d\n",s[0].std_rollNo );
    printf("e is : %d\n",s[n-1].std_rollNo );

    printf("\n-------Quick sort--------\n");
    printf("\nbefore sorting\n");
    printf("roll_no\tStudent_Name\t\tMarks\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%s\t\t\t%d\n", s[i].std_rollNo , s[i].std_name , s[i].std_marks);
    }

    quick_sort(s , start, end , &swap_count);

    printf("\nAfter sorting\n");
    printf("roll_no\tStudent_Name\t\tMarks\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%s\t\t\t%d\n", s[i].std_rollNo , s[i].std_name , s[i].std_marks);
    }
    printf("\nNumber of swap count = %d" , swap_count);
    
    return 0;
}