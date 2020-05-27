
/*-->Make a program to Sort the following string using a merge sort in increasing order. 
    a) Polynomial  
    b) “Test case” 
---------------------------------------------------------------------------------------------
 BY: Alok Sharma (11911001 CSE)
---------------------------------------------------------------------------------------------*/

#include<string.h>
#include<stdio.h>
#include<stdlib.h>

void merge(char arr[], int l, int m, int r) 
{ 
    int i, j, k; 
    int n1 = m - l+1; 
    int n2 =  r - m; 
  
    /* create temp arrays */
    char L[n1], R[n2]; 
  
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++) 
        L[i] = arr[l + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[m + 1+ j]; 
  
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0;                          // Initial index of first subarray 
    j = 0;                          // Initial index of second subarray 
    k = l;                          // Initial index of merged subarray 

    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            arr[k] = L[i]; 
            k++;
            i++;
            // printf("\n%s",arr);
        } 
        else
        { 
            arr[k] = R[j];
            k++;
            j++; 
            //  printf("\n%s",arr);
        } 
         
    } 
  
    /* Copy the remaining elements of L[], if there 
       are any */
    while (i < n1) 
    { 
        arr[k] = L[i];
        k++;
        i++; 
        //  printf("\n%s",arr);
    } 
  
    /* Copy the remaining elements of R[], if there 
       are any */
    while (j < n2) 
    { 
        arr[k] = R[j];
        k++;
        j++; 
        // printf("\n%s",arr);
         
    } 

} 
  
/* l is for left index and r is right index of the 
   sub-array of arr to be sorted */
void mergeSort(char arr[], int l, int r) 
{ 
    if (l < r) 
    { 
        // Same as (l+r)/2, but avoids overflow for 
        // large l and h 
        int m = (r+l)/2; 
  
        // Sort first and second halves 
        mergeSort(arr, l, m); 
        mergeSort(arr, m+1, r); 
  
        merge(arr, l, m, r); 
    } 
    return;
}

void main()
{
    printf("\n(2). SORTING STRINGS USING MERGESORT\n");

    /* the first string is Polynomial*/

    char s1[]="Polynomial";
    int n=10;
    

    printf("\n(a) Initially string is : \"");               //print the initial string
    for(int i=0;i<n;i++)
    printf("%c",s1[i]);
    printf("\"");
    

    mergeSort(s1,0,n-1);            //merge sort function

    printf("\n    Sorted string is : \"");
    for(int i=0;i<n;i++)                                //print the sorted string
    printf("%c",s1[i]);
    printf("\"");

    char s2[]="Test case";
    int n2=9;
    
    /*now, for the second string "Test case"*/

    printf("\n(b) Initially string is : \"");
    for(int i=0;i<n2;i++)
    printf("%c",s2[i]);                             //print the initial string
    printf("\"");

    

    mergeSort(s2,0,n2-1);                   //merge sort function

    printf("\n    Sorted string is : \"");
    for(int i=0;i<n2;i++)                           //print the sorted string
    printf("%c",s2[i]);
    printf("\"");

    
}