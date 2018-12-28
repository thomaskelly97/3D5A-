#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#define size 10000

void quicksort (int arr[], int first, int last);
int partition(int arr[], int first, int last);
int isItUnique(int r, int arr[], int s); 
void printArray(int arr[]);
void swap(int arr[], int a, int b);

int swap_count = 0; 
int comps = 0; 

int main (){
    //% DIFFERENT ARRAY TYPES 
    int rand_arr[size]; 
    int dup_arr[size];
    int asc_arr[size];
    int uni_arr[size];
    int desc_arr[size];
    int random, dd=size;

    //Set all arrays 
    for(int i1=0; i1 < size; i1++){
        random = rand(); 
        while(isItUnique(random, rand_arr,i1)==1){
            random = rand();
        }
        rand_arr[i1] = random; 
        desc_arr[i1] = dd; 
        dd--;  
        dup_arr[i1] = rand(); //Fill random duplicate array
        asc_arr[i1] = i1; //Ascending array 
        uni_arr[i1] = 3; //Uniform array 
    }

    int start = 0, end = size-1;
    printf("---QUICKSORT---\n");
    //UNIQUE RANDOM ARRAY 
    printf("Random Array with unique vales\n"); 
    quicksort(rand_arr, start, end); 
    printf("Swaps: %i\nComparisions: %i\n\n", swap_count,comps);
    swap_count = 0; comps = 0; 
    //DUPLICATE RANDOM ARRAY 
    printf("Random Array with duplicate values\n"); 
    quicksort(dup_arr, start, end); 
    printf("Swaps: %i\nComparisions: %i\n\n", swap_count,comps);
    swap_count = 0; comps = 0; 
     //ASCENDING ARRAY 
    printf("Ascending Sorted Array\n"); 
    quicksort(asc_arr, start, end); 
    printf("Swaps: %i\nComparisions: %i\n\n", swap_count,comps);
    swap_count = 0; comps = 0; 
    //DESCENDING SORTED ARRAY 
    printf("Descending Sorted Array\n"); 
    quicksort(desc_arr, start, end); 
    printf("Swaps: %i\nComparisions: %i\n\n", swap_count,comps);
    swap_count = 0; comps = 0; 
    //UNIFORM VALUE ARRAY 
    printf("Uniform Value Array\n"); 
    quicksort(uni_arr, start, end); 
    printf("Swaps: %i\nComparisions: %i\n\n", swap_count,comps);
    swap_count = 0; comps = 0; 


    return 0; 
}

void quicksort (int arr[], int first, int last){
   int q;   
   comps++; 
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
        
       // printf("Loop %i\n", count);
        do {
            i++; //Move i until you find something bigger than the pivot   
        } while(arr[i] < pivot);

        do{
            j--;  //Move j until you find something smaller than the pivot 
        }while(arr[j] > pivot && j > 0);
        comps++; 
        if(i >= j){
            comps++; 
            if(arr[i] != arr[last]){ //If the values are the same, dont swap 
                swap(arr, i,last);
            }
            
            return i; //Return value of pivot   
        }
        comps++; 
        if(arr[i] != arr[j]){ //If the values are the same, dont swap 
            swap(arr, i,j);
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

int isItUnique(int r, int arr[], int s){
    int check = 0; //If check == 0 then r is unique 
    for(int i =0;i<s;i++){
        if(r == arr[i]){
            return 1; 
        } 
    }
    return 0; 
}

void swap(int arr[], int a, int b){
    swap_count++; 
    int temp = arr[a]; 
    arr[a] = arr[b]; 
    arr[b] = temp; 
}
