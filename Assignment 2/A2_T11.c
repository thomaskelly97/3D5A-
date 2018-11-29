#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#define size 10 

void quicksort (int arr[], int first, int last);
int partition(int arr[], int first, int last);
void printArray(int arr[]);
int swap_count = 0; 
int comps = 0; 

int main (){
    //Array for testing 
    int array[] = {0,2,1,6,9,4,7,8,3,5};
  

   
    int start = 0, end = size-1;
   
    //UNIQUE RANDOM ARRAY 
    printf("\nUnsorted Array:\n"); 
    printArray(array);
    quicksort(array, start, end); 
    printf("Sorted Array:\n");
    printArray(array);
    printf("Swaps: %i\nComparisions: %i\n\n", swap_count,comps);
    swap_count = 0; comps = 0; 
  


    return 0; 
}

void quicksort (int arr[], int first, int last){
   int q;   
   if(first < last){
        q = partition(arr, first, last);
        quicksort(arr, first, q-1);
        quicksort(arr, q+1, last);
   }
}


int partition(int  arr[], int first, int last){
    int i,j,pivot;

    i = (first-1); j = last; 
    pivot = arr[last]; 
    while(true){
        comps++; 
       // printf("Loop %i\n", count);
        do {
            i++; 
        } while(arr[i] < pivot);

        do{
            j--; 
        }while(arr[j] > pivot && j > 0);

        if(i >= j){
            int temp = arr[i];
            //printf("Swapping %i and %i\n", arr[i],arr[last]);
            arr[i] = arr[last]; 
            arr[last] = temp;
            if(arr[i] != arr[last]){
                swap_count++; 
        }
            return i;   
        }
         //printf("Swapping %i and %i\n", arr[i],arr[j]);
    int temp2 = arr[i]; 
    arr[i] = arr[j]; 
    arr[j] = temp2;  
    if(arr[i] != arr[j]){
                swap_count++; 
            } 
    }

} 


void printArray(int arr[]){
    printf("{");
 for(int i =0; i<size; i++){
        printf("%d ", arr[i]);
    } 
    
    printf("}\n");
  
}

