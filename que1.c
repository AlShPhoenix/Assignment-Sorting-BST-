//Program 1
/*--> Make a program to Sort the given array using different sorting techniques to test and compare these techniques:
    1: Quick sort
    2: Selection sort
    3: Merge sort
    4: Insertion sort
---------------------------------------------------------------------------------------------
 BY: Alok Sharma (11911001 CSE)
---------------------------------------------------------------------------------------------*/


#include<stdio.h>

void ssort(int* a, int n)       //function for selection sort
{
    for(int i=0;i<n;i++)
    {
        int p=i;
        int m=a[i];

        for(int j=i+1;j<n;j++)
        {
            if(a[j]<m)
            {
                m=a[j];
                p=j;                //finding smallest element in the rest of the left array
            
            }

        }

        int t=a[i];                 //swap a[i] with a[p]
        a[i]=a[p];
        a[p]=t;

    }

}


/* This function takes last element as pivot, places 
   the pivot element at its correct position in sorted 
    array, and places all smaller (smaller than pivot) 
   to left of pivot and all greater elements to right 
   of pivot */

int partition (int *a, int l, int h) 
{ 
    int pivot = a[h];    // pivot 
    int i = (l - 1);  // Index of smaller element 
  
    for (int j = l; j <= h- 1; j++) 
    { 
                                    // If current element is smaller than the pivot 
        if (a[j] < pivot) 
        { 
            i++;                    // increment index of smaller element 

            int t=a[i];                //swap a[i] and a[j]
            a[i]=a[j];
            a[j]=a[i];
             
        } 
    
    } 

    int t=a[i+1];
    a[i + 1]=a[h];
    a[h]=t;

    return (i + 1); 

} 
  
/* The main function that implements QuickSort 
 a[] --> Array to be sorted, 
  l  --> Starting index, 
  h  --> Ending index */

void qsort(int* a, int l, int h) 
{ 
    if (l < h) 
    { 

        int pi = partition(a, l, h);     /* pi is partitioning index, arr[p] is now 
                                               at right place */
        
                                            // Separately sort elements before 
                                            // partition and after partition 
        qsort(a, l, pi - 1); 
        qsort(a, pi + 1, h); 

    } 

} 
 
 //function for insertion sort
void isort(int *a,int n)
{

    int i,j,t;

    for(i=0;i<n;i++)
    {
        t=a[i];
	    j=i-1;

	    while(j>=0 && a[j]>t) 
        {
            a[j+1]=a[j];
            j--;

        }

	    a[j+1]=t;

    }


}

void merge(int*a , int l, int m, int r)     //function to merge the two sorted arrays
{ 

    int i, j, k; 

    int n1 = m - l + 1; 
    int n2 =  r - m; 
  
                                // create temporary arrays 
    int L[n1], R[n2]; 
  
                                // Copy data to temp arrays L[] and R[] 
    for (i = 0; i < n1; i++) 
        L[i] = a[l + i]; 

    for (j = 0; j < n2; j++) 
        R[j] = a[m + 1+ j]; 
  
                 // Merge the temp arrays back into arr[l..r]

    i = 0;                   // Initial index of first subarray 

    j = 0;                   // Initial index of second subarray 
    
    k = l;                   // Initial index of merged subarray 
    
    while (i < n1 && j < n2) 
    { 
        if (L[i] <= R[j]) 
        { 
            a[k++] = L[i++]; 
             
        } 

        else
        { 
            a[k++] = R[j++]; 
             
        } 
         

    } 
  
                            // Copy the remaining elements of L[], if there are any 
       
    while (i < n1) 
    { 
        a[k++] = L[i++]; 

    } 
  
                            // Copy the remaining elements of R[], if there are any 
       
    while (j < n2) 
    { 
        a[k++] = R[j++]; 
        
    } 


} 
  

void msort(int *a, int l, int r)            //function for merge sort
{ 

    if (l < r) 
    { 
        
        int m = l+(r-l)/2; 
  
        // Sort first and second halves 
        msort(a, l, m); 
        msort(a, m+1, r); 
  
        merge(a, l, m, r); 
    } 

}


void printarr(int* a,int n)     //common function to print the sorted array
{

    printf("\n The sorted array is: ");

    for(int i=0;i<n;i++)
    printf("%d ",a[i]);

}

void main()
{
    
    printf("\n enter the size of the integer array");
    int n;
                            //input the size of the array
    scanf("%d",&n);
   
    printf("\n enter the elements of the array");
    int a[n];                   //input the elements of the array
    
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);

    }
    
    printf("\n Initially the array is: ");
                                                            //print the initial array
    for(int i=0;i<n;i++)                
    printf("%d ",a[i]);
    
    int wish;                   //variable wish is to input the type of sorting technique
    
    printf("\n enter \n 1: quick sort\n 2:selection sort \n 3:merge sort\n 4:insertion sort \n-1:exit");
    scanf("%d",&wish);
    
    while(wish!=-1)
    {
        switch(wish)                    //switch function for different values of wish
        {
            case 1: {
                        qsort(a,0,n);
                        printarr(a,n);              //quick sort
                        break;
                    }   
            case 2:{
                ssort(a,n);                         //selection sort
                printarr(a,n);
                break;
            }
            case 3:{
                msort(a,0,n-1);                     //merge sort
                printarr(a,n);
                break;
            }
            case 4:{
                isort(a,n);                         //insertion sort
                printarr(a,n);
                break;                
            }
            default: printf("\n Invalid Choice");
        }
        
        printf("\n enter \n 1: quick sort\n 2:bubble sort \n 3:merge sort\n 4:insertion sort \n-1:exit");
        scanf("%d",&wish);

    }

}
