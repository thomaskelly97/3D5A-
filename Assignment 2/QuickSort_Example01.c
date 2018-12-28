#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> 

#define MAX_BUFFER 2000 // Maximum string length this program can handle

struct Game {
	int score,year;
	char title[MAX_BUFFER], platform[MAX_BUFFER];
};

struct Game arr[MAX_BUFFER]; 

int partition(struct Game arr[], int first, int last); 
int swap_count = 0; 
int comps = 0; 

// The CSV parser
int next_field( FILE *f, char *buf, int max ) {
	int i=0, end=0, quoted=0;
	
	for(;;) {
		// fetch the next character from file		
		buf[i] = fgetc(f);
		// if we encounter quotes then flip our state and immediately fetch next char
		if(buf[i]=='"') { quoted=!quoted; buf[i] = fgetc(f); }
		// end of field on comma if we're not inside quotes
		if(buf[i]==',' && !quoted) { break; }
		// end record on newline or end of file
		if(feof(f) || buf[i]=='\n') { end=1; break; } 
		// truncate fields that would overflow the buffer
		if( i<max-1 ) { ++i; } 
	}

	buf[i] = 0; // null terminate the string
	return end; // flag stating whether or not this is end of the line
}

// Stuff to make life a bit neater in main
void get_games ( FILE *csv, struct Game *p, int c) {
	char buf[MAX_BUFFER];
    
	next_field( csv, p->title, MAX_BUFFER );  //TITLE 
	next_field( csv, p->platform, MAX_BUFFER ); //PLATFORM 

	next_field( csv, buf, MAX_BUFFER ); //SCORE 
	p->score = atoi(buf);                       
	
	next_field( csv, buf, MAX_BUFFER ); //YEAR 
	p->year = atoi(buf);          

}

void print_games( struct Game p[] ) {
	int c = MAX_BUFFER-1; 
	int count =1; 
	while(c > MAX_BUFFER -11){
		printf("%d. %s, %s, %d, %d\n", (count),p[c].title, p[c].platform, p[c].score, p[c].year);
		c--; 
		count++; 
	}
}


void swap(struct Game arr[], int a, int b){
    swap_count++; 
    struct Game temp = arr[a]; 
    arr[a] = arr[b]; 
    arr[b] = temp; 
}

void quicksort (struct Game arr[], int first, int last){
   int q;   
   comps++; 
   if(first < last){
        q = partition(arr, first, last);
        quicksort(arr, first, q-1);
        quicksort(arr, q+1, last);
   }
}


int partition(struct Game arr[], int first, int last){
    int i,j,pivot;

    i = (first-1); j = last; 
    pivot = arr[last].score; 
    while(true){
        
       // printf("Loop %i\n", count);
        do {
            i++; //Move i until you find something bigger than the pivot   
        } while(arr[i].score < pivot);

        do{
            j--;  //Move j until you find something smaller than the pivot 
        }while(arr[j].score > pivot && j > 0);
        comps++; 
        if(i >= j){
            comps++; 
            if(arr[i].score != arr[last].score){ //If the values are the same, dont swap 
                swap(arr, i,last);
            }
            
            return i; //Return value of pivot   
        }
        comps++; 
        if(arr[i].score != arr[j].score){ //If the values are the same, dont swap 
            swap(arr, i,j);
        }
    
    }
}

int main ( int argc, char *argv[] ) {
	FILE *f;		
	struct Game p;
	struct Game array[MAX_BUFFER]; 
	int first = 0; 
	int last = MAX_BUFFER-1; 
    int count = 0; 

	if( argc < 2 ) { 
		printf("usage: csv FILE\n"); 
		return EXIT_FAILURE; 
	}

	// Try to open the input file. If there is a problem, report failure and quit
	f = fopen(argv[1], "r");
	if(!f) { 
		printf("unable to open %s\n", argv[1]); 
		return EXIT_FAILURE; 
	}

	get_games( f, &p, count); // discard the header data in the first line

	// Now read and print pokemon until the end of the file

    printf("Implementing on an array of size: %d\n   Title - Platform - Score - Year\n", MAX_BUFFER);
	while(!feof(f) && count < MAX_BUFFER) {
		get_games( f, &p, count);
		array[count] = p; 
		
		//printf("\n");
        count++; 
	}
	quicksort(array, first, last);
    print_games( array );
	printf("\n");
	// Always remember to close the file
	fclose(f);
	return EXIT_SUCCESS;
}

