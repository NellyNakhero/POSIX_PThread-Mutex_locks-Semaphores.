#include <stdio.h>
#include <stdlib.h>  
#include <pthread.h>

int marks[100];
int binSize = 10;
int groupCount[10];

int getBinStartIndex(int binNumber) {
    int endIndex = (binSize * binNumber) ;
    return endIndex - binSize;
}

void* processBinArray(void* p ) {
    int groupNumber = *(int*) p;
    int startIndex = getBinStartIndex(groupNumber);
    int bin[binSize];
    int currentIndex =  startIndex;
    for (int i = 0; i < binSize; i++) {
        bin[i] = marks[currentIndex];
        currentIndex ++;
        int group = bin[i] / 10;

        int currentCount = groupCount[group];
        groupCount[group] = ++currentCount;
        
        
        // printf(" Group %d , count:  %d  \n", group +1, groupCount[group]);
    }
     pthread_exit(&groupNumber);
   
}

int main() {
    int numbers[100];
    int j =0;
    FILE *file;

    //Read 100 integers from given input file into an array
    if( file = fopen("example.txt", "r"))
    {
        while (fscanf(file, "%d", &numbers[j]) != EOF)
        {
            j++;
        }
        fclose(file);
    }


    
    // initialize array with file values
    for(int i = 0; i < 100; i++) {
       marks[i] = numbers[i];
    }

    pthread_t tid[10] = {1,2,3,4,5,6,7,8,9,10};
    int group1 = 1;
    int group2 = 2;
    int group3 = 3;
    int group4 = 4;
    int group5 = 5;
    int group6 = 6;
    int group7 = 7;
    int group8 = 8;
    int group9 = 9;
    int group10 = 10;

    
        pthread_create(&tid[10], NULL, processBinArray, &group10);
        pthread_create(&tid[1], NULL, processBinArray, &group1);
        pthread_create(&tid[2], NULL, processBinArray, &group2);
        pthread_create(&tid[3], NULL, processBinArray, &group3);
        pthread_create(&tid[4], NULL, processBinArray, &group4);
        pthread_create(&tid[5], NULL, processBinArray, &group5);
        pthread_create(&tid[6], NULL, processBinArray, &group6);
        pthread_create(&tid[7], NULL, processBinArray, &group7);
        pthread_create(&tid[9], NULL, processBinArray, &group9);
        pthread_create(&tid[8], NULL, processBinArray, &group8);
    


    for (int i = 0; i < 10; i++)
    {
        int currentCount = groupCount[i];
        groupCount[i] = ++currentCount;
        printf(" Group %d , count:  %d  \n", i, groupCount[i]);
    }
    
    
    int* result;
    pthread_join(tid[0], (void**)&result);
  

    return 0;
}