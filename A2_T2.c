#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#define size1 10001
void printArray(int arr[]); 
void insertionSort(int arr[], int size);
int isItUnique(int r, int arr[], int s);
void swap(int arr[],int a,int b);
int swaps=0, comps=0; 

int main(){
     //Using insertion sort because it is stable and better than insertionSort for small data sets and nearly sorted data
     //while insertionSort is bad at these things 
    
    //% DIFFERENT ARRAY TYPES 
    
    int rand_arr[size1]; 
    int dup_arr[size1];
    int asc_arr[size1];
    int uni_arr[size1];
    int desc_arr[size1];
    int random, dd=size1;


    //Set all arrays 
    for(int i1=0; i1 < size1; i1++){
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
    printf("---INSERTIONSORT---\n");
    //UNIQUE RANDOM ARRAY 
    printf("Random Array with unique vales\n"); 
    //printArray(rand_arr);
    insertionSort(rand_arr, size1); 
    //printArray(rand_arr);
    printf("Swaps: %i\nComparisions: %i\n\n", swaps,comps);
    swaps = 0; comps = 0; 
    //DUPLICATE RANDOM ARRAY 
    printf("Random Array with duplicate values\n"); 
    //printArray(dup_arr);
    insertionSort(dup_arr, size1); 
    //printArray(dup_arr);
    printf("Swaps: %i\nComparisions: %i\n\n", swaps,comps);
    swaps = 0; comps = 0; 
     //ASCENDING ARRAY 
    printf("Ascending Sorted Array\n"); 
    //printArray(asc_arr);
    insertionSort(asc_arr, size1); 
   // printArray(asc_arr);
    printf("Swaps: %i\nComparisions: %i\n\n", swaps,comps);
    swaps = 0; comps = 0; 
    //DESCENDING SORTED ARRAY 
    printf("Descending Sorted Array\n"); 
    //printArray(desc_arr);
    insertionSort(desc_arr, size1); 
    //printArray(desc_arr);
    printf("Swaps: %i\nComparisions: %i\n\n", swaps,comps);
    swaps = 0; comps = 0; 
    //UNIFORM VALUE ARRAY 
    printf("Uniform Value Array\n"); 
    //printArray(uni_arr);
    insertionSort(uni_arr, size1); 
    //printArray(uni_arr);
    printf("Swaps: %i\nComparisions: %i\n\n", swaps,comps);
    swaps = 0; comps = 0; 


    return 0; 
}

void printArray(int arr[]){
    printf("{");
    for(int i =0; i< 10; i++){
        printf("%i ", arr[i]);
    }
    printf("}\n");
}

void insertionSort(int arr[], int size){
    //printf("Implementing insertion sort...\n");
    for(int i=0; i<size-1;i++){
        for(int j = i+1; j>0;j--){
            comps++; 
            if(arr[j-1] > arr[j] ){
                swap(arr,(j-1),j);
                swaps++; 
            } else {
                break; 
            }
        }
    }
}

void swap(int arr[],int a,int b){
    int temp = arr[a]; 
    arr[a] = arr[b]; 
    arr[b] = temp; 
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
