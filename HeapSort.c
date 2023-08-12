// Heap Sort in C
 
#include <stdio.h>
#include<stdlib.h>
#include <time.h>
 
// Function to swap the position of two elements
 
void swap(int* a, int* b)
{
 
    int temp = *a;
    *a = *b;
    *b = temp;
}
 
// To heapify a subtree rooted with node i
// which is an index in arr[].
// n is size of heap
void heapify(int arr[], int N, int i)
{
    // Find largest among root,
    // left child and right child
 
    // Initialize largest as root
    int largest = i;
 
    // left = 2*i + 1
    int left = 2 * i + 1;
 
    // right = 2*i + 2
    int right = 2 * i + 2;
 
    // If left child is larger than root
    if (left < N && arr[left] > arr[largest])
 
        largest = left;
 
    // If right child is larger than largest
    // so far
    if (right < N && arr[right] > arr[largest])
 
        largest = right;
 
    // Swap and continue heapifying
    // if root is not largest
    // If largest is not root
    if (largest != i) {
 
        swap(&arr[i], &arr[largest]);
 
        // Recursively heapify the affected
        // sub-tree
        heapify(arr, N, largest);
    }
}
 
// Main function to do heap sort
void heapSort(int arr[], int N)
{
 
    // Build max heap
    for (int i = N / 2 - 1; i >= 0; i--)
 
        heapify(arr, N, i);
 
    // Heap sort
    for (int i = N - 1; i >= 0; i--) {
 
        swap(&arr[0], &arr[i]);
 
        // Heapify root element
        // to get highest element at
        // root again
        heapify(arr, i, 0);
    }
}
 
// A utility function to print array of size n
void printArray(int arr[], int N)
{
    for (int i = 0; i < N; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
// Driver's code
int main()
{   int N;
    clock_t start,end;
    printf("sorting using heapSort\n");
    printf("Enter the number of elements: ");
    scanf("%d",&N);
    int arr[N];
    if(N<=10)
    {
        printf("enter the elements of the array\n");
        for(int i=0;i<N;i++)
        {
            scanf("%d",&arr[i]);
        }
    }
    else
    {
        printf("Providing random numbers\n");
        for(int i=0;i<N;i++)
        {
            arr[i] = rand();
        }
    }
    // Function call
    start = clock();
    heapSort(arr, N);
    end = clock();
    double time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Sorted array is\n");
    printArray(arr, N);
     printf("\nTime taken to sort %d elements: %f seconds\n", N, time_taken);
 return 0;
}
