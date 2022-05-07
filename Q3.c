#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

pthread_t tid[2];
int counter;
pthread_mutex_t lock;
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

        pthread_mutex_lock(&lock);
        int currentCount = groupCount[group];
        groupCount[group] = ++currentCount;
        pthread_mutex_unlock(&lock);
        
        
        // printf(" Group %d , count  %d : \n", group, groupCount[group]);
    }
     pthread_exit(&groupNumber);
   
}

void* routine(void* arg)
{
	pthread_mutex_lock(&lock);

	unsigned long i = 0;
	counter += 1;
	printf("\n Thread %d has started\n", counter);

    pthread_t tid[10] = {1,2,3,4,5,6,7,8,9};
    int group1 = 1;
    pthread_create(&tid[0], NULL, processBinArray, &group1);
    
    int* result;
    pthread_join(tid[0], (void**)&result);
    

	for (i = 0; i < (0xFFFFFFFF); i++)
		;

	printf("\n Thread %d has finished\n", counter);

	pthread_mutex_unlock(&lock);

	return NULL;
}

int main(void)
{
	int i = 0;
	int error;
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


	if (pthread_mutex_init(&lock, NULL) != 0) {
		printf("\n mutex init has failed\n");
		return 1;
	}

	// while (i < 10) {
	// 	error = pthread_create(&(tid[i]),
	// 						NULL,
	// 						&routine, NULL);
	// 	if (error != 0)
	// 		printf("\nThread can't be created :[%s]",
	// 			strerror(error));
	// 	i++;
	// }

    pthread_t tid[10] = {1,2,3,4,5,6,7,8,9,10};
    int group1 = 2;

    while (i < 10) {
		error = pthread_create(&(tid[i]),
							NULL,
							&processBinArray, &i);
		if (error != 0)
			printf("\nThread can't be created :[%s]",
				strerror(error));
		i++;
	}

    for (int i = 0; i < 10; i++)
    {
        int currentCount = groupCount[i];
        groupCount[i] = ++currentCount;
        printf(" Group %d , count:  %d  \n", i, groupCount[i]);
    }

    

	pthread_join(tid[0], NULL);
	pthread_join(tid[1], NULL);
    pthread_join(tid[2], NULL);
    pthread_join(tid[3], NULL);
    pthread_join(tid[4], NULL);
    pthread_join(tid[5], NULL);
    pthread_join(tid[6], NULL);
    pthread_join(tid[7], NULL);
    pthread_join(tid[8], NULL);
    pthread_join(tid[9], NULL);
	pthread_mutex_destroy(&lock);

	return 0;
}
