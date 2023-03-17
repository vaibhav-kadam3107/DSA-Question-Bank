//WAP to implement Insertion sort and Merge Sort on 1D array of
//Student structure (contains student_name, student_roll_no, total_marks),
//with key as student_roll_no. And count the number of swap performed.

#include <stdio.h>

struct student
{
    char std_name[100];
    int std_roll_no;
    int total_marks;
};

void merge(struct student s[] , int start , int end){
    int mid = start + (end-start)/2;
    int length1 = mid - start +1;
    int length2 = end - mid;
    
    struct student first[length1];
    struct student second[length2];

    int mai = start;
    for (int i = 0; i < length1; i++)
    {
        first[i] = s[mai++];
    }
    mai = mid+1;
    for (int i = 0; i < length2; i++)
    {
        second[i] = s[mai++];
    }

    int i=0 , j=0;
    //mai = start;
    while (i < length1 && j < length2)
    {
        if (first[i].std_roll_no < second[j].std_roll_no)
        {
            s[start++] = first[i++];
        }
        else{
            s[start++] = second[j++];
        }
        
    }
    while (i < length1)
    {
        s[start++] = first[i++];
    }
    while (j < length2)
    {   
        s[start++] = second[j++];
    }
 
}

void merge_sort(struct student s[] , int start , int end){
    //base case
    if (start >= end)
    {
        return;
    }
    printf("function is running");
    int mid = start + (end - start)/2;
    merge_sort(s , start , mid );
    merge_sort(s , mid+1 , end);

    merge(s , start , end);
    
}

int main(){

    int n, start, end;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct student s[n];
    for (int i = 0; i < n; i++)
    {
        printf("\nEnter %d student info", i+1);
        printf("\nEnter student name: ");
        scanf("%s" , s[i].std_name);
        printf("\nEnter student roll no: ");
        scanf("%d" , &s[i].std_roll_no);
        printf("\nEnter student total marks: ");
        scanf("%d" , &s[i].total_marks);

    }

    printf("\nBefore sorting\n");
    printf("roll_no\tStudent_Name\t\tMarks\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%s\t\t\t%d\n", s[i].std_roll_no , s[i].std_name , s[i].total_marks);
    }

    start = 0;
    end = n-1;
    merge_sort(s , start , end);

    printf("\nAfter sorting\n");
    printf("roll_no\tStudent_Name\t\tMarks\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%s\t\t\t%d\n", s[i].std_roll_no , s[i].std_name , s[i].total_marks);
    }
    
    return 0;
}